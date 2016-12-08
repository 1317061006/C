#include <stdio.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXVEX 100  /*��󶥵��� Ӧ���û�����*/ 
#define INFINITY 65535 /*��65535��ʾOO*/ 
typedef char VertexType; /*��������Ӧ���û�����*/
typedef int  EdgeType; /*���ϵ�Ȩֵ����Ӧ���û�����*/ 
#define    MAX 100 
typedef  int  Boolean;/*Boolean�ǲ������� ��ֵ��True��False*/
typedef struct 
{
	  VertexType vexs[MAXVEX];/*�����*/ 
	  EdgeType arc[MAXVEX][MAXVEX];/*�ٽӾ��� �ɿ��ɱ�*/
	  int numVertexes,numEdges;/*ͼ�е�ǰ�Ķ������ͱ���*/	   
 }MGraph;
 
/*����������ͼ���ڽӾ����ʾ*/ 
void CreateMGraph(MGraph *G)
{
	int i,j,k,w;
	printf("���붥�����ͱ���:\n");
	scanf("%d,%d",&G->numVertexes,&G->numEdges);/*���붥�����ͱ���*/
	for(i=0;i<G->numVertexes;i++)
	scanf(&G->vexs[i]);
	for(i=0;i<G->numVertexes;i++)
	for(j=0;j<G->numVertexes;j++)
	 G->arc[i][j]=INFINITY;/*��Ӿ����ʼ��*/
	 
	 for(k=0;k <G->numVertexes;k++)/*����numEdges���� �����ڽӾ���*/
	 {
	 	printf("�����(vi,vj)�ϵ��±�i,�±�j��Ȩw:\n");
	    scanf("%d,%d,%d",&i,&j,&w);/*�����(vi,vj)�ϵ�Ȩw*/
		G->arc[i][j]=w;
		G->arc[j][i]=G->arc[i][j];/*��Ϊ������ͼ ����Գ�*/  
	  } 
	
} 
 
  
  
 
Boolean visited[MAX]; /*���ʱ�ʶ������*/
   
  /*��Ӿ����������ȵݹ��㷨*/
	void DFS(MGraph G,int i){
	 int j;
	 visited[i]=TRUE;
	  printf("%c",G.vexs[i]); //��ӡ���� Ҳ������������
	  for(j=0;j<G.numVertexes;j++)
	    if(G.arc[i][j] ==1 && !visited[j])
		 DFS(G,j);         // ��δ���ʵ���Ӷ���ݹ����
		  
	 } 
	 
	 
	 /*��Ӿ������ȱ�������*/
	 void DFSTraverse(MGraph G)
	 {
	 	int i;
	 	for(i=0;i<G.numVertexes;i++)
	 	visited[i]=FALSE; //��ʼ���ж���״̬����δ���ʹ�״̬ 
	 	for(i=0;i<G.numVertexes;i++)
	 	if(!visited[i])//��δ���ʹ��Ķ������DFS ������ͨͼ ֻ��ִ��һ�� 
	 	DFS(G,i);

	  } 
	  
	   
	 
	   
	   
	  
	  
	  
	  
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
 

 

