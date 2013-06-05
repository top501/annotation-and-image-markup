/*
*  2007 � 2013 Copyright Northwestern University
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.
*/

#ifndef _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CTwoDimensionPolyline
#define _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CTwoDimensionPolyline

#include "type_.CTwoDimensionGeometricShapeEntity.h"


namespace AIMXML
{

class CTwoDimensionPolyline : public ::AIMXML::CTwoDimensionGeometricShapeEntity
{
public:
	AIMXML_EXPORT CTwoDimensionPolyline(xercesc::DOMNode* const& init);
	AIMXML_EXPORT CTwoDimensionPolyline(CTwoDimensionPolyline const& init);
	void operator=(CTwoDimensionPolyline const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_altova_CTwoDimensionPolyline); }
	AIMXML_EXPORT void SetXsiType();
};


}	// namespace AIMXML

#endif // _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CTwoDimensionPolyline
