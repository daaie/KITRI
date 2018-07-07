
// 메모장.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// C메모장App:
// See 메모장.cpp for the implementation of this class
//

class C메모장App : public CWinApp
{
public:
	C메모장App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern C메모장App theApp;