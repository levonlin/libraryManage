#ifndef _PREP
#define _PREP
#include"node.h"
#include<string.h>
void printNode(Type data)
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
    printf("%s","������ڣ�");
	printf("%ld\n",data.inDate);
    printf("%s","���Ĵ�����");
	printf("%d\n",data.borTimes);
    printf("%s","����״����");
	printf("%s\n",data.borSitu);
    printf("%s\n","�黹���ڣ�");
	for(i=0;i<data.num1;i++)
	{
		if(data.backDate[i]==0)
			continue;
		printf("%ld\n",data.backDate[i]);
	}
	printf("\n");
}
void readNode(Type* pdata)
{
    int i;
    printf("�������ͼ����Ϣ����ͼ������Ϊ���������\n");
    printf("������");
    scanf("%d",&pdata->num);
	if(pdata->num==0)
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
    scanf("%lf",&pdata->prize);//
    printf("������ڣ�yyyymmdd����");
    scanf("%ld",&pdata->inDate);
    /*pdata->backDate=(long*)malloc((pdata->num)*(sizeof(long)));
    if(pdata->backDate==NULL)
    {
        printf("Allocation failure!");
        exit(1);
    }*/
    for(i=0;i<pdata->num;i++)
    pdata->backDate[i]=0;//����longָ��������洢�黹���ڣ������и�ֵ��ʼ��Ϊ0
    pdata->borTimes=0;
    pdata->borSitu="�ɽ�";
	printf("\n");
}
int equal(Type data1,Type data2,int condition)
{
    int i,a;
    if(condition==1)
        return (strcmp(data1.ID,data2.ID)==0);
    else if(condition==2)
	return (strcmp(data1.name,data2.name)==0);
    else if(condition==3)
        for(i=0;i<data1.num;i++)
        {
         a=data1.backDate[i]-data2.backDate[0];
         if(a>=0&&a<=3)
         return 1;
        }
     return 0;
}
int larger(Type data1,Type data2,int condition)
{
    if(condition==1)
        return data1.ID>data2.ID;
    if(condition==2)
        return data1.borTimes>data2.borTimes;
    return 1;
}
#endif // _PREP
