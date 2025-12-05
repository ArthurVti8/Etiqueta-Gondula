// CodeGear C++Builder
// Copyright (c) 1995, 2009 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Frxcmaptableclass.pas' rev: 21.00

#ifndef FrxcmaptableclassHPP
#define FrxcmaptableclassHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Ttfhelpers.hpp>	// Pascal unit
#include <Frxtruetypetable.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Frxcmaptableclass
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum EncodingFormats { ByteEncoding, HighByteMapping = 2, SegmentMapping = 4, TrimmedTable = 6 };
#pragma option pop

typedef DynamicArray<short> TSmallintArray;

typedef DynamicArray<System::Word> TWordArray;

#pragma pack(push,1)
struct TSegmentMapping
{
	
public:
	System::Word segCountX2;
	System::Word searchRange;
	System::Word entrySelector;
	System::Word rangeShift;
};
#pragma pack(pop)


#pragma pack(push,1)
struct Table_CMAP
{
	
public:
	System::Word TableVersion;
	System::Word NumSubTables;
};
#pragma pack(pop)


#pragma pack(push,1)
struct Table_Encode
{
	
public:
	System::Word Format;
	System::Word Length;
	System::Word Version;
};
#pragma pack(pop)


#pragma pack(push,1)
struct Table_SUBMAP
{
	
public:
	System::Word Platform;
	System::Word EncodingID;
	unsigned TableOffset;
};
#pragma pack(pop)


class DELPHICLASS CmapTableClass;
class PASCALIMPLEMENTATION CmapTableClass : public Frxtruetypetable::TrueTypeTable
{
	typedef Frxtruetypetable::TrueTypeTable inherited;
	
private:
	TWordArray endCount;
	TWordArray GlyphIndexArray;
	TSmallintArray idDelta;
	TWordArray idRangeOffset;
	TWordArray startCount;
	int segment_count;
	
public:
	__fastcall CmapTableClass(Frxtruetypetable::TrueTypeTable* src);
	System::Word __fastcall GetGlyphIndex(System::Word ch);
	
private:
	TWordArray __fastcall LoadCmapSegment(void * segment_ptr, int segment_count);
	
public:
	void __fastcall LoadCmapTable(void * font);
	
private:
	TSmallintArray __fastcall LoadSignedCmapSegment(void * segment_ptr, int segment_count);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~CmapTableClass(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Frxcmaptableclass */
using namespace Frxcmaptableclass;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// FrxcmaptableclassHPP
