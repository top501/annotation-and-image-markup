/*
*  2007 � 2013 Copyright Northwestern University
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.

*/

////////////////////////////////////////////////////////////////////////
//
// AIMXML.h
//
// This file was generated by XMLSpy 2012r2sp1 Enterprise Edition.
//
// YOU SHOULD NOT MODIFY THIS FILE, BECAUSE IT WILL BE
// OVERWRITTEN WHEN YOU RE-RUN CODE GENERATION.
//
// Refer to the XMLSpy Documentation for further details.
// http://www.altova.com/xmlspy
//
////////////////////////////////////////////////////////////////////////

#ifndef _INCLUDED_AIMXML_H_
#define _INCLUDED_AIMXML_H_

#include "../Altova/xs-types.h"
#include "../AltovaXML/Node.h"
#include "AIMXML-typeinfo.h"

#define AIMXML_EXPORT	


namespace AIMXML
{

	class TypeBase
	{
	protected:
		xercesc::DOMNode* m_node;
	public:
		TypeBase(xercesc::DOMNode* const& node) : m_node(node) {}
		xercesc::DOMNode* GetNode() const { return m_node; }

		AIMXML_EXPORT xercesc::DOMNode* GetElementNth(const altova::MemberInfo* member, unsigned index);
		AIMXML_EXPORT xercesc::DOMNode* GetElementLast(const altova::MemberInfo* member);
		AIMXML_EXPORT unsigned CountElement(const altova::MemberInfo* member);
		AIMXML_EXPORT void RemoveElement(const altova::MemberInfo* member);
		AIMXML_EXPORT static int GetEnumerationIndex( const string_type sValue, const unsigned enumOffset, const unsigned enumCount);
		AIMXML_EXPORT static string_type GetEnumerationValue( const int index, const unsigned enumOffset, const unsigned enumCount);
	};

	template <typename MemberType, unsigned MemberIndex, unsigned EnumOffset, unsigned EnumCount>
	class MemberAttribute
	{
		TypeBase& m_owner;
	public:
		typedef const MemberType& argument_type;
		typedef MemberType return_type;

		MemberAttribute(TypeBase& owner) : m_owner(owner) {}
		void operator=(argument_type value);
		operator return_type();
		bool exists();
		void remove();
		int GetEnumerationValue();
		void SetEnumerationValue(const int index);
		altova::meta::Attribute info() const { return altova::meta::Attribute(members + MemberIndex); }
	};

	template <typename MemberType>
	class CastAs 
	{
	public:
		static MemberType Do(xercesc::DOMNode* const& node, const altova::MemberInfo* pMember);
	};

	template <>
	inline bool CastAs<bool>::Do(xercesc::DOMNode* const& node, const altova::MemberInfo* pMember)
	{
		return XercesTreeOperations::CastToBool(node, pMember);
	}

	template <>
	inline double CastAs<double>::Do(xercesc::DOMNode* const& node, const altova::MemberInfo* pMember)
	{
		return XercesTreeOperations::CastToDouble(node, pMember);
	}

	template <>
	inline int CastAs<int>::Do(xercesc::DOMNode* const& node, const altova::MemberInfo* pMember)
	{
		return XercesTreeOperations::CastToInt(node, pMember);
	}

	template <>
	inline unsigned CastAs<unsigned>::Do(xercesc::DOMNode* const& node, const altova::MemberInfo* pMember)
	{
		return XercesTreeOperations::CastToUInt(node, pMember);
	}

	template <>
	inline __int64 CastAs<__int64>::Do(xercesc::DOMNode* const& node, const altova::MemberInfo* pMember)
	{
		return XercesTreeOperations::CastToInt64(node, pMember);
	}

	template <>
	inline unsigned __int64 CastAs<unsigned __int64>::Do(xercesc::DOMNode* const& node, const altova::MemberInfo* pMember)
	{
		return XercesTreeOperations::CastToUInt64(node, pMember);
	}

	template <>
	inline string_type CastAs<string_type>::Do(xercesc::DOMNode* const& node, const altova::MemberInfo* pMember)
	{
		return XercesTreeOperations::CastToString(node, pMember);
	}

