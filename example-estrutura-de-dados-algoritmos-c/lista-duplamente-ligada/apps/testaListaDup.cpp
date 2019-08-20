#include <stdio.h>
#include "../include/ListaDup.hpp"

int main() {

   ListaDup *l = CriaListaDup();
   
   //InsereInicioListaDup(l, 4);
   //InsereInicioListaDup(l, 2);
   //InsereInicioListaDup(l, 10);

   InsereFimListaDup(l, 10);
   InsereFimListaDup(l, 2);
   InsereFimListaDup(l, 4);
   InsereFimListaDup(l, 7);

   ImprimeListaDup(l); 
   ImprimeListaDupInvertido(l);

   puts("Removendo 4");
   RemoveNoDup(l, 4);
   ImprimeListaDup(l); 
   ImprimeListaDupInvertido(l);
   puts("Removendo 7");
   RemoveNoDup(l, 7);

   ImprimeListaDup(l); 
   ImprimeListaDupInvertido(l);

   DestroiListaDup(&l);

   return 0;
}