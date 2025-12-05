// CodeGear C++Builder
// Copyright (c) 1995, 2009 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Frxmaximumprofileclass.pas' rev: 21.00

#ifndef FrxmaximumprofileclassHPP
#define FrxmaximumprofileclassHPP

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

namespace Frxmaximumprofileclass
{
//-- type declarations -------------------------------------------------------
#pragma pack(push,1)
struct MaximumProfile
{
	
public:
	System::Word maxComponentDepth;
	System::Word maxComponentElements;
	System::Word maxCompositeContours;
	System::Word maxCompositePoints;
	System::Word maxContours;
	System::Word maxFunctionDefs;
	System::Word maxInstructionDefs;
	System::Word maxPoints;
	System::Word maxSizeOfInstructions;
	System::Word maxStackElements;
	System::Word maxStorage;
	System::Word maxTwilightPoints;
	System::Word maxZones;
	System::Word numGlyphs;
	unsigned Version;
};
#pragma pack(pop)


class DELPHICLASS MaximumProfileClass;
class PASCALIMPLEMENTATION MaximumProfileClass : public Frxtruetypetable::TrueTypeTable
{
	typedef Frxtruetypetable::TrueTypeTable inherited;
	
private:
	MaximumProfile max_profile;
	
public:
	__fastcall MaximumProfileClass(Frxtruetypetable::TrueTypeTable* src);
	
private:
	HIDESBASE void __fastcall ChangeEndian(void);
	
public:
	virtual void __fastcall Load(void * font);
	virtual unsigned __fastcall Save(void * font, unsigned offset);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~MaximumProfileClass(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Frxmaximumprofileclass */
using namespace Frxmaximumprofileclass;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// FrxmaximumprofileclassHPP
