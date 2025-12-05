// CodeGear C++Builder
// Copyright (c) 1995, 2009 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Frxtruetypecollection.pas' rev: 21.00

#ifndef FrxtruetypecollectionHPP
#define FrxtruetypecollectionHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Ttfhelpers.hpp>	// Pascal unit
#include <Frxtruetypefont.hpp>	// Pascal unit
#include <Frxfontheaderclass.hpp>	// Pascal unit
#include <Frxnametableclass.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Frxtruetypecollection
{
//-- type declarations -------------------------------------------------------
typedef Classes::TList TFontCollection;

#pragma pack(push,1)
struct TTCollectionHeader
{
	
public:
	unsigned TTCTag;
	unsigned Version;
	unsigned numFonts;
};
#pragma pack(pop)


class DELPHICLASS TrueTypeCollection;
class PASCALIMPLEMENTATION TrueTypeCollection : public Ttfhelpers::TTF_Helpers
{
	typedef Ttfhelpers::TTF_Helpers inherited;
	
private:
	Classes::TList* fonts_collection;
	Classes::TList* __fastcall get_FontCollection(void);
	Frxtruetypefont::TrueTypeFont* __fastcall get_Item(System::UnicodeString FamilyName);
	
public:
	__fastcall TrueTypeCollection(void);
	__fastcall virtual ~TrueTypeCollection(void);
	void __fastcall Initialize(char * FD, int FontDataSize);
	Frxtruetypefont::TrueTypeFont* __fastcall LoadFont(Graphics::TFont* font);
	Frxtruetypefont::TByteArray __fastcall PackFont(Frxtruetypefont::TrueTypeFont* ttf, Classes::TList* UsedAlphabet);
	__property Classes::TList* FontCollection = {read=get_FontCollection};
	__property Frxtruetypefont::TrueTypeFont* Item[System::UnicodeString FamilyName] = {read=get_Item};
};


typedef StaticArray<System::WideString, 12> Frxtruetypecollection__2;

//-- var, const, procedure ---------------------------------------------------
static const ShortInt Elements = 0xc;
extern PACKAGE Frxtruetypecollection__2 Substitutes;

}	/* namespace Frxtruetypecollection */
using namespace Frxtruetypecollection;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// FrxtruetypecollectionHPP
