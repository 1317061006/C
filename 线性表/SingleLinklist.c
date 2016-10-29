#include <stdio.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /*�洢�ռ��ʼ��������*/
typedef int ElemType;/*ElemType����ʵ��������� �������Ϊint*/
/*���Ա�ĵ�����洢�ṹ*/
typedef int Status;
typedef struct Node {
	ElemType data;
	struct Node *next;
} Node;

typedef struct Node *LinkList;/*����LinkList*/

/*
��ʼ������˳�����Ա�L�Ѵ��� 1<=i<=ListLength(L)
������������e����L�е�i������Ԫ�ص�ֵ
*/
Status GetElem(LinkList L,int i,ElemType *e) {
	int j;
	LinkList p; /*����һָ��p*/
	p=L->next; /*��pָ������L�ĵ�һ�����*/
	j=1; /*JΪ������*/
	while(p && j<i) { /*p��Ϊ���Ҽ�����j��û�е���iʱ��ѭ������*/
		p=p->next;/*��pָ����һ�����*/
		++j;
	}
	if(!p|| j>i)
		return ERROR;/*��i����㲻����*/
	*e=p->data;/*ȡ��i����������*/
	return OK;
}

/*
��ʼ���� ��˳�����Ա�L�Ѵ��� 1<=i<=ListLength(L)
������������L�е�i�����λ��֮ǰ�����µ�����Ԫ��e,l�ĳ��ȼ�1
*/
Status ListInsert(LinkList *L,int i,ElemType e) {
	int j;
	LinkList p,s;
	p= *L;
	j=1;
	while(p && j<i) { /*Ѱ�ҵ�i-1�����*/
		p=p->next;
		++j;
	}

	if(!p || j>i)
		return ERROR;

	s=(LinkList)malloc(sizeof(Node));/* �����½ڵ�(C��׼����) sizeof���������ֽ���ʽ��������������Ĵ洢��С*/
	s->data=e;
	s->next=p->next; /*��p�ĺ�̽ڵ㸳ֵ��s�ĺ��*/
	p->next=s;/*��S��ֵ��p�ĺ��*/
	return OK;

}
/*
 ��ʼ������˳�����Ա�L�Ѵ��ڣ�1<=i<=ListLength(L)
 �������: ɾ��L�ĵ�i����� ����E������ֵ L�ĳ��ȼ�1
*/
Status ListDelete(LinkList *L,int i,ElemType *e) {
	int j;
	LinkList p,q;
	p=*L;
	j=1;

	while(p->next && j<i) { /*����Ѱ�ҵ�i-1�����*/
		p=p->next;
		++j;
	}

	if(!(p->next) || j>1)
		return ERROR;/*��i����㲻����*/
	q=p->next;
	p->next=q->next;/*��q�ĺ�̸�ֵ��p�ĺ��*/
	*e=q->next;  /*��q����е����ݸ�e**/
	free(q); /*��ϵͳ���մ˽ڵ� �ͷ��ڴ�*/
	return OK;
}



/*�������n��Ԫ�ص�ֵ ��������ͷ�ڵ�ĵ������Ա�*/
Status CreateListHead (LinkList *L,int n) {
	LinkList p;
	int i;
	srand(time(0));/*��ʼ�����������*/
	*L=(LinkList)malloc(sizeof(Node));
	(*L)->next=NULL;/*�Ƚ���һ����ͷ���ĵ�����*/

	for(i=0; i<n; i++) {

		p=(LinkList)malloc(sizeof(Node));/*�����½ڵ�*/
		p->data=rand()%100+1;/*�������100���ڵ�����*/
		p->next=(*L)->next;
		(*L)->next=p;/*���뵽��ͷ*/

	}

}




/*�������n��Ԫ�ص�ֵ ���������ͷ�ڵ�ĵ������Ա�β�巨��*/
void CreateListTail(LinkList *L,int n) {
	LinkList p,r;
	int i;
	srand(time(0));/*��ʼ�����������*/
	*L=(LinkList)malloc(sizeof(Node));/*Ϊ�������Ա�*/
	r=*L;/*rΪָ��β���Ľڵ�*/

	for(i=0; i<n; i++) {
		p=(Node *)malloc(sizeof(Node));/*�����½ڵ�*/
		p->data=rand() %100+1;/*�������100���ڵ�����*/
		r->next=p;/*����β�ն˽ڵ��ָ��ָ���½ڵ�*/
		r=p;
	}
	r->next=NULL;/*��ʾ��ǰ�������*/

}



/*��ʼ������˳�����Ա�L�Ѵ��� ������� ����L����Ϊ�ձ�*/
Status ClearList(LinkList *L) {
	LinkList p,q;
	p=(*L)->next; /*pָ���һ�����*/
	while(p) {  /*û����β*/
		q=p->next;
		free(p);
		p=q;
	}
	(*L)->next=NULL;/*ͷ���ָ����Ϊ��*/
	return OK;
}


//�������� ��û�в��Թ��� 
int length(LinkList *L){
	int length=0;
	LinkList p=(*L)->next;//���ͷ��� 
	while(p){
		length++;
		p=p->next;
	}
	return length;
}
  

void  main() {

	LinkList list,start;
	printf("�����뵥���������");
	list=CreateListHead(list,10);
	for(start =list->next; start!=NULL; start=start->data)
		printf("%d",start->data);
	print("/n");



}
