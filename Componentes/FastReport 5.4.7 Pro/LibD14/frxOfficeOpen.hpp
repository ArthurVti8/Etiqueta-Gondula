// CodeGear C++Builder
// Copyright (c) 1995, 2009 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Frxofficeopen.pas' rev: 21.00

#ifndef FrxofficeopenHPP
#define FrxofficeopenHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Frxclass.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Frxofficeopen
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TfrxStrList;
class PASCALIMPLEMENTATION TfrxStrList : public Classes::TStringList
{
	typedef Classes::TStringList inherited;
	
public:
	virtual int __fastcall AddObject(const System::UnicodeString s, System::TObject* Obj);
public:
	/* TStringList.Create */ inline __fastcall TfrxStrList(void)/* overload */ : Classes::TStringList() { }
	/* TStringList.Destroy */ inline __fastcall virtual ~TfrxStrList(void) { }
	
};


class DELPHICLASS TfrxWriter;
class PASCALIMPLEMENTATION TfrxWriter : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Classes::TStream* FStream;
	bool FOwn;
	
public:
	__fastcall TfrxWriter(Classes::TStream* Stream, bool Own);
	__fastcall virtual ~TfrxWriter(void);
	void __fastcall Write(System::UnicodeString s, bool UCS = false)/* overload */;
	void __fastcall Write(System::UnicodeString const *a, const int a_Size, bool UCS = false)/* overload */;
	void __fastcall Write(const System::UnicodeString Section, Classes::TStrings* StrList)/* overload */;
	void __fastcall Write(const System::UnicodeString Fmt, System::TVarRec const *f, const int f_Size)/* overload */;
};


class DELPHICLASS TfrxFileWriter;
class PASCALIMPLEMENTATION TfrxFileWriter : public TfrxWriter
{
	typedef TfrxWriter inherited;
	
public:
	__fastcall TfrxFileWriter(System::UnicodeString FileName);
public:
	/* TfrxWriter.Destroy */ inline __fastcall virtual ~TfrxFileWriter(void) { }
	
};


struct TfrxMap
{
	
public:
	int FirstRow;
	int LastRow;
	Frxclass::TfrxRect Margins;
	int PaperSize;
	int PageOrientation;
	int Index;
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall Exchange(int &a, int &b);
extern PACKAGE System::WideString __fastcall CleanTrash(const System::WideString s);
extern PACKAGE Graphics::TColor __fastcall RGBSwap(Graphics::TColor c);
extern PACKAGE int __fastcall Distance(int c1, int c2);
extern PACKAGE System::WideString __fastcall Escape(System::WideString s);
extern PACKAGE void __fastcall CreateDirs(const System::UnicodeString RootDir, System::UnicodeString const *SubDirs, const int SubDirs_Size);
extern PACKAGE void __fastcall WriteStr(Classes::TStream* Stream, const System::UnicodeString s, bool UCS = false);
extern PACKAGE void __fastcall WriteStrList(Classes::TStream* Stream, const System::UnicodeString Section, Classes::TStrings* StrList);

}	/* namespace Frxofficeopen */
using namespace Frxofficeopen;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// FrxofficeopenHPP
