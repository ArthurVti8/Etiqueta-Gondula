// CodeGear C++Builder
// Copyright (c) 1995, 2009 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Ttfhelpers.pas' rev: 21.00

#ifndef TtfhelpersHPP
#define TtfhelpersHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Ttfhelpers
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TTF_Helpers;
class PASCALIMPLEMENTATION TTF_Helpers : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	__fastcall TTF_Helpers(void);
	
public:
	__classmethod void * __fastcall Increment(void * ptr, int cbSize);
	__classmethod short __fastcall SwapInt16(short v);
	__classmethod int __fastcall SwapInt32(int v);
	__classmethod System::Word __fastcall SwapUInt16(System::Word v);
	__classmethod unsigned __fastcall SwapUInt32(unsigned v);
	__classmethod unsigned __int64 __fastcall SwapUInt64(unsigned __int64 v);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TTF_Helpers(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Ttfhelpers */
using namespace Ttfhelpers;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TtfhelpersHPP
