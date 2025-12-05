// CodeGear C++Builder
// Copyright (c) 1995, 2009 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Frxpreprogramclass.pas' rev: 21.00

#ifndef FrxpreprogramclassHPP
#define FrxpreprogramclassHPP

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

namespace Frxpreprogramclass
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS PreProgramClass;
class PASCALIMPLEMENTATION PreProgramClass : public Frxtruetypetable::TrueTypeTable
{
	typedef Frxtruetypetable::TrueTypeTable inherited;
	
private:
	typedef DynamicArray<System::Byte> _PreProgramClass__1;
	
	
private:
	_PreProgramClass__1 pre_program;
	
public:
	__fastcall PreProgramClass(Frxtruetypetable::TrueTypeTable* src);
	virtual void __fastcall Load(void * font);
	virtual unsigned __fastcall Save(void * font, unsigned offset);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~PreProgramClass(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Frxpreprogramclass */
using namespace Frxpreprogramclass;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// FrxpreprogramclassHPP
