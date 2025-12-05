// CodeGear C++Builder
// Copyright (c) 1995, 2009 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Frxcbff.pas' rev: 21.00

#ifndef FrxcbffHPP
#define FrxcbffHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Frxstorage.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Frxcbff
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TCbffStream;
class PASCALIMPLEMENTATION TCbffStream : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	Frxstorage::TBlockStream* Stream;
	Frxstorage::TBlockStream* SAT;
	__fastcall TCbffStream(void)/* overload */;
	__fastcall TCbffStream(unsigned SecShift)/* overload */;
	__fastcall virtual ~TCbffStream(void);
	int __fastcall WriteStream(void * Data, unsigned Size);
};


#pragma option push -b-
enum TCbffDirKind { dkEmpty, dkStorage, dkStream, dkLock, dkProp, dkRoot };
#pragma option pop

#pragma option push -b-
enum TCbffNodeColor { ncRed, ncBlack };
#pragma option pop

class DELPHICLASS TCbffDir;
class PASCALIMPLEMENTATION TCbffDir : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	System::WideString Name;
	Frxstorage::TBlockStream* Stream;
	Frxstorage::TObjList* Childs;
	TCbffDir* Right;
	TCbffDir* Left;
	TCbffDir* Parent;
	bool IsBlack;
	TCbffDirKind Kind;
	int SecID;
	int LeftID;
	int RightID;
	int ChildID;
	int SelfID;
	__fastcall TCbffDir(void);
	__fastcall virtual ~TCbffDir(void);
	void __fastcall Flush(Classes::TStream* Stream);
	TCbffDir* __fastcall Add(const System::WideString Name);
};


class DELPHICLASS TCbffDocument;
class PASCALIMPLEMENTATION TCbffDocument : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TCbffDir* Root;
	int SecShift;
	int ShortSecShift;
	unsigned MinStreamSize;
	__fastcall TCbffDocument(void);
	__fastcall virtual ~TCbffDocument(void);
	void __fastcall Flush(Classes::TStream* Stream);
};


#pragma pack(push,1)
struct TCbffHeader
{
	
public:
	StaticArray<System::Byte, 8> Sign;
	StaticArray<System::Word, 8> Id;
	System::Word Rev;
	System::Word Ver;
	System::Word Order;
	System::Word Sec;
	System::Word SSec;
	StaticArray<System::Word, 5> NA1;
	unsigned nSAT;
	int Dir;
	unsigned NA2;
	unsigned MinSize;
	int SSAT;
	unsigned nSSAT;
	int MSAT;
	unsigned nMSAT;
	StaticArray<int, 109> sMSAT;
};
#pragma pack(pop)


typedef TCbffHeader *PCbffHeader;

#pragma pack(push,1)
struct TCbffDirEntry
{
	
public:
	StaticArray<System::WideChar, 32> Name;
	System::Word NameSize;
	System::Byte Kind;
	System::Byte Color;
	int Left;
	int Right;
	int Child;
	StaticArray<System::Word, 8> Id;
	unsigned Flags;
	StaticArray<unsigned, 2> Creation;
	StaticArray<unsigned, 2> LastMod;
	int Stream;
	unsigned Size;
	unsigned NA1;
};
#pragma pack(pop)


typedef TCbffDirEntry *PCbffDirEntry;

//-- var, const, procedure ---------------------------------------------------
static const ShortInt siFree = -1;
static const ShortInt siEOC = -2;
static const ShortInt siSAT = -3;
static const ShortInt siMSAT = -4;

}	/* namespace Frxcbff */
using namespace Frxcbff;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// FrxcbffHPP
