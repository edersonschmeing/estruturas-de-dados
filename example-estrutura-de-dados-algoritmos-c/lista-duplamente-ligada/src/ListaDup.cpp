#include <stdlib.h>
#include <iostream>
#include "../include/ListaDup.hpp"


NoDup *CriaNoDup(int valor)  {
    NoDup *p  = (NoDup*) calloc(1, sizeof(NoDup));
    p->valor = valor; 
    p->anterior = NULL;
    p->proximo = NULL;
    return p;
}

void DestroiNoDup(NoDup **p) {
    NoDup *aux = *p;
    if(aux != NULL) {
        free(aux);
        *p = NULL;
    }
}

ListaDup *CriaListaDup()  {
    ListaDup *l  = (ListaDup*) calloc(1, sizeof(ListaDup));
    l->inicio = NULL;
    l->fim = NULL;
    return l;

}

void DestroiListaDup(ListaDup **l) {
    ListaDup *aux = *l;
    if (aux != NULL ) {
         NoDup *p = aux->inicio;
         while (p != NULL) { 
             NoDup *q = p;
             free(q);
        }
        free(aux);
        l = NULL;
    }
}

int ListaDupEstaVazia(ListaDup *l) {
    return (l->inicio == NULL);
}

void InsereInicioListaDup(ListaDup *l, int valor) {
    NoDup *p = CriaNoDup(valor);
    if (ListaDupEstaVazia(l)) {
        l->inicio = p; 
        l->fim = p;
    } else {
        p->proximo = l->inicio;
        l->inicio->anterior = p;
        l->inicio = p;
    }
} 

void InsereFimListaDup(ListaDup *l, int valor) {
    NoDup *p = CriaNoDup(valor);
    if (ListaDupEstaVazia(l)) {
        l->inicio = p; 
        l->fim = p;
    } else {
        l->fim->proximo = p;
        p->anterior = l->fim;
        l->fim = p;
    }
} 

void RemoveNoDup(ListaDup *l, int valor) {
    if (!ListaDupEstaVazia(l)) {
        NoDup *p = l->inicio;
        if (l->inicio->valor == valor) { //inicio -cabeca da lista
            l->inicio = p->proximo;

            if (l->fim == p) { 
                l->fim = NULL;
            }else{
                l->inicio->anterior = NULL;
            }
            free(p);
            
        } else {
            p = p->proximo;
            while (p != NULL) {
                if (p->valor == valor) {
                    p->anterior->proximo = p->proximo;

                    if (l->fim == p ) {
                        l->fim = p->proximo;
                    }else {
                        p->proximo->anterior = p->anterior;
                    }
                    free(p);
                    p = NULL;
                } else {
                    p = p->proximo;
                }
            }
        }
     }

}


void ImprimeListaDup(ListaDup *l) {
    NoDup *p = l->inicio;
    printf("L Inicio-> ");
    while (p != NULL) {
       printf("%d-> ", p->valor);
       p = p->proximo;
    }
    printf(" NULL \n");    
}

void ImprimeListaDupInvertido(ListaDup *l) {
     NoDup *p = l->fim;
    printf("L Fim-> ");
    while (p != NULL) {
       printf("%d-> ", p->valor);
       p = p->anterior;
    }
    printf(" NULL \n");  

}