
// HelloSdi.h : HelloSdi ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CHelloSdiApp:
// �� Ŭ������ ������ ���ؼ��� HelloSdi.cpp�� �����Ͻʽÿ�.
//

class CHelloSdiApp : public CWinApp
{
public:
	CHelloSdiApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
	virtual int Run();
};

extern CHelloSdiApp theApp;
