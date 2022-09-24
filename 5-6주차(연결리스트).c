//5¹ø

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
/* Source code written by Go Yongguk,
   researcher of Mobile Virtual Reality Research Center at Sejong University */
typedef struct _node {
struct _node *prev, *next;
char elem;
} node;
void initList(node **, node **);
node* add(node *, node *, int, char);
char delete(node *, node *, int);
char get_entry(node *, node *, int);
void print(node *, node *);
int main(void) {
node *header, *trailer;
int n, position;
char c;
initList(&header, &trailer);
scanf("%d", &n);
while (n--) {
getchar();
scanf("%c", &c);
switch (c) {
case 'A':
scanf("%d %c", &position, &c);
if (add(header, trailer, position, c) == NULL)
printf("invalid position\n");
break;
case 'D':
scanf("%d", &position);
if (delete(header, trailer, position) == '0')
printf("invalid position\n");
break;
case 'G':
scanf("%d", &position);
if ((c = get_entry(header, trailer, position)) == '0') 
printf("invalid position\n");
else
printf("%c\n", c);
break;
case 'P':
print(header, trailer);
break;
}
}
}
void initList(node **header, node **trailer) {
*header = (node *)malloc(sizeof(node));
*trailer = (node *)malloc(sizeof(node));
(*header)->next = *trailer;
(*trailer)->prev = *header;
return;
}
node* add(node *header, node *trailer, int position, char element) {
node *p;
node *q = (node *)malloc(sizeof(node));
int i;
q->elem = element;
for (i = 0, p = header; i < position - 1; i++, p = p->next) {
if (p == trailer) 
return NULL;
}
q->prev = p;
q->next = p->next;
p->next->prev = q;
p->next = q;
return q;
}
char delete(node *header, node *trailer, int position) {
node *p;
int i;
char element;
for (i = 0, p = header; i < position; i++) {
p = p->next;
if (p == trailer)
return '0';
}
element = p->elem;
p->prev->next = p->next;
p->next->prev = p->prev;
free(p);
return element;
}
char get_entry(node *header, node *trailer, int position) {
node *p;
int i;
for (i = 0, p = header; i < position; i++) {
p = p->next;
if (p == trailer)
return '0';
}
return p->elem;
}
void print(node *header, node *trailer) {
node *p = header;
while (1) {
p = p->next;
if (p == trailer)
break;
printf("%c", p->elem);
}
printf("\n");
return;
}
 //6¹ø
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disble:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct ListNode {
	int coef;
	int expo;
	struct ListNode*link;
}listNode;
typedef struct {
	listNode*head;
}listLinked_h;
listLinked_h * createLInkedlist(void);
void print(listLinked_h *L);
void addLastNode(listLinked_h*DL, int co, int ex);
listLinked_h* addPoly(listLinked_h * L1, listLinked_h*L2);
int main()
{
	listLinked_h *p;
	listLinked_h*q;
	listLinked_h*result = NULL;
	int a = 0, b = 0;
	int ans1 = 0;
	int ans2 = 0;
	int i = 0;
	p = createLInkedlist();
	q = createLInkedlist();
	scanf("%d", &a);
	for (i = 0; i < a; i++)
	{
		scanf("%d %d", &ans1, &ans2);
		addLastNode(p, ans1, ans2);
	}
	scanf("%d", &b);
	for (i = 0; i < b; i++)
	{
		scanf("%d %d", &ans1, &ans2);
		addLastNode(q, ans1, ans2);
	}
	result = addPoly(p, q);
	print(result);
	return 0;
}
listLinked_h * createLInkedlist(void) {
	listLinked_h  *L;
	L = (listLinked_h*)malloc(sizeof(listLinked_h));
	L->head = NULL;
	return L;
}
void print(listLinked_h *L) {
	listNode *p;
	p = L->head;
	while (p != NULL)
	{
		printf(" %d %d", p->coef, p->expo);
		p = p->link;
	}
}
void addLastNode(listLinked_h*DL, int co, int ex)
{
	listNode *NewNode;
	listNode *p;
	NewNode = (listNode*)malloc(sizeof(listNode));
	NewNode->coef = co;
	NewNode->expo = ex;
	NewNode->link = NULL;
	if (DL->head == NULL)
	{
		DL->head = NewNode;
		return;
	}
	else
	{
		p = DL->head;
		while (p->link != NULL)
		{
			p = p->link;
		}
		p->link = NewNode;
	}
}
listLinked_h* addPoly(listLinked_h * L1, listLinked_h*L2)
{
	listNode *p1;
	listNode *p2;
	listLinked_h *L3;
	p1 = L1->head;
	p2 = L2->head;
	L3 = createLInkedlist();
	while (p1 != NULL && p2 != NULL)
	{
		if (p1->expo > p2->expo)
		{
			addLastNode(L3, p1->coef, p1->expo);
			p1 = p1->link;
		}
		else if (p1->expo < p2->expo)
		{
			addLastNode(L3, p2->coef, p2->expo);
			p2 = p2->link;
		}
		else
		{
			if (p1->coef + p2->coef != 0)
			{
				addLastNode(L3, p1->coef + p2->coef, p1->expo);
			}
			p1 = p1->link;
			p2 = p2->link;
		}
	}
	if (p1 != NULL)
	{
		addLastNode(L3, p1->coef, p1->expo);
		p1 = p1->link;
	}
	if (p2 != NULL)
	{
		addLastNode(L3, p2->coef, p2->expo);
		p2 = p2->link;
	}
	return L3;
}
