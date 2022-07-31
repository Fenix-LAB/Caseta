// C2EjesDlg.cpp: archivo de implementación
//

#include "pch.h"
#include "Caseta.h"
#include "C2EjesDlg.h"
#include "afxdialogex.h"


// Cuadro de diálogo de C2EjesDlg

IMPLEMENT_DYNAMIC(C2EjesDlg, CDialogEx)

C2EjesDlg::C2EjesDlg(CWnd* pParent /*= nullptr*/)
	: CDialogEx(IDD_DLD_EJES2, pParent)
	, m_pago(0)
	, m_cambio(0)
{

}

C2EjesDlg::~C2EjesDlg()
{
}

void C2EjesDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_pago);
	DDX_Text(pDX, IDC_EDIT2, m_cambio);
}


BEGIN_MESSAGE_MAP(C2EjesDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_OK, &C2EjesDlg::OnBnClickedBtnOk)
END_MESSAGE_MAP()


// Controladores de mensajes de C2EjesDlg


void C2EjesDlg::OnBnClickedBtnOk()
{
	int aux;
	UpdateData(true);
	aux = m_pago - 50;
	m_cambio = aux;
	UpdateData(false);
}
