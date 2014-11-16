#include<stdio.h>
#include<stdlib.h>
#include"list.h"
void createFile();
void saveFile(Node* head);
Node* readFile(Node* head);

void createFile()
{
    Type data;
    FILE *fp;
    if((fp=fopen("library.dat","wb"))==NULL)
    {
        printf("library.dat�޷��򿪣�\n");
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
Node* readFile(Node* head)
{
    Type data;
    FILE* fp;
    head=NULL;
    if((fp=fopen("library.dat","rb"))==NULL)
    {
        printf("library.dat�����ڣ������ļ���...\n");
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
void saveFile(Node* head)
{
    Node* p=head;
    FILE* fp;
    if((fp=fopen("library.dat","wb"))==NULL)
    {
        printf("library.dat�޷��򿪣�\n");
		printf("\n");
        exit(0);
    }
    if(head==NULL)
    {
        printf("ͼ������飡\n");
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