	template <>
	inline std::vector<unsigned char> CastAs<std::vector<unsigned char> >::Do(xercesc::DOMNode* const& node, const altova::MemberInfo* pMember)
	{
		return XercesTreeOperations::CastToBinary(node, pMember);
	}

	template <>
	inline altova::DateTime CastAs<altova::DateTime>::Do(xercesc::DOMNode* const& node, const altova::MemberInfo* pMember)
	{
		return XercesTreeOperations::CastToDateTime(node, pMember);
	}

	template <>
	inline altova::Duration CastAs<altova::Duration>::Do(xercesc::DOMNode* const& node, const altova::MemberInfo* pMember)
	{
		return XercesTreeOperations::CastToDuration(node, pMember);
	}

	template <typename DataType>
	class Iterator : public DataType
	{
		XercesTreeOperations::MemberIterator m_it;
	public:
		Iterator(const XercesTreeOperations::MemberIterator& it) : DataType(0), m_it(it) { if (m_it) this->m_node = *m_it; }
		bool operator++() { if (++m_it) { this->m_node = *m_it; return true; } return false; }
		operator bool() const { return m_it; }		

		DataType& operator*() { return *this; }
		DataType* operator->() { return this; }
	};

	template <typename MemberType, unsigned MemberIndex>
	class MemberElement
	{
		TypeBase& m_owner;
	public:
		MemberElement(TypeBase& owner) : m_owner(owner) {}
		MemberType operator[](unsigned index);
		MemberType first();
		MemberType last();
		MemberType append();
		// VK: added
		xercesc::DOMNode* appendSpecial(unsigned DesiredMemberIndex);
		bool exists();
		unsigned count();
		void remove();
		void remove(unsigned index);
		altova::meta::Element info() const { return altova::meta::Element(members + MemberIndex); }

		Iterator<MemberType> all() { return XercesTreeOperations::GetElements(m_owner.GetNode(), members + MemberIndex); }
	};

	template <typename MemberType, unsigned MemberIndex, unsigned EnumOffset, unsigned EnumCount>
	void MemberAttribute<MemberType, MemberIndex, EnumOffset, EnumCount>::operator=(argument_type value)
	{
		XercesTreeOperations::SetValue(m_owner.GetNode(), members + MemberIndex, value);
	}

	template <typename MemberType, unsigned MemberIndex, unsigned EnumOffset, unsigned EnumCount>
	MemberAttribute<MemberType, MemberIndex, EnumOffset, EnumCount>::operator typename MemberAttribute<MemberType, MemberIndex, EnumOffset, EnumCount>::return_type()
	{
		xercesc::DOMNode* att = XercesTreeOperations::FindAttribute(m_owner.GetNode(), members + MemberIndex);
		if (!XercesTreeOperations::IsValid(att))
			throw altova::InvalidOperationException(_T("Cannot read value of non-existent attribute."));
		return CastAs<MemberType>::Do(att, members + MemberIndex);
	}

	template <typename MemberType, unsigned MemberIndex, unsigned EnumOffset, unsigned EnumCount>
	bool MemberAttribute<MemberType, MemberIndex, EnumOffset, EnumCount>::exists()
	{
		xercesc::DOMNode* att = XercesTreeOperations::FindAttribute(m_owner.GetNode(), members + MemberIndex);
		return XercesTreeOperations::IsValid(att);
	}

	template <typename MemberType, unsigned MemberIndex, unsigned EnumOffset, unsigned EnumCount>
	void MemberAttribute<MemberType, MemberIndex, EnumOffset, EnumCount>::remove()
	{
		XercesTreeOperations::RemoveAttribute(m_owner.GetNode(), members + MemberIndex);
	}
	
	template <typename MemberType, unsigned MemberIndex, unsigned EnumOffset, unsigned EnumCount>
	int MemberAttribute<MemberType, MemberIndex, EnumOffset, EnumCount>::GetEnumerationValue() {
		xercesc::DOMNode* att = XercesTreeOperations::FindAttribute(m_owner.GetNode(), members + MemberIndex);
		if (!XercesTreeOperations::IsValid(att))
			throw altova::InvalidOperationException(_T("Cannot read value of non-existent attribute."));
		string_type sValue = CastAs<string_type>::Do(att, members + MemberIndex);
		return TypeBase::GetEnumerationIndex( sValue, types[members[MemberIndex].DataType].Facets + EnumOffset, EnumCount);
	}

