#include <stdio.h>


#define MaxSize 100//不能加;号
typedef struct {
    int data[MaxSize];
    int length;
} SqList;

//初始化顺序表
int CreateList(SqList *L, int data[], int n) {
    if (n > MaxSize) {
        printf("顺序表的空间不够，无法建立顺序表\n");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        L->data[i] = data[i];
    }
    L->length = n;
    return 1;

}

//输出线性表
void PrintSqList(SqList *L) {
    for (int i = 0; i < L->length; i++) {
        printf("%d\n", L->data[i]);
    }
}

//插入数据表
int InsertSqList(SqList *L, int n, int i)//L为要插入的链表,n为要插入的数据,i 为要插入位置
{
    if (i < 0 || i >= L->length + 1) {
        printf("插入的位置溢出\n");
        return 0;
    }
    if (L->length >= MaxSize) {
        printf("顺序表长度已经达到最大值\n");
        return 0;
    }
    for (int j = L->length; j >= i; j--) {
        L->data[j] = L->data[j - 1];
    }
    L->data[i - 1] = n;
    L->length++;

}

//按值查找
int LocateElem(SqList L, int n) {
    for (int i = 0; i < L.length; ++i) {
        if (L.data[i] == n)
            return i + 1;
    }
    return -1;
}

//算法题：收缩整个顺序表，找到最小的一个，然后用最后一个元素替换掉那个最小值
void findMinThenUpdate(SqList *L)
{
//    设定一个最小值
    int value=L->data[0];
//    来存储最小值的地址
    int add=0;

    for (int i = 0; i < L->length; ++i) {
        if(L->data[i]<value)
        {
            value=L->data[i];
            add=i;
        }
    }
    L->data[add]=L->data[L->length-1];
}


int main() {

//        初始化链表
    int data[5] = {3, 2, 3, 4, 5};
    SqList L;
    CreateList(&L, data, 5);
//修改前的顺序表
    printf("修改前的顺序表\n");
    PrintSqList(&L);
    findMinThenUpdate(&L);
//    修改后的顺序表
    printf("修改后的顺序表\n");
    PrintSqList(&L);

////    初始化链表
//    int data[5] = {3, 2, 3, 4, 5};
//    SqList L;
//    CreateList(&L, data, 5);
////插入前
//    printf("插入前的顺序表\n");
//    PrintSqList(&L);
//
//    InsertSqList(&L, 10, 3);
//
////插入后
//    printf("插入后的顺序表\n");
//    PrintSqList(&L);
//
//    int result = LocateElem(L, 10);
//    if (result == -1) {
//        printf("未找到该数值\n");
//    } else {
//        printf("找到了,该数的位置在顺序表的第%d个\n",result);
//    }
}
