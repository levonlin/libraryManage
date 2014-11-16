#ifndef _NODE
#define _NODE
struct book
{
    char ID[20];
    char name[20];
    char loc[10];
    char class[10];
    int  num,num1;//num1记录书的初始数量
    double prize;
    long inDate;
    long backDate[1000];
    int borTimes;
    char* borSitu;
};
typedef struct book Type;
const int sizeBook=sizeof(Type);
typedef struct node
{
    Type data;
    struct node* next;
}Node;
const int size=sizeof(struct node);
#endif
