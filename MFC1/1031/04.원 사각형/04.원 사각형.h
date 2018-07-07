
// 04.원 사각형.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMy04원사각형App:
// See 04.원 사각형.cpp for the implementation of this class
//

class CMy04원사각형App : public CWinApp
{
public:
	CMy04원사각형App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMy04원사각형App theApp;