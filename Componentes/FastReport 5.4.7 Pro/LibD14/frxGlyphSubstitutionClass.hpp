// CodeGear C++Builder
// Copyright (c) 1995, 2009 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Frxglyphsubstitutionclass.pas' rev: 21.00

#ifndef FrxglyphsubstitutionclassHPP
#define FrxglyphsubstitutionclassHPP

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

namespace Frxglyphsubstitutionclass
{
//-- type declarations -------------------------------------------------------
#pragma pack(push,1)
struct FeatureRecord
{
	
public:
	System::Word Feature;
	unsigned FeatureTag;
};
#pragma pack(pop)


struct GSUB_Header
{
	
public:
	unsigned Version;
	System::Word ScriptList;
	System::Word FeatureList;
	System::Word LookupList;
};


#pragma pack(push,1)
struct LangSysRecord
{
	
public:
	unsigned LangSysTag;
	System::Word LangSys;
};
#pragma pack(pop)


#pragma pack(push,1)
struct LangSysTable
{
	
public:
	System::Word LookupOrder;
	System::Word ReqFeatureIndex;
	System::Word FeatureCount;
};
#pragma pack(pop)


#pragma pack(push,1)
struct ScriptListRecord
{
	
public:
	unsigned ScriptTag;
	System::Word ScriptOffset;
};
#pragma pack(pop)


#pragma pack(push,1)
struct ScriptListTable
{
	
public:
	System::Word CountScripts;
};
#pragma pack(pop)


#pragma pack(push,1)
struct ScriptTable
{
	
public:
	System::Word DefaultLangSys;
	System::Word LangSysCount;
};
#pragma pack(pop)


class DELPHICLASS GlyphSubstitutionClass;
class PASCALIMPLEMENTATION GlyphSubstitutionClass : public Frxtruetypetable::TrueTypeTable
{
	typedef Frxtruetypetable::TrueTypeTable inherited;
	
private:
	GSUB_Header header;
	
public:
	__fastcall GlyphSubstitutionClass(Frxtruetypetable::TrueTypeTable* src);
	
private:
	HIDESBASE void __fastcall ChangeEndian(void);
	
public:
	virtual void __fastcall Load(void * font);
	virtual unsigned __fastcall Save(void * font, unsigned offset);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~GlyphSubstitutionClass(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Frxglyphsubstitutionclass */
using namespace Frxglyphsubstitutionclass;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// FrxglyphsubstitutionclassHPP
