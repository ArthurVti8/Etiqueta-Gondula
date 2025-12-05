// CodeGear C++Builder
// Copyright (c) 1995, 2009 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Frxbiff.pas' rev: 21.00

#ifndef FrxbiffHPP
#define FrxbiffHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Contnrs.hpp>	// Pascal unit
#include <Frxutils.hpp>	// Pascal unit
#include <Frxstorage.hpp>	// Pascal unit
#include <Frxescher.hpp>	// Pascal unit
#include <Frxcrypto.hpp>	// Pascal unit
#include <Types.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Frxbiff
{
//-- type declarations -------------------------------------------------------
typedef System::Word TBiffPaperSize;

typedef int TBiffFormatIndex;

typedef int TBiffStreamKind;

typedef System::Word TBiffRecId;

class DELPHICLASS TBiffRecord;
class DELPHICLASS TBiffStream;
class PASCALIMPLEMENTATION TBiffRecord : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TBiffStream* FOwner;
	unsigned FOffset;
	System::Word __fastcall GetRecId(void);
	unsigned __fastcall GetSize(void);
	void __fastcall SetSize(unsigned n);
	
public:
	__fastcall TBiffRecord(TBiffStream* Owner, unsigned Offset);
	void __fastcall Write(const void *Buffer, unsigned Count);
	void __fastcall WriteConst(unsigned Value, unsigned Size);
	void __fastcall WriteZeros(unsigned Size);
	void __fastcall WriteStream(Classes::TStream* Stream);
	void __fastcall WriteBytes(unsigned Offset, unsigned Data, unsigned Count);
	void __fastcall SaveToStream(Classes::TStream* Stream);
	void __fastcall LoadFromStream(Classes::TStream* Stream);
	__property System::Word Id = {read=GetRecId, nodefault};
	__property unsigned Size = {read=GetSize, write=SetSize, nodefault};
	__property unsigned Offset = {read=FOffset, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TBiffRecord(void) { }
	
};


class PASCALIMPLEMENTATION TBiffStream : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TBiffRecord* operator[](int Index) { return Records[Index]; }
	
private:
	Classes::TStream* FStream;
	Frxstorage::TListCache* FRecords;
	TBiffRecord* FLastRec;
	unsigned __fastcall ReadBytes(unsigned Offset, unsigned Count);
	void __fastcall WriteBytes(unsigned Offset, unsigned Data, unsigned Count);
	void __fastcall Append(unsigned Data, unsigned Count);
	void __fastcall AppendData(const void *Data, unsigned Count);
	void __fastcall AppendRecord(TBiffRecord* Rec, const void *Data, unsigned DataSize);
	TBiffRecord* __fastcall GetRecord(int Index);
	int __fastcall GetRecCount(void);
	unsigned __fastcall GetSize(void);
	
public:
	__fastcall TBiffStream(bool Cached);
	__fastcall virtual ~TBiffStream(void);
	TBiffRecord* __fastcall Add(System::Word Id);
	TBiffRecord* __fastcall AddBOF(int k);
	TBiffRecord* __fastcall AddEOF(void);
	void __fastcall SaveToStream(Classes::TStream* Stream);
	__property TBiffRecord* Records[int Index] = {read=GetRecord/*, default*/};
	__property int Count = {read=GetRecCount, nodefault};
	__property unsigned Size = {read=GetSize, nodefault};
};


class DELPHICLASS TBiffObject;
class PASCALIMPLEMENTATION TBiffObject : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	virtual void __fastcall Flush(TBiffStream* Stream) = 0 ;
	HIDESBASE virtual int __fastcall GetHashCode(void);
	HIDESBASE virtual bool __fastcall Equals(TBiffObject* s);
	__classmethod void __fastcall FlushList(Frxstorage::TObjList* list, TBiffStream* Stream);
public:
	/* TObject.Create */ inline __fastcall TBiffObject(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TBiffObject(void) { }
	
};


class DELPHICLASS TBiffUCS;
class PASCALIMPLEMENTATION TBiffUCS : public TBiffObject
{
	typedef TBiffObject inherited;
	
private:
	System::WideString FData;
	Classes::TMemoryStream* FRuns;
	int FHash;
	bool FCompress;
	void __fastcall SetData(const System::WideString Value);
	bool __fastcall IsCompressible(void);
	void __fastcall Init(void);
	
public:
	bool Len16;
	int Tag;
	int SstIndex;
	__fastcall TBiffUCS(void)/* overload */;
	__fastcall TBiffUCS(const System::WideString S, bool UCS16)/* overload */;
	__fastcall virtual ~TBiffUCS(void);
	void __fastcall AddFormat(int Position, int Font);
	virtual void __fastcall Flush(TBiffStream* Stream);
	virtual bool __fastcall Equals(TBiffObject* s);
	virtual int __fastcall GetHashCode(void);
	__property System::WideString Data = {read=FData, write=SetData};
	__property bool Compress = {read=FCompress, write=FCompress, nodefault};
};


#pragma option push -b-
enum TBiffBuiltinStyleId { bsiNormal, bsiRowLevel, bsiColLevel, bsiCOmma, bsiCurrency, bsiPercent, bsiComma0, bsiCurrency0, bsiHyperlink, bsiFHyperlink };
#pragma option pop

class DELPHICLASS TBiffStyle;
class PASCALIMPLEMENTATION TBiffStyle : public TBiffObject
{
	typedef TBiffObject inherited;
	
public:
	int XF;
	int StyleId;
	int Level;
	System::WideString Name;
	__fastcall TBiffStyle(void);
	virtual void __fastcall Flush(TBiffStream* Stream);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TBiffStyle(void) { }
	
};


class DELPHICLASS TBiffCell;
class PASCALIMPLEMENTATION TBiffCell : public TBiffObject
{
	typedef TBiffObject inherited;
	
public:
	int Row;
	int Col;
	int XF;
	__fastcall TBiffCell(void);
	virtual void __fastcall Flush(TBiffStream* Stream);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TBiffCell(void) { }
	
};


