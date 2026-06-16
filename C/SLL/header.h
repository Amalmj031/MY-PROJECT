#ifndef HE_DR
#define HE_DR

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct student
{
	int r_no;
	char name[20];
	float mark;
	struct student *next;
}sll;

void sort(sll *ptr);
void exit_(sll *ptr);
void modify(sll **ptr);
void delete_node(sll **ptr);
int count(sll *ptr);
void print(sll *ptr);
void add_student_deatils_begin(sll **ptr);

#endif
