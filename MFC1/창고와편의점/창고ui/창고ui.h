
// 창고ui.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// C창고uiApp:
// See 창고ui.cpp for the implementation of this class
//

class C창고uiApp : public CWinApp
{
public:
	C창고uiApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern C창고uiApp theApp;