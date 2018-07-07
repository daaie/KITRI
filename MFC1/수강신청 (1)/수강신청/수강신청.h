
// 수강신청.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// C수강신청App:
// See 수강신청.cpp for the implementation of this class
//

class C수강신청App : public CWinApp
{
public:
	C수강신청App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern C수강신청App theApp;