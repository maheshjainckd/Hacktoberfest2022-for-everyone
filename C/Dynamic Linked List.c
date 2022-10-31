#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node* link;
};

struct node* insert(int d, struct node* h);
void displayLL(struct node* h);

int main(){
  struct node* head=NULL;

	head=insert(12, head); head=insert(23, head); head=insert(21, head); head=insert(-3, head); head=insert(123, head); head=insert(-23, head);

	displayLL(head);

  return 0;
}

struct node* insert(int d, struct node* h){
	struct node* loop=NULL;

	struct node* prev=NULL;

  struct node* new=malloc(sizeof(struct node));

  (*new).data=d;
  (*new).link=NULL;

	if(h==NULL){
		h=new;
	}else{
		loop=h;
		while(loop!=NULL){
			prev=loop;
			loop=(*loop).link;
		}
		(*prev).link=new;
	}
	return h;
}

void displayLL(struct node* h){
	struct node* loop=NULL;
	loop=h;
	while(loop!=NULL){
  	printf("| %d |", (*loop).data); printf(" %p |-->", (*loop).link);
  	loop=(*loop).link;
  }
  printf("\n");
}
