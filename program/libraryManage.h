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
	printf("-----���˵�-----\n");
    printf("1.ͼ����Ϣ����\n");
    printf("2.��������ѯͼ����Ϣ\n");
    printf("3.��ʾ���м������ڣ�����֮�ڣ���ͼ��\n");
    printf("4.ͼ�鰴���Ĵ�������\n");
    printf("0.�˳�����ϵͳ\n");
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
	printf("-----ͼ����Ϣ����-----\n");
    printf("1.���ͼ��\n");
    printf("2.ɾ��ͼ����Ϣ\n");
    printf("3.����\n");
	printf("4.����\n");
    printf("0.�������˵�\n");
}
Node* addBooks(Node* head,Type data)
{
   readNode(&data);
   head=InsertOrder(head,data,1);
   return head;
}
Node* deleteBooks(Node* head,Type data)
{
   printf("������ɾ��ͼ�������ţ�");
   scanf("%s",&data.ID);
   head=Delete(head,data);
   printf("\n");
   return head;
}
Node* borrowBooks(Node* head,Type data)
{
  int i,bornum;
  Node* p=NULL;
  printf("����������ͼ�������ţ�");
  scanf("%s",&data.ID);
  if(p=SearchNode(head,data,1))//������if��pָ��
  {	printf("���ļ��������������������0��С�ڵ���%d������",(p->data).num);
    scanf("%d",&bornum);
	if(bornum>0&&bornum<=(p->data).num&&!strcmp((p->data).borSitu,"�ɽ�"))
    {
      for(i=0;i<bornum;i++)
	  {
		  printf("����黹���ڣ�yyyymmdd����\n");
		  scanf("%ld",&((p->data).backDate[(p->data).num1-(p->data).num]));
		  (p->data).num--;				
		  (p->data).borTimes++;
		  if((p->data).num==0)
			  (p->data).borSitu="���ɽ�";
	  }//��data���н��Ĳ���
	}
	else
	   printf("����ͼ�������������٣�\n");
  }
  else
	  printf("ͼ������޴��飡\n");
  printf("\n");
  return head;
}
Node* returnBooks(Node* head,Type data)
{
  int i,j,k,retnum;
  long pos;
  Node* p=NULL;
  printf("�������黹ͼ�������ţ�");
  scanf("%s",&data.ID);
  if(p=SearchNode(head,data,1))
  {	printf("�黹���������������������0��С�ڵ���%d������",(p->data).num1-(p->data).num);
    scanf("%d",&retnum);
	if(retnum>0&&retnum<=((p->data).num1-(p->data).num))
    {
      for(i=0;i<retnum;i++)
	  {
		  printf("������ʱ�ǼǵĹ黹���ڣ�yyyymmdd����\n");
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
			  printf("�ù黹���ڲ����ڣ����������룡\n");
		  }
		  if(j==((p->data).num1-(p->data).num))
		  {
			  i--;
			  continue;
		  }
		  else
		  (p->data).num++;	
		  
	  }//��data���й黹����
	  (p->data).borSitu="�ɽ�";
	}
	else
	   printf("����ͼ�������������٣�\n");
  }
  else
	  printf("ͼ������޴��飡\n");
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
        printf("ѡ�����:");
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
   printf("��������ͼ��������\n");
   scanf("%s",data.name);
   printf("\n");
   while(p)
   {
      if(p=SearchNode(p,data,2))
      head1=InsertAfter(head1,p->data);//ԭ���޸�ֵ
	  if(p==NULL)
	  break;//ԭ���޴˾��޷������������pָ������
      p=p->next;
   }
   if(head1!=NULL)
        {
            PrintList(head1);
        }
   else
      printf("ͼ������޴��飡\n");
   printf("\n");
}
void searchWithBackate(Node* head)
{
   Type data;
   Node* p=head,* head1=NULL;
   printf("����������ڣ�yyyymmdd��:\n");
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
      printf("ͼ������޹黹��������֮�ڵ��飡\n");
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
		    printf("�����Ĵ�������Ľ����\n");
            PrintList(headOrder);
        }
	else
      printf("ͼ������飡\n");
	printf("\n");
    return headOrder;
}
