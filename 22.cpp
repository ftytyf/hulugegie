#include<stdio.h>
#include<stdlib.h>
struct stu
{
	int num;
	struct stu *next;
};
typedef struct stu NODE;
NODE *creat()
{
	int n,i;
	NODE* head,*p,*end;
	head=(NODE*)malloc(sizeof(NODE));
	head->next=NULL;
	p=(NODE*)malloc(sizeof(NODE));
	scanf("%d",&n);
	if(n==0)
	{
		head->next=NULL;
		return head;
	}
	else
	{
	   scanf(" %d",&p->num);
	   head->next=p;
	   end=p;
	   for(i=0;i<n-1;i++)
	  {
		p=(NODE*)malloc(sizeof(NODE));
		scanf("%d",&p->num);
		end->next=p;
		end=p;
	  }
	  end->next=NULL;
	  return head;
	}
}
void print(NODE* head)
{
	NODE *k;
	k=head->next;
	while(k!=NULL)
	{
		printf("%d ",k->num);
		k=k->next;
	}
	
}
void dell(NODE *head)
{
	NODE *p,*p1;
	p=head;
	while(p->next!=NULL)
	{
		p1=p->next;
		if(p->num==p1->num)
		{
			p->next=p1->next;
		}
		else
		{
			p=p->next;
		}
	}
}
int main()
{
	NODE *head1,*head2,*p,*p1;
	int a;
	head1=creat();
	head2=creat();
	p=head1->next;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next=head2->next;
	p=head1->next;
	while(p->next!=NULL)
	{
		p1=p->next;
		while(p1!=NULL)
		{
			if(p->num>p1->num)
			{
				a=p->num;
				p->num=p1->num;
				p1->num=a;
			}
			else
			{
				p1=p1->next;
			}
		}
		p=p->next;
	}
	p=head1->next;
	dell(p);
	print(head1);
	system("pause");
	return 0;
}