	template <typename MemberType, unsigned MemberIndex, unsigned EnumOffset, unsigned EnumCount>
	void MemberAttribute<MemberType, MemberIndex, EnumOffset, EnumCount>::SetEnumerationValue(const int index) 
	{
		XercesTreeOperations::SetValue(m_owner.GetNode(), members + MemberIndex, TypeBase::GetEnumerationValue(index, types[members[MemberIndex].DataType].Facets + EnumOffset, EnumCount) );
	}

	template <typename MemberType, unsigned MemberIndex>
	MemberType MemberElement<MemberType, MemberIndex>::operator[](unsigned index)
	{
		return m_owner.GetElementNth(members + MemberIndex, index);
	}

	template <typename MemberType, unsigned MemberIndex>
	MemberType MemberElement<MemberType, MemberIndex>::first()
	{
		return m_owner.GetElementNth(members + MemberIndex, 0);
	}

	template <typename MemberType, unsigned MemberIndex>
	MemberType MemberElement<MemberType, MemberIndex>::last()
	{
		return m_owner.GetElementLast(members + MemberIndex);
	}

	template <typename MemberType, unsigned MemberIndex>
	MemberType MemberElement<MemberType, MemberIndex>::append()
	{
		return XercesTreeOperations::AddElement(m_owner.GetNode(), members + MemberIndex);
	}

	// VK: added
	template <typename MemberType, unsigned MemberIndex>
	xercesc::DOMNode* MemberElement<MemberType, MemberIndex>::appendSpecial(unsigned DesiredMemberIndex)
	{
//		return XercesTreeOperations::AddElementSpecial(m_owner.GetNode(), members + MemberIndex, members + DesiredMemberIndex);
		return XercesTreeOperations::AddElementSpecial(m_owner.GetNode(), members + MemberIndex, types + DesiredMemberIndex);
	}

	template <typename MemberType, unsigned MemberIndex>
	bool MemberElement<MemberType, MemberIndex>::exists()
	{
		return m_owner.GetElementNth(members + MemberIndex, 0) != 0;
	}

	template <typename MemberType, unsigned MemberIndex>
	unsigned MemberElement<MemberType, MemberIndex>::count()
	{
		return m_owner.CountElement(members + MemberIndex);
	}

	template <typename MemberType, unsigned MemberIndex>
	void MemberElement<MemberType, MemberIndex>::remove()
	{
		m_owner.RemoveElement(members + MemberIndex);
	}

	template <typename MemberType, unsigned MemberIndex>
	void MemberElement<MemberType, MemberIndex>::remove(unsigned index)
	{
		XercesTreeOperations::RemoveElement(m_owner.GetNode(), members + MemberIndex, index);
	}

}

