#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"file.h"
void menu();//主菜单
Node* runMenu(Node* head,int choice);//运行主菜单
void ifoMenu();//信息更新菜单
void addMenu();//添加菜单
Node* addBooks1(Node* head,Type data);//添加新图书
Node* addBooks2(Node* head,Type data);//添加原有图书
Node* addManage(Node* head,Type data);//运行添加菜单
Node* deleteBooks(Node* head,Type data);//删除图书
Node* borrowBooks(Node* head,Type data);//借书
Node* returnBooks(Node* head,Type data);//还书
Node* ifoManage(Node* head);//运行信息更新菜单
void searchWithName(Node* head);//按图书名称查找
void searchWithBackate(Node* head);//查找归还日期在三天以内的图书
Node* range(Node* head);//按借阅次数排序

void menu()//主菜单
{
	system("cls");
	printf("\n\n\n\n\n\t\t**********欢迎使用南邮图书馆管理系统**********\t\t\n");
	printf("\n");
	printf("\t\t\t---------主菜单---------\n");
    printf("\t\t\t1.图书信息更新\n");
    printf("\t\t\t2.按书名查询图书信息\n");
    printf("\t\t\t3.显示所有即将到期（三天之内）的图书\n");
    printf("\t\t\t4.图书按借阅次数排序\n");
    printf("\t\t\t0.退出管理系统\n");
    return;
}
Node* runMenu(Node* head,int choice)//运行主菜单
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
void ifoMenu()//信息更新菜单
{
	system("cls");
	printf("\n\n\n\n\n\t\t\t---------图书信息更新---------\n");
    printf("\t\t\t1.添加图书\n");
    printf("\t\t\t2.删除图书信息\n");
    printf("\t\t\t3.借阅\n");
	printf("\t\t\t4.还书\n");
    printf("\t\t\t0.返回主菜单\n");
}
void addMenu()//添加菜单
{
	system("cls");
	printf("\n\n\n\n\n\t\t\t---------添加图书---------\n");
	printf("\t\t\t1.添加新图书\n");
    printf("\t\t\t2.添加原有图书\n");
	printf("\t\t\t0.返回上级菜单\n");
}
Node* addBooks1(Node* head,Type data)//添加新图书
{
	system("cls");
	while(1)
	{
		readNode(&data);
		if(data.num<=0)
			break;
		head=InsertOrder(head,data,1);
		printf("添加成功！\n");
	}
   return head;
}
Node* addBooks2(Node* head,Type data)//添加原有图书
{
   int addnum;
   Node* p=NULL;
   system("cls");
   printf("输入原有图书索引号：");
   scanf("%s",&data.ID);
   if(p=SearchNode(head,data,1))
   {	printf("添加书本数量（大于零本）：");
        scanf("%d",&addnum);
		if(addnum>0)
		{
			printf("添加入库日期（yyyyddmm）：");
			scanf("%ld",&(p->data.inDate[p->data.inTimes]));
			p->data.num+=addnum;
			p->data.num1+=addnum;
			p->data.inTimes++;
			printf("添加成功！\n");
		}
		else
			printf("添加数量不正确\n");
   }
   else
	   printf("图书馆中无此书！\n");
       getchar();
	   getchar();
   printf("\n");
   return head;
}
Node* addManage(Node* head,Type data)//运行添加菜单
{
	int choice;
	do
	{
		addMenu();
        printf("\t\t\t选择操作:");
        scanf("%d",&choice);
		printf("\n");
		if(choice>=0&&choice<=2)
            switch(choice)
			{
				case 1:head=addBooks1(head,data);
						break;
				case 2:head=addBooks2(head,data);
						break;
				case 0:break;
			}
				else
                {
					printf("\t\t\t选项输入错误，请按回车再次输入！\n\n");
					getchar();
					getchar();
				}
	}while(choice);
	return head;
}
Node* deleteBooks(Node* head,Type data)//删除图书
{
   system("cls");
   printf("输入欲删除图书索引号：");
   scanf("%s",&data.ID);
   head=Delete(head,data);
   getchar();
   getchar();
   printf("\n");
   return head;
}
Node* borrowBooks(Node* head,Type data)//借书
{
  int i,bornum;
  Node* p=NULL;
  system("cls");
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
		  printf("借阅成功！");
	  }//对data进行借阅操作
	}
	else
	   printf("所借图书数量过多或过少！\n");
  }
  else
	  printf("图书馆中无此书！\n");
      getchar();
	  getchar();
  printf("\n");
  return head;
}
Node* returnBooks(Node* head,Type data)//还书
{
  int i,j,k,retnum;
  long pos;
  Node* p=NULL;
  system("cls");
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
	  printf("归还成功！");
	}
	else
	   printf("所还图书数量过多或过少！\n");
  }
  else
	  printf("图书馆中无此书！\n");
      getchar();
	  getchar();
  printf("\n");
  return head;
}
Node* ifoManage(Node* head)//运行信息更新菜单
{
    int choice;
    Type data;
    do
    {
        ifoMenu();
        printf("\t\t\t选择操作:");
        scanf("%d",&choice);
		printf("\n");
		if(choice>=0&&choice<=4)
             switch(choice)
			{
				case 1:head=addManage(head,data);
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
            else
			{
                printf("\t\t\t选项输入错误，请按回车再次输入！\n\n");
				getchar();
		        getchar();
			}
    }while(choice);
    return head;
}
void searchWithName(Node* head)//按图书名称查找
{
   Type data;
   Node* p=head,* head1=NULL;
   system("cls");
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
      getchar();
	  getchar();
   printf("\n");
}
void searchWithBackate(Node* head)//查找归还日期在三天以内的图书
{
   Type data;
   Node* p=head,* head1=NULL;
   system("cls");
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
      getchar();
      getchar();
   printf("\n");
}
Node* range(Node* head)//按借阅次数排序
{
    Node* headOrder=NULL,* p=head;
	system("cls");
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
      getchar();
      getchar();
	printf("\n");
    return headOrder;
}
