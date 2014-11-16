#ifndef _LIST
#define _LIST
#include"prepare.h"
Node* PrintList(Node* head);
Node* SearchNode(Node* head,Type data,int condition);
Node* InsertAfter(Node* head,Type data);
Node* InsertOrder(Node* head,Type data,int condition);
Node* Delete(Node* head,Type data);
Node* Reverse(Node* head);

Node* PrintList(Node* head)
{
  Node* p;
  if(head==NULL)
  {
      printf("图书馆无书！\n");
	  printf("\n");
      return NULL;
  }
  for(p=head;p;p=p->next)
    printNode(p->data);
  printf("\n");
  return head;
}
Node* SearchNode(Node* head,Type data,int condition)
{
    Node* p=head;
    if(head==NULL)
    {
        printf("图书馆无书！\n");
		printf("\n");
        return 0;
    }
    while(p&&!equal(p->data,data,condition))
    {
        p=p->next;
    }
    if(p)
        return p;
    return 0;
}
Node* InsertAfter(Node* head,Type data)
{
    Node* p,* p1;
    p=(Node* )malloc(size);
    p->data=data;
    p->next=NULL;
    if(head==NULL)
    {
        head=p;
        return head;
    }
    p1=head;
    while(p1->next)
    {
        p1=p1->next;
    }
    p1->next=p;
    return head;
}
Node* InsertOrder(Node* head,Type data,int condition)
{
    Node* p,* p1,* p2;
    p2=head;
    p=(Node* )malloc(size);
    p->data=data;
    p->next=NULL;
    if(head==NULL)
    {
        head=p;
        return head;
    }
    while(p2&&larger(p->data,p2->data,condition))
    {
        p1=p2;
        p2=p2->next;
    }
    if(head==p2)
        head=p;
    else
    p1->next=p;
	p->next=p2;
    return head;
}
Node* Delete(Node* head,Type data)
{
    Node* p=head,*q=NULL;
    if(head==NULL)
    {
    printf("图书馆无书！\n");
	printf("\n");
    return head;
    }
    while(p&&!equal(p->data,data,1))
    {
        q=p;
        p=p->next;
    }
    if(p)
    {
            if(q)
                q=q->next=p->next;
            else
                head=head->next;
            free(p);
    }
    else
    printf("图书馆中无此书！\n");
	printf("\n");
    return head;
}
Node* Reverse(Node* head)
{
    Node* p=head,*q;
    head=NULL;
    while(p)
    {
        q=p->next;
        p->next=head;
        head=p;
        p=q;
    }
    return head;
}
#endif // _LIST
