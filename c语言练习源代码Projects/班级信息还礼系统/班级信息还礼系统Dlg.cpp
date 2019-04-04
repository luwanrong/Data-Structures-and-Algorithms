// �༶��Ϣ����ϵͳDlg.cpp : implementation file
//

#include "stdafx.h"
#include "�༶��Ϣ����ϵͳ.h"
#include "�༶��Ϣ����ϵͳDlg.h"
#include "InputDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CString strInput;

#define N 100   //�������

struct stu_info
{
	char xh[15]; //ѧ��
	char xm[7];  //����
	char xb[3];  //�Ա�
	int nl;      //����
};
struct stu_info stu[N+1];//���ڴ�������������Ϣ��0��Ԫ�ر���
int CurrentCount=0;      //��ǰʵ������
int intWz=0;             //����ָʾ��ǰλ�ã�Ԫ�ر�ţ�
bool boolXgOrTj;         //������޸Ļ�����ӣ�TRUE:�޸� FALSE:���


/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyDlg dialog

CMyDlg::CMyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMyDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMyDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMyDlg, CDialog)
	//{{AFX_MSG_MAP(CMyDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_TC, OnButtonTc)
	ON_BN_CLICKED(IDC_BUTTON_TJ, OnButtonTj)
	ON_BN_CLICKED(IDC_BUTTON_XG, OnButtonXg)
	ON_BN_CLICKED(IDC_BUTTON_QD, OnButtonQd)
	ON_BN_CLICKED(IDC_BUTTON_QX, OnButtonQx)
	ON_BN_CLICKED(IDC_BUTTON_SYG, OnButtonSyg)
	ON_BN_CLICKED(IDC_BUTTON_XYG, OnButtonXyg)
	ON_BN_CLICKED(IDC_BUTTON_DYG, OnButtonDyg)
	ON_BN_CLICKED(IDC_BUTTON_MYG, OnButtonMyg)
	ON_BN_CLICKED(IDC_BUTTON_SC, OnButtonSc)
	ON_COMMAND(ID_APP_EXIT, OnAppExit)
	ON_COMMAND(ID_FILE_SAVE, OnFileSave)
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	ON_BN_CLICKED(IDC_BUTTON_CX, OnButtonCx)
	ON_EN_KILLFOCUS(IDC_EDIT_XH, OnKillfocusEditXh)
	ON_EN_KILLFOCUS(IDC_EDIT_XB, OnKillfocusEditXb)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyDlg message handlers

BOOL CMyDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMyDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMyDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMyDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMyDlg::OnButtonTc() 
{
	// TODO: Add your control notification handler code here
	EndDialog(NULL);
}

void CMyDlg::OnButtonTj() 
{
	// TODO: Add your control notification handler code here
	CButton * cBtnSyg=(CButton *)GetDlgItem(IDC_BUTTON_SYG); //��һ����ť
	CButton * cBtnXyg=(CButton *)GetDlgItem(IDC_BUTTON_XYG); //��һ����ť
	CButton * cBtnDyg=(CButton *)GetDlgItem(IDC_BUTTON_DYG); //��һ����ť
	CButton * cBtnMyg=(CButton *)GetDlgItem(IDC_BUTTON_MYG); //ĩһ����ť
	CButton * cBtnTj=(CButton *)GetDlgItem(IDC_BUTTON_TJ);   //��Ӱ�ť
	CButton * cBtnXg=(CButton *)GetDlgItem(IDC_BUTTON_XG);   //�޸İ�ť
	CButton * cBtnQd=(CButton *)GetDlgItem(IDC_BUTTON_QD);   //ȷ����ť
	CButton * cBtnQx=(CButton *)GetDlgItem(IDC_BUTTON_QX);   //ȡ����ť
	CButton * cBtnSc=(CButton *)GetDlgItem(IDC_BUTTON_SC);   //ɾ����ť
	CButton * cBtnCx=(CButton *)GetDlgItem(IDC_BUTTON_CX);   //��ѯ��ť
	CButton * cBtnTc=(CButton *)GetDlgItem(IDC_BUTTON_TC);   //�˳���ť
	
	CEdit * cEdtXh=(CEdit *)GetDlgItem(IDC_EDIT_XH);//ѧ�ű༭��
	CEdit * cEdtXm=(CEdit *)GetDlgItem(IDC_EDIT_XM);//�����༭��
	CEdit * cEdtXb=(CEdit *)GetDlgItem(IDC_EDIT_XB);//�Ա�༭��
	CEdit * cEdtNl=(CEdit *)GetDlgItem(IDC_EDIT_NL);//����༭��
	
	cBtnSyg->EnableWindow(FALSE);
	cBtnXyg->EnableWindow(FALSE);
	cBtnDyg->EnableWindow(FALSE);
	cBtnMyg->EnableWindow(FALSE);
	cBtnTj->EnableWindow(FALSE);
	cBtnXg->EnableWindow(FALSE);
	cBtnQd->EnableWindow(TRUE);
	cBtnQx->EnableWindow(TRUE);
	cBtnSc->EnableWindow(FALSE);
	cBtnCx->EnableWindow(FALSE);
	cBtnTc->EnableWindow(FALSE);
	
	cEdtXh->EnableWindow(TRUE);
	cEdtXm->EnableWindow(TRUE);
	cEdtXb->EnableWindow(TRUE);
	cEdtNl->EnableWindow(TRUE);
	
	cEdtXh->SetFocus();
	boolXgOrTj=FALSE;

}

