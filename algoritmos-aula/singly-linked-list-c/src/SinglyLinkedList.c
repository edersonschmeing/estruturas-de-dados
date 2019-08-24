#include <stdio.h>
#include <stdlib.h>

#include "../include/SinglyLinkedList.h"

SinglyLinkedListNode *createSinglyLinkedListNode(int element) {
    SinglyLinkedListNode *singlyLinkedListNode  = (SinglyLinkedListNode*) malloc(sizeof(SinglyLinkedListNode));
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
}

SinglyLinkedList *createSinglyLinkedList() {
    SinglyLinkedList *singlyLinkedList = (SinglyLinkedList*) malloc(sizeof(SinglyLinkedList));
    if(singlyLinkedList != NULL)
       singlyLinkedList->head = NULL;
       singlyLinkedList->tail = NULL;
    return singlyLinkedList;
 }

 void destroySinglyLinkedList(SinglyLinkedList **singlyLinkedList) { 
     SinglyLinkedList *tmp = *singlyLinkedList;
     if (tmp != NULL) {
         if (!isEmptySinglyLinkedList(tmp)) {  
            SinglyLinkedListNode *current = tmp->head;
            while (current != tmp->tail) {
                SinglyLinkedListNode *p = current;
                current = current->next;
                free(p);
            }
            free(current);
        }
        free(tmp);
     }      
}

int isEmptySinglyLinkedList(SinglyLinkedList *singlyLinkedList) {
    return (singlyLinkedList->head == NULL);
}

void addToHeadSinglyLinkedList(SinglyLinkedList *singlyLinkedList, int element) {
    SinglyLinkedListNode *singlyLinkedListNode = createSinglyLinkedListNode(element);
    if (isEmptySinglyLinkedList(singlyLinkedList)) {
        singlyLinkedList->head = singlyLinkedListNode;
        singlyLinkedList->tail = singlyLinkedListNode;
    } else {
        singlyLinkedListNode->next = singlyLinkedList->head;
        singlyLinkedList->head = singlyLinkedListNode;  
    }
}

void addToTailSinglyLinkedList(SinglyLinkedList *singlyLinkedList, int element) {
    SinglyLinkedListNode *singlyLinkedListNode = createSinglyLinkedListNode(element);
    if (isEmptySinglyLinkedList(singlyLinkedList)) {
        singlyLinkedList->head = singlyLinkedListNode;
        singlyLinkedList->tail = singlyLinkedListNode;
    } else {
        singlyLinkedList->tail->next = singlyLinkedListNode;
        singlyLinkedList->tail = singlyLinkedListNode;
    }

}

int addSinglyLinkedListOrdered(SinglyLinkedList *singlyLinkedList, int element) {
    if(singlyLinkedList == NULL)
        return 0;
    SinglyLinkedListNode *singlyLinkedListNode = createSinglyLinkedListNode(element);
    if (isEmptySinglyLinkedList(singlyLinkedList)) {
       singlyLinkedListNode->next = NULL;
       singlyLinkedList->head = singlyLinkedListNode;  
       singlyLinkedList->tail = singlyLinkedListNode;
       return 1;  
    } else { 
        SinglyLinkedListNode *prev, *current = singlyLinkedList->head; 
        while (current != NULL && current->element < element) {
            prev = current;
            current = current->next;
        }
        if (current == singlyLinkedList->head) {
            singlyLinkedListNode->next = singlyLinkedList->head;
            singlyLinkedList->head = singlyLinkedListNode; 
        } else {
            singlyLinkedListNode->next = current;
            prev->next = singlyLinkedListNode; 
        }
        return 1;
    }
}

void deleteNodeFromSinglyLinkedList(SinglyLinkedList *singlyLinkedList, int element) {

}

/*
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
*/

void printAllSinglyLinkedList(SinglyLinkedList *singlyLinkedList) {
     SinglyLinkedListNode *singlyLinkedListNode = singlyLinkedList->head;
     printf("Head-> ");
     while (singlyLinkedListNode != NULL) {
       printf("%d-> ", singlyLinkedListNode->element);
       singlyLinkedListNode = singlyLinkedListNode->next;
    }
    printf("TAIL \n"); 
}