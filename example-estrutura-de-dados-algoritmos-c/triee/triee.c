#include <stdio.h>
#include <ncurses.h>

//https://forum.imasters.com.br/topic/374985-resolvido%C2%A0c%C3%B3digoarvore-binario-em-c/

main(){
       int arvore[21];
       int i,j,aux;
       int resp,troca,busca;
    
       //enche o vetor para testar o menu e permitir que o usuario visualize mesmo sem ter inserido
       for (i = 0; i<21; i++){
              arvore[i] = 0;              
       }
       // cabecalho
       printf("\n_______________________________________________________________________________\n");
       printf("|\tPrograma Desenvolvido Para Finalidade Academica\t\t\t      |\n");
       printf("|\tUtilizando-se plataforma Windows\t\t\t\t      |\n");
       printf("|\tFerramenta Utilizada: Dev - C ++\t\t\t\t      |\n");
       printf("|\tDesenvolvedor: Vinicius da Silva Barbosa\t\t\t      |\n");
       printf("|\tGraduando do curso de Sistemas de Informacao -  FAVALE\t\t      |\n");
       printf("|\tCarangola, MG - Outubro/2009\t\t\t\t\t      |\n");
       printf("_______________________________________________________________________________\n");
       printf("\n\t  Desenvolveremos uma arvore binaria numerica com 21 posicoes\n");
       
       //laco condicional para repeticao do menu
       while (resp != 0){
              printf("\n_______________________________________________________________________________\n\n");
              printf("\t\t\t|--------->MENU<-----------|");
              printf("\n\t\t\t|__________________________|\n");
              printf("\t\t\t| 1 - Inserir numeros      |\n");
              printf("\t\t\t| 2 - Exibir e ordenar     |\n");
              printf("\t\t\t| 3 - Exibir arvore        |\n");
              printf("\t\t\t| 4 - Editar numeros       |\n");
              printf("\t\t\t| 5 - Editar nos/arvore    |\n");
              printf("\t\t\t| 6 - Pesquisa binaria     |\n");
              printf("\t\t\t| 7 - Sair                 |");   
              printf("\n\t\t\t|__________________________|\n");
              printf("\t\t\t\n\t\t\t Agora, entre com sua opcao: \a");
              scanf("%d",&resp); 
              
              // executa as funçoes do menu
              switch(resp){
                           
                     //insere numeros
                     case 1:                        
                            system("cls");
                            printf("\n_______________________________________________________________________________\n");
                            printf(" -->>Voce escolheu inserir numeros, siga as instrucoes abaixo");
                            printf("\n_______________________________________________________________________________\n\n");
                            printf(" -->>ENTRE COM OS VALORES PARA AS RESPECTIVAS POSICOES\n\n");
                            for (i=0; i<21; i++){
                                  printf("\t\tPosicao    %d : ",i+1); 
                                  scanf("%d",&arvore[i]);                                  
                            }
                            printf("\n\n -->>Voce inseriu 21 numeros!");
                            printf("\n_______________________________________________________________________________\n\n");
                            
                     break;
                     
                     //exibe os numeros em ordem crescente
                     case 2:
                            system("cls");
                            printf("\n_______________________________________________________________________________\n");
                            printf(" -->>Voce escolheu exibir os numeros inseridos");
                            printf("\n_______________________________________________________________________________\n\n");
                            printf(" -->>CONFIRA!\n\n");
                            for(i=0; i<20; i++){
                                  for(j=i+1; j<21; j++){
                                        if (arvore[i] > arvore[j]){
                                              troca = arvore[i];
                                              arvore[i] = arvore[j];
                                              arvore[j] = troca;             
                                        }                                        
                                  }                            
                            }
                            for (i=0; i<21; i++){
                                   printf("\n\t -->> POSICAO %d  =  %d",i,arvore[i]); 
                            }
                            printf("\n\n -->>Voce visualizou os 21 numeros!");
                            printf("\n_______________________________________________________________________________\n\n");
                     break;
                     
                     //exibe os numeros em forma de arvore com seus nos
                     case 3:
                            system("cls");
                            printf("\n_______________________________________________________________________________\n");
                            printf(" -->>Voce escolheu visualizar a arvore");
                            printf("\n_______________________________________________________________________________\n\n");
                            printf(" -->>VEJA OS NOS INTERMEDIARIOS DA ARVORE!\n\n");
                            // altura 0       
                            printf("\t\t\t\t =%d\t\t\t\n",arvore[10]); // posicao 10
                            printf("\t\t\t\t|___|\t\t\t\n"); // linha posicao 10
                            printf("\t\t\t\t  1  \t\t\t\n\n\n\n");// linha posicao 10
                            // altura 1
                            printf("\t\t     =%d\t",arvore[3]); // posicao 3
                            if(arvore[3]>9){
                                  printf("\t     =%d\t\n",arvore[17]); // posicao 17 maior que 9
                            }
                            else
                                  printf("\t\t     =%d\t\n",arvore[17]); // posicao 17 menor que 10
                            printf("\t\t    |___|\t");  // linha posicao 3   
                            printf("\t    |___|\t\n"); // linha posicao 17
                            printf("\t\t      2  \t");  // linha posicao 3   
                            printf("\t      5  \t\n\n\n"); // linha posicao 17
                            // altura 2      
                            printf("\t      =%d",arvore[2]);//  posicao 2
                            printf("\t   =%d",arvore[5]);//  posicao 5       
                            printf("\t      =%d",arvore[15]); //  posicao 15
                            printf("\t   =%d\t\n",arvore[18]); // posicao 18
                            printf("\t     |___|");// linha posicao 2
                            printf("\t  |___|");// linha posicao 5       
                            printf("\t     |___|"); // linha posicao 15
                            printf("\t  |___|\t\n"); // linha posicao 18
                            printf("\t       3  ");// linha posicao 2
                            printf("\t    4  ");// linha posicao 5       
                            printf("\t       6  "); // linha posicao 15
                            printf("\t    7  \t"); // linha posicao 18
                            printf("\n\n"); 
                            printf("\n\n -->>ARVORE BINARIA!");
                            printf("\n_______________________________________________________________________________\n\n");                      
                     break;
                     
                     //edita os numeros do vetor
                     case 4:
                            system("cls");
                            printf("\n_______________________________________________________________________________\n");
                            printf(" -->>Voce escolheu editar os numeros do vetor, siga as instrucoes abaixo");
                            printf("\n_______________________________________________________________________________\n\n");
                            printf(" -->>VEJA OS NUMEROS INSERIDOS\n\n");
                            for (i=0; i<21; i++){
                                   printf("\n\t -->> POSICAO %d  =  %d",i,arvore[i]); 
                            }
                            printf("\n\n -->>AGORA, INFORME A POSICAO A SER EDITADA\n\n");
                            scanf("%d",&i);
                            printf("\n\n -->>EDITE A POSICAO %d, ENTRE COM O NOVO VALOR :  ",i);
                            scanf("%d",&arvore[i]);
                            printf("\n\n -->>ALTERADO COM SUCESSO!");
                            printf("\n_______________________________________________________________________________\n\n");
                     break;
                     
                     //edita os nos da arvore
                     case 5:
                            system("cls");
                            printf("\n_______________________________________________________________________________\n");
                            printf(" -->>Voce escolheu editar os nos da arvore, siga as instrucoes abaixo");
                            printf("\n_______________________________________________________________________________\n\n");
                            printf(" -->>VEJA OS NUMEROS EXISTENTES\n\n");
                            for (i=0; i<21; i++){
                                   printf("\n\t -->> POSICAO %d  =  %d",i,arvore[i]); 
                            }
                            printf("\n\n -->>VEJA OS NOS DA ARVORE\n\n");
                            // altura 0       
                            printf("\t\t\t\t =%d\t\t\t\n",arvore[10]); // posicao 10
                            printf("\t\t\t\t|___|\t\t\t\n"); // linha posicao 10
                            printf("\t\t\t\t  1  \t\t\t\n\n\n\n");// linha posicao 10
                            // altura 1
                            printf("\t\t     =%d\t",arvore[3]); // posicao 3
                            if(arvore[3]>9){
                                  printf("\t     =%d\t\n",arvore[17]); // posicao 17 maior que 9
                            }
                            else
                                  printf("\t\t     =%d\t\n",arvore[17]); // posicao 17 menor que 10
                            printf("\t\t    |___|\t");  // linha posicao 3   
                            printf("\t    |___|\t\n"); // linha posicao 17
                            printf("\t\t      2  \t");  // linha posicao 3   
                            printf("\t      5  \t\n\n\n"); // linha posicao 17
                            // altura 2      
                            printf("\t      =%d",arvore[2]);//  posicao 2
                            printf("\t   =%d",arvore[5]);//  posicao 5       
                            printf("\t      =%d",arvore[15]); //  posicao 15
                            printf("\t   =%d\t\n",arvore[18]); // posicao 18
                            printf("\t     |___|");// linha posicao 2
                            printf("\t  |___|");// linha posicao 5       
                            printf("\t     |___|"); // linha posicao 15
                            printf("\t  |___|\t\n"); // linha posicao 18
                            printf("\t       3  ");// linha posicao 2
                            printf("\t    4  ");// linha posicao 5       
                            printf("\t       6  "); // linha posicao 15
                            printf("\t    7  \t"); // linha posicao 18
                            printf("\n\n");                      
                            printf("\n\n -->>AGORA, INFORME O NO A SER EDITADO\n\n");
                            scanf("%d",&i);
                            aux = i;
                            switch (i){
                                    case 1: i=10;
                                    break;
                                    case 2: i=3;
                                    break;
                                    case 3: i=2;
                                    break;
                                    case 4: i=5;
                                    break;
                                    case 5: i=17;
                                    break;
                                    case 6: i=15;
                                    break;
                                    case 7: i=18;
                                    break;
                            }
                           
                            printf("\n\n -->>EDITE O NO %d, ENTRE COM O NOVO VALOR :  ",aux);
                            scanf("%d",&arvore[i]);
                            printf("\n\n -->>ALTERADO COM SUCESSO!");
                            printf("\n\n -->>APOS ESCOLHER A OPCAO 2 OS NOS SERAO REORGANIZADOS!");
                            printf("\n_______________________________________________________________________________\n\n");
                     break;
                     
                     //pesquisa na arvore binaria
                     case 6:
                            system("cls");
                            printf("\n_______________________________________________________________________________\n");
                            printf(" -->>Voce escolheu editar os nos da arvore, siga as instrucoes abaixo");
                            printf("\n_______________________________________________________________________________\n\n");
                            printf(" -->>VEJA OS NUMEROS EXISTENTES\n\n");
                            for (i=0; i<21; i++){
                                   printf("\n\t -->> POSICAO %d  =  %d",i,arvore[i]); 
                            }
                            printf("\n\n");                      
                            printf("\n\n -->>AGORA, INFORME O NUMERO A SER BUSCADO\n\n");
                            scanf("%d",&busca);
                            //pesquisa lado direito
                            if(busca > arvore[10]){
                                    for (i=11; i<21; i++){
                                         if(busca == arvore[i]){
                                              printf("\n\tNumero %d encontrado no lado direito na POSICAO %d .",arvore[i],i);
                                         }    
                                         else{
                                              printf("\n\t...Ainda nao encontrado!");
                                         }
                                    }
                            } 
                            //pesquisa lado esquerdo
                            else{
                                    if(busca < arvore[10]){
                                         for (i=0; i<10; i++){
                                              if(busca == arvore[i]){
                                                   printf("\n\tNumero %d encontrado no lado esquerdo na POSICAO %d .",arvore[i],i);
                                              }    
                                              else
                                                   printf("\n\t...Ainda nao encontrado!");
                                         }              
                                    }
                            //a pesquisa eh o nó de altura 0
                                    else
                                         printf("\n\tNumero %d encontrado no topo da arvore na POSICAO %d .",arvore[10],10);
                            }
                     break;
                     
                     //finaliza
                     case 7:
                            resp = 0;
                            system("cls");
                            printf("\n_______________________________________________________________________________\n");
                            printf(" -->>VOCE OPTOU POR FINALIZAR O PROGRAMA, OBRIGADO!");
                            printf("\n_______________________________________________________________________________\n\n\n"); 
              
              }        
             
       }            
      
       system("PAUSE");       
    }
 