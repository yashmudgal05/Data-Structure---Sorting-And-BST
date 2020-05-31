#include<stdio.h>

void merge(char A[], int l, int mid, int h)
{
    int i=l,j=mid+1,k=l;

    int B[100];

    while(i<=mid && j<=h)
    {
        if((A[i] >= 'A' && A[i] <= 'Z') && (A[j] >= 'a' && A[j] <= 'z'))
        {
            if((A[i]+32) < A[j])
            {
               B[k++] = A[i++];
            }
            else
            {
               B[k++] = A[j++];
            }
        }
        else if((A[i] >= 'a' && A[i] <= 'b') && (A[j] >= 'A' && A[j] <= 'Z'))
        {
            if(A[i] < (A[j]+32))
            {
               B[k++] = A[i++];
            }
            else
            {
               B[k++] = A[j++];
            }
        }
        else if(A[i] < A[j])
        {
            B[k++] = A[i++];
        }
        else
        {
            B[k++] = A[j++];
        }
    }

    for( ; i<=mid; i++)
    {
        B[k++] = A[i];
    }
    for( ; j<=h; j++)
    {
        B[k++] = A[j];
    }

    for(i=l; i<=h; i++)
    {
        A[i] = B[i];
    }
}

void IterativeMergeSort(char A[], int n)
{
    int p,l,h,mid,i;

    for(p=2; p<=n; p=p*2)
    {
        for(i=0; i+p-1<=n; i=i+p)
        {
            l = i;
            h = i+p-1;
            mid = (l+h)/2;
            merge(A,l,mid,h);
        }
    }

    if(p/2 < n)
    {
        merge(A,0,(p/2)-1,n-1);
    }
}

void display(char A[], int n)
{
    int i,j;

    for(i=0;i<n;i++)
    {
        printf("%c\t",A[i]);
    }
    printf("\n");
}

int main()
{
    char A[] = "Test case";
    int n = 9;

    IterativeMergeSort(A,n);

    display(A,n);

    return 0;
}

