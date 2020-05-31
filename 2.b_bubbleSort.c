#include<stdio.h>

void swap(int *x, int *y)
{
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;

}

void bubbleSort(int A[], int n)
{
    int i,j,flag;

    for(i=0;i<n-1;i++)                                     
    {
        flag = 0;
        for(j=0;j<n-i-1;j++)                            //loop for no. of comparisons or max. no of swap
        {
            if(A[j] > A[j+1])
            {
                swap(&A[j],&A[j+1]);
                flag = 1;
            }
        }
        if(flag == 0)
        {
            break;
        }
    }
}

void display(int A[], int n)
{
    int i;

    for(i=0;i<n;i++)
    {
        printf("%d\t",A[i]);
    }
    printf("\n");
}

int main()
{
    int A[] = {3,7,9,10,6,5,12,4,11,2};
    int n = 10;

    bubbleSort(A,n);

    display(A,n);

    return 0;
}
