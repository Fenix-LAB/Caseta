#pragma once


// Cuadro de diálogo de C3EjesDlg

class C3EjesDlg : public CDialogEx
{
	DECLARE_DYNAMIC(C3EjesDlg)

public:
	C3EjesDlg(CWnd* pParent = nullptr);   // Constructor estándar
	virtual ~C3EjesDlg();

// Datos del cuadro de diálogo
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_3EJES };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Compatibilidad con DDX/DDV

	DECLARE_MESSAGE_MAP()
private:
	int m_pago;
	int m_cambio;
public:
	afx_msg void OnBnClickedBtnCambio();
};