class DELPHICLASS TBiffLinkTable;
class PASCALIMPLEMENTATION TBiffLinkTable : public TBiffObject
{
	typedef TBiffObject inherited;
	
private:
	typedef DynamicArray<System::UnicodeString> _TBiffLinkTable__1;
	
	typedef DynamicArray<int> _TBiffLinkTable__2;
	
	
private:
	_TBiffLinkTable__1 FIntSheetNames;
	_TBiffLinkTable__2 FIntSheetIndex;
	int FSheetsCount;
	int __fastcall FindSheet(const System::UnicodeString Name);
	int __fastcall GetRefsCount(void);
	void __fastcall SetRefsCount(int n);
	
public:
	int __fastcall GetInternalSheetRef(const System::UnicodeString SheetName);
	void __fastcall SetSheetIndex(const System::UnicodeString SheetName, int Index);
	virtual void __fastcall Flush(TBiffStream* Stream);
	__property int RefsCount = {read=GetRefsCount, write=SetRefsCount, nodefault};
	__property int SheetsCount = {read=FSheetsCount, write=FSheetsCount, nodefault};
public:
	/* TObject.Create */ inline __fastcall TBiffLinkTable(void) : TBiffObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TBiffLinkTable(void) { }
	
};


class DELPHICLASS TBiffFormulaCell;
class PASCALIMPLEMENTATION TBiffFormulaCell : public TBiffCell
{
	typedef TBiffCell inherited;
	
private:
	Classes::TStream* FInst;
	
public:
	__fastcall TBiffFormulaCell(Classes::TStream* Instructions);
	__fastcall virtual ~TBiffFormulaCell(void);
	virtual void __fastcall Flush(TBiffStream* Stream);
};


#pragma option push -b-
enum TBiffFormulaLexemKind { flkVoid, flkSpace, flkName, flkInt, flkString, flkOp, flkSymbol };
#pragma option pop

struct TBiffFormulaLexem
{
	
public:
	TBiffFormulaLexemKind Kind;
	System::UnicodeString Text;
};


class DELPHICLASS TBiffFormulaLexer;
class PASCALIMPLEMENTATION TBiffFormulaLexer : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	typedef DynamicArray<TBiffFormulaLexem> _TBiffFormulaLexer__1;
	
	
public:
	TBiffFormulaLexem operator[](int i) { return Lexems[i]; }
	
private:
	System::UnicodeString FText;
	int FPos;
	_TBiffFormulaLexer__1 FLexems;
	bool __fastcall IsAlpha(System::WideChar c);
	bool __fastcall IsDigit(System::WideChar c);
	System::UnicodeString __fastcall Read(int Len);
	System::WideChar __fastcall GetChar(void);
	System::WideChar __fastcall NextChar(void);
	void __fastcall SkipChar(void);
	System::UnicodeString __fastcall SubStr(int Pos, int Len);
	void __fastcall Add(const TBiffFormulaLexem &Lex)/* overload */;
	void __fastcall Add(TBiffFormulaLexemKind LexKind, const System::UnicodeString LexText)/* overload */;
	bool __fastcall AddSpace(void);
	bool __fastcall AddNumber(void);
	bool __fastcall AddSymbol(void);
	bool __fastcall AddName(void);
	bool __fastcall AddString(System::WideChar Quote);
	bool __fastcall AddOp(void);
	int __fastcall GetLexemsCount(void);
	TBiffFormulaLexem __fastcall GetLexem(int i);
	void __fastcall Analyse(const System::UnicodeString Formula);
	
public:
	__property System::UnicodeString Formula = {read=FText, write=Analyse};
	__property int Count = {read=GetLexemsCount, nodefault};
	__property TBiffFormulaLexem Lexems[int i] = {read=GetLexem/*, default*/};
public:
	/* TObject.Create */ inline __fastcall TBiffFormulaLexer(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TBiffFormulaLexer(void) { }
	
};


#pragma option push -b-
enum TBiffFormulaTokenKind { ftkVoid, ftkArg, ftkOp };
#pragma option pop

#pragma option push -b-
enum TBiffFormulaOperatorKind { fokVoid, fokPush, fokDiv100, fokNeg, fokAdd, fokSub, fokDiv, fokMul, fokPow, fokArea, fokColon, fokIsect, fokExt, fokJoin, fokL, fokG, fokE, fokNE, fokLE, fokGE, fokNull, fokNumber, fokBool, fokString, fokCell, fokFunc, fokId };
#pragma option pop

struct TBiffFormulaToken
{
	
public:
	TBiffFormulaTokenKind Kind;
	TBiffFormulaOperatorKind Op;
	System::UnicodeString Text;
	int Flags;
};


typedef DynamicArray<TBiffFormulaToken> TBiffFormulaTokenArray;

class DELPHICLASS TBiffFormulaRPNStack;
class PASCALIMPLEMENTATION TBiffFormulaRPNStack : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TBiffFormulaToken operator[](int i) { return Instructions[i]; }
	
private:
	int FNumArgs;
	TBiffFormulaTokenArray FCode;
	TBiffFormulaTokenArray FStack;
	TBiffFormulaTokenArray FFrame;
	void __fastcall Error(const System::UnicodeString Msg);
	void __fastcall Ensure(bool b, const System::UnicodeString Msg = L"RPN stack failed");
	void __fastcall Push(TBiffFormulaTokenArray &Res, const TBiffFormulaToken &t);
	TBiffFormulaToken __fastcall Pop(TBiffFormulaTokenArray &a);
	TBiffFormulaToken __fastcall Top(const TBiffFormulaTokenArray a);
	void __fastcall PushOp(const TBiffFormulaToken &Op)/* overload */;
	void __fastcall PopOp(void);
	void __fastcall Unroll(void);
	bool __fastcall Joinable(TBiffFormulaOperatorKind Op);
	int __fastcall OpPriority(TBiffFormulaOperatorKind Kind);
	int __fastcall GetCount(void);
	TBiffFormulaToken __fastcall GetInstruction(int i);
	int __fastcall GetFrameArgs(void);
	int __fastcall GetFrameOps(void);
	