void CMyDlg::OnButtonXg() 
{
	// TODO: Add your control notification handler code here
	if(intWz<1 || intWz>CurrentCount)
		MessageBox("��ǰ������Ч���ݣ������޸ģ�����","�޸���Ϣ");
	else
	{
		CButton * cBtnSyg=(CButton *)GetDlgItem(IDC_BUTTON_SYG); //��һ����ť
		CButton * cBtnXyg=(CButton *)GetDlgItem(IDC_BUTTON_XYG); //��һ����ť
		CButton * cBtnDyg=(CButton *)GetDlgItem(IDC_BUTTON_DYG); //��һ����ť
		CButton * cBtnMyg=(CButton *)GetDlgItem(IDC_BUTTON_MYG); //ĩһ����ť
		CButton * cBtnTj=(CButton *)GetDlgItem(IDC_BUTTON_TJ);   //��Ӱ�ť
		CButton * cBtnXg=(CButton *)GetDlgItem(IDC_BUTTON_XG);   //�޸İ�ť
		CButton * cBtnQd=(CButton *)GetDlgItem(IDC_BUTTON_QD);   //ȷ����ť
		CButton * cBtnQx=(CButton *)GetDlgItem(IDC_BUTTON_QX);   //ȡ����ť
		CButton * cBtnSc=(CButton *)GetDlgItem(IDC_BUTTON_SC);   //ɾ����ť
		CButton * cBtnCx=(CButton *)GetDlgItem(IDC_BUTTON_CX);   //��ѯ��ť
		CButton * cBtnTc=(CButton *)GetDlgItem(IDC_BUTTON_TC);   //�˳���ť
		
		CEdit * cEdtXh=(CEdit *)GetDlgItem(IDC_EDIT_XH);//ѧ�ű༭��
		CEdit * cEdtXm=(CEdit *)GetDlgItem(IDC_EDIT_XM);//�����༭��
		CEdit * cEdtXb=(CEdit *)GetDlgItem(IDC_EDIT_XB);//�Ա�༭��
		CEdit * cEdtNl=(CEdit *)GetDlgItem(IDC_EDIT_NL);//����༭��
		
		cBtnSyg->EnableWindow(FALSE);
		cBtnXyg->EnableWindow(FALSE);
		cBtnDyg->EnableWindow(FALSE);
		cBtnMyg->EnableWindow(FALSE);
		cBtnTj->EnableWindow(FALSE);
		cBtnXg->EnableWindow(FALSE);
		cBtnQd->EnableWindow(TRUE);
		cBtnQx->EnableWindow(TRUE);
		cBtnSc->EnableWindow(FALSE);
		cBtnCx->EnableWindow(FALSE);
		cBtnTc->EnableWindow(FALSE);
		
		cEdtXh->EnableWindow(TRUE);
		cEdtXm->EnableWindow(TRUE);
		cEdtXb->EnableWindow(TRUE);
		cEdtNl->EnableWindow(TRUE);
		
		cEdtXh->SetFocus();
		boolXgOrTj=TRUE;
	}

}

