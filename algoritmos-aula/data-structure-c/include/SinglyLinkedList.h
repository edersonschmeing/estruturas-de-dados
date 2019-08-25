#ifndef SINGLY_LINKED_LIST_C
#define SINGLY_LINKED_LIST_C

typedef struct _SinglyLinkedListNode {
    int element;
    struct _SinglyLinkedListNode *next;
} SinglyLinkedListNode; 

typedef struct _SinglyLinkedList {
    SinglyLinkedListNode *head;
    SinglyLinkedListNode *tail;
} SinglyLinkedList;

SinglyLinkedListNode *createSinglyLinkedListNode(int element);
void destroySinglyLinkedListNode(SinglyLinkedListNode **singlyLinkedListNode);

SinglyLinkedList *createSinglyLinkedList();
void destroySinglyLinkedList(SinglyLinkedList **singlyLinkedList);

void addToHeadSinglyLinkedList(SinglyLinkedList *SinglyLinkedList, int element);
void addToTailSinglyLinkedList(SinglyLinkedList *singlyLinkedList, int element);
int addSortedSinglyLinkedList(SinglyLinkedList *singlyLinkedList, int element);

void deleteFromHeadSinglyLinkedList(SinglyLinkedList *singlyLinkedList, int element);
void deleteFromTailSinglyLinkedList(SinglyLinkedList *singlyLinkedList, int element);

int deleteNodeFromSinglyLinkedList(SinglyLinkedList *singlyLinkedList, int element);

int sizeSinglyLinkedList(SinglyLinkedList *singlyLinkedList);
int isEmptySinglyLinkedList(SinglyLinkedList *singlyLinkedList);

void printAllSinglyLinkedList(SinglyLinkedList *singlyLinkedList);

int searchByKeyLinkedList(SinglyLinkedList *singlyLinkedList, int element);
int searchByPositionSinglyLinkedList(SinglyLinkedList *singlyLinkedList, int position);


#endif