#include<stdio.h>
#include<stdlib.h>
#include"libraryManage.h"
int main()
{
    Node* head=NULL;
    int choice;
    head=readFile(head);
    if(!head)
    {
        createFile();
        head=readFile(head);
    }
    do
    {
        menu();
        printf("\t\t\tѡ�����:");
        scanf("%d",&choice);
		printf("\n");
        if(choice>=0&&choice<=4)
            head=runMenu(head,choice);
            else
			{
				printf("\t\t\tѡ����������밴�س��ٴ����룡\n\n");
				getchar();
				getchar();//����getchar()��ֹ�����������´����Ϣ��ʾ
			}
    }while(choice);
    saveFile(head);
    return 0;
}
