#include <stdio.h>
#include <stdlib.h>

#include "../include/SinglyLinkedList.h"

SinglyLinkedListNode *createSinglyLinkedListNode(int element) {
    SinglyLinkedListNode *singlyLinkedListNode  = (SinglyLinkedListNode*) malloc(sizeof(DoublyLinkedListNode));
    if(singlyLinkedListNode == NULL)
        return 0;
    singlyLinkedListNode->element = element; 
    singlyLinkedListNode->next = NULL;
    return singlyLinkedListNode;
}

void destroySinglyLinkedListNode(SinglyLinkedListNode **singlyLinkedListNode) {
    SinglyLinkedListNode *tmp = *singlyLinkedListNode;
    if (tmp != NULL) {
        free(tmp);
        *singlyLinkedListNode = NULL;
}

SinglyLinkedList *createSinglyLinkedList() {
    SinglyLinkedList *singlyLinkedList = (SinglyLinkedList*) malloc(sizeof(SinglyLinkedList));
    if(singlyLinkedList != NULL)
       singlyLinkedList->head = NULL;
       singlyLinkedList->tail = NULL;
    return singlyLinkedList;
}
/*
template<class T>
SinglyLinkedList<T>::~SinglyLinkedList() {
    cout << "Destructor class" << endl;
    for (SinglyLinkedListNode<T> *p; !isEmpty(); ) {
        p = head->next;
        delete head;
        head = p;
    } 
}

void destroyDoublyLinkedList(SinglyLinkedList *singlyLinkedList) { 
     SinglyLinkedListNode *head = singlyLinkedList->head;
     while (isEmptySinglyLinkedList(singlyLinkedListNode)){
        SinglyLinkedListNode *p = head->next;
        free(head);
        head = p; 
     }
}
*/

int isEmptyDoublyLinkedList(SinglyLinkedList *singlyLinkedList) {
    return (singlyLinkedList->head == NULL);
}




/*




int isEmptyDoublyLinkedList(DoublyLinkedList *doublyLinkedList) {
    return (doublyLinkedList->head == NULL);
}

void addToHeadDoublyLinkedList(DoublyLinkedList *doublyLinkedList, int element) {
    DoublyLinkedListNode *doublyLinkedListNode = createDoublyLinkedListNode(element);
    if (isEmptyDoublyLinkedList(doublyLinkedList)) {
        doublyLinkedList->head = doublyLinkedListNode;
        doublyLinkedList->tail = doublyLinkedListNode;
    } else {
        doublyLinkedListNode->next = doublyLinkedList->head;
        doublyLinkedList->head->prev = doublyLinkedListNode; 
        doublyLinkedList->head = doublyLinkedListNode;  
    }
}

void addToTailDoublyLinkedList(DoublyLinkedList *doublyLinkedList, int element) {
    DoublyLinkedListNode *doublyLinkedListNode = createDoublyLinkedListNode(element);
    if (isEmptyDoublyLinkedList(doublyLinkedList)) {
        doublyLinkedList->head = doublyLinkedListNode;
        doublyLinkedList->tail = doublyLinkedListNode;
    } else {
        doublyLinkedList->tail->next = doublyLinkedListNode;
        doublyLinkedListNode->prev = doublyLinkedList->tail;
        doublyLinkedList->tail = doublyLinkedListNode;
    }

}

void deleteFromDoublyLinkedListNode(DoublyLinkedList *doublyLinkedList, int element) {
    if (!isEmptyDoublyLinkedList(doublyLinkedList)) {
        DoublyLinkedListNode *doublyLinkedListNode = doublyLinkedList->head;
        if (doublyLinkedList->head->element = element) {
            doublyLinkedList->head = doublyLinkedListNode->next;

            if (doublyLinkedList->tail == doublyLinkedListNode ) {
                doublyLinkedList->tail = NULL;
            } else {
                doublyLinkedList->head->prev = NULL;

            }
            free(doublyLinkedListNode);
        } else {
            doublyLinkedListNode = doublyLinkedListNode->next;
            while (doublyLinkedListNode != NULL) {
                if (doublyLinkedListNode->element == element) {
                    doublyLinkedListNode->prev->next = doublyLinkedListNode->next;

                    if (doublyLinkedList->head == doublyLinkedListNode ) {
                        doublyLinkedList->tail = doublyLinkedListNode->next;
                    }else {
                        doublyLinkedListNode->next->prev = doublyLinkedListNode->prev;
                    }
                    free(doublyLinkedListNode);
                    doublyLinkedListNode = NULL;
                } else {
                    doublyLinkedListNode = doublyLinkedListNode->next;
                }
            }
        } 
    }
}

void printAllAscDoublyLinkedList(DoublyLinkedList *doublyLinkedList) {
     DoublyLinkedListNode *doublyLinkedListNode = doublyLinkedList->head;
     printf("L Head-> ");
     while (doublyLinkedListNode != NULL) {
       printf("%d-> ", doublyLinkedListNode->element);
       doublyLinkedListNode = doublyLinkedListNode->next;
    }
    printf(" NULL \n"); 
}

void printAllDescDoublyLinkedList(DoublyLinkedList *doublyLinkedList) {
    DoublyLinkedListNode *doublyLinkedListNode = doublyLinkedList->tail;
    printf("L Tail-> ");
    while (doublyLinkedListNode != NULL) {
       printf("%d-> ", doublyLinkedListNode->element);
       doublyLinkedListNode = doublyLinkedListNode->prev;
    }
    printf(" NULL \n");
}
*/