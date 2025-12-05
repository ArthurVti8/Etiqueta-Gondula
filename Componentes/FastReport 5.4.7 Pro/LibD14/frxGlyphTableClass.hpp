// CodeGear C++Builder
// Copyright (c) 1995, 2009 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Frxglyphtableclass.pas' rev: 21.00

#ifndef FrxglyphtableclassHPP
#define FrxglyphtableclassHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Ttfhelpers.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Frxtruetypetable.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Frxglyphtableclass
{
//-- type declarations -------------------------------------------------------
typedef Classes::TList TIntegerList;

#pragma option push -b
enum CompositeFlags { ARG_1_AND_2_ARE_WORDS = 1, ARGS_ARE_XY_VALUES, MORE_COMPONENTS = 32, OVERLAP_COMPOUND = 1024, RESERVED = 16, ROUND_XY_TO_GRID = 4, SCALED_COMPONENT_OFFSET = 2048, UNSCALED_COMPONENT_OFFSET = 65536, USE_MY_METRICS = 512, WE_HAVE_A_SCALE = 8, WE_HAVE_A_TWO_BY_TWO = 128, WE_HAVE_AN_X_AND_Y_SCALE = 64, WE_HAVE_INSTRUCTIONS = 256 };
#pragma option pop

#pragma option push -b-
enum GlyphFlags { ON_CURVE = 1, REP = 8, X_POSITIVE = 16, X_SAME = 16, X_SHORT = 2, Y_POSITIVE = 32, Y_SAME = 32, Y_SHORT = 4 };
#pragma option pop

#pragma pack(push,1)
struct CompositeGlyphHeader
{
	
public:
	System::Word flags;
	System::Word glyphIndex;
};
#pragma pack(pop)


#pragma pack(push,1)
struct GlyphHeader
{
	
public:
	short numberOfContours;
	short xMin;
	short yMin;
	short xMax;
	short yMax;
};
#pragma pack(pop)


class DELPHICLASS GlyphTableClass;
class PASCALIMPLEMENTATION GlyphTableClass : public Frxtruetypetable::TrueTypeTable
{
	typedef Frxtruetypetable::TrueTypeTable inherited;
	
private:
	void *glyph_table_ptr;
	
public:
	__fastcall GlyphTableClass(Frxtruetypetable::TrueTypeTable* src);
	__fastcall virtual ~GlyphTableClass(void);
	Classes::TList* __fastcall CheckGlyph(int glyph_offset, int glyph_size);
	
private:
	GlyphHeader __fastcall GetGlyphHeader(int glyph_offset);
	
public:
	virtual void __fastcall Load(void * font);
};


class DELPHICLASS GlyphPoint;
class PASCALIMPLEMENTATION GlyphPoint : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	bool end_of_contour;
	bool on_curve;
	float x;
	float y;
public:
	/* TObject.Create */ inline __fastcall GlyphPoint(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~GlyphPoint(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Frxglyphtableclass */
using namespace Frxglyphtableclass;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// FrxglyphtableclassHPP
