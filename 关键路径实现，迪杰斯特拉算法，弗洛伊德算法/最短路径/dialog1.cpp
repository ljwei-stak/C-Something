// dialog1.cpp : implementation file
//

#include "stdafx.h"
#include "sheji2.h"
#include "dialog1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Cdialog1 dialog


Cdialog1::Cdialog1(CWnd* pParent /*=NULL*/)
	: CDialog(Cdialog1::IDD, pParent)
{
	//{{AFX_DATA_INIT(Cdialog1)
	m_n = 0;
	m_e = 0;
	m_i = 0;
	m_j = 0;
	m_w = 0;
	m_v = 0;
	m_vv = 0;
	m_ww = 0;
	//}}AFX_DATA_INIT
}


void Cdialog1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Cdialog1)
	DDX_Control(pDX, IDC_LIST2, m_fuluo);
	DDX_Control(pDX, IDC_LIST1, m_dijie);
	DDX_Text(pDX, IDC_EDIT1, m_n);
	DDX_Text(pDX, IDC_EDIT2, m_e);
	DDX_Text(pDX, IDC_EDIT3, m_i);
	DDX_Text(pDX, IDC_EDIT4, m_j);
	DDX_Text(pDX, IDC_EDIT5, m_w);
	DDX_Text(pDX, IDC_EDIT6, m_v);
	DDX_Text(pDX, IDC_EDIT7, m_vv);
	DDX_Text(pDX, IDC_EDIT8, m_ww);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Cdialog1, CDialog)
	//{{AFX_MSG_MAP(Cdialog1)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_RADIO1, OnRadio1)
	ON_BN_CLICKED(IDC_RADIO2, OnRadio2)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Cdialog1 message handlers


	MGraph *G=new MGraph;
int D[MVNum][MVNum],P[MVNum][MVNum];
	int D2[MVNum],P2[MVNum];



void Cdialog1::OnButton1() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
MessageBox("输入完毕！");	

	UpdateData(FALSE);
}

void Cdialog1::OnButton2() 
{
	// TODO: Add your control notification handler code here
UpdateData(TRUE);
	CreateMGraph(G,m_n,m_e);
		UpdateData(FALSE);
}

void Cdialog1::OnButton3() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);m_dijie.ResetContent();
	Dijkstra(G,m_v,m_n);
		UpdateData(TRUE);
	
}

void Cdialog1::OnRadio1() 
{
	// TODO: Add your control notification handler code here
MessageBox("求单元路径，输入源点 v:");
		
}

void Cdialog1::OnRadio2() 
{
	// TODO: Add your control notification handler code here
MessageBox("输入 源点 vl 和 终点 w:");

}


int kk=1;

void Cdialog1::CreateMGraph(MGraph *G, int n, int e)
{//G=new MGraph;	
	
 G->arcs[m_i][m_j]=m_w;
kk++;
if(kk>e) MessageBox("输入完毕！");

}
void Cdialog1::Dijkstra(MGraph *G, int vl, int n)
{//G=new MGraph;	
	if(m_v>m_n) {MessageBox("顶点数应小于 n ！");return ;}
	bool S[MVNum];
int v,i,w,min;
for(v=1;v<=n;v++)
	{S[v]=false;
D2[v]=G->arcs[vl][v];
if(D2[v]<Maxint)
	P2[v]=vl;
else
	P2[v]=0;
	}
	D2[vl]=0;
	S[vl]=TRUE;
	v=vl;
	for(i=1;i<n;i++)
	{min=Maxint;
	for(w=1;w<=n;w++)
		if(!S[w]&&D2[w]<min)
		{v=w;min=D2[w];
		}
		S[v]=TRUE;
		for(w=1;w<=n;w++)
			if(!S[w]&&(D2[v]+G->arcs[v][w]<D2[w]))
		{D2[w]=D2[v]+G->arcs[v][w];
		P2[w]=v;
		}
	}
CString str="",tmp="",sss="";
	//cout<<"路径长度      路径\n";
	for(i=1;i<=n;i++)
	{
	str.Format("%d",D2[i]);
	tmp.Format("%d",i);

	str=str+"            "+tmp;
		//cout<<D2[i];
	//cout<<"\t";
//	cout<<i;
	v=P2[i];
	while(v!=0)
		{//cout<<"<-"<<v;
	sss.Format("%d",v);
	str=str+"<-"+sss;
	v=P2[v];
		}
		m_dijie.AddString(str);
	}

}

void Cdialog1::Floyd(MGraph *G, int n)
{//G=new MGraph;	
int i,j,k;
for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	{if(G->arcs[i][j]!=Maxint)
	P[i][j]=j;
else P[i][j]=0;
D[i][j]=G->arcs[i][j];
	}
	for(k=1;k<=n;k++)
	{for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{if(D[i][k]+D[k][j]<D[i][j])
			{D[i][j]=D[i][k]+D[k][j];
	P[i][j]=P[i][k];
			}
		}
	}
//	cout<<"输入源点和终点\n";
//	cin>>v>>w;
	CString str="",tmp="",fuluo="",length="",kk="";

	k=P[m_vv][m_ww];	
	if(k==0)
		//	cout<<"顶点"<<v<<"和"<<w<<"无路径"<<endl;
	{	str.Format("%d",m_vv);
		tmp.Format("%d",m_ww);
		fuluo+="顶点"+str+"和顶点"+tmp+"无路径";
	m_fuluo.AddString(fuluo);

	}
	else
			{//cout<<"从顶点"<<v<<"到"<<"顶点"<<w<<"的最短路径是:"<<v;
        str.Format("%d",m_vv);
		tmp.Format("%d",m_ww);
		fuluo+="从顶点"+str+"到顶点"+tmp+"的最短路径是:"+str;
	         while(k!=m_ww)
				{//cout<<"->"<<k;
		kk.Format("%d",k);
            fuluo=fuluo+"->"+kk;
					k=P[k][m_ww];
				}
		tmp.Format("%d",m_ww);
		fuluo=fuluo+"->"+tmp;

           m_fuluo.AddString(fuluo);
				//cout<<"路径长度是:"<<D[v][w]<<endl;
length.Format("%d",D[m_vv][m_ww]);
length="路径长度是:"+length;
   m_fuluo.AddString(length);
			}
}

void Cdialog1::CreateMGraph1(MGraph *G, int n)
{
//G=new MGraph;	
	int i,j;
for(i=1;i<=n;i++)
	G->vexs[i]=i;
for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	G->arcs[i][j]=Maxint;

}

void Cdialog1::OnButton4() 
{
	// TODO: Add your control notification handler code here
		UpdateData(TRUE);
   CreateMGraph1(G,m_n);
	   //UpdateData(FALSE);
}

void Cdialog1::OnButton5() 
{
	// TODO: Add your control notification handler code here
	m_fuluo.ResetContent();  //清空ListBox
	UpdateData(TRUE);
Floyd(G,m_n);
		UpdateData(TRUE);
}