void CMyDlg::OnButtonQd() 
{
	// TODO: Add your control notification handler code here
	CButton * cBtnSyg=(CButton *)GetDlgItem(IDC_BUTTON_SYG); //��һ����ť
	CButton * cBtnXyg=(CButton *)GetDlgItem(IDC_BUTTON_XYG); //��һ����ť
	CButton * cBtnDyg=(CButton *)GetDlgItem(IDC_BUTTON_DYG); //��һ����ť
	CButton * cBtnMyg=(CButton *)GetDlgItem(IDC_BUTTON_MYG); //ĩһ����ť
	CButton * cBtnTj=(CButton *)GetDlgItem(IDC_BUTTON_TJ);   //��Ӱ�ť
	CButton * cBtnXg=(CButton *)GetDlgItem(IDC_BUTTON_XG);   //�޸İ�ť
	CButton * cBtnQd=(CButton *)GetDlgItem(IDC_BUTTON_QD);   //ȷ����ť
	CButton * cBtnQx=(CButton *)GetDlgItem(IDC_BUTTON_QX);   //ȡ����ť
	CButton * cBtnSc=(CButton *)GetDlgItem(IDC_BUTTON_SC);   //ɾ����ť
	CButton * cBtnCx=(CButton *)GetDlgItem(IDC_BUTTON_CX);   //��ѯ��ť
	CButton * cBtnTc=(CButton *)GetDlgItem(IDC_BUTTON_TC);   //�˳���ť
	
	CEdit * cEdtXh=(CEdit *)GetDlgItem(IDC_EDIT_XH);//ѧ�ű༭��
	CEdit * cEdtXm=(CEdit *)GetDlgItem(IDC_EDIT_XM);//�����༭��
	CEdit * cEdtXb=(CEdit *)GetDlgItem(IDC_EDIT_XB);//�Ա�༭��
	CEdit * cEdtNl=(CEdit *)GetDlgItem(IDC_EDIT_NL);//����༭��
	
	cBtnSyg->EnableWindow(TRUE);
	cBtnXyg->EnableWindow(TRUE);
	cBtnDyg->EnableWindow(TRUE);
	cBtnMyg->EnableWindow(TRUE);
	cBtnTj->EnableWindow(TRUE);
	cBtnXg->EnableWindow(TRUE);
	cBtnQd->EnableWindow(FALSE);
	cBtnQx->EnableWindow(FALSE);
	cBtnSc->EnableWindow(TRUE);
	cBtnCx->EnableWindow(TRUE);
	cBtnTc->EnableWindow(TRUE);
	
	cEdtXh->EnableWindow(FALSE);
	cEdtXm->EnableWindow(FALSE);
	cEdtXb->EnableWindow(FALSE);
	cEdtNl->EnableWindow(FALSE);
	
	if(boolXgOrTj==FALSE)//��������������
	{
		if(CurrentCount==N)
			MessageBox("�����Ѵ����ޣ���������ӣ�����","�����Ϣ");
		else
		{
			CString strTemp;
			CurrentCount++;
			intWz=CurrentCount;
			cEdtXh->GetWindowText(stu[CurrentCount].xh,14);
			cEdtXm->GetWindowText(stu[CurrentCount].xm,8);
			cEdtXb->GetWindowText(stu[CurrentCount].xb,4);
			cEdtNl->GetWindowText(strTemp);
			stu[CurrentCount].nl=atoi(strTemp);
		}
		cBtnTj->SetFocus();
	}
	else//�����޸��������
	{
		CString strTemp;
		cEdtXh->GetWindowText(stu[intWz].xh,14);
		cEdtXm->GetWindowText(stu[intWz].xm,8);
		cEdtXb->GetWindowText(stu[intWz].xb,4);
		cEdtNl->GetWindowText(strTemp);
		stu[intWz].nl=atoi(strTemp);
		cBtnXg->SetFocus();
	}

}

