#include <stdio.h>
#include <stdlib.h>

struct Node;
typedef struct Node* ptrtoNode;
typedef ptrtoNode position;
typedef ptrtoNode tree;

struct Node
{
    int x;
    position left;
    position right;
};

tree insert(int x, tree T);
void preorder(tree T);

int main()
{
    int num = 5;
    int x;
    tree T = NULL;
    for (int i = 0; i < num; i++)
    {
        scanf("%d,", &x);
        T = insert(x, T);
    }
    preorder(T);

    return 0;
}

tree insert(int x, tree T)
{
    if (T == NULL)
    {
        T = (struct Node*)malloc(sizeof(struct Node));
        T->x = x;
        T->left = T->right = NULL;
    }
    else
    {
        if (x < T->x)
        {
            T->left = insert(x, T->left);
        }
        else if (x > T->x)
        {
            T->right = insert(x, T->right);
        }
    }
    return T;
}
void preorder(tree T)
{
    if (T == NULL)
    {
        return ;
    }
    printf("%d,", T->x);
    preorder(T->left);
    preorder(T->right);
}