/*
*  2010 � 2012 Copyright Northwestern University and Stanford University 
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.
*/


package edu.stanford.isis.ats.ui;

import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.HashMap;
import java.util.List;
import java.util.Locale;
import java.util.Map;

import org.restlet.data.Disposition;
import org.restlet.data.Form;
import org.restlet.data.MediaType;
import org.restlet.representation.Representation;
import org.restlet.representation.StringRepresentation;
import org.restlet.resource.Get;

import com.sleepycat.dbxml.XmlException;
import com.sleepycat.dbxml.XmlValue;

import edu.stanford.isis.ats.resources.Constants;
import edu.stanford.isis.ats.resources.Uid;
import edu.stanford.isis.ats.utils.FreemarkerUtil;
import edu.stanford.isis.ats.xmldb.DbUtils;
import edu.stanford.isis.ats.xmldb.XMLDatabaseResource;
import edu.stanford.isis.ats.xmldb.data.QueryResultAdapter;
import edu.stanford.isis.ats.xmldb.data.TemplateComponentQueryResult;

/**
 * The resource to download search results as XML.
 * @author alansnyder
 * @author Vladimir Kleper
 */
public class DownloadResource extends XMLDatabaseResource {

    private static final String PARAM_NAME_UID = "uid"; // template UID
    private static final String PARAM_NAME_MODE = "mode"; // download mode: View, Save As, etc.
    
    private static final String MODE_SAVE_AS = "save"; // will trigger attachment Save As dialog in a browser
    private static final String MODE_VIEW = "view"; // in-line viewing mode (default)

    private static final String TEMPLATE_XQUERY = "for $x in collection(\"%s\")/TemplateContainer/Template[@uid=\"%s\"] \n return $x";
    private static final String GROUP_XQUERY = "for $x in collection(\"%s\")/TemplateContainer[@uid=\"%s\"] \n return $x";

    private static final HashMap<String, String> templateContainerProtos;
    static {
        templateContainerProtos = new HashMap<String, String>();
        templateContainerProtos.put(Constants.TEMPLATE_SCHEMA_NAME_V1RV23, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<TemplateContainer creationDate=\"%s\" authors=\"ATS 1.0\" name=\"ATS Template\" version=\"1\" uid=\"%s\" description=\"Template container generated by ATS 1.0\" xsi:schemaLocation=\"gme://caCORE.caCORE/3.2/edu.northwestern.radiology.AIMTemplate AIMTemplate_v1rv23.xsd\" xmlns=\"gme://caCORE.caCORE/3.2/edu.northwestern.radiology.AIMTemplate\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\">\n%s\n</TemplateContainer>");
    }
    
    private String downloadFileName = null;
    private String templateSchemaName = null;
    
    @Get
    public Representation downloadXmlResult(Representation entity) {

        Form queryForm = new Form(entity);

        final String uid = getParamValue(PARAM_NAME_UID, null);

        log.info("downloading item with UID=" + uid);

        this.downloadFileName = uid == null ? "template" : "template_" + uid + ".xml";
        String result = findResultForUid(uid, queryForm);

        if (result != null && result.length() > 0) {
            boolean isSaveAsMode = getParamValue(PARAM_NAME_MODE, MODE_VIEW).equalsIgnoreCase(MODE_SAVE_AS);
            
            // Generate container for single template for browser download
            if (isSaveAsMode && (!result.startsWith("<?xml version") && !result.startsWith("<TemplateContainer"))) {
                result = this.generateTemplateContainer(result);
            }
            final StringRepresentation download = new StringRepresentation(result);
            download.setMediaType(MediaType.TEXT_XML);
            if (isSaveAsMode) {
                final Disposition disposition = new Disposition(Disposition.TYPE_ATTACHMENT);
                disposition.setFilename(this.downloadFileName == null ? "template.xml" : this.downloadFileName);
                download.setDisposition(disposition);
            }
            return download;
        } else {
            // give an error message that UID=... was not found.
            Map<String, Object> pageData = new HashMap<String, Object>();
            String errorMessage = "Could not find result for UID=" + uid;
            pageData.put("errorMessage", errorMessage);
            return FreemarkerUtil.getInstance().toRepresentation("error-page.ftl", pageData, MediaType.TEXT_HTML);
        }
    }

