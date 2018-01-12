#include<assert.h>  
#include <stdlib.h>  
#include <iostream>  
#include<assert.h>  
#include<stdlib.h>  
using namespace std;  
#define RADIX_10 10         
#define KEYNUM_31 10        
void Swap(int* a, int* b)  
{  
    int temp;  
    temp = *a;  
    *a = *b;  
    *b = temp;  
}  
//1.≤Â»Î≈≈–Ú  
void InsertSort(int* a, int n)   
{  
    for (int i =0; i<n-1;i++)  
    {  
        int tmp;  
        int end = i;            
        tmp = a[end + 1];       
        while (end>=0)  
        {  
            if (a[end]>tmp)     
            {      
                a[end + 1] = a[end];        
                --end;  
            }                    
            else{  
                break;  
            }  
        }  
        a[end + 1] = tmp;  
    }}  
//œ£∂˚≈≈–Ú  
void ShellSort(int* a, int n)      
{  
    int gap = n;  
    while (gap>1)  
    {  
        gap=gap/3+1;  
        for (int i = 0; i < n-gap;i++)  
        {  
            int tmp;  
            int end = i;  
            tmp = a[end + gap];       
            while (end>=0){  
                if (a[end]>tmp){       
                    a[end + gap] = a[end];      
                    --end;  
                }                     
                else{  
                    break;  
                }  
            }  
            a[end + gap] = tmp;  
        }     
        }  
    }  
