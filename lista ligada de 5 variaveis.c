#include<stdio.h>
#include<stdlib.h>
struct listaNo{
	int elemento;
	struct listaNo *prox;
};
int main (void){
   struct listaNo *head = NULL,*no;
   int pos, qtd=1;
	 
   for(pos=0; pos<=4 ;pos++){
      printf("Digite o elemento %d:\n", pos+1);
      scanf("%d", &qtd);
	 	
      if(!(no=malloc(sizeof(struct listaNo)))){
         printf("Faltou memória!\n");
         exit(1);
      }
      no -> prox = head;
      head = no;
      no -> elemento = qtd ;
   }
 
   printf("\nFim da criacao da lista\n");
   printf("\n Mostra a lista:\n");
	 
   no = head;
   while( no!= NULL){
      printf("Elementos= %d\n", no -> elemento);
      no = no->prox;
   }
   printf("Destruindo a lista:\n");

   no = head;
   while(no != NULL){
      head = head->prox;
      free(no);
      no=head;
   }
  return 0;
}

