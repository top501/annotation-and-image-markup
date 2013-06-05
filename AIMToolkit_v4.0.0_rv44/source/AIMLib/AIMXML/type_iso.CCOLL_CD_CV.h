/*
*  2007 � 2013 Copyright Northwestern University
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.
*/

#ifndef _ALTOVA_INCLUDED_AIMXML_ALTOVA_iso_ALTOVA_CCOLL_CD_CV
#define _ALTOVA_INCLUDED_AIMXML_ALTOVA_iso_ALTOVA_CCOLL_CD_CV

#include "type_iso.CANY.h"


namespace AIMXML
{

namespace iso
{	

class CCOLL_CD_CV : public ::AIMXML::iso::CANY
{
public:
	AIMXML_EXPORT CCOLL_CD_CV(xercesc::DOMNode* const& init);
	AIMXML_EXPORT CCOLL_CD_CV(CCOLL_CD_CV const& init);
	void operator=(CCOLL_CD_CV const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_iso_altova_CCOLL_CD_CV); }
	AIMXML_EXPORT void SetXsiType();
};



} // namespace iso

}	// namespace AIMXML

#endif // _ALTOVA_INCLUDED_AIMXML_ALTOVA_iso_ALTOVA_CCOLL_CD_CV
