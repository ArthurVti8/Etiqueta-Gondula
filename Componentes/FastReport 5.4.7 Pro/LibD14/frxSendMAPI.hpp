// CodeGear C++Builder
// Copyright (c) 1995, 2009 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Frxsendmapi.pas' rev: 21.00

#ifndef FrxsendmapiHPP
#define FrxsendmapiHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Frxsendmapi
{
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TMapiErrEvent)(System::TObject* Sender, int ErrCode);

class DELPHICLASS TMapiControl;
class PASCALIMPLEMENTATION TMapiControl : public Classes::TComponent
{
	typedef Classes::TComponent inherited;
	
__published:
	__fastcall virtual TMapiControl(Classes::TComponent* AOwner);
	__fastcall virtual ~TMapiControl(void);
	
private:
	System::UnicodeString FSubject;
	System::UnicodeString FMailtext;
	System::UnicodeString FFromName;
	System::UnicodeString FFromAdress;
	Classes::TStrings* FTOAdr;
	Classes::TStrings* FCCAdr;
	Classes::TStrings* FBCCAdr;
	Classes::TStrings* FAttachedFileName;
	bool FShowDialog;
	bool FUseAppHandle;
	Classes::TNotifyEvent FOnUserAbort;
	TMapiErrEvent FOnMapiError;
	Classes::TNotifyEvent FOnSuccess;
	void __fastcall SetToAddr(Classes::TStrings* newValue);
	void __fastcall SetCCAddr(Classes::TStrings* newValue);
	void __fastcall SetBCCAddr(Classes::TStrings* newValue);
	void __fastcall SetAttachedFileName(Classes::TStrings* newValue);
	
public:
	unsigned ApplicationHandle;
	System::UnicodeString __fastcall Sendmail(System::UnicodeString User, System::UnicodeString Passwd);
	void __fastcall Reset(void);
	System::AnsiString __fastcall GetName(System::UnicodeString mailaddress);
	System::AnsiString __fastcall GetAddress(System::UnicodeString mailaddress);
	
__published:
	__property System::UnicodeString Subject = {read=FSubject, write=FSubject};
	__property System::UnicodeString Body = {read=FMailtext, write=FMailtext};
	__property System::UnicodeString FromName = {read=FFromName, write=FFromName};
	__property System::UnicodeString FromAdress = {read=FFromAdress, write=FFromAdress};
	__property Classes::TStrings* Recipients = {read=FTOAdr, write=SetToAddr};
	__property Classes::TStrings* CopyTo = {read=FCCAdr, write=SetCCAddr};
	__property Classes::TStrings* BlindCopyTo = {read=FBCCAdr, write=SetBCCAddr};
	__property Classes::TStrings* AttachedFiles = {read=FAttachedFileName, write=SetAttachedFileName};
	__property bool ShowDialog = {read=FShowDialog, write=FShowDialog, nodefault};
	__property bool UseAppHandle = {read=FUseAppHandle, write=FUseAppHandle, nodefault};
	__property Classes::TNotifyEvent OnUserAbort = {read=FOnUserAbort, write=FOnUserAbort};
	__property TMapiErrEvent OnMapiError = {read=FOnMapiError, write=FOnMapiError};
	__property Classes::TNotifyEvent OnSuccess = {read=FOnSuccess, write=FOnSuccess};
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Frxsendmapi */
using namespace Frxsendmapi;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// FrxsendmapiHPP
