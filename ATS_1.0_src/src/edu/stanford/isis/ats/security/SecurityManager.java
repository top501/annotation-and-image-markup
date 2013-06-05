/*
*  2010 � 2012 Copyright Northwestern University and Stanford University 
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.
*/


package edu.stanford.isis.ats.security;

/**
 *
 * @author alansnyder
 */
public interface SecurityManager {

    SecurityStatus doLogin(String user, String pwd);

    SecurityStatus checkLogin(String cookieValue);
    
    void doLogout(String cookieValue);
}
