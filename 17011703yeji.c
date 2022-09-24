#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 

typedef struct ListNode {  //단순연결리스트의 노드 구조 정의   
	char data[10];   
	struct ListNode* link; 
} listNode; 

	typedef struct {   //리스트의 헤드 노드의 구조 정의  
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
printf("(1) 공백 리스트 생성하기! \n");
printList(L);
getchar();

 printf("(2) 리스트 3개의 노드 추가하기! \n");
 addLastNode(L, "화");  
 addLastNode(L, "수");   
 addLastNode(L, "목");   
 printList(L);
 getchar();

printf("(3) 리스트 첫번째에 노드 한개 추가하기! \n");   
addFirstNode(L, "월");  
printList(L); 
getchar();

printf("(4) 첫번째 노드 삭제하기! \n");

deleteFirstNode(L);  
printList(L); 
getchar();

printf("(5) 리스트 공간을 해제하여, 공백 리스트 상태로 만들기! \n");  
freeLinkedList_h(L);   
printList(L);
getchar();


return 0;
}

void freeLinkedList_h(linkedList_h* L)
{  //리스트 전체 메모리 해제 연산  
	listNode* p;
	while (L->head != NULL) {
		p = L->head;
		L->head = L->head->link;
		free(p);
		p = NULL;
	}
}

void printList(linkedList_h* L) {   //노드 순서대로 리스트를 출력하는 연산  
	listNode* p;
	printf("L = (");
	p = L->head;
	while (p != NULL) {
		printf("%s", p->data);
		p = p->link;

		if (p != NULL) printf(", ");
	}   printf(") \n");
}

	void addLastNode(linkedList_h* L, char* x) { //리스트의 마지막 노드 삽입 연산   
		listNode* newNode;
		listNode* p;
		newNode = (listNode*)malloc(sizeof(listNode)); //삽입할 새 노드 할당  
		strcpy(newNode->data, x); //새 노드의 데이터 필드에 x 저장   

		newNode->link = NULL;
		if (L->head == NULL) {  //현재 리스트가 공백인 경우 :    
			L->head = newNode;
			return;
		}
		p = L->head;
		while (p->link != NULL)
			p = p->link;
		p->link = newNode;
	}
	linkedList_h* createLinkedList_h(void) {  //공백 연결리스트 생성 연산  
		linkedList_h* L;
		L = (linkedList_h*)malloc(sizeof(linkedList_h)); //헤드 노드 할당  
		L->head = NULL; //공백 리스트이므로 NULL 설정  
		return L;
	}
	void addFirstNode(linkedList_h* L, char* x) { //리스트의 마지막 노드 삽입 연산   
		listNode* newNode;
		//listNode* p;
		newNode = (listNode*)malloc(sizeof(listNode)); //삽입할 새 노드 할당  
		strcpy(newNode->data, x); //새 노드의 데이터 필드에 x 저장   
		newNode->link =L->head;
		if (L->head == NULL) {  //현재 리스트가 공백인 경우 :    
			L->head = newNode;
			return;
		}
		L->head = newNode;
	}
	void deleteFirstNode(linkedList_h * L) { //리스트의 마지막 노드 삭제 연산 
		if (L->head == NULL)
			return;  //공백 리스트인 경우, 삭제 연산 중단 

		if (L->head->link == NULL) {  //리스트에 노드가 한 개만 있는 경우, 
			free(L->head);             // 첫 번째 노드를 메모리 해제하고   
			L->head = NULL;          // 리스트 시작 포인터를 null로 설정한다.     
			return;
		}
		else {                        //리스트에 노드가 여러 개 있는 경우,      
			L->head = L->head->link;
		}
	}




