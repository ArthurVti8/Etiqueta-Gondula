// CodeGear C++Builder
// Copyright (c) 1995, 2009 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Frxexporthelpers.pas' rev: 21.00

#ifndef FrxexporthelpersHPP
#define FrxexporthelpersHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Frxclass.hpp>	// Pascal unit
#include <Frxcrypto.hpp>	// Pascal unit
#include <Frxstorage.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Frxexporthelpers
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TfrxCSSStyle;
class PASCALIMPLEMENTATION TfrxCSSStyle : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	System::UnicodeString operator[](System::UnicodeString Index) { return Style[Index]; }
	
private:
	Classes::TStrings* FKeys;
	Classes::TStrings* FValues;
	System::UnicodeString FName;
	void __fastcall SetStyle(System::UnicodeString Index, const System::UnicodeString Value);
	void __fastcall SetPrefixStyle(System::UnicodeString Index, const System::UnicodeString Value);
	System::UnicodeString __fastcall GetStyle(System::UnicodeString Index);
	
public:
	__fastcall TfrxCSSStyle(void);
	__fastcall virtual ~TfrxCSSStyle(void);
	TfrxCSSStyle* __fastcall This(void);
	int __fastcall Count(void);
	System::UnicodeString __fastcall Text(bool Formatted = false);
	void __fastcall AssignTo(TfrxCSSStyle* Dest);
	__property System::UnicodeString Style[System::UnicodeString Index] = {read=GetStyle, write=SetStyle/*, default*/};
	__property System::UnicodeString PrefixStyle[System::UnicodeString Index] = {write=SetPrefixStyle};
	__property System::UnicodeString Name = {read=FName, write=FName};
};


class DELPHICLASS TfrxCSS;
class PASCALIMPLEMENTATION TfrxCSS : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	Frxstorage::TObjList* FStyles;
	Classes::TList* FStyleHashes;
	
protected:
	TfrxCSSStyle* __fastcall GetStyle(int i);
	int __fastcall GetHash(const System::UnicodeString s);
	System::UnicodeString __fastcall GetStyleName(int i);
	int __fastcall GetStylesCount(void);
	
public:
	__fastcall TfrxCSS(void);
	__fastcall virtual ~TfrxCSS(void);
	TfrxCSSStyle* __fastcall Style(const System::UnicodeString StyleName);
	System::UnicodeString __fastcall Add(TfrxCSSStyle* Style)/* overload */;
	TfrxCSSStyle* __fastcall Add(const System::UnicodeString StyleName)/* overload */;
	void __fastcall Save(Classes::TStream* Stream, bool Formatted);
};


struct TfrxPictureInfo
{
	
public:
	System::UnicodeString Extension;
	System::UnicodeString Mimetype;
};


class DELPHICLASS TfrxPictureStorage;
class PASCALIMPLEMENTATION TfrxPictureStorage : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::UnicodeString FWorkDir;
	System::UnicodeString FPrefix;
	Classes::TList* FHashes;
	
protected:
	int __fastcall GetHash(Classes::TMemoryStream* Stream);
	
public:
	__fastcall TfrxPictureStorage(const System::UnicodeString WorkDir, System::UnicodeString Prefix);
	__fastcall virtual ~TfrxPictureStorage(void);
	System::UnicodeString __fastcall Save(Graphics::TGraphic* Pic);
	__classmethod TfrxPictureInfo __fastcall GetInfo(Graphics::TGraphic* Pic);
};


#pragma option push -b-
enum TfrxPictureFormat { pfPNG, pfEMF, pfBMP, pfJPG };
#pragma option pop

class DELPHICLASS TfrxPicture;
class PASCALIMPLEMENTATION TfrxPicture : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TfrxPictureFormat FFormat;
	Graphics::TGraphic* FGraphic;
	Graphics::TCanvas* FCanvas;
	Graphics::TBitmap* FBitmap;
	
public:
	__fastcall TfrxPicture(TfrxPictureFormat Format, int Width, int Height);
	__fastcall virtual ~TfrxPicture(void);
	Graphics::TGraphic* __fastcall Release(void);
	void __fastcall SetTransparentColor(Graphics::TColor TransparentColor);
	void __fastcall FillColor(Graphics::TColor Color);
	__property Graphics::TCanvas* Canvas = {read=FCanvas};
};


typedef bool __fastcall (__closure *TfrxExportHandler)(Frxclass::TfrxView* Obj);

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE System::UnicodeString __fastcall StrFindAndReplace(const System::UnicodeString Source, const System::UnicodeString Dlm, System::UnicodeString *SFR, const int SFR_Size);
extern PACKAGE bool __fastcall HasSpecialChars(const System::UnicodeString s);
extern PACKAGE System::UnicodeString __fastcall GetBorderRadius(int Curve);
extern PACKAGE System::UnicodeString __fastcall GetColor(Graphics::TColor Color);
extern PACKAGE System::UnicodeString __fastcall IfStr(bool Flag, const System::UnicodeString sTrue, System::UnicodeString sFalse = L"");

}	/* namespace Frxexporthelpers */
using namespace Frxexporthelpers;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// FrxexporthelpersHPP
