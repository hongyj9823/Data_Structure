#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 

typedef struct ListNode {  //�ܼ����Ḯ��Ʈ�� ��� ���� ����   
	char data[10];   
	struct ListNode* link; 
} listNode; 

	typedef struct {   //����Ʈ�� ��� ����� ���� ����  
		listNode* head; 
	} linkedList_h; 

linkedList_h* createLinkedList_h(void);
void freeLinkedList_h(linkedList_h*); 
void addLastNode(linkedList_h*, char*); 
void printList(linkedList_h*);
void addFirstNode(linkedList_h* L, char* x);
void deleteFirstNode(linkedList_h * L);

int main() 
{
linkedList_h* L; 
L = createLinkedList_h(); 
printf("(1) ���� ����Ʈ �����ϱ�! \n");
printList(L);
getchar();

 printf("(2) ����Ʈ 3���� ��� �߰��ϱ�! \n");
 addLastNode(L, "ȭ");  
 addLastNode(L, "��");   
 addLastNode(L, "��");   
 printList(L);
 getchar();

printf("(3) ����Ʈ ù��°�� ��� �Ѱ� �߰��ϱ�! \n");   
addFirstNode(L, "��");  
printList(L); 
getchar();

printf("(4) ù��° ��� �����ϱ�! \n");

deleteFirstNode(L);  
printList(L); 
getchar();

printf("(5) ����Ʈ ������ �����Ͽ�, ���� ����Ʈ ���·� �����! \n");  
freeLinkedList_h(L);   
printList(L);
getchar();


return 0;
}

void freeLinkedList_h(linkedList_h* L)
{  //����Ʈ ��ü �޸� ���� ����  
	listNode* p;
	while (L->head != NULL) {
		p = L->head;
		L->head = L->head->link;
		free(p);
		p = NULL;
	}
}

void printList(linkedList_h* L) {   //��� ������� ����Ʈ�� ����ϴ� ����  
	listNode* p;
	printf("L = (");
	p = L->head;
	while (p != NULL) {
		printf("%s", p->data);
		p = p->link;

		if (p != NULL) printf(", ");
	}   printf(") \n");
}

	void addLastNode(linkedList_h* L, char* x) { //����Ʈ�� ������ ��� ���� ����   
		listNode* newNode;
		listNode* p;
		newNode = (listNode*)malloc(sizeof(listNode)); //������ �� ��� �Ҵ�  
		strcpy(newNode->data, x); //�� ����� ������ �ʵ忡 x ����   

		newNode->link = NULL;
		if (L->head == NULL) {  //���� ����Ʈ�� ������ ��� :    
			L->head = newNode;
			return;
		}
		p = L->head;
		while (p->link != NULL)
			p = p->link;
		p->link = newNode;
	}
	linkedList_h* createLinkedList_h(void) {  //���� ���Ḯ��Ʈ ���� ����  
		linkedList_h* L;
		L = (linkedList_h*)malloc(sizeof(linkedList_h)); //��� ��� �Ҵ�  
		L->head = NULL; //���� ����Ʈ�̹Ƿ� NULL ����  
		return L;
	}
	void addFirstNode(linkedList_h* L, char* x) { //����Ʈ�� ������ ��� ���� ����   
		listNode* newNode;
		//listNode* p;
		newNode = (listNode*)malloc(sizeof(listNode)); //������ �� ��� �Ҵ�  
		strcpy(newNode->data, x); //�� ����� ������ �ʵ忡 x ����   
		newNode->link =L->head;
		if (L->head == NULL) {  //���� ����Ʈ�� ������ ��� :    
			L->head = newNode;
			return;
		}
		L->head = newNode;
	}
	void deleteFirstNode(linkedList_h * L) { //����Ʈ�� ������ ��� ���� ���� 
		if (L->head == NULL)
			return;  //���� ����Ʈ�� ���, ���� ���� �ߴ� 

		if (L->head->link == NULL) {  //����Ʈ�� ��尡 �� ���� �ִ� ���, 
			free(L->head);             // ù ��° ��带 �޸� �����ϰ�   
			L->head = NULL;          // ����Ʈ ���� �����͸� null�� �����Ѵ�.     
			return;
		}
		else {                        //����Ʈ�� ��尡 ���� �� �ִ� ���,      
			L->head = L->head->link;
		}
	}




