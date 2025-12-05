// CodeGear C++Builder
// Copyright (c) 1995, 2009 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Frxnametableclass.pas' rev: 21.00

#ifndef FrxnametableclassHPP
#define FrxnametableclassHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Ttfhelpers.hpp>	// Pascal unit
#include <Frxfontheaderclass.hpp>	// Pascal unit
#include <Frxtruetypetable.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Frxnametableclass
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum NameID { NameID_CompatibleFull = 18, NameID_CopyrightNotice = 0, NameID_Description = 10, NameID_Designer = 9, NameID_FamilyName = 1, NameID_FullName = 4, NameID_LicenseDescription = 13, NameID_LicenseInfoURL, NameID_Manufacturer = 8, NameID_PostscriptCID = 20, NameID_PostscriptName = 6, NameID_PreferredFamily = 16, NameID_PreferredSubFamily, NameID_SampleText = 19, NameID_SubFamilyName = 2, NameID_Trademark = 7, NameID_UniqueID = 3, NameID_URL_Designer = 12, NameID_URL_Vendor = 11, NameID_Version = 5, NameID_WWS_Family_Name = 21, NameID_WWS_SubFamily_Name };
#pragma option pop

#pragma pack(push,1)
struct NamingTableHeader
{
	
public:
	System::Word TableVersion;
	System::Word Count;
	System::Word stringOffset;
};
#pragma pack(pop)


#pragma pack(push,1)
struct NamingRecord
{
	
public:
	System::Word PlatformID;
	System::Word EncodingID;
	System::Word LanguageID;
	System::Word NameID;
	System::Word Length;
	System::Word Offset;
};
#pragma pack(pop)


class DELPHICLASS NameTableClass;
class PASCALIMPLEMENTATION NameTableClass : public Frxtruetypetable::TrueTypeTable
{
	typedef Frxtruetypetable::TrueTypeTable inherited;
	
private:
	NamingTableHeader name_header;
	void *namerecord_ptr;
	void *string_storage_ptr;
	
public:
	__fastcall NameTableClass(Frxtruetypetable::TrueTypeTable* src);
	__fastcall virtual ~NameTableClass(void);
	
private:
	HIDESBASE void __fastcall ChangeEndian(void);
	
public:
	virtual void __fastcall Load(void * font);
	
private:
	System::AnsiString __fastcall get_Item(NameID Index);
	
public:
	__property System::AnsiString Item[NameID Index] = {read=get_Item};
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Frxnametableclass */
using namespace Frxnametableclass;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// FrxnametableclassHPP
