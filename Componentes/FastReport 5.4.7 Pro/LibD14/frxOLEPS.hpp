// CodeGear C++Builder
// Copyright (c) 1995, 2009 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Frxoleps.pas' rev: 21.00

#ifndef FrxolepsHPP
#define FrxolepsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Frxoleps
{
//-- type declarations -------------------------------------------------------
typedef StaticArray<unsigned, 4> TOlepsFmtId;

typedef unsigned TOlepsPropId;

typedef System::Word TOlepsPropType;

typedef unsigned TOlepsAccess;

class DELPHICLASS TOlepsProp;
class PASCALIMPLEMENTATION TOlepsProp : public Classes::TMemoryStream
{
	typedef Classes::TMemoryStream inherited;
	
public:
	unsigned PropId;
	System::Word PropType;
	int Offset;
	void __fastcall Flush(Classes::TStream* Stream);
	void __fastcall WriteVal(int Value, int BytesCount);
	void __fastcall WriteUCS(const System::WideString Str);
	void __fastcall WriteAnsi(const System::AnsiString Str);
public:
	/* TMemoryStream.Destroy */ inline __fastcall virtual ~TOlepsProp(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TOlepsProp(void) : Classes::TMemoryStream() { }
	
};


class DELPHICLASS TOlepsPropSet;
class PASCALIMPLEMENTATION TOlepsPropSet : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TOlepsFmtId FmtId;
	Classes::TList* Props;
	int Offset;
	__fastcall TOlepsPropSet(void);
	__fastcall virtual ~TOlepsPropSet(void);
	void __fastcall Flush(Classes::TStream* Stream);
	TOlepsProp* __fastcall Add(unsigned PropId, System::Word PropType);
	TOlepsProp* __fastcall AddUCS(unsigned PropId, const System::WideString Str);
	TOlepsProp* __fastcall AddAnsi(unsigned PropId, const System::AnsiString Str);
	TOlepsProp* __fastcall AddUnicode(unsigned PropId, const System::WideString Str);
	TOlepsProp* __fastcall AddTime(unsigned PropId, const _FILETIME &t);
};


class DELPHICLASS TOlepsStream;
class PASCALIMPLEMENTATION TOlepsStream : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	Classes::TList* PropSets;
	__fastcall TOlepsStream(void);
	__fastcall virtual ~TOlepsStream(void);
	void __fastcall Flush(Classes::TStream* Stream);
	TOlepsPropSet* __fastcall Add(unsigned const *FmtId);
};


//-- var, const, procedure ---------------------------------------------------
static const ShortInt OlepsSiCodepage = 0x1;
static const ShortInt OlepsSiAuthor = 0x4;
static const ShortInt OlepsSiLastAuthor = 0x8;
static const ShortInt OlepsSiAppName = 0x12;
static const ShortInt OlepsSiAccess = 0x13;
static const ShortInt OlepsSiComment = 0x6;
static const ShortInt OlepsSiKeywords = 0x5;
static const ShortInt OlepsSiSubject = 0x3;
static const ShortInt OlepsSiTitle = 0x2;
static const ShortInt OlepsSiRevision = 0x9;
static const ShortInt OlepsSiCreation = 0xc;
static const ShortInt OlepsSiLastSave = 0xd;
static const ShortInt OlepsAfAll = 0x0;
static const ShortInt OlepsAfPassword = 0x1;
static const ShortInt OlepsAfReadOnlyR = 0x2;
static const ShortInt OlepsAfReadOnlyF = 0x4;
static const ShortInt OlepsAfNoAnnot = 0x8;
static const ShortInt OlepsDsiCategory = 0x2;
static const ShortInt OlepsDsiCompany = 0xf;
static const ShortInt OlepsDsiManager = 0xe;
extern PACKAGE TOlepsFmtId OlepsFmtIdSi;
extern PACKAGE TOlepsFmtId OlepsFmtIdDsi;
static const ShortInt OlepsPtWord = 0x2;
static const ShortInt OlepsPtInt = 0x3;
static const ShortInt OlepsPtString = 0x1e;
static const ShortInt OlepsPtUnicode = 0x1f;
static const ShortInt OlepsPtTime = 0x40;

}	/* namespace Frxoleps */
using namespace Frxoleps;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// FrxolepsHPP
