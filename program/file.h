#include<stdio.h>
#include<stdlib.h>
#include"list.h"
void createFile();//创建文件
void saveFile(Node* head);//读取文件
Node* readFile(Node* head);//保存文件

void createFile()//创建文件
{
    Type data;
    FILE *fp;
    if((fp=fopen("library.dat","wb"))==NULL)
    {
        printf("library.dat无法打开！\n");
		printf("\n");
        exit(0);
    }
    readNode(&data);
    while(data.num!=0)
    {
        fwrite(&data,sizeBook,1,fp);
        readNode(&data);
    }
    fclose(fp);
}
Node* readFile(Node* head)//读取文件
{
    Type data;
    FILE* fp;
    head=NULL;
    if((fp=fopen("library.dat","rb"))==NULL)
    {
        printf("library.dat不存在，建立文件中...\n");
		printf("\n");
        return(0);
    }
    fread(&data,sizeBook,1,fp);
    while(!feof(fp))
    {
        head=InsertOrder(head,data,1);
        fread(&data,sizeBook,1,fp);
    }
    fclose(fp);
    return head;
}
void saveFile(Node* head)//保存文件
{
    Node* p=head;
    FILE* fp;
    if((fp=fopen("library.dat","wb"))==NULL)
    {
        printf("library.dat无法打开！\n");
		printf("\n");
        exit(0);
    }
    if(head==NULL)
    {
        printf("图书馆无书！\n");
		printf("\n");
        return ;
    }
    while(p)
    {
        fwrite(&p->data,sizeBook,1,fp);
        p=p->next;
    }
    fclose(fp);
}
