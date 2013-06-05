/*
*  2007 � 2013 Copyright Northwestern University
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.
*/

#ifndef _ALTOVA_INCLUDED_AIMXML_ALTOVA_iso_ALTOVA_CDSET_AD
#define _ALTOVA_INCLUDED_AIMXML_ALTOVA_iso_ALTOVA_CDSET_AD

#include "type_iso.CCOLL_AD.h"


namespace AIMXML
{

namespace iso
{	

class CDSET_AD : public ::AIMXML::iso::CCOLL_AD
{
public:
	AIMXML_EXPORT CDSET_AD(xercesc::DOMNode* const& init);
	AIMXML_EXPORT CDSET_AD(CDSET_AD const& init);
	void operator=(CDSET_AD const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_iso_altova_CDSET_AD); }
	MemberElement<iso::CAD, _altova_mi_iso_altova_CDSET_AD_altova_item> item;
	struct item { typedef Iterator<iso::CAD> iterator; };
	AIMXML_EXPORT void SetXsiType();
};



} // namespace iso

}	// namespace AIMXML

#endif // _ALTOVA_INCLUDED_AIMXML_ALTOVA_iso_ALTOVA_CDSET_AD
