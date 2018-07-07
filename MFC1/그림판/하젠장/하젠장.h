
// ÇÏÁ¨Àå.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CÇÏÁ¨ÀåApp:
// See ÇÏÁ¨Àå.cpp for the implementation of this class
//

class CÇÏÁ¨ÀåApp : public CWinApp
{
public:
	CÇÏÁ¨ÀåApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CÇÏÁ¨ÀåApp theApp;