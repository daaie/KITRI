
// ������Ʈ.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// C������ƮApp:
// See ������Ʈ.cpp for the implementation of this class
//

class C������ƮApp : public CWinApp
{
public:
	C������ƮApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern C������ƮApp theApp;