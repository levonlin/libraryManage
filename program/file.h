#include<stdio.h>
#include<stdlib.h>
#include"list.h"
void createFile()
{
    Type data;
    FILE *fp;
    if((fp=fopen("library.dat","wb"))==NULL)
    {
        printf("library.dat无法打开！\n");
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
Node* readFile(Node* head)
{
    Type data;
    FILE* fp;
    head=NULL;
    if((fp=fopen("library.dat","rb"))==NULL)
    {
        printf("library.dat不存在，请先建立文件！\n");
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
void saveFile(Node* head)
{
    Node* p=head;
    FILE* fp;
    if((fp=fopen("library.dat","wb"))==NULL)
    {
        printf("library.dat无法打开！\n");
        exit(0);
    }
    if(head==NULL)
    {
        printf("记录为空！\n");
        return ;
    }
    while(p)
    {
        fwrite(&p->data,sizeBook,1,fp);
        p=p->next;
    }
    fclose(fp);
}