namespace AIMXML
{
// Namespace: gme://caCORE.caCORE/3.2/edu.northwestern.radiology.AIM 
// SchemaPrefix: 
class CAimStatus;
class CAnatomicEntity;
class CAnatomicEntityCharacteristic;
class CAnnotation;
class CAnnotationOfAnnotation;
class CAnnotationRole;
class CCalculation;
class CCalculationData;
class CCalculationResult;
class CCalculationResultIdentifier;
class CCharacteristicQuantification;
class CCircle;
class CComparisonOperators;
class CCoordinate;
class CDICOMImageReference;
class CDimension;
class CEllipse;
class CEquipment;
class CGeometricShape;
class CImage;
class CImageAnnotation;
class CImageReference;
class CImageSeries;
class CImageStudy;
class CImagingObservation;
class CImagingObservationCharacteristic;
class CInference;
class CInterval;
class CMultiPoint;
class CNonQuantifiable;
class CNumerical;
class CPerson;
class CPoint;
class CPolyline;
class CPresentationState;
class CQuantile;
class CReferencedAnnotation;
class CReferencedCalculation;
class CReferencedGeometricShape;
class CScale;
class CSegmentation;
class CSpatialCoordinate;
class CTextAnnotation;
class CThreeDimensionSpatialCoordinate;
class CTwoDimensionSpatialCoordinate;
class CUser;
class CWebImageReference;
class CAIMXML;
class CanatomicEntityCharacteristicCollectionType;
class CcharacteristicQuantificationCollectionType;
class CcalculationCollectionType;
class CinferenceCollectionType;
class CuserType;
class CequipmentType;
class CanatomicEntityCollectionType;
class CimagingObservationCollectionType;
class CaimStatusType;
class CreferencedAnnotationCollectionType;
class CreferencedCalculationCollectionType;
class CcalculationResultCollectionType;
class CreferencedGeometricShapeCollectionType;
class CcoordinateCollectionType;
class CcalculationDataCollectionType;
class CdimensionCollectionType;
class CspatialCoordinateCollectionType;
class CimageStudyType;
class CpresentationStateCollectionType;
class CsegmentationCollectionType;
class CimageReferenceCollectionType;
class CgeometricShapeCollectionType;
class CpersonType;
class CtextAnnotationCollectionType;
class CimageCollectionType;
class CimageSeriesType;
class CimagingObservationCharacteristicCollectionType;
class CreferencedGeometricShapeType;
class CcharacteristicQuantificationCollectionType2;
class CannotationRoleType;
class CimagingObservationType;
class CmultiPointType;
// Namespace: http://www.w3.org/2001/XMLSchema 
// SchemaPrefix: xs

namespace xs
{	
class CENTITIES;
class CENTITY;
class CID;
class CIDREF;
class CIDREFS;
class CNCName;
class CNMTOKEN;
class CNMTOKENS;
class CNOTATION;
class CName;
class CQName;
class CanySimpleType;
class CanyType;
class CanyURI;
class Cbase64Binary;
class Cboolean;
class Cbyte;
class Cdate;
class CdateTime;
class Cdecimal;
class Cdouble;
class Cduration;
class Cfloat;
class CgDay;
class CgMonth;
class CgMonthDay;
class CgYear;
class CgYearMonth;
class ChexBinary;
class Cint;
class Cinteger;
class Clanguage;
class Clong;
class CnegativeInteger;
class CnonNegativeInteger;
class CnonPositiveInteger;
class CnormalizedString;
class CpositiveInteger;
class Cshort;
class Cstring;
class Ctime;
class Ctoken;
class CunsignedByte;
class CunsignedInt;
class CunsignedLong;
class CunsignedShort;

} // namespace xs


}

// include individual types

