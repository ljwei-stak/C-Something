// GameOfProjectDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "GameOfProject.h"
#include "GameOfProjectDlg.h"
#include "GameSnake.h"
#include "GameFlyControl.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "ManToHellControl.h"
#include "SeaWarControl.h"
#include "GameTools.h"


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CGameOfProjectDlg �Ի���




CGameOfProjectDlg::CGameOfProjectDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGameOfProjectDlg::IDD, pParent)
	, m_strScore(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGameOfProjectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_SCORE_EDIT, m_strScore);
	DDX_Control(pDX, IDC_COMBO1, m_GameListBox);

}

BEGIN_MESSAGE_MAP(CGameOfProjectDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_WM_LBUTTONDOWN()
	
	ON_WM_TIMER()
	ON_WM_KEYDOWN()
	ON_BN_CLICKED(IDC_PAUSE_BUTTON, &CGameOfProjectDlg::OnBnClickedPauseButton)
	ON_BN_CLICKED(IDC_END_BUTTON, &CGameOfProjectDlg::OnBnClickedEndButton)
	ON_BN_CLICKED(IDC_START_BUTTON, &CGameOfProjectDlg::OnBnClickedStartButton)
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_RESTART_BUTTON, &CGameOfProjectDlg::OnBnClickedRestartButton)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CGameOfProjectDlg::OnCbnSelchangeCombo1)
END_MESSAGE_MAP()


// CGameOfProjectDlg ��Ϣ�������

BOOL CGameOfProjectDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	gameFather = NULL;
	CString strPathName ="" ;
	strPathName = CGameTools::GetIniPathName() +"11.ini";
	iniRead=new MYIniReadTools(strPathName);
	vector<CString> vSave;
	iniRead->GetAllSection(vSave);
	InitChoice(vSave);
	InitGameFather();
	vector<INIKEYINFO> vIni;
	iniRead->GetAllValueAndKey("123",vIni);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CGameOfProjectDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CGameOfProjectDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDC *pDc=GetDC();
		
		gameFather->GameOnPaint(pDc);
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CGameOfProjectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CGameOfProjectDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	gameFather->GameOnLButtonDown(nFlags,point);
	

	CDialog::OnLButtonDown(nFlags, point);
}

// void CGameOfProjectDlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
// {
// 	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
// 	
// 	CDialog::OnKeyDown(nChar, nRepCnt, nFlags);
// }

void CGameOfProjectDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//Invalidate(false);
	if(gameFather->OnGameTimer(nIDEvent)==-2)
	{
		MessageBox("Ŭ���ɣ���������","��ʾ",MB_OK);
	}
	gameFather->SetScore(m_strScore);
	UpdateData(FALSE);
	
	CDialog::OnTimer(nIDEvent);
}

void CGameOfProjectDlg::OnBnClickedButton1()
{
	
	
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}

void CGameOfProjectDlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	gameFather->GameOnKeyDown(nChar,nRepCnt,nFlags);
	CDialog::OnKeyDown(nChar, nRepCnt, nFlags);
}
BOOL CGameOfProjectDlg::PreTranslateMessage(MSG* pMsg)
{
	gameFather->PreTranslateMessage(pMsg);
	
	return CDialog::PreTranslateMessage(pMsg);
}
void CGameOfProjectDlg::OnBnClickedPauseButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	bPause=!bPause;
	if (!bPause)
	{
		GetDlgItem(IDC_PAUSE_BUTTON)->SetWindowText("����");
	}
	else
	{
		GetDlgItem(IDC_PAUSE_BUTTON)->SetWindowText("��ͣ");
	}
	gameFather->PauseGame(bPause);
}

void CGameOfProjectDlg::OnBnClickedEndButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialog::OnCancel();
}

void CGameOfProjectDlg::OnBnClickedStartButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	GetDlgItem(IDC_START_BUTTON)->EnableWindow(FALSE);
	Sleep(3000);
	gameFather->StartGame();
}

void CGameOfProjectDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	gameFather->GameOnLButtonUp(nFlags,point);
	CDialog::OnLButtonUp(nFlags, point);
}

void CGameOfProjectDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	gameFather->GameOnMouseMove(nFlags,point);
	CDialog::OnMouseMove(nFlags, point);
}

void CGameOfProjectDlg::OnBnClickedRestartButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
	gameFather->ReStartGame();
}

void CGameOfProjectDlg::OnCbnSelchangeCombo1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
	CString str;
	m_GameListBox.GetLBText(m_GameListBox.GetCurSel(),str);
	switchGame(str);
	InitGameFather();
	Invalidate(FALSE);
}
void CGameOfProjectDlg::InitChoice(vector<CString> vSave)
{
	m_GameListBox.ResetContent();
	for (int i=0;i<vSave.size();i++)
	{
		m_GameListBox.AddString(vSave[i]);
	}
	m_GameListBox.SetCurSel(0);
	CString str;
	m_GameListBox.GetLBText(0,str);
	switchGame(str);
}
void CGameOfProjectDlg::switchGame(CString str)
{
	if (gameFather!=NULL)
	{
		gameFather->KillAllTimer();
		delete gameFather;
		gameFather = NULL;
	}
	GetDlgItem(IDC_START_BUTTON)->EnableWindow(TRUE);
	ShowCursor(TRUE);
	if (str.CompareNoCase("̰����")==0)
	{
		gameFather = new CGameSnake;
	
		return ;
	}
	if (str.CompareNoCase("���˾���100s")==0)
	{
		gameFather=new CManToHellControl;
		return ;
	}
	if (str.CompareNoCase("Ǳͧ��ս") == 0)
	{
		gameFather = new CSeaWarControl; 
		return;
	}
	if (str.CompareNoCase("С����")==0)
	{
		gameFather = new CGameFlyControl;
		return;
	}

	MessageBox("�����ļ�����!","��ʾ",MB_OK);

}
void CGameOfProjectDlg::InitGameFather() 
{
	CDC *pDc=GetDC();
	gameFather->SetCDC(pDc);
	gameFather->SetHWnd(m_hWnd);
	m_strScore="";
	gameFather->SetScore(m_strScore);
	gameFather->SetGameBkColor(RGB(40,150,40));
	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	bPause=FALSE;
}
