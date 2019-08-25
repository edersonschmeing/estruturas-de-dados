#include <stdio.h>
#include <stdlib.h>

#include "../include/DoublyLinkedList.h"

DoublyLinkedListNode *createDoublyLinkedListNode(int element) {
    DoublyLinkedListNode *doublyLinkedListNode  = (DoublyLinkedListNode*) malloc(sizeof(DoublyLinkedListNode));
    if(doublyLinkedListNode == NULL)
        return 0;
    doublyLinkedListNode->element = element; 
    doublyLinkedListNode->prev = NULL;
    doublyLinkedListNode->next = NULL;
    return doublyLinkedListNode;
}

void destroyDoublyLinkedListNode(DoublyLinkedListNode **doublyLinkedListNode) {
    DoublyLinkedListNode *tmp = *doublyLinkedListNode;
    if (tmp != NULL) {
        free(tmp);
        *doublyLinkedListNode = NULL;
    }
}

DoublyLinkedList *createDoublyLinkedList() {
    DoublyLinkedList *doublyLinkedList = (DoublyLinkedList*) malloc(sizeof(DoublyLinkedList));
    if(doublyLinkedList != NULL)
       doublyLinkedList->head = NULL;
       doublyLinkedList->tail = NULL;
    return doublyLinkedList;
}

void destroyDoublyLinkedList(DoublyLinkedList **doublyLinkedList) { 
    DoublyLinkedList *tmp = *doublyLinkedList;
    if (tmp != NULL) { 
        if (!isEmptyDoublyLinkedList(tmp)) {
            DoublyLinkedListNode *p = tmp->head;
            while (p != tmp->tail)  {
                DoublyLinkedListNode *q = p;
                p = p->next;
                free(q);
            } 
            free(p);
        }
        free(tmp);
        *doublyLinkedList = NULL;
    } 
}

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

void deleteNodeDoublyLinkedList(DoublyLinkedList *doublyLinkedList, int element) {
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