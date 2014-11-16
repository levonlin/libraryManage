#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"file.h"
void menu()
{
    printf("1.图书信息更新\n");
    printf("2.按书名查询图书信息\n");
    printf("3.显示所有即将到期（三天之内）的图书\n");
    printf("4.图书按借阅次数排序\n");
    printf("0.退出管理系统\n");
    return;
}
void ifoMenu()
{
    printf("1.添加图书\n");
    printf("2.删除图书信息\n");
    printf("3.修改图书信息\n");
    printf("0.返回主菜单\n");
}
Node* ifoManage(Node* head)
{
    int choice,i,j,bornum;
	char choice1;
    Type data;
    Node* p=NULL;
    do
    {
        ifoMenu();
        printf("选择操作:");
        scanf("%d",&choice);
		printf("\n");
        switch(choice)
        {
            case 1:readNode(&data);
                    head=InsertOrder(head,data,1);
					saveFile(head);
                    break;
            case 2:printf("输入欲删除图书索引号：");
                    scanf("%s",&data.ID);
                    head=Delete(head,data);
					saveFile(head);
					printf("\n");
                    break;
            case 3:printf("借阅管理？(y/n)\n");
				   getchar();
                   scanf("%c",&choice1);
				   printf("\n");
                   if(choice1=='y'||choice1=='Y')
                    {
                        printf("输入欲借阅图书索引号：");
                        scanf("%s",&data.ID);
                        if(p=SearchNode(head,data,1))//必须有if防指p空
                        {	printf("借阅几本（所借数量必须大于0且小于等于%d本）：",(p->data).num);
							scanf("%d",&bornum);
							if(bornum>0&&bornum<=(p->data).num&&!strcmp((p->data).borSitu,"可借"))
                            {
                                printf("输入归还日期（yyyymmdd）：\n");
                                for(i=0;i<bornum;i++)
								{
									scanf("%ld",&((p->data).backDate[(p->data).num1-(p->data).num]));
									(p->data).num--; 
									(p->data).borTimes++;
									if((p->data).num==0)
                                    (p->data).borSitu="不可借";
								}//对data进行借阅操作
                            }
							else
								printf("所借图书数量过多或过少！\n");
						saveFile(head);
						}
						else
							printf("图书馆中无此书！\n");
						printf("\n");
                    }
                    else
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
    return headOrder;
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
