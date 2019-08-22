#ifndef SINGLY_LINKED_LIST
#define SINGLY_LINKED_LIST

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
void addToSinglyLinkedListOrdered(SinglyLinkedList *singlyLinkedList, int element);

int deleteFromHeadSinglyLinkedList(SinglyLinkedList *singlyLinkedList, int element);
int deleteFromTailSinglyLinkedList(SinglyLinkedList *singlyLinkedList, int element);

int deleteElementFromSinglyLinkedList(SinglyLinkedList *singlyLinkedList, int element);

int sizeSinglyLinkedList(SinglyLinkedList *singlyLinkedList);
int isEmptySinglyLinkedList(SinglyLinkedList *singlyLinkedList);
//int lista_cheia(Lista* li);

void printAllAscSinglyLinkedList(SinglyLinkedList *singlyLinkedList);
void printAllDescSinglyLinkedList(SinglyLinkedList *singlyLinkedList);

int findElementSinglyLinkedList(SinglyLinkedList *singlyLinkedList, int element);
int findPositionSinglyLinkedList(SinglyLinkedList *singlyLinkedList, int element);


#endif