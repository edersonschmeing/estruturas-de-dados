#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    int key;
    struct _Node *next;
} Node;

void merge(Node *head1, Node *head2) {  
    if (head1 != NULL ) {
       Node* temp = head1;
       while (temp->next != NULL ) {
            temp = temp->next;
       } 
       temp->next = head2;
    }
}

/*Node* mergeComRetorno(Node* head1, Node* head2) {  
    if (head1 == NULL && head2 == NULL) 
        return NULL;
    else if (head1 != NULL && head2 == NULL)
        return head1;
    else if (head2 != NULL && head1 == NULL)
        return head2;

    Node* temp = head1;
    while (temp->next != NULL ) {
       temp = temp->next;
    } 
    temp->next = head2;
    return head1; 
}*/




int main() {
    
    Node* segundoHead1 = (Node*) malloc(sizeof(Node));
    segundoHead1->key = 2;
    segundoHead1->next = NULL;
    
    Node* head1 = (Node*) malloc(sizeof(Node));
    head1->key = 1;
    head1->next = segundoHead1;

    Node* head2 = (Node*) malloc(sizeof(Node));
    head2->key = 3;
    head2->next = NULL;

    //head1 = NULL; //para testar com NULL
    //head2 = NULL; //para testar com NULL

    merge(head1, head2);

   // Node* headMerge = mergeComRetorno(head1, head2);; 
     
     while (head1 != NULL) {
       printf("%d - \n", head1->key);
       head1 = head1->next; 
    }

    /*while (headMerge != NULL) {
       printf("%d - \n", headMerge->key);
       headMerge = headMerge->next; 
    }*/

    free(head1);
    free(segundoHead1);
    free(head2);
    //free(headMerge);

    printf("Executou até o final");


};
