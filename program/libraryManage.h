#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"file.h"
void menu()
{
    printf("1.ͼ����Ϣ����\n");
    printf("2.��������ѯͼ����Ϣ\n");
    printf("3.��ʾ���м������ڣ�����֮�ڣ���ͼ��\n");
    printf("4.ͼ�鰴���Ĵ�������\n");
    printf("0.�˳�����ϵͳ\n");
    return;
}
void ifoMenu()
{
    printf("1.���ͼ��\n");
    printf("2.ɾ��ͼ����Ϣ\n");
    printf("3.�޸�ͼ����Ϣ\n");
    printf("0.�������˵�\n");
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
        printf("ѡ�����:");
        scanf("%d",&choice);
		printf("\n");
        switch(choice)
        {
            case 1:readNode(&data);
                    head=InsertOrder(head,data,1);
					saveFile(head);
                    break;
            case 2:printf("������ɾ��ͼ�������ţ�");
                    scanf("%s",&data.ID);
                    head=Delete(head,data);
					saveFile(head);
					printf("\n");
                    break;
            case 3:printf("���Ĺ���(y/n)\n");
				   getchar();
                   scanf("%c",&choice1);
				   printf("\n");
                   if(choice1=='y'||choice1=='Y')
                    {
                        printf("����������ͼ�������ţ�");
                        scanf("%s",&data.ID);
                        if(p=SearchNode(head,data,1))//������if��ָp��
                        {	printf("���ļ��������������������0��С�ڵ���%d������",(p->data).num);
							scanf("%d",&bornum);
							if(bornum>0&&bornum<=(p->data).num&&!strcmp((p->data).borSitu,"�ɽ�"))
                            {
                                printf("����黹���ڣ�yyyymmdd����\n");
                                for(i=0;i<bornum;i++)
								{
									scanf("%ld",&((p->data).backDate[(p->data).num1-(p->data).num]));
									(p->data).num--; 
									(p->data).borTimes++;
									if((p->data).num==0)
                                    (p->data).borSitu="���ɽ�";
								}//��data���н��Ĳ���
                            }
							else
								printf("����ͼ�������������٣�\n");
						saveFile(head);
						}
						else
							printf("ͼ������޴��飡\n");
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
