#ifndef _PREP
#define _PREP
#include"node.h"
#include<string.h>
void printNode(Type data);//打印结点
void readNode(Type* pdata);//输入结点
int equal(Type data1,Type data2,int condition);//按条件判断结点是否相等
int larger(Type data1,Type data2,int condition);//按条件判断结点大小

void printNode(Type data)//打印结点
{
    int i;
	printf("%s","索引号：");
    printf("%s\n",data.ID);
	printf("%s","书名：");
    printf("%s\n",data.name);
	printf("%s","馆藏地：");
    printf("%s\n",data.loc);
	printf("%s","类别：");
    printf("%s\n",data.class);
	printf("%s","数量：");
    printf("%d\n",data.num);
    printf("%s","价格：");
	printf("%f\n",data.prize);
	printf("%s","入库次数：");
	printf("%d\n",data.inTimes);
    printf("%s\n","入库日期：");
	for(i=0;i<data.inTimes;i++)
	{
		printf("%ld\n",data.inDate[i]);
	}
    printf("%s","借阅次数：");
	printf("%d\n",data.borTimes);
    printf("%s","借阅状况：");
	printf("%s\n",data.borSitu);
    printf("%s\n","归还日期：");
	for(i=0;i<(data.num1-data.num);i++)
	{
		printf("%ld\n",data.backDate[i]);
	}
	printf("\n");
}
void readNode(Type* pdata)//输入结点
{
    int i;
    printf("输入该批图书信息（以图书数量小于等于零结束）：\n");
    printf("数量：");
    scanf("%d",&pdata->num);
	if(pdata->num<=0)
	{
		printf("\n");
		return;
	}
	pdata->num1=pdata->num;
    printf("索引号:");
    scanf("%s",&pdata->ID);
    printf("书名:");
    scanf("%s",&pdata->name);
    printf("馆藏地（三牌楼、仙林）：");
    scanf("%s",&pdata->loc);
    printf("类别（人文、科技、外语等）：");
    scanf("%s",&pdata->class);
    printf("价格：");
    scanf("%lf",&pdata->prize);//scanf输入double必须为%lf
    pdata->inTimes=1;
    printf("入库日期（yyyymmdd）：");
    scanf("%ld",&pdata->inDate[0]);
    for(i=0;i<pdata->num;i++)
    pdata->backDate[i]=0;//建立long指针型数组存储归还日期，数组中各值初始化为0
    pdata->borTimes=0;
    pdata->borSitu="可借";
	printf("\n");
}
int equal(Type data1,Type data2,int condition)//按条件判断结点是否相等
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
int larger(Type data1,Type data2,int condition)//按条件判断结点大小
{
    if(condition==1)
        return (strcmp(data1.ID,data2.ID)>0);//ID已变为字符数组
    if(condition==2)
        return data1.borTimes>data2.borTimes;
    return 1;
}
#endif // _PREP
