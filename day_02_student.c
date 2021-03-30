//
// Created by zx on 2021/3/18.
//
#include "stdio.h"

#define MaxSize 100
typedef int ElemType;
typedef struct {
    ElemType data[MaxSize];
    int length;
}SqList;
int CreatList(SqList *L, data[], int n)
{
    if (n > MaxSize) { printf("顺序表的空间不够，无法建立顺序表\n"); return 0; }
    for (int i = 0; i < n; i++)
        L->data[i] = data[i];
    L->length = n;
    return 1;
}
void PrintList(SqList *L)
{
    for(int i=0;i<=L->length;i++){
        printf("%d\n",L->data[i]);
    }

}

int ListInsert(SqList *L,int i,ElemType e){
    if(i<1||i>L->length+1){
        printf("未知错误，插入失败\n");
        return 0;//false
    }
    if(L->length>=MaxSize){
        printf("溢出错误，插入失败\n");
        return 0;//false
    }
    for(int j=L->length;j>=i;j--)
        L->data[j]=L->data[j-1];
    L->data[i-1]=e;
    L->length++;
    return 1;
}




int main(){

    int r[5]={1,2,3,4,5},i,x;
    SqList L;
    CreatList(&L,r,5);
    printf("当前线性表的数据为\n");
    PrintList(&L);                      /*输出当前线性表1 2 3 4 5*/




//
//    int arr[]={1,2,3,4,5,5,4,3,2,1,7,7,-9,-9,9};
//    int sz=sizeof(arr)/sizeof (int );
//    int ret=0;
//    for (int i=0;i<sz;i++){
//        ret=ret^arr[i];
//    }
//    printf("单身狗是:%d\n",ret);





//    int sum1=0;
//    int sum2=0;
//    scanf("%d%d",&sum1,&sum2);
//    int sum=sum1+sum2;
//    printf("sum1+sum2=%d\n",sum);
//    return 0;
}