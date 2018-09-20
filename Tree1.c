#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node * left;
	struct node *right;
};

struct node * root=NULL;

struct node* new_node(int data){
	struct node*  newNode;
	newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data=data;
	newNode->left=NULL;
	newNode->right=NULL;
	
	printf("new node created  %d\n", newNode->data);
	
	return newNode; 
}

void search(struct node * root, int key){
	if(root->data==key){
		printf("Found\n");
		return;
	}
	else if(root==NULL){
		printf("Not found\n");         //*****
		return;
	}
	else{
		if(key< root->data){
			printf("low\n");
			search(root->left, key);
		}
		else{
			search(root->right, key);
		}
	}
}

struct node * insert(struct node * root, int data){
	if(root==NULL){
		return new_node(data);
	}
	else{
		if(data< root->data){
			root->left= insert(root->left, data);
		}
		else{
			root->right= insert(root->right, data);
		}
	}
	//return root;
}
struct node* minval(struct node* root){
	struct node* min=root;
	while(min->left!=NULL){
		min=min->left;
	}
	return min;
}

struct node* del (struct node* root, int key){
	struct node* temp;
	if(key<root->data){
		root->left = del(root->left, key);
	}
	else if(key>root->data){ 
		root-> right = del(root->right, key);
	}
	else{
		if(root->right==NULL){
			temp=root->left;
			free(root);
			return temp;
		}
		else if(root->left==NULL){
			temp=root->right;
			free(root);
			return temp;
		}
		else{
			temp=minval(root->right);
			root->data=temp->data;
			root->right= del(root->right,temp->data);
		}
	}
	//return root;

}

void preOrder(struct node* root){
	if(root==NULL){
		return;
	}
	else{
		printf("%d ",root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}

void inOrder(struct node* root){
	if(root==NULL){
		return;
	}
	else{
		inOrder(root->left);
		printf("%d ", root->data);
		inOrder(root->right);
	}
}

void postOrder(struct node* root){
	if(root==NULL){
		return;
	}
	else{
		postOrder(root->left);
		postOrder(root->right);
		printf("%d ", root->data);
	}
}


int main(){
	root=new_node(10);
	insert(root, 4);
	insert(root, 3);
	insert(root, 20);
	insert(root, 5);
	insert(root, 1);
	
	inOrder(root);
	preOrder(root);
	postOrder(root);
	/*struct node*min;
	root=new_node(5);
	insert(root,3);
	insert(root,10);
	insert(root,1);
	inOrder(root);
	min=minval(root);
	printf("min=%d ", min->data);
	del(root, 10);
	inOrder(root);
	printf("\n");
	printf ("wawawa\n");
	preOrder(root);
	printf("\n");
	postOrder(root);
	//search(root, 3);*/
}
