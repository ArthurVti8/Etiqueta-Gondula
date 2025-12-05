// CodeGear C++Builder
// Copyright (c) 1995, 2009 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Frxcrypto.pas' rev: 21.00

#ifndef FrxcryptoHPP
#define FrxcryptoHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Frxcrypto
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TCryptoRC4;
class PASCALIMPLEMENTATION TCryptoRC4 : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	StaticArray<System::Byte, 256> FS;
	System::Byte FI;
	System::Byte FJ;
	
public:
	void __fastcall Init(const void *Key, int Len);
	void __fastcall Encrypt(void * Data, int Size);
public:
	/* TObject.Create */ inline __fastcall TCryptoRC4(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TCryptoRC4(void) { }
	
};


typedef StaticArray<System::Byte, 16> TCryptoAESMatrix;

typedef StaticArray<System::Byte, 256> TCryptoAESSBox;

typedef StaticArray<System::Byte, 4> TCryptoAESDiffuseRow;

class DELPHICLASS TCryptoAES;
class PASCALIMPLEMENTATION TCryptoAES : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	typedef DynamicArray<TCryptoAESMatrix> _TCryptoAES__1;
	
	
private:
	int FNr;
	_TCryptoAES__1 FW;
	__classmethod void __fastcall InitSBox();
	__classmethod int __fastcall Mul8(int a, int b);
	
protected:
	__classmethod void __fastcall MatrixToData(/* out */ void *Data, System::Byte const *a);
	__classmethod void __fastcall DataToMatrix(/* out */ System::Byte *a, const void *Data);
	void __fastcall Sum(System::Byte *a, System::Byte const *b, System::Byte const *c);
	void __fastcall Mov(System::Byte *a, System::Byte const *b);
	void __fastcall Zero(System::Byte *a);
	void __fastcall Apply(System::Byte *a, System::Byte const *Box);
	void __fastcall Rotate(System::Byte *a, int Dir);
	void __fastcall Diffuse(System::Byte *a, const TCryptoAESDiffuseRow DiffuseRow);
	void __fastcall ExpandKey(System::Byte const *Key, const int Key_Size);
	virtual void __fastcall Encrypt(System::Byte *a)/* overload */;
	virtual void __fastcall Decrypt(System::Byte *a)/* overload */;
	
public:
	__fastcall TCryptoAES(System::Byte const *Key, const int Key_Size);
	virtual void __fastcall Encrypt(void *Output, const void *Input)/* overload */;
	virtual void __fastcall Decrypt(void *Output, const void *Input)/* overload */;
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TCryptoAES(void) { }
	
};


