// C3EjesDlg.cpp: archivo de implementación
//

#include "pch.h"
#include "Caseta.h"
#include "C3EjesDlg.h"
#include "afxdialogex.h"


// Cuadro de diálogo de C3EjesDlg

IMPLEMENT_DYNAMIC(C3EjesDlg, CDialogEx)

C3EjesDlg::C3EjesDlg(CWnd* pParent /*= nullptr*/)
	: CDialogEx(IDD_DLG_3EJES, pParent)
	, m_pago(0)
	, m_cambio(0)
{

}

C3EjesDlg::~C3EjesDlg()
{
}

void C3EjesDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDT_PAGO, m_pago);
	DDX_Text(pDX, IDC_EDT_CAMBIO, m_cambio);
}


BEGIN_MESSAGE_MAP(C3EjesDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_CAMBIO, &C3EjesDlg::OnBnClickedBtnCambio)
END_MESSAGE_MAP()


// Controladores de mensajes de C3EjesDlg


void C3EjesDlg::OnBnClickedBtnCambio()
{
	int aux;
	UpdateData(true);
	aux = m_pago - 80;
	m_cambio = aux;
	UpdateData(false);
}
