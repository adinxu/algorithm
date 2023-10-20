#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct tag_BSTNode
{
    int val;
    struct tag_BSTNode* left;
    struct tag_BSTNode* right;
}BSTNode;
typedef struct tag_BSTHead
{
    BSTNode* root;
}BSTHead;
BSTHead BstTree;
void BST_insert(BSTNode **ppstNode,int val)
{
    BSTNode *pstNode=*ppstNode;
    if(pstNode!=NULL)
    {
        if(val<pstNode->val)
        {
            BST_insert(&pstNode->left,val);
        }
        else
        {
            BST_insert(&pstNode->right,val);
        }
    }
    else
    {
        pstNode=calloc(1,sizeof(BSTNode));
        pstNode->val=val;
        *ppstNode=pstNode;
    }
    return;
}
void leftRootForeach(BSTNode* pstNode)
{
    printf("%d\n",pstNode->val);
    if(pstNode->left!=NULL)
    {
        leftRootForeach(pstNode->left);
    }
    if(pstNode->right!=NULL)
    {
        leftRootForeach(pstNode->right);
    }
    return;
}
void middleRootForeach(BSTNode* pstNode)
{
    if(pstNode->left!=NULL)
    {
        middleRootForeach(pstNode->left);
    }
    printf("%d\n",pstNode->val);
    if(pstNode->right!=NULL)
    {
        middleRootForeach(pstNode->right);
    }
    return;
}
void rightRootForeach(BSTNode* pstNode)
{
    if(pstNode->left!=NULL)
    {
        rightRootForeach(pstNode->left);
    }
    if(pstNode->right!=NULL)
    {
        rightRootForeach(pstNode->right);
    }
    printf("%d\n",pstNode->val);
    return;
}
int BST()
{
    memset(&BstTree,0,sizeof(BstTree));
    int array[20]={1,3,5,7,8,9,2,11,17,20,16,6,4,15,14,13,12,10,18,19};
    for(int i =0;i<20;i++)
    {
        BST_insert(&BstTree.root,array[i]);
    }
    leftRootForeach(BstTree.root);
    printf("----------\n");
    middleRootForeach(BstTree.root);
    printf("----------\n");
    rightRootForeach(BstTree.root);
   return 0;
}
