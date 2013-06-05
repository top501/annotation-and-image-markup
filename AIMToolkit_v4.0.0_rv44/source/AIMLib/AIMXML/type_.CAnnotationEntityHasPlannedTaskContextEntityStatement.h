/*
*  2007 � 2013 Copyright Northwestern University
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.
*/

#ifndef _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CAnnotationEntityHasPlannedTaskContextEntityStatement
#define _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CAnnotationEntityHasPlannedTaskContextEntityStatement

#include "type_.CAnnotationStatement.h"


namespace AIMXML
{

class CAnnotationEntityHasPlannedTaskContextEntityStatement : public ::AIMXML::CAnnotationStatement
{
public:
	AIMXML_EXPORT CAnnotationEntityHasPlannedTaskContextEntityStatement(xercesc::DOMNode* const& init);
	AIMXML_EXPORT CAnnotationEntityHasPlannedTaskContextEntityStatement(CAnnotationEntityHasPlannedTaskContextEntityStatement const& init);
	void operator=(CAnnotationEntityHasPlannedTaskContextEntityStatement const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_altova_CAnnotationEntityHasPlannedTaskContextEntityStatement); }
	AIMXML_EXPORT void SetXsiType();
};


}	// namespace AIMXML

#endif // _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CAnnotationEntityHasPlannedTaskContextEntityStatement
