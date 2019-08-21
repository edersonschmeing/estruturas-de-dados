#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

typedef struct _DoublyLinkedListNode {
    int element;
    struct _DoublyLinkedListNode *prev;
    struct _DoublyLinkedListNode *next;
} DoublyLinkedListNode;

typedef struct _DoublyLinkedList {
    DoublyLinkedListNode *head;
    DoublyLinkedListNode *tail;
} DoublyLinkedList;


DoublyLinkedListNode *createDoublyLinkedListNode(int element);
void destroyDoublyLinkedListNode(DoublyLinkedListNode **doublyLinkedListNode);

DoublyLinkedList *createDoublyLinkedList();
void destroyDoublyLinkedList(DoublyLinkedList **doublyLinkedList);

int isEmptyDoublyLinkedList(DoublyLinkedList *doublyLinkedList);

void addToHeadDoublyLinkedList(DoublyLinkedList *doublyLinkedList, int element);
void addToTailDoublyLinkedList(DoublyLinkedList *doublyLinkedList, int element);

//int deleteFromHeadDoublyLinkedList(DoublyLinkedList *doublyLinkedList, int element);
//int deleteFromTailDoublyLinkedList(DoublyLinkedList *doublyLinkedList, int element);
void deleteFromDoublyLinkedListNode(DoublyLinkedList *doublyLinkedList, int element);

void printAllAscDoublyLinkedList(DoublyLinkedList *doublyLinkedList);
void printAllDescDoublyLinkedList(DoublyLinkedList *doublyLinkedList);

#endif