void CMyDlg::OnButtonQx() 
{
	// TODO: Add your control notification handler code here
	CButton * cBtnSyg=(CButton *)GetDlgItem(IDC_BUTTON_SYG); //��һ����ť
	CButton * cBtnXyg=(CButton *)GetDlgItem(IDC_BUTTON_XYG); //��һ����ť
	CButton * cBtnDyg=(CButton *)GetDlgItem(IDC_BUTTON_DYG); //��һ����ť
	CButton * cBtnMyg=(CButton *)GetDlgItem(IDC_BUTTON_MYG); //ĩһ����ť
	CButton * cBtnTj=(CButton *)GetDlgItem(IDC_BUTTON_TJ);   //��Ӱ�ť
	CButton * cBtnXg=(CButton *)GetDlgItem(IDC_BUTTON_XG);   //�޸İ�ť
	CButton * cBtnQd=(CButton *)GetDlgItem(IDC_BUTTON_QD);   //ȷ����ť
	CButton * cBtnQx=(CButton *)GetDlgItem(IDC_BUTTON_QX);   //ȡ����ť
	CButton * cBtnSc=(CButton *)GetDlgItem(IDC_BUTTON_SC);   //ɾ����ť
	CButton * cBtnCx=(CButton *)GetDlgItem(IDC_BUTTON_CX);   //��ѯ��ť
	CButton * cBtnTc=(CButton *)GetDlgItem(IDC_BUTTON_TC);   //�˳���ť
	
	CEdit * cEdtXh=(CEdit *)GetDlgItem(IDC_EDIT_XH);//ѧ�ű༭��
	CEdit * cEdtXm=(CEdit *)GetDlgItem(IDC_EDIT_XM);//�����༭��
	CEdit * cEdtXb=(CEdit *)GetDlgItem(IDC_EDIT_XB);//�Ա�༭��
	CEdit * cEdtNl=(CEdit *)GetDlgItem(IDC_EDIT_NL);//����༭��
	
	cBtnSyg->EnableWindow(TRUE);
	cBtnXyg->EnableWindow(TRUE);
	cBtnDyg->EnableWindow(TRUE);
	cBtnMyg->EnableWindow(TRUE);
	cBtnTj->EnableWindow(TRUE);
	cBtnXg->EnableWindow(TRUE);
	cBtnQd->EnableWindow(FALSE);
	cBtnQx->EnableWindow(FALSE);
	cBtnSc->EnableWindow(TRUE);
	cBtnCx->EnableWindow(TRUE);
	cBtnTc->EnableWindow(TRUE);
	
	cEdtXh->EnableWindow(FALSE);
	cEdtXm->EnableWindow(FALSE);
	cEdtXb->EnableWindow(FALSE);
	cEdtNl->EnableWindow(FALSE);
	
	if(boolXgOrTj==FALSE)//��������������
		cBtnTj->SetFocus();
	else//�����޸��������
		cBtnXg->SetFocus();

}

void CMyDlg::OnButtonSyg() 
{
	// TODO: Add your control notification handler code here
	CEdit * cEdtXh=(CEdit *)GetDlgItem(IDC_EDIT_XH);//ѧ�ű༭��
	CEdit * cEdtXm=(CEdit *)GetDlgItem(IDC_EDIT_XM);//�����༭��
	CEdit * cEdtXb=(CEdit *)GetDlgItem(IDC_EDIT_XB);//�Ա�༭��
	CEdit * cEdtNl=(CEdit *)GetDlgItem(IDC_EDIT_NL);//����༭��
	
	if(CurrentCount<1)
		MessageBox("����Ϣ�ɹ��鿴������","�鿴��Ϣ");
	else
	{
		if(intWz<=1)
			intWz=CurrentCount;
		else
			intWz--;
		cEdtXh->SetWindowText(stu[intWz].xh);
		cEdtXm->SetWindowText(stu[intWz].xm);
		cEdtXb->SetWindowText(stu[intWz].xb);
		CString strTemp;
		strTemp.Format("%d",stu[intWz].nl);
		cEdtNl->SetWindowText(strTemp);
	}

}

