#ifndef _PREP
#define _PREP
#include"node.h"
#include<string.h>
void printNode(Type data);//��ӡ���
void readNode(Type* pdata);//������
int equal(Type data1,Type data2,int condition);//�������жϽ���Ƿ����
int larger(Type data1,Type data2,int condition);//�������жϽ���С

void printNode(Type data)//��ӡ���
{
    int i;
	printf("%s","�����ţ�");
    printf("%s\n",data.ID);
	printf("%s","������");
    printf("%s\n",data.name);
	printf("%s","�ݲصأ�");
    printf("%s\n",data.loc);
	printf("%s","���");
    printf("%s\n",data.class);
	printf("%s","������");
    printf("%d\n",data.num);
    printf("%s","�۸�");
	printf("%f\n",data.prize);
	printf("%s","��������");
	printf("%d\n",data.inTimes);
    printf("%s\n","������ڣ�");
	for(i=0;i<data.inTimes;i++)
	{
		printf("%ld\n",data.inDate[i]);
	}
    printf("%s","���Ĵ�����");
	printf("%d\n",data.borTimes);
    printf("%s","����״����");
	printf("%s\n",data.borSitu);
    printf("%s\n","�黹���ڣ�");
	for(i=0;i<(data.num1-data.num);i++)
	{
		printf("%ld\n",data.backDate[i]);
	}
	printf("\n");
}
void readNode(Type* pdata)//������
{
    int i;
    printf("�������ͼ����Ϣ����ͼ������С�ڵ������������\n");
    printf("������");
    scanf("%d",&pdata->num);
	if(pdata->num<=0)
	{
		printf("\n");
		return;
	}
	pdata->num1=pdata->num;
    printf("������:");
    scanf("%s",&pdata->ID);
    printf("����:");
    scanf("%s",&pdata->name);
    printf("�ݲصأ�����¥�����֣���");
    scanf("%s",&pdata->loc);
    printf("������ġ��Ƽ�������ȣ���");
    scanf("%s",&pdata->class);
    printf("�۸�");
    scanf("%lf",&pdata->prize);//scanf����double����Ϊ%lf
    pdata->inTimes=1;
    printf("������ڣ�yyyymmdd����");
    scanf("%ld",&pdata->inDate[0]);
    for(i=0;i<pdata->num;i++)
    pdata->backDate[i]=0;//����longָ��������洢�黹���ڣ������и�ֵ��ʼ��Ϊ0
    pdata->borTimes=0;
    pdata->borSitu="�ɽ�";
	printf("\n");
}
int equal(Type data1,Type data2,int condition)//�������жϽ���Ƿ����
{
    int i,a;
    if(condition==1)
        return (strcmp(data1.ID,data2.ID)==0);
    else if(condition==2)
	return (strcmp(data1.name,data2.name)==0);
    else if(condition==3)
        for(i=0;i<(data1.num1-data1.num);i++)
        {
         a=data1.backDate[i]-data2.backDate[0];
         if(a>=0&&a<=3)
         return 1;
        }
     return 0;
}
int larger(Type data1,Type data2,int condition)//�������жϽ���С
{
    if(condition==1)
        return (strcmp(data1.ID,data2.ID)>0);//ID�ѱ�Ϊ�ַ�����
    if(condition==2)
        return data1.borTimes>data2.borTimes;
    return 1;
}
#endif // _PREP
