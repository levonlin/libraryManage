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
        printf("ѡ�����:");
        scanf("%d",&choice);
		printf("\n");
        if(choice>=0&&choice<=5)
            head=runMenu(head,choice);
            else
                printf("ѡ������������ٴ����룡\n\n");
    }while(choice);
    saveFile(head);
    return 0;
}
