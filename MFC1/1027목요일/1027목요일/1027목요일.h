
// 1027格夸老.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMy1027格夸老App:
// See 1027格夸老.cpp for the implementation of this class
//

class CMy1027格夸老App : public CWinApp
{
public:
	CMy1027格夸老App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMy1027格夸老App theApp;