void CMyDlg::OnButtonXyg() 
{
	// TODO: Add your control notification handler code here
	CEdit * cEdtXh=(CEdit *)GetDlgItem(IDC_EDIT_XH);//ѧ�ű༭��
	CEdit * cEdtXm=(CEdit *)GetDlgItem(IDC_EDIT_XM);//�����༭��
	CEdit * cEdtXb=(CEdit *)GetDlgItem(IDC_EDIT_XB);//�Ա�༭��
	CEdit * cEdtNl=(CEdit *)GetDlgItem(IDC_EDIT_NL);//����༭��
	
	if(CurrentCount<1)
		MessageBox("����Ϣ�ɹ��鿴������","�鿴��Ϣ");
	else
	{
		if(intWz>=CurrentCount)
			intWz=1;
		else
			intWz++;
		cEdtXh->SetWindowText(stu[intWz].xh);
		cEdtXm->SetWindowText(stu[intWz].xm);
		cEdtXb->SetWindowText(stu[intWz].xb);
		CString strTemp;
		strTemp.Format("%d",stu[intWz].nl);
		cEdtNl->SetWindowText(strTemp);
	}

}

void CMyDlg::OnButtonDyg() 
{
	// TODO: Add your control notification handler code here
	CEdit * cEdtXh=(CEdit *)GetDlgItem(IDC_EDIT_XH);//ѧ�ű༭��
	CEdit * cEdtXm=(CEdit *)GetDlgItem(IDC_EDIT_XM);//�����༭��
	CEdit * cEdtXb=(CEdit *)GetDlgItem(IDC_EDIT_XB);//�Ա�༭��
	CEdit * cEdtNl=(CEdit *)GetDlgItem(IDC_EDIT_NL);//����༭��
	
	if(CurrentCount<1)
		MessageBox("����Ϣ�ɹ��鿴������","�鿴��Ϣ");
	else
	{
		intWz=1;
		cEdtXh->SetWindowText(stu[intWz].xh);
		cEdtXm->SetWindowText(stu[intWz].xm);
		cEdtXb->SetWindowText(stu[intWz].xb);
		CString strTemp;
		strTemp.Format("%d",stu[intWz].nl);
		cEdtNl->SetWindowText(strTemp);
	}

}

void CMyDlg::OnButtonMyg() 
{
	// TODO: Add your control notification handler code here
	CEdit * cEdtXh=(CEdit *)GetDlgItem(IDC_EDIT_XH);//ѧ�ű༭��
	CEdit * cEdtXm=(CEdit *)GetDlgItem(IDC_EDIT_XM);//�����༭��
	CEdit * cEdtXb=(CEdit *)GetDlgItem(IDC_EDIT_XB);//�Ա�༭��
	CEdit * cEdtNl=(CEdit *)GetDlgItem(IDC_EDIT_NL);//����༭��
	
	if(CurrentCount<1)
		MessageBox("����Ϣ�ɹ��鿴������","�鿴��Ϣ");
	else
	{
		intWz=CurrentCount;
		cEdtXh->SetWindowText(stu[intWz].xh);
		cEdtXm->SetWindowText(stu[intWz].xm);
		cEdtXb->SetWindowText(stu[intWz].xb);
		CString strTemp;
		strTemp.Format("%d",stu[intWz].nl);
		cEdtNl->SetWindowText(strTemp);
	}

}

