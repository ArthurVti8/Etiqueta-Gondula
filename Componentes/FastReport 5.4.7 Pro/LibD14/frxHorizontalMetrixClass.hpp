// CodeGear C++Builder
// Copyright (c) 1995, 2009 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Frxhorizontalmetrixclass.pas' rev: 21.00

#ifndef FrxhorizontalmetrixclassHPP
#define FrxhorizontalmetrixclassHPP

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

namespace Frxhorizontalmetrixclass
{
//-- type declarations -------------------------------------------------------
#pragma pack(push,1)
struct longHorMetric
{
	
public:
	System::Word advanceWidth;
	short lsb;
};
#pragma pack(pop)


typedef DynamicArray<longHorMetric> THorMetricArray;

class DELPHICLASS HorizontalMetrixClass;
class PASCALIMPLEMENTATION HorizontalMetrixClass : public Frxtruetypetable::TrueTypeTable
{
	typedef Frxtruetypetable::TrueTypeTable inherited;
	
private:
	THorMetricArray MetrixTable;
	
public:
	System::Word NumberOfMetrics;
	__fastcall HorizontalMetrixClass(Frxtruetypetable::TrueTypeTable* src);
	virtual void __fastcall Load(void * font);
	longHorMetric __fastcall GetItem(int index);
	__property longHorMetric Item[int index] = {read=GetItem};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~HorizontalMetrixClass(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Frxhorizontalmetrixclass */
using namespace Frxhorizontalmetrixclass;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// FrxhorizontalmetrixclassHPP