class DELPHICLASS ECryptoAESException;
class PASCALIMPLEMENTATION ECryptoAESException : public Sysutils::Exception
{
	typedef Sysutils::Exception inherited;
	
public:
	/* Exception.Create */ inline __fastcall ECryptoAESException(const System::UnicodeString Msg) : Sysutils::Exception(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall ECryptoAESException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall ECryptoAESException(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall ECryptoAESException(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall ECryptoAESException(const System::UnicodeString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall ECryptoAESException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall ECryptoAESException(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall ECryptoAESException(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~ECryptoAESException(void) { }
	
};


class DELPHICLASS ECryptoAESInvalidKeyLength;
class PASCALIMPLEMENTATION ECryptoAESInvalidKeyLength : public ECryptoAESException
{
	typedef ECryptoAESException inherited;
	
public:
	/* Exception.Create */ inline __fastcall ECryptoAESInvalidKeyLength(const System::UnicodeString Msg) : ECryptoAESException(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall ECryptoAESInvalidKeyLength(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : ECryptoAESException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall ECryptoAESInvalidKeyLength(int Ident)/* overload */ : ECryptoAESException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall ECryptoAESInvalidKeyLength(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : ECryptoAESException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall ECryptoAESInvalidKeyLength(const System::UnicodeString Msg, int AHelpContext) : ECryptoAESException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall ECryptoAESInvalidKeyLength(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : ECryptoAESException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall ECryptoAESInvalidKeyLength(int Ident, int AHelpContext)/* overload */ : ECryptoAESException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall ECryptoAESInvalidKeyLength(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : ECryptoAESException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~ECryptoAESInvalidKeyLength(void) { }
	
};


class DELPHICLASS ECryptoAESInvalidBlockSize;
class PASCALIMPLEMENTATION ECryptoAESInvalidBlockSize : public ECryptoAESException
{
	typedef ECryptoAESException inherited;
	
public:
	/* Exception.Create */ inline __fastcall ECryptoAESInvalidBlockSize(const System::UnicodeString Msg) : ECryptoAESException(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall ECryptoAESInvalidBlockSize(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : ECryptoAESException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall ECryptoAESInvalidBlockSize(int Ident)/* overload */ : ECryptoAESException(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall ECryptoAESInvalidBlockSize(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : ECryptoAESException(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall ECryptoAESInvalidBlockSize(const System::UnicodeString Msg, int AHelpContext) : ECryptoAESException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall ECryptoAESInvalidBlockSize(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : ECryptoAESException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall ECryptoAESInvalidBlockSize(int Ident, int AHelpContext)/* overload */ : ECryptoAESException(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall ECryptoAESInvalidBlockSize(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : ECryptoAESException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~ECryptoAESInvalidBlockSize(void) { }
	
};


class DELPHICLASS TCryptoAES_CBC;
class PASCALIMPLEMENTATION TCryptoAES_CBC : public TCryptoAES
{
	typedef TCryptoAES inherited;
	
private:
	TCryptoAESMatrix FC;
	
protected:
	virtual void __fastcall Encrypt(System::Byte *a)/* overload */;
	virtual void __fastcall Decrypt(System::Byte *a)/* overload */;
	
public:
	__fastcall TCryptoAES_CBC(System::Byte const *Key, const int Key_Size, const void *IV);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TCryptoAES_CBC(void) { }
	
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Encrypt(void *Output, const void *Input){ TCryptoAES::Encrypt(Output, Input); }
	inline void __fastcall  Decrypt(void *Output, const void *Input){ TCryptoAES::Decrypt(Output, Input); }
	
};


class DELPHICLASS TCryptoCMWC;
class PASCALIMPLEMENTATION TCryptoCMWC : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	typedef DynamicArray<unsigned> _TCryptoCMWC__1;
	
	
private:
	unsigned FMultiplier;
	_TCryptoCMWC__1 FSeed;
	unsigned FCarry;
	int FNext;
	
public:
	__fastcall TCryptoCMWC(unsigned a, unsigned r);
	unsigned __fastcall Next(void);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TCryptoCMWC(void) { }
	
};


class DELPHICLASS TCryptoHash;
class PASCALIMPLEMENTATION TCryptoHash : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	typedef DynamicArray<System::Byte> _TCryptoHash__1;
	
	
private:
	_TCryptoHash__1 FChunk;
	int FLength;
	
protected:
	__fastcall TCryptoHash(int ChunkSize)/* overload */;
	virtual void __fastcall Process(System::Byte const *Chunk, const int Chunk_Size) = 0 ;
	virtual void __fastcall Finish(int LengthSize, bool Straight);
	
public:
	__classmethod TCryptoHash* __fastcall Create(const System::UnicodeString Name)/* overload */;
	__classmethod void __fastcall Hash(const System::UnicodeString Name, void *Digest, int DigestSize, const void *Data, int Size)/* overload */;
	__classmethod void __fastcall Hash(const System::UnicodeString Name, void *Digest, int DigestSize, const System::AnsiString s)/* overload */;
	virtual void __fastcall Reset(void);
	void __fastcall Push(System::Byte b)/* overload */;
	void __fastcall Push(const void *Data, int Size)/* overload */;
	void __fastcall Push(Classes::TStream* Stream)/* overload */;
	virtual void __fastcall GetDigest(/* out */ void *Digest, int Size) = 0 ;
	virtual int __fastcall DigestSize(void) = 0 ;
	int __fastcall ChunkSize(void);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TCryptoHash(void) { }
	
};


class DELPHICLASS ECryptoHash;
class PASCALIMPLEMENTATION ECryptoHash : public Sysutils::Exception
{
	typedef Sysutils::Exception inherited;
	
public:
	/* Exception.Create */ inline __fastcall ECryptoHash(const System::UnicodeString Msg) : Sysutils::Exception(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall ECryptoHash(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall ECryptoHash(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall ECryptoHash(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall ECryptoHash(const System::UnicodeString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall ECryptoHash(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall ECryptoHash(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall ECryptoHash(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~ECryptoHash(void) { }
	
};


class DELPHICLASS ECryptoHashUnknown;
class PASCALIMPLEMENTATION ECryptoHashUnknown : public ECryptoHash
{
	typedef ECryptoHash inherited;
	
public:
	__fastcall ECryptoHashUnknown(System::UnicodeString Name);
public:
	/* Exception.CreateFmt */ inline __fastcall ECryptoHashUnknown(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : ECryptoHash(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall ECryptoHashUnknown(int Ident)/* overload */ : ECryptoHash(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall ECryptoHashUnknown(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : ECryptoHash(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall ECryptoHashUnknown(const System::UnicodeString Msg, int AHelpContext) : ECryptoHash(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall ECryptoHashUnknown(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : ECryptoHash(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall ECryptoHashUnknown(int Ident, int AHelpContext)/* overload */ : ECryptoHash(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall ECryptoHashUnknown(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : ECryptoHash(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~ECryptoHashUnknown(void) { }
	
};


class DELPHICLASS TCryptoMD5;
class PASCALIMPLEMENTATION TCryptoMD5 : public TCryptoHash
{
	typedef TCryptoHash inherited;
	
private:
	StaticArray<int, 4> FState;
	__classmethod void __fastcall InitSinTable();
	void __fastcall InitState(void);
	
protected:
	virtual void __fastcall Process(System::Byte const *Chunk, const int Chunk_Size);
	
public:
	__fastcall TCryptoMD5(void);
	virtual void __fastcall GetDigest(/* out */ void *Digest, int Size);
	virtual void __fastcall Reset(void);
	virtual int __fastcall DigestSize(void);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TCryptoMD5(void) { }
	
};


class DELPHICLASS TCryptoSHA1;
class PASCALIMPLEMENTATION TCryptoSHA1 : public TCryptoHash
{
	typedef TCryptoHash inherited;
	
private:
	StaticArray<int, 5> FState;
	void __fastcall InitState(void);
	
protected:
	virtual void __fastcall Process(System::Byte const *Chunk, const int Chunk_Size);
	
public:
	__fastcall TCryptoSHA1(void);
	virtual void __fastcall GetDigest(/* out */ void *Digest, int Size);
	virtual void __fastcall Reset(void);
	virtual int __fastcall DigestSize(void);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TCryptoSHA1(void) { }
	
};


typedef StaticArray<StaticArray<System::Byte, 8>, 8> TCryptoWhirlpoolMatrix;

class DELPHICLASS TCryptoWhirlpool;
class PASCALIMPLEMENTATION TCryptoWhirlpool : public TCryptoHash
{
	typedef TCryptoHash inherited;
	
private:
	TCryptoWhirlpoolMatrix FState;
	void __fastcall ApplySBox(StaticArray<System::Byte, 8> *a);
	void __fastcall Rotate(StaticArray<System::Byte, 8> *a);
	void __fastcall Diffuse(StaticArray<System::Byte, 8> *a);
	void __fastcall Transform(StaticArray<System::Byte, 8> *a, StaticArray<System::Byte, 8> const *b);
	void __fastcall InitState(void);
	void __fastcall Sum(StaticArray<System::Byte, 8> *a, StaticArray<System::Byte, 8> const *b, StaticArray<System::Byte, 8> const *c);
	void __fastcall Encrypt(StaticArray<System::Byte, 8> *w, StaticArray<System::Byte, 8> const *a, StaticArray<System::Byte, 8> const *b);
	
protected:
	virtual void __fastcall Process(System::Byte const *Chunk, const int Chunk_Size);
	
private:
	__classmethod void __fastcall InitSBox();
	__classmethod void __fastcall InitMul8();
	__classmethod int __fastcall Mul4(int a, int b);
	__classmethod int __fastcall Mul8(int a, int b);
	__classmethod int __fastcall Mul8NoCache(int a, int b);
	
public:
	__fastcall TCryptoWhirlpool(void);
	virtual void __fastcall GetDigest(/* out */ void *Digest, int Size);
	virtual void __fastcall Reset(void);
	virtual int __fastcall DigestSize(void);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TCryptoWhirlpool(void) { }
	
};


class DELPHICLASS TCryptoJenkins;
class PASCALIMPLEMENTATION TCryptoJenkins : public TCryptoHash
{
	typedef TCryptoHash inherited;
	
private:
	unsigned FState;
	
protected:
	virtual void __fastcall Finish(int LengthSize, bool Straight);
	virtual void __fastcall Process(System::Byte const *Chunk, const int Chunk_Size);
	
public:
	__fastcall TCryptoJenkins(void);
	virtual void __fastcall GetDigest(/* out */ void *Digest, int Size);
	virtual void __fastcall Reset(void);
	virtual int __fastcall DigestSize(void);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TCryptoJenkins(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Frxcrypto */
using namespace Frxcrypto;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// FrxcryptoHPP
