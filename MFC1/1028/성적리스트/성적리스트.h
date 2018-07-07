
// 己利府胶飘.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// C己利府胶飘App:
// See 己利府胶飘.cpp for the implementation of this class
//

class C己利府胶飘App : public CWinApp
{
public:
	C己利府胶飘App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()

};

extern C己利府胶飘App theApp;