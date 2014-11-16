#ifndef _NODE
#define _NODE
struct book
{				//图书结构
    char ID[20];//索引号
    char name[20];//名称
    char loc[10];//馆藏地址
    char class[10];//类别
    int  num,num1;//num记录书的在库数量，num1记录书的总数量
    double prize;//价格
    long inDate[1000];//入库日期
	int inTimes;//记录进书批数
    long backDate[1000];//归还日期
    int borTimes;//借阅时间
    char* borSitu;//借阅情况
};
typedef struct book Type;
const int sizeBook=sizeof(Type);
typedef struct node
{						//结点结构
    Type data;//结点元素内容
    struct node* next;//指向下一节点的指针
}Node;
const int size=sizeof(struct node);
#endif
