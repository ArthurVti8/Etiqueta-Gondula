// CodeGear C++Builder
// Copyright (c) 1995, 2009 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Frxescher.pas' rev: 21.00

#ifndef FrxescherHPP
#define FrxescherHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Types.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Frxescher
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TEscherStream;
class DELPHICLASS TEscherRec;
class PASCALIMPLEMENTATION TEscherStream : public Classes::TMemoryStream
{
	typedef Classes::TMemoryStream inherited;
	
private:
	Classes::TList* Records;
	
public:
	__fastcall TEscherStream(void);
	__fastcall virtual ~TEscherStream(void);
	virtual void __fastcall Flush(Classes::TStream* Stream);
	void __fastcall WriteVal(unsigned Value, unsigned Count);
	TEscherRec* __fastcall Add(void)/* overload */;
	TEscherRec* __fastcall Add(System::Byte Version, System::Word Instance, System::Word Kind)/* overload */;
	TEscherRec* __fastcall AddCont(System::Word Instance, System::Word Kind)/* overload */;
};


class PASCALIMPLEMENTATION TEscherRec : public TEscherStream
{
	typedef TEscherStream inherited;
	
public:
	System::Byte Version;
	System::Word Instance;
	System::Word Kind;
	virtual void __fastcall Flush(Classes::TStream* Stream);
	unsigned __fastcall GetESize(void);
public:
	/* TEscherStream.Create */ inline __fastcall TEscherRec(void) : TEscherStream() { }
	/* TEscherStream.Destroy */ inline __fastcall virtual ~TEscherRec(void) { }
	
};


typedef System::Byte TEscherBlipKind;

typedef System::Word TEscherBlipSign;

class DELPHICLASS TEscherPicture;
class PASCALIMPLEMENTATION TEscherPicture : public Classes::TMemoryStream
{
	typedef Classes::TMemoryStream inherited;
	
public:
	System::Byte Kind;
	virtual unsigned __fastcall GetESize(void) = 0 ;
	virtual void __fastcall Flush(Classes::TStream* Stream) = 0 ;
public:
	/* TMemoryStream.Destroy */ inline __fastcall virtual ~TEscherPicture(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TEscherPicture(void) : Classes::TMemoryStream() { }
	
};


class DELPHICLASS TEscherBitmap;
class PASCALIMPLEMENTATION TEscherBitmap : public TEscherPicture
{
	typedef TEscherPicture inherited;
	
public:
	virtual unsigned __fastcall GetESize(void);
	virtual void __fastcall Flush(Classes::TStream* Stream);
public:
	/* TMemoryStream.Destroy */ inline __fastcall virtual ~TEscherBitmap(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TEscherBitmap(void) : TEscherPicture() { }
	
};


class DELPHICLASS TEscherMetafile;
class PASCALIMPLEMENTATION TEscherMetafile : public TEscherPicture
{
	typedef TEscherPicture inherited;
	
public:
	Types::TRect Bounds;
	Types::TPoint MFSize;
	bool Compr;
	virtual unsigned __fastcall GetESize(void);
	virtual void __fastcall Flush(Classes::TStream* Stream);
public:
	/* TMemoryStream.Destroy */ inline __fastcall virtual ~TEscherMetafile(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TEscherMetafile(void) : TEscherPicture() { }
	
};


typedef StaticArray<System::Byte, 16> TEscherBlipHash;

class DELPHICLASS TEscherBlip;
class PASCALIMPLEMENTATION TEscherBlip : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TEscherBlipHash Hash;
	unsigned RefCount;
	TEscherPicture* Pict;
	unsigned Index;
	__fastcall TEscherBlip(TEscherPicture* Pict);
	__fastcall virtual ~TEscherBlip(void);
	void __fastcall Flush(TEscherStream* Stream);
};


class DELPHICLASS TEscherProp;
class PASCALIMPLEMENTATION TEscherProp : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	System::Word Id;
	bool Blip;
	bool Complex;
	int Value;
	__fastcall TEscherProp(System::Word Id);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TEscherProp(void) { }
	
};


class DELPHICLASS TEscherPropList;
class PASCALIMPLEMENTATION TEscherPropList : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Classes::TList* FS;
	
public:
	__fastcall TEscherPropList(void);
	__fastcall virtual ~TEscherPropList(void);
	TEscherProp* __fastcall Add(System::Word Id);
	void __fastcall Flush(TEscherStream* Stream);
};


class DELPHICLASS TEscherShapePos;
class PASCALIMPLEMENTATION TEscherShapePos : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	int Left;
	int Top;
	int Right;
	int Bottom;
	int LeftOffset;
	int TopOffset;
	int RightOffset;
	int BottomOffset;
	void __fastcall Flush(TEscherStream* Stream);
public:
	/* TObject.Create */ inline __fastcall TEscherShapePos(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TEscherShapePos(void) { }
	
};


