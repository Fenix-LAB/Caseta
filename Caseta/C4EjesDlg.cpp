// C4EjesDlg.cpp: archivo de implementación
//

#include "pch.h"
#include "Caseta.h"
#include "C4EjesDlg.h"
#include "afxdialogex.h"


// Cuadro de diálogo de C4EjesDlg

IMPLEMENT_DYNAMIC(C4EjesDlg, CDialogEx)

C4EjesDlg::C4EjesDlg(CWnd* pParent /*= nullptr*/)
	: CDialogEx(IDD_DLG_4EJES, pParent)
	, m_pago(0)
	, m_cambio(0)
{

}

C4EjesDlg::~C4EjesDlg()
{
}

void C4EjesDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDT_PAGO, m_pago);
	DDX_Text(pDX, IDC_EDT_CAMBIO, m_cambio);
}


BEGIN_MESSAGE_MAP(C4EjesDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_CAMBIO, &C4EjesDlg::OnBnClickedBtnCambio)
END_MESSAGE_MAP()


// Controladores de mensajes de C4EjesDlg


void C4EjesDlg::OnBnClickedBtnCambio()
{
	int aux;
	UpdateData(true);
	aux = m_pago - 100;
	m_cambio = aux;
	UpdateData(false);
}