public:
	void __fastcall PushArg(TBiffFormulaOperatorKind Op, const System::UnicodeString Text, int Flags = 0x0);
	void __fastcall PushOp(TBiffFormulaOperatorKind Op, const System::UnicodeString Text, int NumArgs = 0x0)/* overload */;
	void __fastcall PushFrame(const System::UnicodeString Func = L"");
	void __fastcall PopFrame(void);
	__property int Count = {read=GetCount, nodefault};
	__property TBiffFormulaToken Instructions[int i] = {read=GetInstruction/*, default*/};
public:
	/* TObject.Create */ inline __fastcall TBiffFormulaRPNStack(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TBiffFormulaRPNStack(void) { }
	
};


class DELPHICLASS EBiffFormulaRPNStackError;
class PASCALIMPLEMENTATION EBiffFormulaRPNStackError : public Sysutils::Exception
{
	typedef Sysutils::Exception inherited;
	
public:
	/* Exception.Create */ inline __fastcall EBiffFormulaRPNStackError(const System::UnicodeString Msg) : Sysutils::Exception(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EBiffFormulaRPNStackError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EBiffFormulaRPNStackError(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EBiffFormulaRPNStackError(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EBiffFormulaRPNStackError(const System::UnicodeString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EBiffFormulaRPNStackError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EBiffFormulaRPNStackError(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EBiffFormulaRPNStackError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EBiffFormulaRPNStackError(void) { }
	
};


class DELPHICLASS TBiffFormulaParser;
class PASCALIMPLEMENTATION TBiffFormulaParser : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	typedef DynamicArray<TBiffFormulaLexem> _TBiffFormulaParser__1;
	
	typedef DynamicArray<int> _TBiffFormulaParser__2;
	
	
public:
	TBiffFormulaToken operator[](int i) { return Tokens[i]; }
	
private:
	_TBiffFormulaParser__1 FLexems;
	int FPos;
	_TBiffFormulaParser__2 FSavedPos;
	TBiffFormulaRPNStack* FRPN;
	TBiffFormulaTokenArray FCode;
	TBiffFormulaToken __fastcall CreateArgToken(TBiffFormulaOperatorKind Kind, const System::UnicodeString Text = L"", int Flags = 0x0);
	void __fastcall Push(TBiffFormulaOperatorKind Arg, const System::UnicodeString Text = L"", int Flags = 0x0);
	void __fastcall Error(const System::UnicodeString ErrorMsg);
	void __fastcall Ensure(bool b, const System::UnicodeString ErrorMsg = L"Invalid formula");
	TBiffFormulaLexem __fastcall Lexem(int i = 0x0);
	void __fastcall SkipLexem(void);
	bool __fastcall SkipLexemIf(const System::UnicodeString Text)/* overload */;
	bool __fastcall SkipLexemIf(TBiffFormulaLexemKind Kind, /* out */ System::UnicodeString &Text)/* overload */;
	bool __fastcall IsOp(const TBiffFormulaLexem &Lex, const System::UnicodeString Text);
	bool __fastcall IsArgSep(const TBiffFormulaLexem &Lex);
	void __fastcall Save(void);
	void __fastcall Load(void);
	void __fastcall Discard(void);
	TBiffFormulaOperatorKind __fastcall OpKind(const System::UnicodeString s);
	void __fastcall Parse(const System::UnicodeString s);
	void __fastcall BuildLexems(const System::UnicodeString s);
	void __fastcall CleanLexems(void);
	void __fastcall CopyCodeFromRPNStack(void);
	bool __fastcall ReadSym(const System::UnicodeString s);
	bool __fastcall ReadString(/* out */ System::UnicodeString &s);
	bool __fastcall ReadNumber(/* out */ System::UnicodeString &s);
	bool __fastcall ReadName(/* out */ System::UnicodeString &s);
	bool __fastcall ReadOp(/* out */ System::UnicodeString &s);
	bool __fastcall ReadSheet(/* out */ System::UnicodeString &s);
	bool __fastcall ReadCell(/* out */ TBiffFormulaToken &t);
	bool __fastcall ParseFormula(void);
	bool __fastcall ParsePPTerm(void);
	bool __fastcall ParsePrefOp(void);
	bool __fastcall ParsePostOp(void);
	bool __fastcall ParseTerm(void);
	bool __fastcall ParseString(void);
	bool __fastcall ParseNumber(void);
	bool __fastcall ParseCell(void);
	bool __fastcall ParseArea(void);
	bool __fastcall ParseBinOp(void);
	bool __fastcall ParseFuncCall(void);
	bool __fastcall ParseNameConst(void);
	bool __fastcall ParseExtCell(void);
	bool __fastcall ParseExtArea(void);
	TBiffFormulaToken __fastcall GetToken(int i);
	int __fastcall GetTokensCount(void);
	
public:
	__property System::UnicodeString Formula = {write=Parse};
	__property TBiffFormulaToken Tokens[int i] = {read=GetToken/*, default*/};
	__property int Count = {read=GetTokensCount, nodefault};
public:
	/* TObject.Create */ inline __fastcall TBiffFormulaParser(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TBiffFormulaParser(void) { }
	
};


class DELPHICLASS EBiffFormulaParserError;
class PASCALIMPLEMENTATION EBiffFormulaParserError : public Sysutils::Exception
{
	typedef Sysutils::Exception inherited;
	
public:
	/* Exception.Create */ inline __fastcall EBiffFormulaParserError(const System::UnicodeString Msg) : Sysutils::Exception(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EBiffFormulaParserError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EBiffFormulaParserError(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EBiffFormulaParserError(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EBiffFormulaParserError(const System::UnicodeString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EBiffFormulaParserError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EBiffFormulaParserError(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EBiffFormulaParserError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EBiffFormulaParserError(void) { }
	
};


struct TBiffFormulaCellRef
{
	
public:
	int Row;
	int Col;
	bool AbsRow;
	bool AbsCol;
};


#pragma option push -b-
enum TBiffFormulaRetType { frtVoid, frtRef, frtVal, frtArray };
#pragma option pop

class DELPHICLASS TBiffFormulaCodeEmitter;
class PASCALIMPLEMENTATION TBiffFormulaCodeEmitter : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Classes::TStream* FInst;
	TBiffFormulaRetType FRetTypeMode;
	void __fastcall Error(const System::UnicodeString ErrorMsg);
	void __fastcall Ensure(bool b, const System::UnicodeString ErrorMsg = L"Cannot emit opcode");
	void __fastcall EnsureCellRange(const TBiffFormulaCellRef &Cell);
	System::Byte __fastcall RelFlags(bool RelRow, bool RelCol);
	void __fastcall WriteOpCode(System::Byte Op);
	void __fastcall Write(unsigned Inst, unsigned Len = (unsigned)(0x1));
	void __fastcall WriteCellRef(const TBiffFormulaCellRef &Cell);
	void __fastcall WriteAreaRef(const TBiffFormulaCellRef &Cell1, const TBiffFormulaCellRef &Cell2);
	
public:
	void __fastcall Push(int Value)/* overload */;
	void __fastcall Push(double Value)/* overload */;
	void __fastcall Push(bool b)/* overload */;
	void __fastcall Push(const System::UnicodeString s)/* overload */;
	void __fastcall PushNull(void);
	void __fastcall PushCell(const TBiffFormulaCellRef &Cell);
	void __fastcall PushArea(const TBiffFormulaCellRef &Cell1, const TBiffFormulaCellRef &Cell2);
	void __fastcall PushExtCell(int SheetRefId, const TBiffFormulaCellRef &Cell);
	void __fastcall PushExtArea(int SheetRefId, const TBiffFormulaCellRef &Cell1, const TBiffFormulaCellRef &Cell2);
	void __fastcall Call(unsigned Func)/* overload */;
	void __fastcall Call(unsigned Func, unsigned NumArgs)/* overload */;
	void __fastcall CallId(void);
	void __fastcall Neg(void);
	void __fastcall Div100(void);
	void __fastcall Add(void);
	void __fastcall Sub(void);
	void __fastcall Mul(void);
	void __fastcall Divide(void);
	void __fastcall Pow(void);
	void __fastcall CmpL(void);
	void __fastcall CmpG(void);
	void __fastcall CmpLE(void);
	void __fastcall CmpGE(void);
	void __fastcall CmpE(void);
	void __fastcall CmpNE(void);
	void __fastcall Intersect(void);
	void __fastcall Range(void);
	void __fastcall Join(void);
	__property Classes::TStream* Output = {read=FInst, write=FInst};
	__property TBiffFormulaRetType RetMode = {read=FRetTypeMode, write=FRetTypeMode, nodefault};
public:
	/* TObject.Create */ inline __fastcall TBiffFormulaCodeEmitter(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TBiffFormulaCodeEmitter(void) { }
	
};


class DELPHICLASS EBiffFormulaCodeEmitterError;
class PASCALIMPLEMENTATION EBiffFormulaCodeEmitterError : public Sysutils::Exception
{
	typedef Sysutils::Exception inherited;
	
public:
	/* Exception.Create */ inline __fastcall EBiffFormulaCodeEmitterError(const System::UnicodeString Msg) : Sysutils::Exception(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EBiffFormulaCodeEmitterError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EBiffFormulaCodeEmitterError(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EBiffFormulaCodeEmitterError(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EBiffFormulaCodeEmitterError(const System::UnicodeString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EBiffFormulaCodeEmitterError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EBiffFormulaCodeEmitterError(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EBiffFormulaCodeEmitterError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EBiffFormulaCodeEmitterError(void) { }
	
};


struct TBiffFormulaFunc
{
	
public:
	System::UnicodeString Name;
	int Id;
	int MinArgs;
	int MaxArgs;
	bool Volatile;
	System::WideChar RetType;
	System::UnicodeString ArgTypes;
};


typedef DynamicArray<TBiffFormulaFunc> TBiffFormulaFuncArray;

class DELPHICLASS TBiffFormulaFuncList;
class PASCALIMPLEMENTATION TBiffFormulaFuncList : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	__classmethod void __fastcall Init();
	__classmethod void __fastcall Add(const TBiffFormulaFunc &f)/* overload */;
	__classmethod int __fastcall Find(System::UnicodeString Name);
	__classmethod int __fastcall GetCount();
	__classmethod TBiffFormulaFunc __fastcall GetFunc(int i);
	__classmethod void __fastcall SetFunc(int i, const TBiffFormulaFunc &f);
	__classmethod void __fastcall SetCount(int n);
	
public:
	__classmethod void __fastcall Add(int Id, System::UnicodeString Name, int MinArgs, int MaxArgs, System::WideChar RetType, System::UnicodeString ArgTypes, bool Volatile = false)/* overload */;
	__classmethod bool __fastcall Exists(const System::UnicodeString Name);
	__classmethod TBiffFormulaFunc __fastcall Get(const System::UnicodeString Name);
	__classmethod System::WideChar __fastcall GetArgType(const System::UnicodeString Name, int i);
public:
	/* TObject.Create */ inline __fastcall TBiffFormulaFuncList(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TBiffFormulaFuncList(void) { }
	
};


class DELPHICLASS TBiffFormulaCompiler;
class PASCALIMPLEMENTATION TBiffFormulaCompiler : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	typedef DynamicArray<TBiffFormulaRetType> _TBiffFormulaCompiler__1;
	
	
private:
	TBiffFormulaParser* FParser;
	int FPos;
	TBiffFormulaCodeEmitter* FEmitter;
	Classes::TStream* FCode;
	TBiffLinkTable* FLinkTable;
	_TBiffFormulaCompiler__1 FRetTypes;
	TBiffLinkTable* __fastcall GetLinkTable(void);
	TBiffFormulaToken __fastcall Token(int i = 0x0);
	void __fastcall SkipToken(void);
	void __fastcall SelectToken(int i);
	void __fastcall Error(const System::UnicodeString Fmt, System::TVarRec const *Args, const int Args_Size);
	void __fastcall Ensure(bool b, const System::UnicodeString ErrorMsg = L"Cannot compile formula")/* overload */;
	void __fastcall Ensure(bool b, const System::UnicodeString Fmt, System::TVarRec const *Args, const int Args_Size)/* overload */;
	bool __fastcall IsCell(const TBiffFormulaToken &t);
	bool __fastcall IsStr(const TBiffFormulaToken &t);
	TBiffFormulaCellRef __fastcall GetCellPos(const TBiffFormulaToken &t);
	void __fastcall CalcRetTypes(void);
	void __fastcall Compile(const System::UnicodeString s);
	void __fastcall CompileToken(void);
	void __fastcall EmitNum(double Num);
	void __fastcall EmitOp(TBiffFormulaOperatorKind Kind, int NumArgs);
	void __fastcall EmitFunc(System::UnicodeString Name, int NumArgs);
	void __fastcall EmitIdFunc(int NumArgs);
	void __fastcall EmitArea(const TBiffFormulaToken &Cell1, const TBiffFormulaToken &Cell2);
	void __fastcall EmitExtCell(const TBiffFormulaToken &Sheet, const TBiffFormulaToken &Cell);
	void __fastcall EmitExtArea(const TBiffFormulaToken &Sheet, const TBiffFormulaToken &Cell1, const TBiffFormulaToken &Cell2);
	void __fastcall EmitPush(const TBiffFormulaToken &t);
	
public:
	__fastcall TBiffFormulaCompiler(void);
	__fastcall virtual ~TBiffFormulaCompiler(void);
	void __fastcall SaveToStream(Classes::TStream* Stream);
	__property System::UnicodeString Formula = {write=Compile};
	__property TBiffLinkTable* LinkTable = {read=GetLinkTable, write=FLinkTable};
};


class DELPHICLASS EBiffFormulaCompilerError;
class PASCALIMPLEMENTATION EBiffFormulaCompilerError : public Sysutils::Exception
{
	typedef Sysutils::Exception inherited;
	
public:
	/* Exception.Create */ inline __fastcall EBiffFormulaCompilerError(const System::UnicodeString Msg) : Sysutils::Exception(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EBiffFormulaCompilerError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EBiffFormulaCompilerError(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EBiffFormulaCompilerError(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EBiffFormulaCompilerError(const System::UnicodeString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EBiffFormulaCompilerError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EBiffFormulaCompilerError(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EBiffFormulaCompilerError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EBiffFormulaCompilerError(void) { }
	
};


class DELPHICLASS TBiffTextCell;
class PASCALIMPLEMENTATION TBiffTextCell : public TBiffCell
{
	typedef TBiffCell inherited;
	
public:
	int SST;
	__fastcall TBiffTextCell(int SST);
	virtual void __fastcall Flush(TBiffStream* Stream);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TBiffTextCell(void) { }
	
};


class DELPHICLASS TBiffNumberCell;
class PASCALIMPLEMENTATION TBiffNumberCell : public TBiffCell
{
	typedef TBiffCell inherited;
	
public:
	double Value;
	__fastcall TBiffNumberCell(double Value);
	virtual void __fastcall Flush(TBiffStream* Stream);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TBiffNumberCell(void) { }
	
};


#pragma option push -b-
enum TBiffColorIndex { ciBlack, ciWhite, ciRed, ciGreen, ciBlue, ciYellow, ciMagenta, ciCyan };
#pragma option pop

typedef int TBiffFontOptions;

#pragma option push -b-
enum TBiffFontFamily { ffNone, ffRoman, ffSwiss, ffModern, ffScript, ffDecorative };
#pragma option pop

#pragma option push -b-
enum TBiffFontEscapement { feNone, feSuperScript, feSubScript };
#pragma option pop

typedef int TBiffFontUnderline;

typedef int TBiffFontWeight;

struct TBiffFontData
{
	
public:
	int Height;
	System::Word Options;
	System::Word Color;
	System::Word Weight;
	TBiffFontEscapement Esc;
	int Underline;
	TBiffFontFamily Family;
	System::Byte Charset;
};


class DELPHICLASS TBiffFont;
class PASCALIMPLEMENTATION TBiffFont : public TBiffObject
{
	typedef TBiffObject inherited;
	
public:
	TBiffFontData Data;
	System::WideString Name;
	int Hash;
	int FontIndex;
	__fastcall TBiffFont(void);
	virtual void __fastcall Flush(TBiffStream* Stream);
	virtual bool __fastcall Equals(TBiffObject* Font);
	virtual int __fastcall GetHashCode(void);
	int __fastcall StrWidth(const System::WideString Str);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TBiffFont(void) { }
	
};


typedef int TBiffXFTypeProt;

typedef int TBiffXFUsedAttrib;

typedef int TBiffPatternStyle;

#pragma option push -b-
enum TBiffXFHAlign { xfhaGeneral, xfhaLeft, xfhaCentered, xfhaRight, xfhaFilled, xfhaJustified, xfhaCAS, xfhaDistributed };
#pragma option pop

#pragma option push -b-
enum TBiffXFVAlign { xfvaTop, xfvaCentered, xfvaBottom, xfvaJustified, xfvaDistributed };
#pragma option pop

#pragma option push -b-
enum TBiffXFTextDir { xftdAuto, xftdLTR, xftdRTL };
#pragma option pop

#pragma option push -b-
enum TBiffXFOrientation { xfoNone, xfoTop, xfo90CCW, xfo90CW };
#pragma option pop

#pragma option push -b-
enum TBiffLineStyle { lsNone, lsThin, lsMedium, lsDashed, lsDotted, lsThick, lsDouble, lsHair, lsMediumDashed, lsThinDashDotted, lsMediumDashDotted, lsThinDashDotDotted, lsMediumDashDotDotted, lsSlantedMediumDashDotted };
#pragma option pop

struct TBiffLine
{
	
public:
	TBiffLineStyle Style;
	System::Byte Color;
};


struct TBiffXfData
{
	
public:
	int Font;
	int Format;
	System::Byte Prot;
	int Parent;
	TBiffXFHAlign HAlign;
	bool WordWrap;
	TBiffXFVAlign VAlign;
	bool Justify;
	System::Byte Rotation;
	System::Byte Indent;
	bool Shrink;
	TBiffXFTextDir Direction;
	System::Byte UsedAttrs;
	TBiffLine L;
	TBiffLine T;
	TBiffLine R;
	TBiffLine B;
	TBiffLine D;
	bool LTRB;
	bool LBRT;
	System::Byte Patt;
	System::Word PattColor;
	System::Word PattBgColor;
};


class DELPHICLASS TBiffXF;
class PASCALIMPLEMENTATION TBiffXF : public TBiffObject
{
	typedef TBiffObject inherited;
	
public:
	int XfIndex;
	TBiffXfData Data;
	int Hash;
	__fastcall TBiffXF(void);
	virtual void __fastcall Flush(TBiffStream* Stream);
	virtual bool __fastcall Equals(TBiffObject* XF);
	virtual int __fastcall GetHashCode(void);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TBiffXF(void) { }
	
};


class DELPHICLASS TBiffColInfo;
class PASCALIMPLEMENTATION TBiffColInfo : public TBiffObject
{
	typedef TBiffObject inherited;
	
public:
	int First;
	int Last;
	int XF;
	bool Hidden;
	bool Collapsed;
	System::Byte Outline;
	int Width;
	__fastcall TBiffColInfo(int Column, int XF, int Width);
	virtual void __fastcall Flush(TBiffStream* Stream);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TBiffColInfo(void) { }
	
};


typedef int TBiffWindowOptions;

class DELPHICLASS TBiffWindow;
class PASCALIMPLEMENTATION TBiffWindow : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	int HPos;
	int VPos;
	int Width;
	int Height;
	int ActiveSheet;
	int FirstTab;
	int SelSheet;
	int TabWidth;
	bool Visible;
	bool Open;
	bool HSBVisible;
	bool VSBVisible;
	bool TabVisible;
	__fastcall TBiffWindow(void);
	void __fastcall Flush(TBiffStream* Stream);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TBiffWindow(void) { }
	
};


class DELPHICLASS TBiffRow;
class PASCALIMPLEMENTATION TBiffRow : public TBiffObject
{
	typedef TBiffObject inherited;
	
public:
	int Row;
	Frxstorage::TObjList* Cells;
	int FirstCol;
	int LastCol;
	int Height;
	System::Byte Outline;
	int XF;
	bool Hidden;
	unsigned FirstCell;
	unsigned Offset;
	__fastcall TBiffRow(void);
	__fastcall virtual ~TBiffRow(void);
	virtual void __fastcall Flush(TBiffStream* Stream);
};


#pragma option push -b-
enum TBiffPageOrientation { bpoLandscape, bpoPortrait };
#pragma option pop

class DELPHICLASS TBiffPageSetup;
class PASCALIMPLEMENTATION TBiffPageSetup : public TBiffObject
{
	typedef TBiffObject inherited;
	
public:
	System::Word Size;
	TBiffPageOrientation Orient;
	int Copies;
	bool Colored;
	System::Word Xdpi;
	System::Word Ydpi;
	bool PrintInRows;
	bool Draft;
	bool CellNotes;
	bool SheetNotes;
	__fastcall TBiffPageSetup(void);
	virtual void __fastcall Flush(TBiffStream* Stream);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TBiffPageSetup(void) { }
	
};


class DELPHICLASS TBiffRC4;
class PASCALIMPLEMENTATION TBiffRC4 : public TBiffObject
{
	typedef TBiffObject inherited;
	
private:
	StaticArray<System::Byte, 16> FSalt;
	StaticArray<System::Byte, 16> FVerifier;
	StaticArray<System::Byte, 16> FHash;
	StaticArray<System::Byte, 5> FTruncHash;
	Frxcrypto::TCryptoRC4* FCipher;
	int FTail;
	int FBlockId;
	void __fastcall EncryptEx(void * Data, int Size);
	void __fastcall MD5(/* out */ void *Hash, const void *Data, int Size);
	
public:
	__fastcall TBiffRC4(void);
	__fastcall virtual ~TBiffRC4(void);
	void __fastcall Prepare(const void *Password, int PassLen);
	virtual void __fastcall Flush(TBiffStream* Stream);
	void __fastcall Init(void * Key, int Len);
	void __fastcall Initialize(unsigned BlockId);
	void __cdecl Encrypt(void * Data, int Size);
	void __fastcall EncryptStream(TBiffStream* Stream);
};


struct TBiffBounds
{
	
public:
	int FR;
	int LR;
	int FC;
	int LC;
};


class DELPHICLASS TBiffWindow2;
class PASCALIMPLEMENTATION TBiffWindow2 : public TBiffObject
{
	typedef TBiffObject inherited;
	
public:
	System::Word Options;
	System::Word FirstRow;
	System::Word FirstCol;
	System::Word GridCol;
	System::Word MFPBP;
	System::Word CMFNV;
	__fastcall TBiffWindow2(void);
	virtual void __fastcall Flush(TBiffStream* Stream);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TBiffWindow2(void) { }
	
};


typedef int TBiffSheetKind;

#pragma option push -b-
enum TBiffSheetVisibility { svVisible, svHidden, svVeryHidden };
#pragma option pop

struct TBiffMargin
{
	
public:
	double Left;
	double Top;
	double Right;
	double Bottom;
};


class DELPHICLASS TRectangle;
class PASCALIMPLEMENTATION TRectangle : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Types::TRect FRect;
	int __fastcall GetBottom(void);
	Types::TPoint __fastcall GetBottomRight(void);
	int __fastcall GetLeft(void);
	int __fastcall GetRight(void);
	int __fastcall GetTop(void);
	Types::TPoint __fastcall GetTopLeft(void);
	void __fastcall SetBottom(const int Value);
	void __fastcall SetBottomRight(const Types::TPoint &Value);
	void __fastcall SetLeft(const int Value);
	void __fastcall SetRight(const int Value);
	void __fastcall SetTop(const int Value);
	void __fastcall SetTopLeft(const Types::TPoint &Value);
	
public:
	__property int Bottom = {read=GetBottom, write=SetBottom, nodefault};
	__property Types::TPoint BottomRight = {read=GetBottomRight, write=SetBottomRight};
	__property int Left = {read=GetLeft, write=SetLeft, nodefault};
	__property int Right = {read=GetRight, write=SetRight, nodefault};
	__property int Top = {read=GetTop, write=SetTop, nodefault};
	__property Types::TPoint TopLeft = {read=GetTopLeft, write=SetTopLeft};
public:
	/* TObject.Create */ inline __fastcall TRectangle(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TRectangle(void) { }
	
};


class DELPHICLASS TBiffSheet;
class DELPHICLASS TBiffWorkbook;
class PASCALIMPLEMENTATION TBiffSheet : public TBiffObject
{
	typedef TBiffObject inherited;
	
private:
	Frxstorage::TObjList* FRows;
	Frxstorage::TObjList* FCols;
	Contnrs::TObjectList* FMrgCells;
	Frxescher::TEscherGroup* FDGroup;
	TBiffWorkbook* FOwner;
	int FKind;
	TBiffSheetVisibility FVis;
	Classes::TList* FPB;
	int FStrCount;
	int FLastReadRow;
	void __fastcall SetColWidth(int i, int w);
	void __fastcall SetRowHeight(int i, int h);
	int __fastcall GetColWidth(int i);
	int __fastcall GetRowHeight(int i);
	TBiffRow* __fastcall GetRow(int Index);
	
public:
	System::WideString Name;
	TBiffMargin Margin;
	TBiffPageSetup* PageSetup;
	TBiffWindow2* View;
	TBiffBounds Bounds;
	int RecIndex;
	__fastcall TBiffSheet(TBiffWorkbook* Owner);
	__fastcall virtual ~TBiffSheet(void);
	void __fastcall AddCell(TBiffCell* Cell);
	void __fastcall MergeCells(const Types::TRect &Rect);
	void __fastcall AddColInfo(TBiffColInfo* Info);
	Frxescher::TEscherShape* __fastcall AddDrawing(void);
	virtual void __fastcall Flush(TBiffStream* Stream);
	void __fastcall AddPageBreak(int Row);
	int __fastcall LastRowIndex(void);
	__property int ColWidth[int i] = {read=GetColWidth, write=SetColWidth};
	__property int RowHeight[int i] = {read=GetRowHeight, write=SetRowHeight};
	__property int TextCellsCount = {read=FStrCount, nodefault};
	__property TBiffSheetVisibility Visibility = {read=FVis, nodefault};
	__property int Kind = {read=FKind, nodefault};
};


class PASCALIMPLEMENTATION TBiffWorkbook : public TBiffObject
{
	typedef TBiffObject inherited;
	
private:
	Frxstorage::TObjList* SST;
	Frxstorage::TListHashTable* SSTHash;
	TBiffWindow* Win;
	Frxstorage::TObjList* Sheets;
	Frxstorage::TObjList* Styles;
	Frxstorage::TObjList* FFormats;
	Frxescher::TEscherStorage* Escher;
	TBiffLinkTable* FLinkTbl;
	Frxstorage::TObjList* Fonts;
	Frxstorage::TListHashTable* FontHash;
	Frxstorage::TObjList* XFs;
	Frxstorage::TListHashTable* XFHash;
	StaticArray<unsigned, 64> Palette;
	unsigned PalUsed;
	TBiffRC4* FCipher;
	_RTL_CRITICAL_SECTION FCsStrings;
	_RTL_CRITICAL_SECTION FCsFonts;
	_RTL_CRITICAL_SECTION FCsXFs;
	_RTL_CRITICAL_SECTION FCsSheets;
	_RTL_CRITICAL_SECTION FCsStyles;
	_RTL_CRITICAL_SECTION FCsColors;
	_RTL_CRITICAL_SECTION FCsPictures;
	_RTL_CRITICAL_SECTION FCsFormats;
	void __fastcall LockSst(void);
	void __fastcall UnlockSst(void);
	void __fastcall LockFonts(void);
	void __fastcall UnlockFonts(void);
	void __fastcall LockXfs(void);
	void __fastcall UnlockXfs(void);
	void __fastcall LockSheets(void);
	void __fastcall UnlockSheets(void);
	void __fastcall LockStyles(void);
	void __fastcall UnlockStyles(void);
	void __fastcall LockColors(void);
	void __fastcall UnlockColors(void);
	void __fastcall LockPictures(void);
	void __fastcall UnlockPictures(void);
	void __fastcall LockFormats(void);
	void __fastcall UnlockFormats(void);
	TBiffLinkTable* __fastcall GetLinkTable(void);
	int __fastcall GetSheetsCount(void);
	TBiffSheet* __fastcall GetSheet(int Index);
	int __fastcall GetFontsCount(void);
	TBiffFont* __fastcall GetFont(int Index);
	void __fastcall SetFormat(int i, const System::WideString s);
	int __fastcall AddBlip(Frxescher::TEscherPicture* Blip);
	int __fastcall AddColorInternal(unsigned C);
	
public:
	__fastcall TBiffWorkbook(void);
	__fastcall virtual ~TBiffWorkbook(void);
	void __fastcall SetPassword(const System::WideString s);
	unsigned __fastcall AddString(TBiffUCS* S)/* overload */;
	unsigned __fastcall AddString(System::WideString S)/* overload */;
	unsigned __fastcall AddFont(TBiffFont* F);
	unsigned __fastcall AddXF(TBiffXF* X);
	unsigned __fastcall AddSheet(TBiffSheet* S);
	int __fastcall AddStyle(TBiffStyle* S);
	int __fastcall AddFormat(const System::WideString FormatStr, int FormatIndex = 0xffffffff);
	int __fastcall AddColor(unsigned C);
	int __fastcall AddBitmap(System::Byte Kind, Classes::TStream* Contents);
	int __fastcall AddMetafile(Graphics::TMetafile* Metafile);
	int __fastcall StringsCount(void);
	virtual void __fastcall Flush(TBiffStream* Stream);
	__property int SheetsCount = {read=GetSheetsCount, nodefault};
	__property TBiffSheet* Sheet[int Index] = {read=GetSheet};
	__property int FontsCount = {read=GetFontsCount, nodefault};
	__property TBiffFont* Font[int Index] = {read=GetFont};
	__property System::WideString Format[int i] = {write=SetFormat};
	__property TBiffLinkTable* LinkTable = {read=GetLinkTable};
};


//-- var, const, procedure ---------------------------------------------------
static const Word BiffMaxRecLen = 0x2020;
static const Word BiffMaxMrgCellsNum = 0x402;
static const ShortInt BiffRowBlockSz = 0x20;
static const ShortInt BiffPaletteSize = 0x40;
static const Word BiffRrdMaxCount = 0x1010;
static const Word BiffMaxRow = 0xfffe;
static const Byte BiffMaxCol = 0xfe;
static const Byte BiffUserFormat = 0xa4;
static const ShortInt bkWBGlobals = 0x5;
static const ShortInt bkVBModule = 0x6;
static const ShortInt bkSheet = 0x10;
static const ShortInt bkChart = 0x20;
static const ShortInt bkMacro = 0x40;
static const Word bkWorkspace = 0x100;
static const ShortInt foBold = 0x1;
static const ShortInt foItalic = 0x2;
static const ShortInt foUnderline = 0x4;
static const ShortInt foStruckOut = 0x8;
static const ShortInt foOutline = 0x10;
static const ShortInt foShadow = 0x20;
static const ShortInt foCondense = 0x40;
static const Byte foExtended = 0x80;
static const ShortInt fuNone = 0x0;
static const ShortInt fuSingle = 0x1;
static const ShortInt fuDouble = 0x2;
static const ShortInt fuSingleAcc = 0x21;
static const ShortInt fuDoubleAcc = 0x22;
static const Word fwNormal = 0x190;
static const Word fwBold = 0x2bc;
static const ShortInt xftpCellLocked = 0x1;
static const ShortInt xftpHidden = 0x2;
static const ShortInt xftpStyle = 0x4;
static const ShortInt BiffXfuaNumber = 0x1;
static const ShortInt BiffXfuaFont = 0x2;
static const ShortInt BiffXfuaText = 0x4;
static const ShortInt BiffXfuaBorders = 0x8;
static const ShortInt BiffXfuaBg = 0x10;
static const ShortInt BiffXfuaCellProt = 0x20;
static const ShortInt BiffXfuaAll = 0x3f;
static const ShortInt psNone = 0x0;
static const ShortInt psSolid = 0x1;
static const ShortInt psChess = 0x2;
static const ShortInt psHorThick = 0x5;
static const ShortInt psVerThick = 0x6;
static const ShortInt psChessThick = 0x9;
static const ShortInt psHor = 0xb;
static const ShortInt psVer = 0xc;
static const ShortInt psDiagBack = 0xd;
static const ShortInt psDiag = 0xe;
static const ShortInt psCross = 0xf;
static const ShortInt psCrossDiag = 0x10;
static const ShortInt woFormula = 0x1;
static const ShortInt woGrid = 0x2;
static const ShortInt woHeaders = 0x4;
static const ShortInt woFreezePanes = 0x8;
static const ShortInt woShowZeros = 0x10;
static const ShortInt woAutoGridCol = 0x20;
static const ShortInt woColRTL = 0x40;
static const Byte woOutline = 0x80;
static const Word woNoSplits = 0x100;
static const Word woSelected = 0x200;
static const Word woActive = 0x400;
static const Word woPageBreak = 0x800;
static const ShortInt skWorksheet = 0x0;
static const ShortInt skChart = 0x2;
static const ShortInt skVB = 0x6;
static const ShortInt BiffFmtGeneral = 0x0;
static const ShortInt BiffFmtFixedPoint = 0x2;
static const ShortInt BiffFmtThSep = 0x4;
static const ShortInt BiffFmtCurrency = 0x5;
static const ShortInt BiffFmtDateTime = 0x16;
static const ShortInt BiffWoFormulas = 0x1;
static const ShortInt BiffWoGridLines = 0x2;
static const ShortInt BiffWoHeaders = 0x4;
static const ShortInt BiffWoFrozen = 0x8;
static const ShortInt BiffWoZeros = 0x10;
static const ShortInt BiffWoAutoGridColor = 0x20;
static const ShortInt BiffWoColumnsRTL = 0x40;
static const Byte BiffWoOutline = 0x80;
static const Word BiffWoNoSplits = 0x100;
static const Word BiffWoSelected = 0x200;
static const Word BiffWoActive = 0x400;
static const Word BiffWoPageBreak = 0x800;
static const ShortInt BiffPsUnknown = 0x0;
static const ShortInt BiffPsA4 = 0x9;
static const ShortInt BiffPsReservedMin = 0x76;
static const Byte BiffPsReservedMax = 0xff;
static const Word BiffPsCustomMin = 0x100;
static const ShortInt BiffBoffWin = 0x1;
static const ShortInt BiffBoffRisc = 0x2;
static const ShortInt BiffBoffBeta = 0x4;
static const ShortInt BiffBoffWinAny = 0x8;
static const ShortInt BiffBoffMacAny = 0x10;
static const ShortInt BiffBoffBetaAny = 0x20;
static const Word BiffBoffRiscAny = 0x100;
static const Word BiffBoffFontLim = 0x2000;
static const ShortInt BiffWsbShowBreaks = 0x1;
static const ShortInt BiffWsbDialog = 0x10;
static const ShortInt BiffWsbOutline = 0x20;
static const ShortInt BiffWsbRowSums = 0x40;
static const Byte BiffWsbColSums = 0x80;
static const Word BiffWsbFitPage = 0x100;
static const Word BiffWsbHSync = 0x1000;
static const Word BiffWsbVSync = 0x2000;
static const Word BiffWsbAltExpr = 0x4000;
static const Word BiffWsbAltFormulas = 0x8000;
extern PACKAGE unsigned __fastcall NearestColor(void * Colors, unsigned Count, unsigned Color);
extern PACKAGE void __fastcall ValidateLineBreaks(System::WideString &s);

}	/* namespace Frxbiff */
using namespace Frxbiff;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// FrxbiffHPP
