// CodeGear C++Builder
// Copyright (c) 1995, 2009 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Frxpostscriptclass.pas' rev: 21.00

#ifndef FrxpostscriptclassHPP
#define FrxpostscriptclassHPP

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

namespace Frxpostscriptclass
{
//-- type declarations -------------------------------------------------------
#pragma pack(push,1)
struct PostScript
{
	
public:
	unsigned isFixedPitch;
	int ItalicAngle;
	unsigned maxMemType1;
	unsigned maxMemType42;
	unsigned minMemType1;
	unsigned minMemType42;
	short underlinePosition;
	short underlineThickness;
	unsigned Version;
};
#pragma pack(pop)


class DELPHICLASS PostScriptClass;
class PASCALIMPLEMENTATION PostScriptClass : public Frxtruetypetable::TrueTypeTable
{
	typedef Frxtruetypetable::TrueTypeTable inherited;
	
private:
	PostScript post_script;
	
public:
	__fastcall PostScriptClass(Frxtruetypetable::TrueTypeTable* src);
	
private:
	HIDESBASE void __fastcall ChangeEndian(void);
	
public:
	virtual void __fastcall Load(void * font);
	virtual unsigned __fastcall Save(void * font, unsigned offset);
	__property int ItalicAngle = {read=post_script.ItalicAngle, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~PostScriptClass(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Frxpostscriptclass */
using namespace Frxpostscriptclass;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// FrxpostscriptclassHPP
