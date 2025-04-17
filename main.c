#include <stdio.h>
#include "list.h"

#define M 100

int main(){
  List l;
  l=newList();
  FILE *fp;
  fp=fopen("input.txt","r");
  char *line;
  int elem, ch, n, pos;

  for(int i=1; fgets(line, M, fp)!=NULL; i++){
    while((sscanf(line, "%d%n", &elem, &ch))==1){
      addListTail(l, &elem);
    }
    printf("\n\nLista %d letta", i);
    printlistRec(l);
    printf("\nInserire un valore da ricercare e contare quante volte appare: ");
    scanf("%d", &n);
    if(searchListRec(l, n, &pos)){
      printf("\nValore trovato nella posizione %d.", pos);
      printf("\nValore trovato %d volte.", countItemListRec(l, n));
    }else{
      printf("\nValore non trovato.");
    }
    destroyListRec(l);
    printf("\nlista %d distrutta");
  }
}