    /**
     * Get submitted parameter value
     * 
     * @param paramName - name of the parameter
     * @param defaultValue - the value to return if the given parameter is not found
     * @return String  - query string value of the given parameter (case-insensitive) or defaultValue
     */
    private String getParamValue(String paramName, String defaultValue){
        final Form queryForm = this.getReference().getQueryAsForm();
        return queryForm.getFirstValue(paramName, true, defaultValue);
    }

    /**
     * Find the Result for the UID and return as XML, or null if not found.
     * @param uid
     * @return String result as XML String or null if not found.
     */
    private String findResultForUid(String uid,Form queryForm){

        if(uid==null){
            return null;
        }

        try{
            String collection = getCollection(queryForm);
            String namespace = getNamespace(queryForm);

            log.debug("debugXQuery collection="+collection+" namespace="+namespace);
            
            // List<String> results = getResults(TEMPLATE_XQUERY,uid,collection,namespace);
            final String templateQuery = String.format(TEMPLATE_XQUERY, collection, uid);
            List<String> results = processQuery(collection, namespace, templateQuery, new QueryResultAdapter<String>() {
                @Override
                public String adaptResult(XmlValue value) {
                    if (value == null)
                        return null;
                    
                    try {
                        // Figure out template schema version
                        final String schemaLocation = DbUtils.getAttributeValue(value.getParentNode(), "schemaLocation");
                        if (schemaLocation != null) {
                            if (schemaLocation.endsWith(Constants.TEMPLATE_SCHEMA_NAME_V1RV23))
                                templateSchemaName = Constants.TEMPLATE_SCHEMA_NAME_V1RV23;
                        }
                        log.debug("Identified schema name is " + templateSchemaName);
                    
                        return value.asString();
                    } catch (XmlException ex) {
                        log.error("(DR-250): Failed to convert query result to string. The value will be ignored.", ex);
                    }
                    return null;
                }
            });
            
            if(results.isEmpty()){
                log.debug("Checking Template Groups for uid: "+uid);
//                results = getResults(GROUP_XQUERY,uid,collection,namespace);
                // VK: find out template file name
                final String templateComponentQuery = String.format(GROUP_XQUERY, collection, uid);
                List<TemplateComponentQueryResult> queryResults = processQuery(collection, namespace, templateComponentQuery, TemplateComponentQueryResult.templateComponentQueryResultAdapter);
                if (!queryResults.isEmpty()) {
                    if (queryResults.get(0).getFileName() != null)
                        this.downloadFileName = queryResults.get(0).getFileName();
                    for(TemplateComponentQueryResult queryResult : queryResults)
                        results.add(queryResult.getTemplateComponent());
                }
               
                
                log.info("Group found: "+results.size()+" results for uid="+uid);
            }

            return toXmlTemplateDownload(results);
//        }catch(UnsupportedEncodingException uee){
//            log.error("DR-88, Encoding failure. ", uee);
//        }
        } catch (Exception ex) {
            log.error("DR-288, Error:", ex);
        }
        return null;
    }

    private String generateTemplateContainer(String innerTemplate) {
        final String currentTemplateSchemaName = templateContainerProtos.containsKey(this.templateSchemaName) ? this.templateSchemaName : Constants.TEMPLATE_SCHEMA_NAME_V1RV23;
        final String containerProto = templateContainerProtos.get(currentTemplateSchemaName);
        final DateFormat df = new SimpleDateFormat("yyyy-MM-dd", Locale.US);
        final String uid = Uid.generate();
        
        return String.format(containerProto, df.format(new Date()), uid, innerTemplate);
    }
}
