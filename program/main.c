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
        printf("\t\t\t选择操作:");
        scanf("%d",&choice);
		printf("\n");
        if(choice>=0&&choice<=4)
            head=runMenu(head,choice);
            else
			{
				printf("\t\t\t选项输入错误，请按回车再次输入！\n\n");
				getchar();
				getchar();//两个getchar()防止过快清屏导致错过信息提示
			}
    }while(choice);
    saveFile(head);
    return 0;
}
