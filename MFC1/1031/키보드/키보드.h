
// 키보드.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// C키보드App:
// See 키보드.cpp for the implementation of this class
//

class C키보드App : public CWinApp
{
public:
	C키보드App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern C키보드App theApp;