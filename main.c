#include <stdio.h>
#include <stdlib.h>
#include "list.h"

#define M 100

Item inputItemString(char **stream){
	int *p = malloc(sizeof(int));
	int ch;
	if((sscanf(*stream, "%d%n", p, &ch))==1){
		(*stream)+=ch;
		return p;
	}else{
		return NULL;
	}
}

int main(){
  List l;
  l=newList();
  FILE *fp;
  fp=fopen("input.txt","r");
  char *line;
  int pos;
  Item e, arr[M], n;

  for(int i=1; fgets(line, M, fp)!=NULL; i++){
    while(1){
      e=inputItemString(&line);
      if(e==NULL){
        break;
      }else{
        addListTail(l, e);
      }
    }
    printf("\n\nLista %d letta ", i);
    printListRec(l);
    printf("\nInserire un valore da ricercare e contare le apparizioni: ");
    n=inputItem();
    if(searchListRec(l, n, &pos)){
      printf("\nValore trovato nella posizione %d.", pos);
      printf("\nValore trovato %d volte.", countItemListRec(l, n));
    }else{
      printf("\nValore non trovato.");
    }
    destroyListRec(l);
    printf("\nlista %d distrutta.", i);
  }
}
