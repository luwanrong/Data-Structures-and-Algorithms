; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMyDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "班级信息还礼系统.h"

ClassCount=4
Class1=CMyApp
Class2=CMyDlg
Class3=CAboutDlg

ResourceCount=5
Resource1=IDD_DIALOG_INPUT
Resource2=IDR_MAINFRAME
Resource3=IDD_MY_DIALOG
Resource4=IDD_ABOUTBOX
Class4=CInputDlg
Resource5=IDR_MENU_MAIN

[CLS:CMyApp]
Type=0
HeaderFile=班级信息还礼系统.h
ImplementationFile=班级信息还礼系统.cpp
Filter=N

[CLS:CMyDlg]
Type=0
HeaderFile=班级信息还礼系统Dlg.h
ImplementationFile=班级信息还礼系统Dlg.cpp
Filter=D
LastObject=IDC_EDIT_XB
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=班级信息还礼系统Dlg.h
ImplementationFile=班级信息还礼系统Dlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MY_DIALOG]
Type=1
Class=CMyDlg
ControlCount=19
Control1=IDC_STATIC_XB,static,1342308352
Control2=IDC_EDIT_XH,edit,1484849280
Control3=IDC_STATIC_XH,static,1342308352
Control4=IDC_EDIT_XM,edit,1484849280
Control5=IDC_STATIC_XM,static,1342308352
Control6=IDC_EDIT_XB,edit,1484849280
Control7=IDC_STATIC_NL,static,1342308352
Control8=IDC_EDIT_NL,edit,1484849280
Control9=IDC_BUTTON_XYG,button,1342242816
Control10=IDC_BUTTON_SYG,button,1342242816
Control11=IDC_BUTTON_DYG,button,1342242816
Control12=IDC_BUTTON_MYG,button,1342242816
Control13=IDC_BUTTON_TJ,button,1342242816
Control14=IDC_BUTTON_XG,button,1342242816
Control15=IDC_BUTTON_QD,button,1476460544
Control16=IDC_BUTTON_QX,button,1476460544
Control17=IDC_BUTTON_SC,button,1342242816
Control18=IDC_BUTTON_CX,button,1342242816
Control19=IDC_BUTTON_TC,button,1342242816

[MNU:IDR_MENU_MAIN]
Type=1
Class=CMyDlg
Command1=ID_FILE_OPEN
Command2=ID_FILE_SAVE
Command3=ID_APP_EXIT
Command4=ID_APP_ABOUT
CommandCount=4

[DLG:IDD_DIALOG_INPUT]
Type=1
Class=CInputDlg
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT_INPUT,edit,1350631552

[CLS:CInputDlg]
Type=0
HeaderFile=InputDlg.h
ImplementationFile=InputDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CInputDlg
VirtualFilter=dWC

