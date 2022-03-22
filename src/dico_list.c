#include "dico_list.h"


void print_link(link_t link){
  printf("%s",link.mot);
}

dico_list_t dico_list_new(){
  return NULL;
}

bool dico_list_is_empty(dico_list_t dico){
  return NULL == dico;
}

void print_dico_list_occurences(dico_list_t dico){
  dico_list_t parcours=dico;
  if (dico_list_is_empty(dico)) {
    printf("(La liste est vide)\n");
    return;
  }
  while (!dico_list_is_empty(parcours)) {
    printf("%s nombre d'occurences:%d\n", parcours->mot,parcours->nombre);
    parcours=parcours->next;
  }
}

void print_dico_list(dico_list_t dico){
  dico_list_t parcours=dico;
  if (dico_list_is_empty(dico)) {
    printf("(La liste est vide)\n");
    return;
  }
  while (!dico_list_is_empty(parcours)) {
    printf("%s\n", parcours->mot);
    parcours=parcours->next;
  }
}

dico_list_t dico_list_nouveau_maillon(const char* mot){
  dico_list_t nouveau_maillon=malloc(sizeof(*nouveau_maillon));
  nouveau_maillon->mot=malloc((strlen(mot)+1)*sizeof(char));
  strcpy(nouveau_maillon->mot,mot);
  nouveau_maillon->nombre=1;
  nouveau_maillon->next=NULL;
  return(nouveau_maillon);
}

dico_list_t dico_list_add_first(char* mot, dico_list_t dico){
  dico_list_t nouveau_maillon=dico_list_nouveau_maillon(mot);
  nouveau_maillon->next=dico;
  return nouveau_maillon;
}

dico_list_t dico_list_add_last(const char* mot,dico_list_t dico){

  dico_list_t nouveau_maillon=dico_list_nouveau_maillon(mot);
  if(dico_list_is_empty(dico)){
      return nouveau_maillon;
  }

  else{
    dico_list_t courant = dico;
    while (true) {
      if(courant->next == NULL){
        courant->next = nouveau_maillon;
        return dico;
      }
      courant = courant->next;
    }
  }
}

/*verifie si le mot a déja été ajouté à la liste si c'est le cas
le nombre d'occurences est implémenté et la fonction renvoie true
sinon la fonction renvoie false mais le mot n'est pas ajouté*/
bool dico_list_implement(char* mot, dico_list_t* l){
  dico_list_t parcours=*l;
  while (parcours!=NULL) {
    if (!strcasecmp(mot,parcours->mot)) {
      parcours->nombre++;
      return true;
    }
    parcours=parcours->next;
  }
  return false;
}

bool dico_list_is_in(char* mot, dico_list_t dico){
  dico_list_t courant=dico;
  while(!dico_list_is_empty(courant)){
    if(strcasecmp(courant->mot,mot)==0){
      return true;
    }
    courant=courant->next;
  }
  return false;
}


dico_list_t dico_list_del_first(dico_list_t dico){
  assert(!dico_list_is_empty(dico));
  dico_list_t p=dico->next;
  free(dico->mot);
  free(dico);
  return p;
}

dico_list_t dico_list_delete(dico_list_t dico){
  dico_list_t p=dico;
  while (!dico_list_is_empty(p)){
    p = dico_list_del_first(p);
  }
  return p;
}
