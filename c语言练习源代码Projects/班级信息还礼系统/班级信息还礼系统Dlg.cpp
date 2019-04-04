// 班级信息还礼系统Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "班级信息还礼系统.h"
#include "班级信息还礼系统Dlg.h"
#include "InputDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CString strInput;

#define N 100   //最大人数

struct stu_info
{
	char xh[15]; //学号
	char xm[7];  //姓名
	char xb[3];  //性别
	int nl;      //年龄
};
struct stu_info stu[N+1];//用于存放所有人相关信息，0号元素备用
int CurrentCount=0;      //当前实际人数
int intWz=0;             //用于指示当前位置（元素编号）
bool boolXgOrTj;         //标记是修改还是添加，TRUE:修改 FALSE:添加


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
	CButton * cBtnSyg=(CButton *)GetDlgItem(IDC_BUTTON_SYG); //上一个按钮
	CButton * cBtnXyg=(CButton *)GetDlgItem(IDC_BUTTON_XYG); //下一个按钮
	CButton * cBtnDyg=(CButton *)GetDlgItem(IDC_BUTTON_DYG); //第一个按钮
	CButton * cBtnMyg=(CButton *)GetDlgItem(IDC_BUTTON_MYG); //末一个按钮
	CButton * cBtnTj=(CButton *)GetDlgItem(IDC_BUTTON_TJ);   //添加按钮
	CButton * cBtnXg=(CButton *)GetDlgItem(IDC_BUTTON_XG);   //修改按钮
	CButton * cBtnQd=(CButton *)GetDlgItem(IDC_BUTTON_QD);   //确定按钮
	CButton * cBtnQx=(CButton *)GetDlgItem(IDC_BUTTON_QX);   //取消按钮
	CButton * cBtnSc=(CButton *)GetDlgItem(IDC_BUTTON_SC);   //删除按钮
	CButton * cBtnCx=(CButton *)GetDlgItem(IDC_BUTTON_CX);   //查询按钮
	CButton * cBtnTc=(CButton *)GetDlgItem(IDC_BUTTON_TC);   //退出按钮
	
	CEdit * cEdtXh=(CEdit *)GetDlgItem(IDC_EDIT_XH);//学号编辑框
	CEdit * cEdtXm=(CEdit *)GetDlgItem(IDC_EDIT_XM);//姓名编辑框
	CEdit * cEdtXb=(CEdit *)GetDlgItem(IDC_EDIT_XB);//性别编辑框
	CEdit * cEdtNl=(CEdit *)GetDlgItem(IDC_EDIT_NL);//年龄编辑框
	
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
		MessageBox("当前不是有效数据，不能修改！！！","修改信息");
	else
	{
		CButton * cBtnSyg=(CButton *)GetDlgItem(IDC_BUTTON_SYG); //上一个按钮
		CButton * cBtnXyg=(CButton *)GetDlgItem(IDC_BUTTON_XYG); //下一个按钮
		CButton * cBtnDyg=(CButton *)GetDlgItem(IDC_BUTTON_DYG); //第一个按钮
		CButton * cBtnMyg=(CButton *)GetDlgItem(IDC_BUTTON_MYG); //末一个按钮
		CButton * cBtnTj=(CButton *)GetDlgItem(IDC_BUTTON_TJ);   //添加按钮
		CButton * cBtnXg=(CButton *)GetDlgItem(IDC_BUTTON_XG);   //修改按钮
		CButton * cBtnQd=(CButton *)GetDlgItem(IDC_BUTTON_QD);   //确定按钮
		CButton * cBtnQx=(CButton *)GetDlgItem(IDC_BUTTON_QX);   //取消按钮
		CButton * cBtnSc=(CButton *)GetDlgItem(IDC_BUTTON_SC);   //删除按钮
		CButton * cBtnCx=(CButton *)GetDlgItem(IDC_BUTTON_CX);   //查询按钮
		CButton * cBtnTc=(CButton *)GetDlgItem(IDC_BUTTON_TC);   //退出按钮
		
		CEdit * cEdtXh=(CEdit *)GetDlgItem(IDC_EDIT_XH);//学号编辑框
		CEdit * cEdtXm=(CEdit *)GetDlgItem(IDC_EDIT_XM);//姓名编辑框
		CEdit * cEdtXb=(CEdit *)GetDlgItem(IDC_EDIT_XB);//性别编辑框
		CEdit * cEdtNl=(CEdit *)GetDlgItem(IDC_EDIT_NL);//年龄编辑框
		
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
	CButton * cBtnSyg=(CButton *)GetDlgItem(IDC_BUTTON_SYG); //上一个按钮
	CButton * cBtnXyg=(CButton *)GetDlgItem(IDC_BUTTON_XYG); //下一个按钮
	CButton * cBtnDyg=(CButton *)GetDlgItem(IDC_BUTTON_DYG); //第一个按钮
	CButton * cBtnMyg=(CButton *)GetDlgItem(IDC_BUTTON_MYG); //末一个按钮
	CButton * cBtnTj=(CButton *)GetDlgItem(IDC_BUTTON_TJ);   //添加按钮
	CButton * cBtnXg=(CButton *)GetDlgItem(IDC_BUTTON_XG);   //修改按钮
	CButton * cBtnQd=(CButton *)GetDlgItem(IDC_BUTTON_QD);   //确定按钮
	CButton * cBtnQx=(CButton *)GetDlgItem(IDC_BUTTON_QX);   //取消按钮
	CButton * cBtnSc=(CButton *)GetDlgItem(IDC_BUTTON_SC);   //删除按钮
	CButton * cBtnCx=(CButton *)GetDlgItem(IDC_BUTTON_CX);   //查询按钮
	CButton * cBtnTc=(CButton *)GetDlgItem(IDC_BUTTON_TC);   //退出按钮
	
	CEdit * cEdtXh=(CEdit *)GetDlgItem(IDC_EDIT_XH);//学号编辑框
	CEdit * cEdtXm=(CEdit *)GetDlgItem(IDC_EDIT_XM);//姓名编辑框
	CEdit * cEdtXb=(CEdit *)GetDlgItem(IDC_EDIT_XB);//性别编辑框
	CEdit * cEdtNl=(CEdit *)GetDlgItem(IDC_EDIT_NL);//年龄编辑框
	
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
	
	if(boolXgOrTj==FALSE)//属于添加这种情况
	{
		if(CurrentCount==N)
			MessageBox("人数已达上限，不能再添加！！！","添加信息");
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
	else//属于修改这种情况
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
	CButton * cBtnSyg=(CButton *)GetDlgItem(IDC_BUTTON_SYG); //上一个按钮
	CButton * cBtnXyg=(CButton *)GetDlgItem(IDC_BUTTON_XYG); //下一个按钮
	CButton * cBtnDyg=(CButton *)GetDlgItem(IDC_BUTTON_DYG); //第一个按钮
	CButton * cBtnMyg=(CButton *)GetDlgItem(IDC_BUTTON_MYG); //末一个按钮
	CButton * cBtnTj=(CButton *)GetDlgItem(IDC_BUTTON_TJ);   //添加按钮
	CButton * cBtnXg=(CButton *)GetDlgItem(IDC_BUTTON_XG);   //修改按钮
	CButton * cBtnQd=(CButton *)GetDlgItem(IDC_BUTTON_QD);   //确定按钮
	CButton * cBtnQx=(CButton *)GetDlgItem(IDC_BUTTON_QX);   //取消按钮
	CButton * cBtnSc=(CButton *)GetDlgItem(IDC_BUTTON_SC);   //删除按钮
	CButton * cBtnCx=(CButton *)GetDlgItem(IDC_BUTTON_CX);   //查询按钮
	CButton * cBtnTc=(CButton *)GetDlgItem(IDC_BUTTON_TC);   //退出按钮
	
	CEdit * cEdtXh=(CEdit *)GetDlgItem(IDC_EDIT_XH);//学号编辑框
	CEdit * cEdtXm=(CEdit *)GetDlgItem(IDC_EDIT_XM);//姓名编辑框
	CEdit * cEdtXb=(CEdit *)GetDlgItem(IDC_EDIT_XB);//性别编辑框
	CEdit * cEdtNl=(CEdit *)GetDlgItem(IDC_EDIT_NL);//年龄编辑框
	
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
	
	if(boolXgOrTj==FALSE)//属于添加这种情况
		cBtnTj->SetFocus();
	else//属于修改这种情况
		cBtnXg->SetFocus();

}

void CMyDlg::OnButtonSyg() 
{
	// TODO: Add your control notification handler code here
	CEdit * cEdtXh=(CEdit *)GetDlgItem(IDC_EDIT_XH);//学号编辑框
	CEdit * cEdtXm=(CEdit *)GetDlgItem(IDC_EDIT_XM);//姓名编辑框
	CEdit * cEdtXb=(CEdit *)GetDlgItem(IDC_EDIT_XB);//性别编辑框
	CEdit * cEdtNl=(CEdit *)GetDlgItem(IDC_EDIT_NL);//年龄编辑框
	
	if(CurrentCount<1)
		MessageBox("无信息可供查看！！！","查看信息");
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
	CEdit * cEdtXh=(CEdit *)GetDlgItem(IDC_EDIT_XH);//学号编辑框
	CEdit * cEdtXm=(CEdit *)GetDlgItem(IDC_EDIT_XM);//姓名编辑框
	CEdit * cEdtXb=(CEdit *)GetDlgItem(IDC_EDIT_XB);//性别编辑框
	CEdit * cEdtNl=(CEdit *)GetDlgItem(IDC_EDIT_NL);//年龄编辑框
	
	if(CurrentCount<1)
		MessageBox("无信息可供查看！！！","查看信息");
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
	CEdit * cEdtXh=(CEdit *)GetDlgItem(IDC_EDIT_XH);//学号编辑框
	CEdit * cEdtXm=(CEdit *)GetDlgItem(IDC_EDIT_XM);//姓名编辑框
	CEdit * cEdtXb=(CEdit *)GetDlgItem(IDC_EDIT_XB);//性别编辑框
	CEdit * cEdtNl=(CEdit *)GetDlgItem(IDC_EDIT_NL);//年龄编辑框
	
	if(CurrentCount<1)
		MessageBox("无信息可供查看！！！","查看信息");
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
	CEdit * cEdtXh=(CEdit *)GetDlgItem(IDC_EDIT_XH);//学号编辑框
	CEdit * cEdtXm=(CEdit *)GetDlgItem(IDC_EDIT_XM);//姓名编辑框
	CEdit * cEdtXb=(CEdit *)GetDlgItem(IDC_EDIT_XB);//性别编辑框
	CEdit * cEdtNl=(CEdit *)GetDlgItem(IDC_EDIT_NL);//年龄编辑框
	
	if(CurrentCount<1)
		MessageBox("无信息可供查看！！！","查看信息");
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
		MessageBox("当前不是有效数据，不能删除！！！","删除信息");
	else
		if(MessageBox("确定要删除吗？","删除信息",MB_ICONQUESTION|MB_YESNO)==IDYES)
		{
			//从数组中删除
			for(int i=intWz+1;i<=CurrentCount;i++)
				stu[i-1]=stu[i];
			CurrentCount--;
			MessageBox("已成功删除！","删除信息");

			//显示后一条记录信息
			CEdit * cEdtXh=(CEdit *)GetDlgItem(IDC_EDIT_XH);//学号编辑框
			CEdit * cEdtXm=(CEdit *)GetDlgItem(IDC_EDIT_XM);//姓名编辑框
			CEdit * cEdtXb=(CEdit *)GetDlgItem(IDC_EDIT_XB);//性别编辑框
			CEdit * cEdtNl=(CEdit *)GetDlgItem(IDC_EDIT_NL);//年龄编辑框
			
			if(CurrentCount>=1)//还有剩余信息可供操作
			{
				if(intWz>=CurrentCount+1)//当前是最后一个
					intWz=1;            //显示第一条信息
				cEdtXh->SetWindowText(stu[intWz].xh);
				cEdtXm->SetWindowText(stu[intWz].xm);
				cEdtXb->SetWindowText(stu[intWz].xb);
				CString strTemp;
				strTemp.Format("%d",stu[intWz].nl);
				cEdtNl->SetWindowText(strTemp);
			}
			else
			{
				cEdtXh->SetWindowText("无人员信息");
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
	unsigned char fileFilter[]= "文本文件(*.txt)|*.txt|所有文件(*.*)|*.*||";
	CFileDialog   dlgOpenFile(false,0,0,OFN_HIDEREADONLY|OFN_FILEMUSTEXIST,(LPCTSTR)fileFilter,NULL);
	if(dlgOpenFile.DoModal()==IDOK)
	{
		CString fileName=dlgOpenFile.GetPathName();
		fp=fopen(fileName,"w");
		if(fp==NULL)
			MessageBox("文件建立失败，无法保存信息！！！","信息保存",MB_OK);
		else
		{
			fprintf(fp,"%d",CurrentCount);
			for(int i=1;i<=CurrentCount;i++)
				fprintf(fp,"\n%16s%8s%4s%4d",stu[i].xh,stu[i].xm,stu[i].xb,stu[i].nl);
			fclose(fp);
			MessageBox("信息已成功保存！！！","信息保存",MB_OK);
		}
	}


}

void CMyDlg::OnFileOpen() 
{
	// TODO: Add your command handler code here
FILE *fp;
	unsigned char fileFilter[]= "文本文件(*.txt)|*.txt|所有文件(*.*)|*.*||";
	CFileDialog   dlgOpenFile(true,0,0,OFN_HIDEREADONLY|OFN_FILEMUSTEXIST,(LPCTSTR)fileFilter,NULL);
	if(dlgOpenFile.DoModal()==IDOK)
	{
		CString fileName=dlgOpenFile.GetPathName();
		fp=fopen("bjxx.txt","r");
		if(fp==NULL)
			MessageBox("文件打开错误，无法读取信息！！！","信息读取",MB_OK);
		else
		{
			fscanf(fp,"%d",&CurrentCount);
			for(int i=1;i<=CurrentCount;i++)
				fscanf(fp,"%s%s%s%d",stu[i].xh,stu[i].xm,stu[i].xb,&stu[i].nl);
			fclose(fp);
			MessageBox("信息已成功读取！！！","信息读取",MB_OK);
			CEdit * cEdtXh=(CEdit *)GetDlgItem(IDC_EDIT_XH);//学号编辑框
			CEdit * cEdtXm=(CEdit *)GetDlgItem(IDC_EDIT_XM);//姓名编辑框
			CEdit * cEdtXb=(CEdit *)GetDlgItem(IDC_EDIT_XB);//性别编辑框
			CEdit * cEdtNl=(CEdit *)GetDlgItem(IDC_EDIT_NL);//年龄编辑框
			
			if(CurrentCount>=1)//还有剩余信息可供操作
			{
				intWz=1;            //显示第一条信息
				cEdtXh->SetWindowText(stu[intWz].xh);
				cEdtXm->SetWindowText(stu[intWz].xm);
				cEdtXb->SetWindowText(stu[intWz].xb);
				CString strTemp;
				strTemp.Format("%d",stu[intWz].nl);
				cEdtNl->SetWindowText(strTemp);
			}
			else
			{
				cEdtXh->SetWindowText("无人员信息");
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
	if(strInput.GetLength()>0)//有等查信息
	{
		int i=0;
		CString strDcxx;
		
		CEdit * cEdtXh=(CEdit *)GetDlgItem(IDC_EDIT_XH);//学号编辑框
		CEdit * cEdtXm=(CEdit *)GetDlgItem(IDC_EDIT_XM);//姓名编辑框
		CEdit * cEdtXb=(CEdit *)GetDlgItem(IDC_EDIT_XB);//性别编辑框
		CEdit * cEdtNl=(CEdit *)GetDlgItem(IDC_EDIT_NL);//年龄编辑框
		
		do
		{
			i++;
			strDcxx.Format("%s",stu[i].xh);
		}while((strInput.Compare(strDcxx)!=0) && (i<=CurrentCount));
		
		if(i<=CurrentCount)//找到了
		{
			cEdtXh->SetWindowText(stu[i].xh);
			cEdtXm->SetWindowText(stu[i].xm);
			cEdtXb->SetWindowText(stu[i].xb);
			CString strTemp;
			strTemp.Format("%d",stu[i].nl);
			cEdtNl->SetWindowText(strTemp);
		}
		else//没找到
		{
			cEdtXh->SetWindowText("找不到");
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
	CEdit * cEdtXh=(CEdit *)GetDlgItem(IDC_EDIT_XH);//学号编辑框
	cEdtXh->GetWindowText(strInput);
	if(strInput.GetLength()!=11)
		MessageBox("学号位数不对，请重输！！！","信息输入",MB_OK);

}

void CMyDlg::OnKillfocusEditXb() 
{
	// TODO: Add your control notification handler code here
	CString strNan;
	CString strNv;
	CString strInput;
	CEdit * cEdtXb=(CEdit *)GetDlgItem(IDC_EDIT_XB);//性别编辑框
	cEdtXb->GetWindowText(strInput);
	strNan.Format("男");
	strNv.Format("女");
	if((strInput.Compare(strNan)!=0)&&(strInput.Compare(strNv)!=0))
		MessageBox("输入必须为男或女，请重输！！！","信息输入",MB_OK);

}
