#ifndef _NODE
#define _NODE
struct book
{				//ͼ��ṹ
    char ID[20];//������
    char name[20];//����
    char loc[10];//�ݲص�ַ
    char class[10];//���
    int  num,num1;//num��¼����ڿ�������num1��¼���������
    double prize;//�۸�
    long inDate[1000];//�������
	int inTimes;//��¼��������
    long backDate[1000];//�黹����
    int borTimes;//����ʱ��
    char* borSitu;//�������
};
typedef struct book Type;
const int sizeBook=sizeof(Type);
typedef struct node
{						//���ṹ
    Type data;//���Ԫ������
    struct node* next;//ָ����һ�ڵ��ָ��
}Node;
const int size=sizeof(struct node);
#endif
