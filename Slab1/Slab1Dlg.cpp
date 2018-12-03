
// Slab1Dlg.cpp : файл реализации
//

#include "stdafx.h"
#include "Slab1.h"
#include "Slab1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// диалоговое окно CSlab1Dlg



CSlab1Dlg::CSlab1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SLAB1_DIALOG, pParent)
	, textBox(_T(""))
	, ProcessList(_T(""))
	, MsgEnable(FALSE)
	, procEnable(FALSE)
	, mShow(FALSE)
	, pShow(FALSE)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSlab1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, textBox);
	DDX_CBString(pDX, IDC_COMBO1, ProcessList);
	DDX_Check(pDX, IDC_CHECK1, MsgEnable);
	DDX_Control(pDX, IDC_EDIT1, m1);
	DDX_Control(pDX, IDC_BUTTON1, m2);
	DDX_Control(pDX, IDC_BUTTON2, m3);
	DDX_Control(pDX, IDC_BUTTON3, m4);
	DDX_Check(pDX, IDC_CHECK2, procEnable);
	DDX_Control(pDX, IDC_COMBO1, p1);
	DDX_Control(pDX, IDC_BUTTON4, p2);
	DDX_Check(pDX, IDC_CHECK3, mShow);
	DDX_Check(pDX, IDC_CHECK4, pShow);
	DDX_Control(pDX, IDC_CHECK1, m5);
	DDX_Control(pDX, IDC_CHECK2, p3);
	//DDX_Control(pDX, text1, text1);
	//DDX_Control(pDX, text2, Text2);
}

BEGIN_MESSAGE_MAP(CSlab1Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CSlab1Dlg::showMessage)
	ON_BN_CLICKED(IDC_BUTTON3, &CSlab1Dlg::clearTextBox)
	ON_BN_CLICKED(IDC_BUTTON2, &CSlab1Dlg::setDefaultTextBox)
	ON_BN_CLICKED(IDC_BUTTON4, &CSlab1Dlg::runProcess)
	ON_BN_CLICKED(IDC_CHECK1, &CSlab1Dlg::enableMessage)
	ON_BN_CLICKED(IDC_CHECK2, &CSlab1Dlg::procEnabled)
	ON_BN_CLICKED(IDC_CHECK3, &CSlab1Dlg::OnBnClickedCheck3)
	ON_BN_CLICKED(IDC_CHECK4, &CSlab1Dlg::OnBnClickedCheck4)
	ON_BN_CLICKED(IDC_BUTTON5, &CSlab1Dlg::Exit)
END_MESSAGE_MAP()


// обработчики сообщений CSlab1Dlg

BOOL CSlab1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию

	textBox = "Place a message here";
	MsgEnable = true;
	procEnable = true;
	mShow = true;
	pShow = true;
	UpdateData(FALSE);

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CSlab1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CSlab1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSlab1Dlg::showMessage()
{
	UpdateData(TRUE);
	MessageBox(textBox, L"C++", MB_OK);
}


void CSlab1Dlg::clearTextBox()
{
	textBox = "";
	UpdateData(FALSE);
}


void CSlab1Dlg::setDefaultTextBox()
{
	textBox = "Enter a message here.";
	UpdateData(FALSE);
}


void CSlab1Dlg::runProcess()
{
	UpdateData(TRUE);
	ShellExecute(NULL, L"open", ProcessList, NULL, NULL, SW_SHOWNORMAL);
}


void CSlab1Dlg::enableMessage()
{
	UpdateData(TRUE);
	if (!MsgEnable) {
		m1.EnableWindow(false);
		m2.EnableWindow(false);
		m3.EnableWindow(false);
		m4.EnableWindow(false);
	}
	else
	{
		m1.EnableWindow(true);
		m2.EnableWindow(true);
		m3.EnableWindow(true);
		m4.EnableWindow(true);
	}
}


void CSlab1Dlg::procEnabled()
{
	UpdateData(TRUE);
	if (!procEnable) {
		p1.EnableWindow(false);
		p2.EnableWindow(false);
	}
	else
	{
		p1.EnableWindow(true);
		p2.EnableWindow(true);
	}
}


void CSlab1Dlg::OnBnClickedCheck3()
{
	UpdateData(TRUE);
	if (!mShow) {
		m1.ShowWindow(SW_HIDE);
		m2.ShowWindow(SW_HIDE);
		m3.ShowWindow(SW_HIDE);
		m4.ShowWindow(SW_HIDE);
		m5.ShowWindow(SW_HIDE);
		CWnd* pWnd = GetDlgItem(IDC_STATIC_ONE);
		pWnd->ShowWindow(SW_HIDE);
	}
	else
	{
		m1.ShowWindow(SW_SHOW);
		m2.ShowWindow(SW_SHOW);
		m3.ShowWindow(SW_SHOW);
		m4.ShowWindow(SW_SHOW);
		m5.ShowWindow(SW_SHOW);
		CWnd* pWnd = GetDlgItem(IDC_STATIC_ONE);
		pWnd->ShowWindow(SW_SHOW);
	}
}


void CSlab1Dlg::OnBnClickedCheck4()
{
	UpdateData(TRUE);
	if (!pShow) {
		p1.ShowWindow(SW_HIDE);
		p2.ShowWindow(SW_HIDE);
		p3.ShowWindow(SW_HIDE);
		CWnd* pWnd = GetDlgItem(IDC_STATIC_TWO);
		pWnd->ShowWindow(SW_HIDE);
	}
	else
	{
		p1.ShowWindow(SW_SHOW);
		p2.ShowWindow(SW_SHOW);
		p3.ShowWindow(SW_SHOW);
		CWnd* pWnd = GetDlgItem(IDC_STATIC_TWO);
		pWnd->ShowWindow(SW_SHOW);
	}
}


void CSlab1Dlg::Exit()
{
	PostQuitMessage(0);
}
