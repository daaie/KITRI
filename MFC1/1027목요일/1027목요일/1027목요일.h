
// 1027�����.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMy1027�����App:
// See 1027�����.cpp for the implementation of this class
//

class CMy1027�����App : public CWinApp
{
public:
	CMy1027�����App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMy1027�����App theApp;