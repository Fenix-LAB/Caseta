
// CasetaDlg.cpp: archivo de implementación
//

#include "pch.h"
#include "framework.h"
#include "Caseta.h"
#include "CasetaDlg.h"
#include "afxdialogex.h"

#include "CEsp32.h";
#include "C2EjesDlg.h";
#include "C3EjesDlg.h";
#include "C4EjesDlg.h";

CEsp32 Pluma;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cuadro de diálogo CAboutDlg utilizado para el comando Acerca de

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Datos del cuadro de diálogo
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Compatibilidad con DDX/DDV

// Implementación
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Cuadro de diálogo de CCasetaDlg



CCasetaDlg::CCasetaDlg(CWnd* pParent /*= nullptr*/)
	: CDialogEx(IDD_CASETA_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCasetaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCasetaDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_UP, &CCasetaDlg::OnBnClickedBtnUp)
	ON_BN_CLICKED(IDC_BTN_DOWN, &CCasetaDlg::OnBnClickedBtnDown)
	ON_BN_CLICKED(IDC_BTN_2EJES, &CCasetaDlg::OnBnClickedBtn2ejes)
	ON_BN_CLICKED(IDC_BTN_3EJES, &CCasetaDlg::OnBnClickedBtn3ejes)
	ON_BN_CLICKED(IDC_BTN_4EJES, &CCasetaDlg::OnBnClickedBtn4ejes)
END_MESSAGE_MAP()


// Controladores de mensajes de CCasetaDlg

BOOL CCasetaDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Agregar el elemento de menú "Acerca de..." al menú del sistema.

	// IDM_ABOUTBOX debe estar en el intervalo de comandos del sistema.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Establecer el icono para este cuadro de diálogo.  El marco de trabajo realiza esta operación
	//  automáticamente cuando la ventana principal de la aplicación no es un cuadro de diálogo
	SetIcon(m_hIcon, TRUE);			// Establecer icono grande
	SetIcon(m_hIcon, FALSE);		// Establecer icono pequeño

	// TODO: agregar aquí inicialización adicional

	return TRUE;  // Devuelve TRUE  a menos que establezca el foco en un control
}

void CCasetaDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// Si agrega un botón Minimizar al cuadro de diálogo, necesitará el siguiente código
//  para dibujar el icono.  Para aplicaciones MFC que utilicen el modelo de documentos y vistas,
//  esta operación la realiza automáticamente el marco de trabajo.

void CCasetaDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // Contexto de dispositivo para dibujo

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Centrar icono en el rectángulo de cliente
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Dibujar el icono
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// El sistema llama a esta función para obtener el cursor que se muestra mientras el usuario arrastra
// la ventana minimizada.

HCURSOR CCasetaDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCasetaDlg::OnBnClickedBtnUp()
{
	Pluma.SetServo(90);

	SetDlgItemText(IDC_EDT_PLUMA, _T("Se ha levantado la Pluma"));

	UpdateData(false);
}


void CCasetaDlg::OnBnClickedBtnDown()
{
	Pluma.SetServo(0);

	SetDlgItemText(IDC_EDT_PLUMA, _T("Se ha bajado la Pluma"));

	UpdateData(false);
}


void CCasetaDlg::OnBnClickedBtn2ejes()
{
	C2EjesDlg a;
	a.DoModal();
}


void CCasetaDlg::OnBnClickedBtn3ejes()
{
	C3EjesDlg b;
	b.DoModal();
}


void CCasetaDlg::OnBnClickedBtn4ejes()
{
	C4EjesDlg c;
	c.DoModal();
}