void CMyDlg::OnButtonSc() 
{
	// TODO: Add your control notification handler code here
	if(intWz<1 || intWz>CurrentCount)
		MessageBox("��ǰ������Ч���ݣ�����ɾ��������","ɾ����Ϣ");
	else
		if(MessageBox("ȷ��Ҫɾ����","ɾ����Ϣ",MB_ICONQUESTION|MB_YESNO)==IDYES)
		{
			//��������ɾ��
			for(int i=intWz+1;i<=CurrentCount;i++)
				stu[i-1]=stu[i];
			CurrentCount--;
			MessageBox("�ѳɹ�ɾ����","ɾ����Ϣ");

			//��ʾ��һ����¼��Ϣ
			CEdit * cEdtXh=(CEdit *)GetDlgItem(IDC_EDIT_XH);//ѧ�ű༭��
			CEdit * cEdtXm=(CEdit *)GetDlgItem(IDC_EDIT_XM);//�����༭��
			CEdit * cEdtXb=(CEdit *)GetDlgItem(IDC_EDIT_XB);//�Ա�༭��
			CEdit * cEdtNl=(CEdit *)GetDlgItem(IDC_EDIT_NL);//����༭��
			
			if(CurrentCount>=1)//����ʣ����Ϣ�ɹ�����
			{
				if(intWz>=CurrentCount+1)//��ǰ�����һ��
					intWz=1;            //��ʾ��һ����Ϣ
				cEdtXh->SetWindowText(stu[intWz].xh);
				cEdtXm->SetWindowText(stu[intWz].xm);
				cEdtXb->SetWindowText(stu[intWz].xb);
				CString strTemp;
				strTemp.Format("%d",stu[intWz].nl);
				cEdtNl->SetWindowText(strTemp);
			}
			else
			{
				cEdtXh->SetWindowText("����Ա��Ϣ");
				cEdtXm->SetWindowText("");
				cEdtXb->SetWindowText("");
				CString strTemp;
				strTemp.Format("%s","");
				cEdtNl->SetWindowText(strTemp);
			}
		}

}

void CMyDlg::OnAppExit() 
{
	// TODO: Add your command handler code here
	EndDialog(NULL);
}

void CMyDlg::OnFileSave() 
{
	// TODO: Add your command handler code here
FILE *fp;
	unsigned char fileFilter[]= "�ı��ļ�(*.txt)|*.txt|�����ļ�(*.*)|*.*||";
	CFileDialog   dlgOpenFile(false,0,0,OFN_HIDEREADONLY|OFN_FILEMUSTEXIST,(LPCTSTR)fileFilter,NULL);
	if(dlgOpenFile.DoModal()==IDOK)
	{
		CString fileName=dlgOpenFile.GetPathName();
		fp=fopen(fileName,"w");
		if(fp==NULL)
			MessageBox("�ļ�����ʧ�ܣ��޷�������Ϣ������","��Ϣ����",MB_OK);
		else
		{
			fprintf(fp,"%d",CurrentCount);
			for(int i=1;i<=CurrentCount;i++)
				fprintf(fp,"\n%16s%8s%4s%4d",stu[i].xh,stu[i].xm,stu[i].xb,stu[i].nl);
			fclose(fp);
			MessageBox("��Ϣ�ѳɹ����棡����","��Ϣ����",MB_OK);
		}
	}


}

void CMyDlg::OnFileOpen() 
{
	// TODO: Add your command handler code here
FILE *fp;
	unsigned char fileFilter[]= "�ı��ļ�(*.txt)|*.txt|�����ļ�(*.*)|*.*||";
	CFileDialog   dlgOpenFile(true,0,0,OFN_HIDEREADONLY|OFN_FILEMUSTEXIST,(LPCTSTR)fileFilter,NULL);
	if(dlgOpenFile.DoModal()==IDOK)
	{
		CString fileName=dlgOpenFile.GetPathName();
		fp=fopen("bjxx.txt","r");
		if(fp==NULL)
			MessageBox("�ļ��򿪴����޷���ȡ��Ϣ������","��Ϣ��ȡ",MB_OK);
		else
		{
			fscanf(fp,"%d",&CurrentCount);
			for(int i=1;i<=CurrentCount;i++)
				fscanf(fp,"%s%s%s%d",stu[i].xh,stu[i].xm,stu[i].xb,&stu[i].nl);
			fclose(fp);
			MessageBox("��Ϣ�ѳɹ���ȡ������","��Ϣ��ȡ",MB_OK);
			CEdit * cEdtXh=(CEdit *)GetDlgItem(IDC_EDIT_XH);//ѧ�ű༭��
			CEdit * cEdtXm=(CEdit *)GetDlgItem(IDC_EDIT_XM);//�����༭��
			CEdit * cEdtXb=(CEdit *)GetDlgItem(IDC_EDIT_XB);//�Ա�༭��
			CEdit * cEdtNl=(CEdit *)GetDlgItem(IDC_EDIT_NL);//����༭��
			
			if(CurrentCount>=1)//����ʣ����Ϣ�ɹ�����
			{
				intWz=1;            //��ʾ��һ����Ϣ
				cEdtXh->SetWindowText(stu[intWz].xh);
				cEdtXm->SetWindowText(stu[intWz].xm);
				cEdtXb->SetWindowText(stu[intWz].xb);
				CString strTemp;
				strTemp.Format("%d",stu[intWz].nl);
				cEdtNl->SetWindowText(strTemp);
			}
			else
			{
				cEdtXh->SetWindowText("����Ա��Ϣ");
				cEdtXm->SetWindowText("");
				cEdtXb->SetWindowText("");
				CString strTemp;
				strTemp.Format("%s","");
				cEdtNl->SetWindowText(strTemp);
			}
		}
	}


}