//—°‘Ò≈≈–Ú  
void SelectSort1(int* a, int n)  
{  
    int  min,i ;  
    for (i = 0; i < n;i++)  
    {  
        min = i;  
        for (int j = i + 1; j < n;j++)  
        {  
            if (a[j]<=a[min])  
            {  
                min = j;  
            }  
        }  
        swap(a[min], a[i]);  
    }  
}  
void SeleteSort2(int* a, int n)     
{  
    int max, min, i, j;  
    for (i =1; i <=n / 2;i++)  
    {  
        min = i; max = i;      
        for (j = i + 1; j <=n-i;j++)  
        {  
            if (a[j] >a[max])  
            {  
                max = j;  
            }     
            if (a[j] <a[min])  
            {  
                min = j;  
            }  
        }  
        swap(a[i], a[min]);    
        swap(a[n-i], a[max]);         
    }  
}  
//∂—≈≈–Ú  
void AdjustHeap(int *a, int root, int len)  
{  
    int parent = root;  
    int child = 2 * parent + 1;  
    while (child<len)  
    {  
        if (child+1<len&&a[child]<a[child+1])  
        {  
            ++child;  
        }  
        if (a[parent]<a[child])  
        {  
            swap(a[parent],a[child]);  
            parent= child;  
            child = 2 * parent + 1;  
        }  
        else  
        {  
            break;  
        }  
    }  
}  
void BuildHeap(int * a, int len)  
{  
    for (int i = (len - 1) / 2; i >= 0; i--)  
    {  
        AdjustHeap(a, i, len);  
    }  
}  
void HeapSort(int* a, int len)  
{  
    BuildHeap(a, len);  
    for (int i = len - 1; i > 0;i--)  
    {  
        int temp = a[i]; a[i] = a[0]; a[0] = temp;  
        AdjustHeap(a,0, i);  
    }  
}  
//√∞≈›≈≈–Ú  
void BubbleSort(int* a,int len)  
{  
    for (int i= 0; i < len;i++)  
   {  
        for (int j = 0; j < len - i-1;j++)  
        {  
            if (a[j]>a[j+1])  
            {  
                swap(a[j],a[j+1]);  
            }  
        }  
   }  
}  
//øÏÀŸ≈≈–Ú  
int GetMidIndex(int* a, int left, int right)    
{  
    int mid = left+(left - right) / 2;  
    if (a[left]<a[mid])  
    {  
        if (a[mid]<a[right])  
        {  
            return mid;  
        }  
        else if (a[left]>a[right])  
        {  
            return left;  
        }  
        else  
            return right;  
    }  
    else  //left>mid  
    {  
        if (a[mid]>a[right])  
        {  
            return mid;  
        }  
        else if (a[left] < a[right])  
        {  
            return left;  
        }  
        else  
            return right;  
    }  
  
}  
int   PartSort1(int* a, int left, int right)  
{  
    int mid = GetMidIndex(a, left,right);  
    swap(a[mid],a[right]);  
    int key = a[right];  
    int begin = left;  
    int end = right;  
    while (begin < end)  
    {  
        while (begin<end&&a[begin]<=key)  
        {  
            ++begin;  
        }  
        while (begin<end&&a[end]>=key)  
        {  
            --end;  
        }  
        if (begin < end)  
    swap(a[begin], a[end]);  
    }  
   
        swap(a[begin],a[right]);  
        return begin;  
}  
void QuickSort(int* a, int left, int right)  
{  
    assert(a);  
  
    if (left >= right)  
        return;  
  
    if (right - left < 5)  
    {  
        InsertSort(a + left, right - left + 1);  
    }  
    else  
    {  
        int div = PartSort1(a, left, right);  
        QuickSort(a, left, div - 1);  
        QuickSort(a, div + 1, right);  
    }  
}  
//πÈ≤¢≈≈–Ú  
void  Merge(int* a, int* tmp, int begin1, int end1, int begin2, int end2)  
{  
    int pos = begin1;  
    int index = begin1;  
    while (begin1<=end1&&begin2<=end2)  
    {  
        if (a[begin1]<a[begin2])  
        {  
            tmp[index++] = a[begin1++];  
        }  
        else  
        {  
            tmp[index++] = a[begin2++];  
        }  
  
    }  
    while (begin1<=end1)  
    {  
        tmp[index++] = a[begin1++];  
    }  
    while (begin2<=end2)  
    {  
        tmp[index++] = a[begin2++];  
    }  
    memcpy(a+pos,tmp+pos,sizeof(int)*(end2-pos+1));  
}  
void _MergeSort(int* a,int* tmp,int left,int right)  
{  
   if (left>=right)  
   {  
       return;  
   }  
   int mid = left + (right-left) / 2;  
   _MergeSort(a,tmp,left,mid);  
   _MergeSort(a, tmp, mid + 1, right);  
   Merge(a, tmp, left, mid, mid + 1, right);  
}  
void MergeSort(int* a, int len)  
{  
    assert(a);  
    int* tmp = new int[len];  
    _MergeSort(a,tmp,0,len-1);  
    delete[]  tmp;  
}  
void Display(int* a, int n)  
{  
    for (int i = 0; i < n;i++)    
    {  
        cout << a[i] <<"   ";  
    }  
    cout << endl;  
}  
void TestInsertSort()  
{  
    int a[] = { 2, 1, 3, 4, 7, 4, 6, 8, 9, 10 };  
    Display(a, sizeof(a) / sizeof(a[0]));  
    InsertSort(a, sizeof(a) / sizeof(a[0]));  
    Display(a, sizeof(a) / sizeof(a[0]));  
}  
void TestShellSort()  
{  
    int a[] = { 1, 3, 4, 5, 4, 6, 8, 9, 10 };  
    Display(a, sizeof(a) / sizeof(a[0]));  
    ShellSort(a, sizeof(a) / sizeof(a[0]));  
    Display(a, sizeof(a) / sizeof(a[0]));  
}  
void TestSelectSort()  
{  
    int a[] = { 11, 3, 30, 5, 4,60, 5, 9, 10 };  
    Display(a, sizeof(a) / sizeof(a[0]));  
    SelectSort1(a, sizeof(a) / sizeof(a[0]));  
    Display(a, sizeof(a) / sizeof(a[0]));  
    SeleteSort2(a, sizeof(a) / sizeof(a[0]));  
    Display(a, sizeof(a) / sizeof(a[0]));  
}  
void TestHeapSort()  
{  
    int a[] = {3,1,4,2,5,8,6,9,7,10};  
    Display(a, sizeof(a) / sizeof(a[0]));  
    int len = sizeof(a) / sizeof(a[0]);  
    HeapSort(a, len);  
    Display(a, sizeof(a) / sizeof(a[0]));  
}  
void TestBubbleSort()  
{  
    int a[] = { 3, 1, 4, 2, 5, 4, 6, 9, 7, 10 };  
    Display(a, sizeof(a) / sizeof(a[0]));  
    int len = sizeof(a) / sizeof(a[0]);  
    BubbleSort(a, len);  
    Display(a, sizeof(a) / sizeof(a[0]));  
}  
void TestQuickSort()  
{  
    int a[] = { 3, 1, 4, 2, 5, 4, 6, 9, 7, 10 };  
    Display(a, sizeof(a) / sizeof(a[0]));  
    int len = sizeof(a) / sizeof(a[0]);  
    QuickSort(a, 0, len-1);  
    Display(a, sizeof(a) / sizeof(a[0]));  
}  
void TestMergeSort()  
{  
    int a[] = { 3, 1, 4, 2, 5, 4, 6, 9, 7, 10 };  
    Display(a, sizeof(a) / sizeof(a[0]));  
    int len = sizeof(a) / sizeof(a[0]);  
    MergeSort(a, sizeof(a) / sizeof(a[0]));  
    Display(a, sizeof(a) / sizeof(a[0]));  
}  
