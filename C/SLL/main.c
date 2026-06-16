
#include"header.h"

void main()
{
	sll *headptr=0;
	int op;
	while(1)
	{
		printf("\n--------------------\nenter the operation \n--------------------\n");
		printf("1.add_student details\n2.print\n3.count\n4.delete\n5.modift data base\n6.save to file(e)\n8.exit\n");
		scanf("%d",&op);
		printf("--------------------\n");
		switch(op)
		{
			case 1:add_student_deatils_begin(&headptr);
				break;
			case 2:print(headptr);
				break;
			case 3:int c=count(headptr);
				printf("count= %d \n",c);
				break;
			case 4:delete_node(&headptr);
				break;
			case 5:modify(&headptr);
				break;
			case 7:exit_(headptr);
				break;
			default :printf("unkown \n");
				 break;
		}
	}
}

void exit_(sll *ptr)
{
	int n;
	printf("select the choice \n1-save and exit\n2-save without exit\n");
	scanf("%d",&n);
	if(n==1)
	{
		FILE *fp=fopen("student.data","w+");
		if(!fp)
		{
			printf("no data \nn");
			return;
		}
		while(ptr!=NULL)
		{
			fprintf(fp,"%d  %s  %f \n",ptr->r_no,ptr->name,ptr->mark);
			ptr=ptr->next;
		}
	}
	if(n==2)
	{
		printf("exit without saving\n");
		return;
	}
	else
	{
		printf("invalid choise \n");
		return;
	}
}

void modify(sll **ptr)
{
	int d,flag=0;
	char s[30];
	int r;
	float f;
	sll *c=*ptr;
	printf("modify student records\n1.roll_no\n2.name\n3.mark\n");
	scanf("%d",&d);
	switch(d)
	{
		case 1:printf("modify student details by roll no.\n");
		       int roll;
		       scanf("%d",&roll);

		       while(c!=NULL)
		       {
		       	if(c->r_no==roll)
		       	{
		       		flag=1;
		       		printf("%d %s %f \n",c->r_no,c->name,c->mark);
		       		if(flag==1)
		       		{
		       			printf("enter the name to modify \n");
		       			scanf("%s",s);
		       			strcpy(c->name,s);
		       			printf("enter the percentage to modify \n");
		       			scanf("%f",&f);
		       			c->mark=f;
		       		}
		       	}

		       	c=c->next;
		       }
		       if(flag==0)
		       	printf("no data exist\n");
		       break;
		case 2:printf("modify student detail by name\n");
		       scanf("%s",s);
		       c=*ptr;
		       while(c!=NULL)
		       {
		       	if(strcmp(c->name,s)==0)
		       	{
		       		flag++;
		       		printf("%d %s %f \n",c->r_no,c->name,c->mark);
		       	}
		       	c=c->next;
		       }

		       if(flag==0)
		       {
		       	printf("no data exist\n");
		       	break;
		       }
		       c=*ptr;
		       if(flag==1)
		       {
		       	while(c!=NULL)
		       	{
		       		if(strcmp(c->name,s)==0)
		       		{
		       			printf("enter the roll no. to change \n");
		       			scanf("%d",&r);
		       			c->r_no=r;
		       			printf("enter the percentge to change \n");
		       			scanf("%f",&f);
		       			c->mark=f;
		       		}
		       		c=c->next;
		       	}
		       }
		       c=*ptr;
		       if(flag>=2)
		       {
		       	printf("select the roll no to modify\n");
		       	scanf("%d",&r);
		       	while(c!=NULL)
		       	{
		       		if(c->r_no==r)
		       		{
		       			printf("enter the roll no to modify \n");
		       			scanf("%d",&r);
		       			c->r_no=r;
		       			printf("enter the mark to modify \n");
		       			scanf("%f",&f);
		       			c->mark=f;
		       		}
		       		c=c->next;
		       	}
		       }
		       break;

		case 3:printf("enter the percentage \n");
		       scanf("%f",&f);
		       while(c!=NULL)
		       {
		       	if(c->mark==f)
		       	{
		       		flag++;
		       		printf("%d %s %f\n",c->r_no,c->name,c->mark);
		       	}
		       	c=c->next;
		       }

		       if(flag==0)
		       {
		       	printf("no data exist \n");
		       	break;
		       }
		       c=*ptr;
		       if(flag==1)
		       {
		       	while(c!=NULL)
		       	{
		       		if(c->mark==f)
		       		{
		       			printf("enter the roll no to modify \n");
		       			scanf("%d",&r);
		       			printf("enter the name to modify\n");
		       			scanf("%s",s);

		       			c->r_no=r;
		       			strcpy(c->name,s);
		       		}
		       		c=c->next;
		       	}
		       }
		       if(flag>=2)
		       {
		       	printf("select the roll no to modify \n");
		       	scanf("%d",&r);
		       	while(c!=NULL)
		       	{
		       		if(c->r_no==r)
		       		{
		       			printf("enter the roll no to modify \n");
		       			scanf("%d",&r);
		       			c->r_no=r;
		       			printf("enter the name to modify \n");
		       			scanf("%s",s);
		       			strcpy(c->name,s);
		       		}
		       		c=c->next;
		       	}
		       }
		       break;
		default:printf("unknown\n");
			 break;
	}
}

