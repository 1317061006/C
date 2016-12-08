#include <stdio.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXVEX 100  /*��󶥵��� Ӧ���û�����*/ 
#define INFINITY 65535 /*��65535��ʾOO*/ 
typedef char VertexType; /*��������Ӧ���û�����*/
typedef int  EdgeType; /*���ϵ�Ȩֵ����Ӧ���û�����*/ 
#define  MAX 100 
typedef  int  Boolean;/*Boolean�ǲ������� ��ֵ��True��False*/
Boolean visited[MAX]; /*���ʱ�ʶ������*/


 typedef struct EdgeNode /*�߱���*/
{ 
      int adjvex; /*�ڽӵ��� �洢�ö����Ӧ���±�*/
       EdgeType weight; /*���ڴ洢Ȩֵ ���ڷ���ͼ���Բ���Ҫ*/ 
       struct EdgeNode *next;/*���� ָ����һ���ڽ��*/ 
}EdgeNode;

 typedef struct VertexNode /*�������*/
 {
 	VertexType data; /*������ �洢������Ϣ*/
 	EdgeNode *firstedge;/*�߱�ͷָ��*/
 }VertexNode,AdjList[MAXVEX];
 
 
 
 typedef struct
 {
 	AdjList adjlist;
 	int numVertexes,numEdges;/*ͼ�е�ǰ�������ͱ���*/
  }GraphAdjList;
  
  /*����ͼ���ڽӱ�ṹ*/
 void CreateALGraph(GraphAdjList *G)
 {
 	int i,j,k;
 	EdgeNode *e;
 	printf("���붥�����ͱ���:\n");
 	scanf("%d,%d",&G->numVertexes,&G->numEdges);/*���붥�����ͱ���*/
 	for(i=0;i<G->numVertexes;i++)
	 {
	 	scanf(&G->adjlist[i].data);/*���붥����Ϣ*/ 
	 	G->adjlist[i].firstedge=NULL;/*���߱���Ϊ�ձ�*/ 
	  } 
	  for(k=0;k<G->numEdges;k++)/*�����߱�*/ 
	  {
	  printf("�����(vi,vj)�ϵĶ������:\n");
	  scanf("%d,%d",&i,&j);/*�����(vi,vj)�ϵĶ������*/
	  e=(EdgeNode *)malloc(sizeof(EdgeNode));/*���ڴ�����ռ�*/
	                                          /*���ɱ߱���*/
      e->adjvex=j;/*�ڽ����j*/
	  e->next=G->adjlist[i].firstedge; /*��eָ��ָ��ǰ����ָ��Ľڵ�*/
	  G->adjlist[i].firstedge=e;/*����ǰ�����ָ��ָ��e*/
	  e=(EdgeNode *)malloc(sizeof(EdgeNode));/*���ڴ�����ռ�*/		
	                                          /*���ɱ߱���*/
      e->adjvex=i;/*�ڽ����Ϊi*/
	  e->next=G->adjlist[j].firstedge;/*��eָ��ָ��ǰ����ָ��Ľڵ�*/
	  G->adjlist[j].firstedge=e;/*����ǰ�����ָ��ָ��e*/							   	
	  }
  } 
  
  
     //�ڽӱ����������㷨 
	  void  DFS(GraphAdjList *GL,int i)
	  {
	  	EdgeNode *p;
	  	visited[i]=TRUE;
	  	printf("%c",GL->adjlist[i].data); //��ӡ��� Ҳ���Խ����������� 
	  	p=GL->adjlist[i].firstedge;
	  	while(p)
	  	{
	  		if(!visited[p->adjvex])
             DFS(GL,p->adjvex); //��Ϊ���ʵ��ڽӶ���ݹ���� 
             p=p->next;
		  }
	   } 
	   
	   
	   
	   
	   /*�ڽӱ����ȱ�������*/
	   void DFSTraverse(GraphAdjList GL)
	   {
	   	int i;
	   	for(i=0;i<GL->numVertexes;i++)
	   	 visited[i]=FALSE;
	   	 for(i=0;i<GL->numVertexes;i++)
	   	 if(!visited[i]) // ��δ���ʹ��Ľ�����DFS ������ͨͼ ֻ��ִ��һ��
		  DFS(GL,i); 
		
		} 
		
		
		
		
		
		
		
		
