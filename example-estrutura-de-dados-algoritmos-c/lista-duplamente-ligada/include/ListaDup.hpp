#ifndef _LISTA_DUP_H
#define _LISTA_DUP_H

typedef struct _no_dup {
    int valor;
    struct _no_dup *anterior;
    struct _no_dup *proximo;
} NoDup;

typedef struct _lista_dup {
    NoDup *inicio;
    NoDup *fim;
} ListaDup;


NoDup *CriaNoDup(int valor);
void DestroiNoDup(NoDup **p);

ListaDup *CriaListaDup();
void DestroiListaDup(ListaDup **l);
int ListaDupEstaVazia(ListaDup *l);
void InsereInicioListaDup(ListaDup *l, int valor);
void InsereFimListaDup(ListaDup *l, int valor);
void ImprimeListaDup(ListaDup *l);
void ImprimeListaDupInvertido(ListaDup *l);
void RemoveNoDup(ListaDup *l, int valor);



#endif