void CMyDlg::OnAppAbout() 
{
	// TODO: Add your command handler code here
	CAboutDlg cDlg;
	cDlg.DoModal();

}

void CMyDlg::OnButtonCx() 
{
	// TODO: Add your control notification handler code here
	CInputDlg cInputDlg;
	cInputDlg.DoModal();
	if(strInput.GetLength()>0)//�еȲ���Ϣ
	{
		int i=0;
		CString strDcxx;
		
		CEdit * cEdtXh=(CEdit *)GetDlgItem(IDC_EDIT_XH);//ѧ�ű༭��
		CEdit * cEdtXm=(CEdit *)GetDlgItem(IDC_EDIT_XM);//�����༭��
		CEdit * cEdtXb=(CEdit *)GetDlgItem(IDC_EDIT_XB);//�Ա�༭��
		CEdit * cEdtNl=(CEdit *)GetDlgItem(IDC_EDIT_NL);//����༭��
		
		do
		{
			i++;
			strDcxx.Format("%s",stu[i].xh);
		}while((strInput.Compare(strDcxx)!=0) && (i<=CurrentCount));
		
		if(i<=CurrentCount)//�ҵ���
		{
			cEdtXh->SetWindowText(stu[i].xh);
			cEdtXm->SetWindowText(stu[i].xm);
			cEdtXb->SetWindowText(stu[i].xb);
			CString strTemp;
			strTemp.Format("%d",stu[i].nl);
			cEdtNl->SetWindowText(strTemp);
		}
		else//û�ҵ�
		{
			cEdtXh->SetWindowText("�Ҳ���");
			cEdtXm->SetWindowText("");
			cEdtXb->SetWindowText("");
			CString strTemp;
			strTemp.Format("%s","");
			cEdtNl->SetWindowText(strTemp);
		}
	}

}

void CMyDlg::OnKillfocusEditXh() 
{
	// TODO: Add your control notification handler code here
	CString strInput;
	CEdit * cEdtXh=(CEdit *)GetDlgItem(IDC_EDIT_XH);//ѧ�ű༭��
	cEdtXh->GetWindowText(strInput);
	if(strInput.GetLength()!=11)
		MessageBox("ѧ��λ�����ԣ������䣡����","��Ϣ����",MB_OK);

}

void CMyDlg::OnKillfocusEditXb() 
{
	// TODO: Add your control notification handler code here
	CString strNan;
	CString strNv;
	CString strInput;
	CEdit * cEdtXb=(CEdit *)GetDlgItem(IDC_EDIT_XB);//�Ա�༭��
	cEdtXb->GetWindowText(strInput);
	strNan.Format("��");
	strNv.Format("Ů");
	if((strInput.Compare(strNan)!=0)&&(strInput.Compare(strNv)!=0))
		MessageBox("�������Ϊ�л�Ů�������䣡����","��Ϣ����",MB_OK);

}
