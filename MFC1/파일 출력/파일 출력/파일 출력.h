
// 파일 출력.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// C파일출력App:
// See 파일 출력.cpp for the implementation of this class
//

class C파일출력App : public CWinApp
{
public:
	C파일출력App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern C파일출력App theApp;