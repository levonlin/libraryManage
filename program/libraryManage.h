#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"file.h"
void menu();
Node* runMenu(Node* head,int choice);
void ifoMenu();
Node* addBooks(Node* head,Type data);
Node* deleteBooks(Node* head,Type data);
Node* borrowBooks(Node* head,Type data);
Node* returnBooks(Node* head,Type data);
Node* ifoManage(Node* head);
void searchWithName(Node* head);
void searchWithBackate(Node* head);
Node* range(Node* head);

void menu()
{
	printf("-----主菜单-----\n");
    printf("1.图书信息更新\n");
    printf("2.按书名查询图书信息\n");
    printf("3.显示所有即将到期（三天之内）的图书\n");
    printf("4.图书按借阅次数排序\n");
    printf("0.退出管理系统\n");
    return;
}
Node* runMenu(Node* head,int choice)
{
  switch(choice)
        {
            case 1:head=ifoManage(head);
                   break;
            case 2:searchWithName(head);
                    break;
            case 3:searchWithBackate(head);
                    break;
            case 4:head=range(head);
                    break;
            case 0:break;
        }
        return head;
}
void ifoMenu()
{
	printf("-----图书信息更新-----\n");
    printf("1.添加图书\n");
    printf("2.删除图书信息\n");
    printf("3.借阅\n");
	printf("4.还书\n");
    printf("0.返回主菜单\n");
}
Node* addBooks(Node* head,Type data)
{
   readNode(&data);
   head=InsertOrder(head,data,1);
   return head;
}
Node* deleteBooks(Node* head,Type data)
{
   printf("输入欲删除图书索引号：");
   scanf("%s",&data.ID);
   head=Delete(head,data);
   printf("\n");
   return head;
}
Node* borrowBooks(Node* head,Type data)
{
  int i,bornum;
  Node* p=NULL;
  printf("输入欲借阅图书索引号：");
  scanf("%s",&data.ID);
  if(p=SearchNode(head,data,1))//必须有if防p指空
  {	printf("借阅几本（所借数量必须大于0且小于等于%d本）：",(p->data).num);
    scanf("%d",&bornum);
	if(bornum>0&&bornum<=(p->data).num&&!strcmp((p->data).borSitu,"可借"))
    {
      for(i=0;i<bornum;i++)
	  {
		  printf("输入归还日期（yyyymmdd）：\n");
		  scanf("%ld",&((p->data).backDate[(p->data).num1-(p->data).num]));
		  (p->data).num--;				
		  (p->data).borTimes++;
		  if((p->data).num==0)
			  (p->data).borSitu="不可借";
	  }//对data进行借阅操作
	}
	else
	   printf("所借图书数量过多或过少！\n");
  }
  else
	  printf("图书馆中无此书！\n");
  printf("\n");
  return head;
}
Node* returnBooks(Node* head,Type data)
{
  int i,j,k,retnum;
  long pos;
  Node* p=NULL;
  printf("输入欲归还图书索引号：");
  scanf("%s",&data.ID);
  if(p=SearchNode(head,data,1))
  {	printf("归还几本（所还数量必须大于0且小于等于%d本）：",(p->data).num1-(p->data).num);
    scanf("%d",&retnum);
	if(retnum>0&&retnum<=((p->data).num1-(p->data).num))
    {
      for(i=0;i<retnum;i++)
	  {
		  printf("输入借出时登记的归还日期（yyyymmdd）：\n");
		  scanf("%ld",&pos);
		  for(j=0;j<((p->data).num1-(p->data).num);j++)
		  {
			if((p->data).backDate[j]==pos)	
			{
				for(k=j;k<((p->data).num1-(p->data).num-j-1);k++)
				  (p->data).backDate[k]=(p->data).backDate[k+1];
				break;
			}
			if(j==((p->data).num1-(p->data).num-1))
			  printf("该归还日期不存在！请重新输入！\n");
		  }
		  if(j==((p->data).num1-(p->data).num))
		  {
			  i--;
			  continue;
		  }
		  else
		  (p->data).num++;	
		  
	  }//对data进行归还操作
	  (p->data).borSitu="可借";
	}
	else
	   printf("所还图书数量过多或过少！\n");
  }
  else
	  printf("图书馆中无此书！\n");
  printf("\n");
  return head;
}
Node* ifoManage(Node* head)
{
    int choice;
    Type data;
    do
    {
        ifoMenu();
        printf("选择操作:");
        scanf("%d",&choice);
		printf("\n");
        switch(choice)
        {
            case 1:head=addBooks(head,data);
					saveFile(head);
                    break;
            case 2:head=deleteBooks(head,data);
					saveFile(head);
                    break;
            case 3:head=borrowBooks(head,data);
					saveFile(head);
                    break;
			case 4:head=returnBooks(head,data);
					saveFile(head);
                    break;
            case 0:break;
        }
    }while(choice);
    return head;
}
void searchWithName(Node* head)
{
   Type data;
   Node* p=head,* head1=NULL;
   printf("输入欲搜图书书名：\n");
   scanf("%s",data.name);
   printf("\n");
   while(p)
   {
      if(p=SearchNode(p,data,2))
      head1=InsertAfter(head1,p->data);//原来无赋值
	  if(p==NULL)
	  break;//原来无此句无法解决链表建立后p指空问题
      p=p->next;
   }
   if(head1!=NULL)
        {
            PrintList(head1);
        }
   else
      printf("图书馆中无此书！\n");
   printf("\n");
}
void searchWithBackate(Node* head)
{
   Type data;
   Node* p=head,* head1=NULL;
   printf("输入今日日期（yyyymmdd）:\n");
      scanf("%ld",&data.backDate[0]);
       printf("\n");
   while(p)
   {
      if(p=SearchNode(p,data,3))
      head1=InsertAfter(head1,p->data); 
	  if(p==NULL)
	  break;
      p=p->next;
   }
   if(head1!=NULL)
        {
            PrintList(head1);
        }
   else
      printf("图书馆中无归还日期三天之内的书！\n");
   printf("\n");
}
Node* range(Node* head)
{
    Node* headOrder=NULL,* p=head;
    while(p)
    {
        headOrder=InsertOrder(headOrder,p->data,2);
        p=p->next;
    }
    headOrder=Reverse(headOrder);
	if(headOrder!=NULL)
        {
		    printf("按借阅次数排序的结果：\n");
            PrintList(headOrder);
        }
	else
      printf("图书馆无书！\n");
	printf("\n");
    return headOrder;
}
