#pragma once


// Cuadro de diálogo de C4EjesDlg

class C4EjesDlg : public CDialogEx
{
	DECLARE_DYNAMIC(C4EjesDlg)

public:
	C4EjesDlg(CWnd* pParent = nullptr);   // Constructor estándar
	virtual ~C4EjesDlg();

// Datos del cuadro de diálogo
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_4EJES };
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
