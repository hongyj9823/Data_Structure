//1번
#pragma warning (disable:4996)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct ListNode {
	int data;
	struct ListNode*link;
}listNode;

void addLastNode(listNode *L, int x1) { //리스트의 마지막 노드 삽입 연산  
	listNode* newNode;
	listNode* p;
	newNode = (listNode*)malloc(sizeof(listNode)); //삽입할 새 노드 할당  
	newNode->data = x1; //새 노드의 데이터 필드에 x 저장   

	newNode->link = NULL;
	p = L;
	while (p->link != NULL)
	{
		p = p->link;
	}
	p->link = newNode;

}
void print(listNode * DL1, listNode * DL2, int x, int y) {

	int flag = 0;
	listNode*p1;
	listNode*p2;
	int i = 0;
	int j = 0;
	p1 = DL1;

	int cnt = 0;
	for (i = 0; i < x; i++)
	{
		p2 = DL2;
		for (j = 0; j < y; j++)
		{
			if (p1->data == p2->data)
			{
				cnt++;
			}
			p2 = p2->link;
		}
		p1 = p1->link;
	}
	if (cnt == x)
		printf("0");
	else
	{
		p1 = DL1;
		for (i = 0; i < x; i++)
		{
			cnt = 0;
			p2 = DL2;
			for (j = 0; j < y; j++)
			{
				if (p1->data == p2->data)
				{
					cnt++;
				}


				p2 = p2->link;

			}
			if (cnt == 0)
			{
				if (flag == 0)
				{

					printf("%d", p1->data);
					flag = 1;
					break;
				}
			}
			p1 = p1->link;
		}

	}

}
int main() {
	int n1 = 0;
	int n2 = 0;
	int k = 0;
	int i = 0;

	listNode* DL1 = NULL;
	listNode *DL2 = NULL;
	listNode *p1;


	DL1 = (listNode*)malloc(sizeof(listNode));
	DL2 = (listNode*)malloc(sizeof(listNode));
	p1 = DL1;

	scanf("%d", &n1);
	if (n1 != 0)
	{
		scanf("%d", &DL1->data);
		DL1->link = NULL;
		for (i = 1; i < n1; i++)
		{
			scanf("%d", &k);
			addLastNode(DL1, k);
		}
	}
	scanf("%d", &n2);
	if (n2 != 0)
	{
		scanf("%d", &DL2->data);
		DL2->link = NULL;
		for (i = 1; i < n2; i++)
		{
			scanf("%d", &k);
			addLastNode(DL2, k);
		}
	}
	if (n1 == 0 && n2 == 0)
	{
		printf("0");
	}
	else if (n1 == 0 && n2 != 0)
	{
		printf("0");
	}
	else if (n1 != 0 && n2 == 0)
	{
		printf("%d", p1->data);
	}

	else
	{
		if (n1 <= n2)

		{
			print(DL1, DL2, n1, n2);
		}
		else
		{
			print(DL1, DL2, n1, n2);
		}

	}
	return 0;
}
//2번
#pragma warning (disable:4996)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct ListNode {
	int data;
	struct ListNode*link;
}listNode;
typedef struct {
	listNode* head;
}linkedList_h;
linkedList_h*createLinkedList_h(void)
{
	linkedList_h*DL;
	DL = (linkedList_h*)malloc(sizeof(linkedList_h));
	DL->head = NULL;
	return DL;
}
void addLastNode(linkedList_h* L, int x1) { //리스트의 마지막 노드 삽입 연산  
	listNode* newNode;
	listNode* p;
	newNode = (listNode*)malloc(sizeof(listNode)); //삽입할 새 노드 할당  
	newNode->data = x1; //새 노드의 데이터 필드에 x 저장   
	newNode->link = NULL;
	if (L->head == NULL) {  //현재 리스트가 공백인 경우 :   
		L->head = newNode;
		return;
	}
	p = L->head;
	while (p->link != NULL)
		p = p->link;
	p->link = newNode;
	p = L->head;
}
linkedList_h* addPoly(linkedList_h*DL1, linkedList_h* DL2) {
	listNode*p1;
	listNode*p2;
	listNode*p3;

	p1 = DL1->head;
	p2 = DL2->head;
	int sum = 0;

	linkedList_h*result;
	result = createLinkedList_h();
	p3 = result->head;
	if (p1 == NULL && p2 == NULL)
	{
		addLastNode(result, 0);
	}
	else if (p1 == NULL || p2 == NULL)
	{
		while (p1 != NULL)
		{
			addLastNode(result, p1->data);
			p1 = p1->link;
		}
		while (p2 != NULL)
		{
			addLastNode(result, p2->data);
			p2 = p2->link;
		}

	}

	while (p1 != NULL && p2 != NULL)
	{
		if (p1->data< p2->data)
		{
			addLastNode(result, p1->data);
			p1 = p1->link;
		}
		else if (p1->data == p2->data)
		{
			addLastNode(result, p1->data);
			p1 = p1->link;
			p2 = p2->link;
		}
		else
		{
			addLastNode(result, p2->data);
			p2 = p2->link;
		}

	}
	while (p1 != NULL)
	{
		addLastNode(result, p1->data);
		p1 = p1->link;
	}
	while (p2 != NULL)
	{
		addLastNode(result, p2->data);
		p2 = p2->link;
	}

	return result;


}

linkedList_h* print(linkedList_h * DL1, linkedList_h * DL2) {
	listNode*p1;
	listNode*p2;
	listNode*p3;

	p1 = DL1->head;
	p2 = DL2->head;
	int sum = 0;


	linkedList_h*result;
	result = createLinkedList_h();
	p3 = result->head;
	if (p1 == NULL && p2 == NULL)
	{
		addLastNode(result, 0);
	}
	else if (p1 == NULL || p2 == NULL)
	{
		addLastNode(result, 0);
	}

	while (p1 != NULL && p2 != NULL)
	{
		if (p1->data< p2->data)
		{
			// addLastNode(result, p1->data);
			p1 = p1->link;
		}
		else if (p1->data == p2->data)
		{
			addLastNode(result, p1->data);
			p1 = p1->link;
			p2 = p2->link;
		}
		else
		{
			//addLastNode(result, p2->data);
			p2 = p2->link;
		}

	}


	return result;


}
int main() {
	int n1 = 0;
	int n2 = 0;
	int i = 0;
	int a = 0;
	int b = 0;
	linkedList_h* DL1;
	linkedList_h*DL2;
	linkedList_h*result1;
	linkedList_h*result2;
	listNode *p;
	DL1 = createLinkedList_h();
	DL2 = createLinkedList_h();


	scanf("%d", &n1);
	if (n1 == 0)
	{

	}
	else
	{
		for (i = 0; i < n1; i++)
		{
			scanf("%d", &a);

			addLastNode(DL1, a);

		}
	}
	scanf("%d", &n2);
	if (n2 == 0)
	{


	}
	else
	{

		for (i = 0; i < n2; i++)
		{
			scanf("%d", &a);
			addLastNode(DL2, a);

		}
	}
	result1 = addPoly(DL1, DL2);//합집합
	result2 = print(DL1, DL2);

	p = result1->head;

	while (p != NULL)
	{
		printf(" %d", p->data);
		p = p->link;
	}
	printf("\n");
	p = result2->head;
	while (p != NULL)
	{
		printf(" %d", p->data);
		p = p->link;
	}
	return 0;
}