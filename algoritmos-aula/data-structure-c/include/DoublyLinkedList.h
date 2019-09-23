#ifndef DOUBLY_LINKED_LIST_C
#define DOUBLY_LINKED_LIST_C

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

void deleteFromHeadDoublyLinkedList(DoublyLinkedList *doublyLinkedList, int element);
void deleteFromTailDoublyLinkedList(DoublyLinkedList *doublyLinkedList, int element);
void deleteNodeDoublyLinkedList(DoublyLinkedList *doublyLinkedList, int element);

void printAllAscDoublyLinkedList(DoublyLinkedList *doublyLinkedList);
void printAllDescDoublyLinkedList(DoublyLinkedList *doublyLinkedList);

int searchByKeyDoublyLinkedList(DoublyLinkedList *doublyLinkedList, int element);
int searchByPositionDoublyLinkedList(DoublyLinkedList *doublyLinkedList, int position);


#endif 