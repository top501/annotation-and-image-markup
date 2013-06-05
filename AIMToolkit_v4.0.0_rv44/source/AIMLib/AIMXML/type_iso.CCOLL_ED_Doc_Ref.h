/*
*  2007 � 2013 Copyright Northwestern University
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.
*/

#ifndef _ALTOVA_INCLUDED_AIMXML_ALTOVA_iso_ALTOVA_CCOLL_ED_Doc_Ref
#define _ALTOVA_INCLUDED_AIMXML_ALTOVA_iso_ALTOVA_CCOLL_ED_Doc_Ref

#include "type_iso.CANY.h"


namespace AIMXML
{

namespace iso
{	

class CCOLL_ED_Doc_Ref : public ::AIMXML::iso::CANY
{
public:
	AIMXML_EXPORT CCOLL_ED_Doc_Ref(xercesc::DOMNode* const& init);
	AIMXML_EXPORT CCOLL_ED_Doc_Ref(CCOLL_ED_Doc_Ref const& init);
	void operator=(CCOLL_ED_Doc_Ref const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_iso_altova_CCOLL_ED_Doc_Ref); }
	AIMXML_EXPORT void SetXsiType();
};



} // namespace iso

}	// namespace AIMXML

#endif // _ALTOVA_INCLUDED_AIMXML_ALTOVA_iso_ALTOVA_CCOLL_ED_Doc_Ref
