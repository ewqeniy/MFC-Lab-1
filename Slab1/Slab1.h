
// Slab1.h : главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CSlab1App:
// О реализации данного класса см. Slab1.cpp
//

class CSlab1App : public CWinApp
{
public:
	CSlab1App();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CSlab1App theApp;