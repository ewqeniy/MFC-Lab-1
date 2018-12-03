
// Slab1Dlg.h : файл заголовка
//

#pragma once
#include "afxwin.h"


// диалоговое окно CSlab1Dlg
class CSlab1Dlg : public CDialogEx
{
// Создание
public:
	CSlab1Dlg(CWnd* pParent = NULL);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SLAB1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString textBox;
	afx_msg void showMessage();
	afx_msg void clearTextBox();
	afx_msg void setDefaultTextBox();
	CString ProcessList;
	afx_msg void runProcess();
	BOOL MsgEnable;
	afx_msg void enableMessage();
	CEdit m1;
	CButton m2;
	CButton m3;
	CButton m4;
	BOOL procEnable;
	afx_msg void procEnabled();
	CComboBox p1;
	CButton p2;
	BOOL mShow;
	BOOL pShow;
	CButton m5;
	afx_msg void OnBnClickedCheck3();
	afx_msg void OnBnClickedCheck4();
	CButton p3;
	CStatic text1;
	CStatic Text2;
	afx_msg void Exit();
};
