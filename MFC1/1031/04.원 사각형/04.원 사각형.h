
// 04.�� �簢��.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMy04���簢��App:
// See 04.�� �簢��.cpp for the implementation of this class
//

class CMy04���簢��App : public CWinApp
{
public:
	CMy04���簢��App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMy04���簢��App theApp;