class DELPHICLASS TEscherShape;
class PASCALIMPLEMENTATION TEscherShape : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	unsigned Id;
	unsigned Flags;
	unsigned Image;
	TEscherShapePos* Pos;
	__fastcall TEscherShape(void);
	__fastcall virtual ~TEscherShape(void);
	void __fastcall Flush(TEscherStream* Stream);
};


class DELPHICLASS TEscherGroup;
class PASCALIMPLEMENTATION TEscherGroup : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TEscherShape* operator[](int Index) { return Items[Index]; }
	
private:
	unsigned SId;
	Classes::TList* Shapes;
	TEscherShape* __fastcall GetShape(int Index);
	unsigned __fastcall GetSId(void);
	unsigned __fastcall GetRId(void);
	
public:
	unsigned Id;
	__fastcall TEscherGroup(void);
	__fastcall virtual ~TEscherGroup(void);
	void __fastcall Flush(TEscherStream* Stream);
	unsigned __fastcall Count(void);
	TEscherShape* __fastcall Add(void);
	unsigned __fastcall GetMaxSId(void);
	__property TEscherShape* Items[int Index] = {read=GetShape/*, default*/};
};


class DELPHICLASS TEscherStorage;
class PASCALIMPLEMENTATION TEscherStorage : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Classes::TList* Groups;
	Classes::TList* Images;
	TEscherGroup* __fastcall GetGroup(int Index);
	TEscherBlip* __fastcall GetImage(int Index);
	
public:
	TEscherPropList* Props;
	__fastcall TEscherStorage(void);
	__fastcall virtual ~TEscherStorage(void);
	TEscherGroup* __fastcall AddGroup(void);
	TEscherBlip* __fastcall AddImage(TEscherPicture* Pict);
	bool __fastcall Empty(void);
	void __fastcall Flush(TEscherStream* Stream);
	__property TEscherBlip* Image[int Index] = {read=GetImage};
	__property TEscherGroup* Group[int Index] = {read=GetGroup};
};


//-- var, const, procedure ---------------------------------------------------
static const Word EscherRkBse = 0xf007;
static const Word EscherRkBlip = 0xf018;
static const Word EscherRkDggc = 0xf000;
static const Word EscherRkDgg = 0xf006;
static const Word EscherRkBstore = 0xf001;
static const Word EscherRkSpCont = 0xf004;
static const Word EscherRkSp = 0xf00a;
static const Word EscherRkOpts = 0xf00b;
static const Word EscherRkAnchor = 0xf00e;
static const Word EscherRkDgCont = 0xf002;
static const Word EscherRkDg = 0xf008;
static const Word EscherRkSpgrCont = 0xf003;
static const Word EscherRkSpgr = 0xf009;
static const Word EscherRkSMC = 0xf11e;
static const Word EscherRkCData = 0xf011;
static const Word EscherRkCAnchor = 0xf010;
static const ShortInt EscherBkEMF = 0x2;
static const ShortInt EscherBkWMF = 0x3;
static const ShortInt EscherBkJPEG = 0x5;
static const ShortInt EscherBkPNG = 0x6;
static const ShortInt EscherBkDIB = 0x7;
static const ShortInt EscherBkTIFF = 0x8;
static const ShortInt EscherBsUnknown = 0x0;
static const Word EscherBsWMF = 0x216;
static const Word EscherBsEMF = 0x3d4;
static const Word EscherBsPNG = 0x6e0;
static const Word EscherBsJPEG = 0x46a;
static const Word EscherBsDIB = 0x7a8;
static const Word EscherBsTIFF = 0x6e4;
static const ShortInt EscherBuDefault = 0x0;
static const ShortInt EscherBuTexture = 0x1;
static const ShortInt EscherMcDeflate = 0x0;
static const Byte EscherMcNone = 0xfe;
static const ShortInt EscherSfGroup = 0x1;
static const ShortInt EscherSfChild = 0x2;
static const ShortInt EscherSfRoot = 0x4;
static const ShortInt EscherSfDeleted = 0x8;
static const ShortInt EscherSfOle = 0x10;
static const ShortInt EscherSfMaster = 0x20;
static const ShortInt EscherSfFlipHor = 0x40;
static const Byte EscherSfFlipVer = 0x80;
static const Word EscherSfConn = 0x100;
static const Word EscherSfAnchor = 0x200;
static const Word EscherSfBg = 0x400;
static const Word EscherSfShape = 0x800;
static const ShortInt EscherStNone = 0x0;
static const ShortInt EscherStPictureFrame = 0x4b;
static const Word EscherGroupLimit = 0x400;
extern PACKAGE System::Word __fastcall EscherGetBlipSign(System::Byte Kind);
extern PACKAGE void __fastcall EscherGetBlipHash(/* out */ System::Byte *Hash, Classes::TMemoryStream* Blip);

}	/* namespace Frxescher */
using namespace Frxescher;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// FrxescherHPP
