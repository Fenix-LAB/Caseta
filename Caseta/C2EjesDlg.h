#pragma once


// Cuadro de diálogo de C2EjesDlg

class C2EjesDlg : public CDialogEx
{
	DECLARE_DYNAMIC(C2EjesDlg)

public:
	C2EjesDlg(CWnd* pParent = nullptr);   // Constructor estándar
	virtual ~C2EjesDlg();

// Datos del cuadro de diálogo
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLD_EJES2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Compatibilidad con DDX/DDV

	DECLARE_MESSAGE_MAP()
private:
	int m_pago;
	int m_cambio;
public:
	afx_msg void OnBnClickedBtnOk();
};
