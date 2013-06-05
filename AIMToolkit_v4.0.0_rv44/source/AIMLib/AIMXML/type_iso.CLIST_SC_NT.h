/*
*  2007 � 2013 Copyright Northwestern University
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.
*/

#ifndef _ALTOVA_INCLUDED_AIMXML_ALTOVA_iso_ALTOVA_CLIST_SC_NT
#define _ALTOVA_INCLUDED_AIMXML_ALTOVA_iso_ALTOVA_CLIST_SC_NT

#include "type_iso.CANY.h"


namespace AIMXML
{

namespace iso
{	

class CLIST_SC_NT : public ::AIMXML::iso::CANY
{
public:
	AIMXML_EXPORT CLIST_SC_NT(xercesc::DOMNode* const& init);
	AIMXML_EXPORT CLIST_SC_NT(CLIST_SC_NT const& init);
	void operator=(CLIST_SC_NT const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_iso_altova_CLIST_SC_NT); }
	MemberElement<iso::CSC_NT, _altova_mi_iso_altova_CLIST_SC_NT_altova_item> item;
	struct item { typedef Iterator<iso::CSC_NT> iterator; };
	AIMXML_EXPORT void SetXsiType();
};



} // namespace iso

}	// namespace AIMXML

#endif // _ALTOVA_INCLUDED_AIMXML_ALTOVA_iso_ALTOVA_CLIST_SC_NT
