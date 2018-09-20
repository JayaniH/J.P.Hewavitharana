#include<stdio.h>
#include<stdio.h>
#define size 20

struct _node{
	int data;
	struct _node *left;
	struct _node *right;
};

struct _node* queue[size];
int front=-1, rear=-1;

void enqueue(struct _node *root){
	if(rear==size-1){
		printf("Queue is full");
	}
	else if(front==-1 && rear==-1){
		front++;
		rear++;
		queue[rear]=root;
	}
	else{
		rear++;
		queue[rear]=root;
	}
}

struct _node* dequeue(){
	if(front==-1){
		printf("Queue is empty");
	}
	else{
		return queue[front++];
	}
}

void levelOrder(struct _node* root){
	while(root!=NULL){
		printf("%d ",root->data);
		if(root->left!=NULL){
			enqueue(root->left);
		}
		if(root->right!=NULL){
			enqueue(root->right);
		}
		root=dequeue();
	}
}


