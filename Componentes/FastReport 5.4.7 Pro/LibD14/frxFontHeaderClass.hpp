// CodeGear C++Builder
// Copyright (c) 1995, 2009 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Frxfontheaderclass.pas' rev: 21.00

#ifndef FrxfontheaderclassHPP
#define FrxfontheaderclassHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Ttfhelpers.hpp>	// Pascal unit
#include <Frxtruetypetable.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Frxfontheaderclass
{
//-- type declarations -------------------------------------------------------
#pragma pack(push,1)
struct FontHeader
{
	
public:
	unsigned version;
	unsigned revision;
	unsigned checkSumAdjustment;
	unsigned magicNumber;
	System::Word flags;
	System::Word unitsPerEm;
	unsigned __int64 CreatedDateTime;
	unsigned __int64 ModifiedDateTime;
	short xMin;
	short yMin;
	short xMax;
	short yMax;
	System::Word macStyle;
	System::Word lowestRecPPEM;
	short fontDirectionHint;
	short indexToLocFormat;
	short glyphDataFormat;
};
#pragma pack(pop)


#pragma option push -b-
enum IndexToLoc { IndexToLoc_LongType = 1, IndexToLoc_ShortType = 0 };
#pragma option pop

#pragma option push -b
enum FontType { FontType_TrueTypeCollection = 1717793908, FontType_TrueTypeFontType = 0, FontType_OpenTypeFontType };
#pragma option pop

class DELPHICLASS FontHeaderClass;
class PASCALIMPLEMENTATION FontHeaderClass : public Frxtruetypetable::TrueTypeTable
{
	typedef Frxtruetypetable::TrueTypeTable inherited;
	
public:
	FontHeader font_header;
	
private:
	IndexToLoc __fastcall get_indexToLocFormat(void);
	
public:
	__property IndexToLoc indexToLocFormat = {read=get_indexToLocFormat, nodefault};
	__property System::Word unitsPerEm = {read=font_header.unitsPerEm, nodefault};
	__fastcall FontHeaderClass(Frxtruetypetable::TrueTypeTable* src);
	
private:
	HIDESBASE void __fastcall ChangeEndian(void);
	
public:
	virtual void __fastcall Load(void * font);
	void __fastcall SaveFontHeader(void * header_ptr, unsigned CheckSum);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~FontHeaderClass(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Frxfontheaderclass */
using namespace Frxfontheaderclass;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// FrxfontheaderclassHPP
