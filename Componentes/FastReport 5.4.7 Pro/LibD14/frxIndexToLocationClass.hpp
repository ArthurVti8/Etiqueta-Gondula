// CodeGear C++Builder
// Copyright (c) 1995, 2009 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Frxindextolocationclass.pas' rev: 21.00

#ifndef FrxindextolocationclassHPP
#define FrxindextolocationclassHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Ttfhelpers.hpp>	// Pascal unit
#include <Frxfontheaderclass.hpp>	// Pascal unit
#include <Frxtruetypetable.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Frxindextolocationclass
{
//-- type declarations -------------------------------------------------------
typedef DynamicArray<unsigned> TCardinalArray;

typedef DynamicArray<System::Word> TWordArray;

class DELPHICLASS IndexToLocationClass;
class PASCALIMPLEMENTATION IndexToLocationClass : public Frxtruetypetable::TrueTypeTable
{
	typedef Frxtruetypetable::TrueTypeTable inherited;
	
private:
	TCardinalArray LongIndexToLocation;
	TWordArray ShortIndexToLocation;
	
public:
	__fastcall IndexToLocationClass(Frxtruetypetable::TrueTypeTable* src);
	System::Word __fastcall GetGlyph(System::Word i2l_idx, Frxfontheaderclass::FontHeaderClass* font_header, unsigned &location);
	void __fastcall LoadIndexToLocation(void * font, Frxfontheaderclass::FontHeaderClass* font_header);
	__property TCardinalArray Long = {read=LongIndexToLocation};
	__property TWordArray Short = {read=ShortIndexToLocation};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~IndexToLocationClass(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Frxindextolocationclass */
using namespace Frxindextolocationclass;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// FrxindextolocationclassHPP
