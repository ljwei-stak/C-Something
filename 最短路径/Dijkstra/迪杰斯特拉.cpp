#include<stdio.h>
#include<stdlib.h>
#define MaxVnum 100
#define INF 30000
typedef int Weight[MaxVnum][MaxVnum];

typedef struct{
	int vexnum,arcnum;
	Weight wei;
}Graph;


void CreateG(Graph &G)
{
	int n,i,j,k;
	scanf("%d%d",&G.vexnum,&G.arcnum);
	for(i=0;i<G.arcnum;i++)
		for(j=0;j<G.vexnum;j++)
			G.wei[i][j]=INF;
	for(k=0;k<G.arcnum;k++)
	{
		scanf("%d%d%d",&i,&j,&n);
		G.wei[i][j]=n;
	}
}
/*                    //输出矩阵
void PrintG(Graph &G)
{
	int i,j,k;
	for(i=0;i<G.vexnum;i++)
	{
		for(j=0;j<G.vexnum;j++)
		{
			if(G.wei[i][j]<INF)
				printf("%4d",G.wei[i][j]);
			else printf("%4d",0);
		}
		printf("\n");
	}
}
*/

typedef struct BPNode{//表结点               
     int  w;                          //邻接顶点
     struct BPNode *next;            //指向下一个邻接顶点的指针
}BPNode; 

struct P{   //头结点
	 int w;
     BPNode  *first;                //指向第一个邻接顶点的指针
}P[MaxVnum]; 



void Dijkstra(Graph &G,int v0)
{
	BPNode *q,*p,*r,*a;
	printf("\n\n\n");
	bool final[MaxVnum];
	int D[MaxVnum];
	int v,w,i,j,min,k;
	for(v=0;v<G.vexnum;v++)
	{
		final[v]=false;
		P[v].w=v;
		D[v]=G.wei[v0][v];
		if(D[v]<INF)
		{
			q=(BPNode*)malloc(sizeof(BPNode));
			q->w=v0;q->next=NULL;
			P[v].first=q;
		}
		else 	P[v].first=NULL;
	}
	D[v0]=0;final[v0]=true;
	for(i=1;i<G.vexnum;i++)
	{
		min=INF;
		for(k=0;k<G.vexnum;k++)
			if(final[k]==false)
				if(D[k]<min)
				{
					min=D[k];                  
					j=k;                     
				}
		final[j]=true;                          //
		for(k=0;k<G.vexnum;k++)
			if(final[k]==false && D[j]+G.wei[j][k]<D[k] )
			{
				D[k]=D[j]+G.wei[j][k];      
                p=P[j].first;
				q=P[k].first;a=NULL;
				while(p)
				{
					if(q)
					{
					  q->w=p->w;
					  p=p->next; a=q;
					  q=q->next;                     //
					}
					else
					{
						r=(BPNode*)malloc(sizeof(BPNode));
                        r->w=p->w;r->next=NULL; 
						if(a!=NULL)
						{
							a->next=r;
					        p=p->next;a=a->next;q=r->next;
						}
						else
						{   P[k].first=r;q=r->next;p=p->next;a=r;}
					}
				}
				if(q) a->next=NULL;
                r=(BPNode*)malloc(sizeof(BPNode));
                r->w=j;r->next=NULL;a->next=r;
				
			}
	}
	for(v=0;v<G.vexnum;v++)
		if(P[v].first!=NULL)
		{
			p=P[v].first;
			while(p)
			{
				printf("v%d ",p->w);
				p=p->next;
			}
			printf("v%d\n",v);
		}
}



void main()
{
	Graph G;
	CreateG(G);
	Dijkstra(G,0);      //PrintG(G);
}
				
		
		










		












