////////////////////////////////////////////////////////////////
void delete_node(sll **ptr)
{
	int op;
	printf("based on roll no --1\nbased on name --0 \n");
	scanf("%d",&op);
	switch(op)
	{
		case 1:printf("enter the roll no. delete \n");
		       int s;
		       scanf("%d",&s);
		       sll *c,*del=*ptr;
		       while(del!=NULL)
		       {
		       	if(del->r_no==s)
		       	{
		       		if(del==*ptr)
		       			*ptr=del->next;
		       		else
		       			c->next=del->next;
		       		free(del);
		       	}
		       	c=del;
		       	del=del->next;
		       }
		       c=*ptr;
		       int r=1;
		       while(c!=NULL)
		       {
		       	c->r_no=r;
		       	r++;
		       	c=c->next;
		       }
		       break;
		case 0:printf("enter the name to delete \n");
		       char s1[30];
		       scanf("%s",s1);
		       sll *c1,*del1=*ptr;
		       while(del1!=NULL)
		       {
		       	if(strcmp(del1->name,s1)==0)
		       	{
		       		if(del1==*ptr)
		       			*ptr=del1->next;
		       		else
		       			c1->next=del1->next;
		       		free(del1);
		       	}
		       	c1=del1;
		       	del1=del1->next;
		       }
		       sll *c2=*ptr;
		       int r1=1;
		       while(c2!=NULL)
		       {
		       	c2->r_no=r1;
		       	r1++;
		       	c2=c2->next;
		       }
		       break;
		default:printf("unknow\n");
			 break;
	}
}

void add_student_deatils_begin(sll **ptr)
{
	sll *new=malloc(sizeof(sll));
	if(new==NULL)
	{
		printf("no data \n");
		return ;
	}
	printf("name-mark\n");
	scanf("%s%f",new->name,&new->mark);
	new->next=NULL;
	if(*ptr==NULL)
	{
		*ptr=new;
	}
	else
	{
		sll *c=*ptr;
		while(c->next!=NULL)
		{
			c=c->next;
		}
		c->next=new;
	}
	sll *s=*ptr;
	int roll=1;
	while (s != NULL) {
		s->r_no = roll;
		roll++;
		s = s->next;
	}
}

void print(sll *ptr)
{
	if(ptr==NULL)
	{
		printf("no data \n");
		return;
	}
	while(ptr)
	{
		printf(" %d    %s    %f \n",ptr->r_no,ptr->name,ptr->mark);
		ptr=ptr->next;
	}
}

int count(sll *ptr)
{
	int count=0;
	while(ptr)
	{
		count++;
		ptr=ptr->next;
	}
	return count;
}
