// CodeGear C++Builder
// Copyright (c) 1995, 2009 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Frxcollections.pas' rev: 21.00

#ifndef FrxcollectionsHPP
#define FrxcollectionsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Frxcollections
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TfrxCollectionItem;
class PASCALIMPLEMENTATION TfrxCollectionItem : public Classes::TCollectionItem
{
	typedef Classes::TCollectionItem inherited;
	
protected:
	System::UnicodeString FInheritedName;
	bool FIsInherited;
	virtual System::UnicodeString __fastcall GetInheritedName(void);
	virtual void __fastcall SetInheritedName(const System::UnicodeString Value);
	virtual bool __fastcall IsNameStored(void);
	
public:
	void __fastcall CreateUniqueName(void);
	__property bool IsInherited = {read=FIsInherited, write=FIsInherited, nodefault};
	
__published:
	__property System::UnicodeString InheritedName = {read=GetInheritedName, write=SetInheritedName, stored=IsNameStored};
public:
	/* TCollectionItem.Create */ inline __fastcall virtual TfrxCollectionItem(Classes::TCollection* Collection) : Classes::TCollectionItem(Collection) { }
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TfrxCollectionItem(void) { }
	
};


class DELPHICLASS TfrxCollection;
class PASCALIMPLEMENTATION TfrxCollection : public Classes::TCollection
{
	typedef Classes::TCollection inherited;
	
protected:
	virtual void __fastcall Added(Classes::TCollectionItem* &Item);
	
public:
	virtual void __fastcall SerializeProperties(System::TObject* Writer, TfrxCollection* Ancestor, Classes::TComponent* Owner);
	virtual void __fastcall DeserializeProperties(System::UnicodeString PropName, System::TObject* Reader, TfrxCollection* Ancestor);
	virtual TfrxCollectionItem* __fastcall FindByName(System::UnicodeString Name);
public:
	/* TCollection.Create */ inline __fastcall TfrxCollection(Classes::TCollectionItemClass ItemClass) : Classes::TCollection(ItemClass) { }
	/* TCollection.Destroy */ inline __fastcall virtual ~TfrxCollection(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Frxcollections */
using namespace Frxcollections;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// FrxcollectionsHPP
