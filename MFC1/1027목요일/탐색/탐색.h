
// Ž��.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CŽ��App:
// See Ž��.cpp for the implementation of this class
//

class CŽ��App : public CWinApp
{
public:
	CŽ��App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CŽ��App theApp;