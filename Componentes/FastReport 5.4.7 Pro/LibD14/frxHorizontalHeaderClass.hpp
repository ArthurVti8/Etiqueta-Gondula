// CodeGear C++Builder
// Copyright (c) 1995, 2009 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Frxhorizontalheaderclass.pas' rev: 21.00

#ifndef FrxhorizontalheaderclassHPP
#define FrxhorizontalheaderclassHPP

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

namespace Frxhorizontalheaderclass
{
//-- type declarations -------------------------------------------------------
#pragma pack(push,1)
struct HorizontalHeader
{
	
public:
	unsigned Version;
	short Ascender;
	short Descender;
	short LineGap;
	System::Word advanceWidthMax;
	short minLeftSideBearing;
	short minRightSideBearing;
	short xMaxExtent;
	short caretSlopeRise;
	short caretSlopeRun;
	short reserved1;
	short reserved2;
	short reserved3;
	short reserved4;
	short reserved5;
	short metricDataFormat;
	System::Word numberOfHMetrics;
};
#pragma pack(pop)


class DELPHICLASS HorizontalHeaderClass;
class PASCALIMPLEMENTATION HorizontalHeaderClass : public Frxtruetypetable::TrueTypeTable
{
	typedef Frxtruetypetable::TrueTypeTable inherited;
	
private:
	HorizontalHeader horizontal_header;
	
public:
	__fastcall HorizontalHeaderClass(Frxtruetypetable::TrueTypeTable* src);
	
private:
	HIDESBASE void __fastcall ChangeEndian(void);
	
public:
	virtual void __fastcall Load(void * font);
	virtual unsigned __fastcall Save(void * font, unsigned offset);
	__property short Ascender = {read=horizontal_header.Ascender, nodefault};
	__property short Descender = {read=horizontal_header.Descender, nodefault};
	__property short LineGap = {read=horizontal_header.LineGap, nodefault};
	__property System::Word MaxWidth = {read=horizontal_header.advanceWidthMax, nodefault};
	__property System::Word NumberOfHMetrics = {read=horizontal_header.numberOfHMetrics, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~HorizontalHeaderClass(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Frxhorizontalheaderclass */
using namespace Frxhorizontalheaderclass;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// FrxhorizontalheaderclassHPP
