#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"file.h"
void menu();//���˵�
Node* runMenu(Node* head,int choice);//�������˵�
void ifoMenu();//��Ϣ���²˵�
void addMenu();//��Ӳ˵�
Node* addBooks1(Node* head,Type data);//�����ͼ��
Node* addBooks2(Node* head,Type data);//���ԭ��ͼ��
Node* addManage(Node* head,Type data);//������Ӳ˵�
Node* deleteBooks(Node* head,Type data);//ɾ��ͼ��
Node* borrowBooks(Node* head,Type data);//����
Node* returnBooks(Node* head,Type data);//����
Node* ifoManage(Node* head);//������Ϣ���²˵�
void searchWithName(Node* head);//��ͼ�����Ʋ���
void searchWithBackate(Node* head);//���ҹ黹�������������ڵ�ͼ��
Node* range(Node* head);//�����Ĵ�������

void menu()//���˵�
{
	system("cls");
	printf("\n\n\n\n\n\t\t**********��ӭʹ������ͼ��ݹ���ϵͳ**********\t\t\n");
	printf("\n");
	printf("\t\t\t---------���˵�---------\n");
    printf("\t\t\t1.ͼ����Ϣ����\n");
    printf("\t\t\t2.��������ѯͼ����Ϣ\n");
    printf("\t\t\t3.��ʾ���м������ڣ�����֮�ڣ���ͼ��\n");
    printf("\t\t\t4.ͼ�鰴���Ĵ�������\n");
    printf("\t\t\t0.�˳�����ϵͳ\n");
    return;
}
Node* runMenu(Node* head,int choice)//�������˵�
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
void ifoMenu()//��Ϣ���²˵�
{
	system("cls");
	printf("\n\n\n\n\n\t\t\t---------ͼ����Ϣ����---------\n");
    printf("\t\t\t1.���ͼ��\n");
    printf("\t\t\t2.ɾ��ͼ����Ϣ\n");
    printf("\t\t\t3.����\n");
	printf("\t\t\t4.����\n");
    printf("\t\t\t0.�������˵�\n");
}
void addMenu()//��Ӳ˵�
{
	system("cls");
	printf("\n\n\n\n\n\t\t\t---------���ͼ��---------\n");
	printf("\t\t\t1.�����ͼ��\n");
    printf("\t\t\t2.���ԭ��ͼ��\n");
	printf("\t\t\t0.�����ϼ��˵�\n");
}
Node* addBooks1(Node* head,Type data)//�����ͼ��
{
	system("cls");
	while(1)
	{
		readNode(&data);
		if(data.num<=0)
			break;
		head=InsertOrder(head,data,1);
		printf("��ӳɹ���\n");
	}
   return head;
}
Node* addBooks2(Node* head,Type data)//���ԭ��ͼ��
{
   int addnum;
   Node* p=NULL;
   system("cls");
   printf("����ԭ��ͼ�������ţ�");
   scanf("%s",&data.ID);
   if(p=SearchNode(head,data,1))
   {	printf("����鱾�����������㱾����");
        scanf("%d",&addnum);
		if(addnum>0)
		{
			printf("���������ڣ�yyyyddmm����");
			scanf("%ld",&(p->data.inDate[p->data.inTimes]));
			p->data.num+=addnum;
			p->data.num1+=addnum;
			p->data.inTimes++;
			printf("��ӳɹ���\n");
		}
		else
			printf("�����������ȷ\n");
   }
   else
	   printf("ͼ������޴��飡\n");
       getchar();
	   getchar();
   printf("\n");
   return head;
}
Node* addManage(Node* head,Type data)//������Ӳ˵�
{
	int choice;
	do
	{
		addMenu();
        printf("\t\t\tѡ�����:");
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
					printf("\t\t\tѡ����������밴�س��ٴ����룡\n\n");
					getchar();
					getchar();
				}
	}while(choice);
	return head;
}
Node* deleteBooks(Node* head,Type data)//ɾ��ͼ��
{
   system("cls");
   printf("������ɾ��ͼ�������ţ�");
   scanf("%s",&data.ID);
   head=Delete(head,data);
   getchar();
   getchar();
   printf("\n");
   return head;
}
Node* borrowBooks(Node* head,Type data)//����
{
  int i,bornum;
  Node* p=NULL;
  system("cls");
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
		  printf("���ĳɹ���");
	  }//��data���н��Ĳ���
	}
	else
	   printf("����ͼ�������������٣�\n");
  }
  else
	  printf("ͼ������޴��飡\n");
      getchar();
	  getchar();
  printf("\n");
  return head;
}
Node* returnBooks(Node* head,Type data)//����
{
  int i,j,k,retnum;
  long pos;
  Node* p=NULL;
  system("cls");
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
	  printf("�黹�ɹ���");
	}
	else
	   printf("����ͼ�������������٣�\n");
  }
  else
	  printf("ͼ������޴��飡\n");
      getchar();
	  getchar();
  printf("\n");
  return head;
}
Node* ifoManage(Node* head)//������Ϣ���²˵�
{
    int choice;
    Type data;
    do
    {
        ifoMenu();
        printf("\t\t\tѡ�����:");
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
                printf("\t\t\tѡ����������밴�س��ٴ����룡\n\n");
				getchar();
		        getchar();
			}
    }while(choice);
    return head;
}
void searchWithName(Node* head)//��ͼ�����Ʋ���
{
   Type data;
   Node* p=head,* head1=NULL;
   system("cls");
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
      getchar();
	  getchar();
   printf("\n");
}
void searchWithBackate(Node* head)//���ҹ黹�������������ڵ�ͼ��
{
   Type data;
   Node* p=head,* head1=NULL;
   system("cls");
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
      getchar();
      getchar();
   printf("\n");
}
Node* range(Node* head)//�����Ĵ�������
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
		    printf("�����Ĵ�������Ľ����\n");
            PrintList(headOrder);
        }
	else
      printf("ͼ������飡\n");
      getchar();
      getchar();
	printf("\n");
    return headOrder;
}