// namespace "gme://caCORE.caCORE/3.2/edu.northwestern.radiology.AIM"
#include "type_.CAimStatus.h"
#include "type_.CAnatomicEntity.h"
#include "type_.CAnatomicEntityCharacteristic.h"
#include "type_.CAnnotation.h"
#include "type_.CAnnotationOfAnnotation.h"
#include "type_.CAnnotationRole.h"
#include "type_.CCalculation.h"
#include "type_.CCalculationData.h"
#include "type_.CCalculationResult.h"
#include "type_.CCalculationResultIdentifier.h"
#include "type_.CCharacteristicQuantification.h"
#include "type_.CCircle.h"
#include "type_.CComparisonOperators.h"
#include "type_.CCoordinate.h"
#include "type_.CDICOMImageReference.h"
#include "type_.CDimension.h"
#include "type_.CEllipse.h"
#include "type_.CEquipment.h"
#include "type_.CGeometricShape.h"
#include "type_.CImage.h"
#include "type_.CImageAnnotation.h"
#include "type_.CImageReference.h"
#include "type_.CImageSeries.h"
#include "type_.CImageStudy.h"
#include "type_.CImagingObservation.h"
#include "type_.CImagingObservationCharacteristic.h"
#include "type_.CInference.h"
#include "type_.CInterval.h"
#include "type_.CMultiPoint.h"
#include "type_.CNonQuantifiable.h"
#include "type_.CNumerical.h"
#include "type_.CPerson.h"
#include "type_.CPoint.h"
#include "type_.CPolyline.h"
#include "type_.CPresentationState.h"
#include "type_.CQuantile.h"
#include "type_.CReferencedAnnotation.h"
#include "type_.CReferencedCalculation.h"
#include "type_.CReferencedGeometricShape.h"
#include "type_.CScale.h"
#include "type_.CSegmentation.h"
#include "type_.CSpatialCoordinate.h"
#include "type_.CTextAnnotation.h"
#include "type_.CThreeDimensionSpatialCoordinate.h"
#include "type_.CTwoDimensionSpatialCoordinate.h"
#include "type_.CUser.h"
#include "type_.CWebImageReference.h"
#include "type_.CAIMXML.h"
#include "type_.CanatomicEntityCharacteristicCollectionType.h"
#include "type_.CcharacteristicQuantificationCollectionType.h"
#include "type_.CcalculationCollectionType.h"
#include "type_.CinferenceCollectionType.h"
#include "type_.CuserType.h"
#include "type_.CequipmentType.h"
#include "type_.CanatomicEntityCollectionType.h"
#include "type_.CimagingObservationCollectionType.h"
#include "type_.CaimStatusType.h"
#include "type_.CreferencedAnnotationCollectionType.h"
#include "type_.CreferencedCalculationCollectionType.h"
#include "type_.CcalculationResultCollectionType.h"
#include "type_.CreferencedGeometricShapeCollectionType.h"
#include "type_.CcoordinateCollectionType.h"
#include "type_.CcalculationDataCollectionType.h"
#include "type_.CdimensionCollectionType.h"
#include "type_.CspatialCoordinateCollectionType.h"
#include "type_.CimageStudyType.h"
#include "type_.CpresentationStateCollectionType.h"
#include "type_.CsegmentationCollectionType.h"
#include "type_.CimageReferenceCollectionType.h"
#include "type_.CgeometricShapeCollectionType.h"
#include "type_.CpersonType.h"
#include "type_.CtextAnnotationCollectionType.h"
#include "type_.CimageCollectionType.h"
#include "type_.CimageSeriesType.h"
#include "type_.CimagingObservationCharacteristicCollectionType.h"
#include "type_.CreferencedGeometricShapeType.h"
#include "type_.CcharacteristicQuantificationCollectionType2.h"
#include "type_.CannotationRoleType.h"
#include "type_.CimagingObservationType.h"
#include "type_.CmultiPointType.h"

// namespace "http://www.w3.org/2001/XMLSchema"
#include "type_xs.CENTITIES.h"
#include "type_xs.CENTITY.h"
#include "type_xs.CID.h"
#include "type_xs.CIDREF.h"
#include "type_xs.CIDREFS.h"
#include "type_xs.CNCName.h"
#include "type_xs.CNMTOKEN.h"
#include "type_xs.CNMTOKENS.h"
#include "type_xs.CNOTATION.h"
#include "type_xs.CName.h"
#include "type_xs.CQName.h"
#include "type_xs.CanySimpleType.h"
#include "type_xs.CanyType.h"
#include "type_xs.CanyURI.h"
#include "type_xs.Cbase64Binary.h"
#include "type_xs.Cboolean.h"
#include "type_xs.Cbyte.h"
#include "type_xs.Cdate.h"
#include "type_xs.CdateTime.h"
#include "type_xs.Cdecimal.h"
#include "type_xs.Cdouble.h"
#include "type_xs.Cduration.h"
#include "type_xs.Cfloat.h"
#include "type_xs.CgDay.h"
#include "type_xs.CgMonth.h"
#include "type_xs.CgMonthDay.h"
#include "type_xs.CgYear.h"
#include "type_xs.CgYearMonth.h"
#include "type_xs.ChexBinary.h"
#include "type_xs.Cint.h"
#include "type_xs.Cinteger.h"
#include "type_xs.Clanguage.h"
#include "type_xs.Clong.h"
#include "type_xs.CnegativeInteger.h"
#include "type_xs.CnonNegativeInteger.h"
#include "type_xs.CnonPositiveInteger.h"
#include "type_xs.CnormalizedString.h"
#include "type_xs.CpositiveInteger.h"
#include "type_xs.Cshort.h"
#include "type_xs.Cstring.h"
#include "type_xs.Ctime.h"
#include "type_xs.Ctoken.h"
#include "type_xs.CunsignedByte.h"
#include "type_xs.CunsignedInt.h"
#include "type_xs.CunsignedLong.h"
#include "type_xs.CunsignedShort.h"

// finished

#endif //_INCLUDED_AIMXML_H_
