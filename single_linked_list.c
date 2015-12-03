#include<stdio.h>
#include<stdlib.h>
struct node {
	int info;
	struct node *link;
};
struct node *addatbeg(struct node*,int);
struct node *addatend(struct node *start,int data)
{
	if(start == NULL)
	{
		start=addatbeg(start,data);
	}
	else
	{
		struct node *p=start;
		struct node *tmp=(struct node*)malloc(sizeof(struct node));
		while(p->link!=NULL)
		{
			p=p->link;
		}
		tmp->info=data;
		tmp->link=p->link;
		p->link=tmp;
	}
	return start;
}
struct node *addatbeg(struct node *start,int data)
{
	struct node *tmp;
	if(start == NULL)
	{
		tmp = (struct node*)malloc(sizeof(struct node));
		tmp->info=data;
		tmp->link=start;
		start = tmp;
	}
	else
	{
		tmp = (struct node*)malloc(sizeof(struct node));
		tmp->info=data;	
		tmp->link=start;
		start = tmp;
	}
	return start;
	
}
void display(struct node *start)
{
	struct node *p;
	if(start==NULL)
	{
		printf("empty list");
	}
	p=start;
	printf("list is:\n");
	while(p!=NULL)
	{
		printf("%d\t",p->info);
		p=p->link;
	}
	printf("\n");
}
int main()
{
	struct node *start=NULL;
	start=addatbeg(start,10);
	start=addatbeg(start,40);
	start=addatbeg(start,20);
	start=addatbeg(start,60);
	start=addatend(start,70);
	display(start);
}
