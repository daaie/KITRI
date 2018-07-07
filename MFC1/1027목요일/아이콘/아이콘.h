
// 아이콘.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// C아이콘App:
// See 아이콘.cpp for the implementation of this class
//

class C아이콘App : public CWinApp
{
public:
	C아이콘App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern C아이콘App theApp;