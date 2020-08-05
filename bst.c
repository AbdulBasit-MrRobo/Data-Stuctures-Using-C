#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct mynode /* structure of node*/
{
	int key;
	struct mynode * left;
	struct mynode * right;
};
struct mynode * root=NULL;
struct mynode * newNode(int key) /* definition of new node function*/
{
	struct mynode * temp;
	temp=malloc(sizeof(struct mynode));
	temp->key=key;
	temp->left=temp->right=NULL;
}
struct mynode * insert(struct mynode * new,int key) /* definition of insert function*/
{
	
 	if(new==NULL)
 	{
 		return newNode(key); /* calling of new node function*/
 	}
 	if(key<new->key)
 	{
 		new->left=insert(new->left,key); /* recursive call of insert function*/
 	}
 	else if(key>new->key)
 	{
 		new->right=insert(new->right,key); /* recursive call of insert function*/
 	}
 	return new;
}
void inorder(struct mynode *root) /* definition of inorder function*/
{
	if(root!=NULL)
	{
		inorder(root->left); /* recursive call of inorder function*/
		printf("%d\t",root->key);
		inorder(root->right); /* recursive call of inorder function*/
	}
}
void preorder(struct mynode *root) /* definition of preorder function*/
{
	if(root!=NULL)
	{
		printf("%d\t",root->key);
		preorder(root->left); /* recursive call of preorder function*/
		preorder(root->right); /* recursive call of preorder function*/
	}
}
void postorder(struct mynode *root) /* definition of postorder function*/
{
	if(root!=NULL)
	{
		postorder(root->left); /* recursive call of postorder function*/
		postorder(root->right); /* recursive call of postorder function*/
		printf("%d\t",root->key);
	}
}
void main()
{
 	root=insert(root,50); /* calling of insert function*/
 	insert(root,20); /* calling of insert function*/
 	insert(root,30); /* calling of insert function*/
	insert(root,60); /* calling of insert function*/
 	insert(root,70); /* calling of insert function*/
 	printf("\nPreorder of tree is :\t");
 	preorder(root); /* calling of preorder function*/
 	printf("\nInorder of tree is :\t");
 	inorder(root); /* calling of inorder function*/
 	printf("\nPostorder of tree is :\t");
 	postorder(root); /* calling of postorder function*/
}
