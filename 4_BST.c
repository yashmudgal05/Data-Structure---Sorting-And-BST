#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct node
{
    struct node * lchild;
    char * s;
    struct node * rchild;
}*root=NULL;

void inorder(struct node * p)
{
    if(p)
    {
        inorder(p->lchild);
        printf("%s\n",p->s);
        inorder(p->rchild);

    }
}

struct node * Rinsert(struct node * p, char key[], int n)
{
    int i,j,k;
    struct node * t = NULL;

    if(p == NULL)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->s = (char *)malloc(n*sizeof(char));
        for(i=0; key[i]!='\0'; i++)
        {
            t->s[i] = key[i];
        }
        t->s[i] = '\0';

        t->lchild = t->rchild = NULL;
        return t;
    }

    for(k=0,j=0; key[k]!='\0' && p->s[j]!=0 ; k++,j++)
    {
        if(key[k] != p->s[j])
        {
            if(key[k] < p->s[j])
            {
                p->lchild = Rinsert(p->lchild, key, n);
                break;
            }
            else
            {
                p->rchild =  Rinsert(p->rchild, key, n);
                break;
            }
        }
    }

    return p;
}

int main()
{
    root = Rinsert(root,"Yash",sizeof("Yash"));
    Rinsert(root,"Nikunj",sizeof("Nikunj"));
    Rinsert(root,"Ketan",sizeof("Ketan"));
    Rinsert(root,"Akash",sizeof("Akash"));
    Rinsert(root,"Aniket",sizeof("Aniket"));
    Rinsert(root,"Sachin",sizeof("Sachin"));

    inorder(root);

    return 0;
}
