#include "dico_hashtable.h"

int fonction_hash(char* mot){
    unsigned int hash=0;
    char* copy_mot=conversion_minuscule(mot);
    for(unsigned i=0;i<strlen(mot);++i){
        hash+=copy_mot[i];
        hash+=(hash<<10);
        hash^=(hash>>6);
    }
    free(copy_mot);
    hash+=(hash<<3);
    hash^=(hash>>11);
    hash+=(hash<<15);
    return hash;
}

hashtable_t dico_hashtable_new(int n){
  hashtable_t h;
  h.size=n;
  h.table=calloc(n,sizeof(dico_list_t));
  for(int i=0;i<n;i++){
    h.table[i]=dico_list_new();
  }
  return h;
}

bool dico_hashtable_n_is_empty(hashtable_t h, int n){
  return dico_list_is_empty(h.table[n]);
}

void print_dico_hashtable(hashtable_t h){
  int i=0;
  while(i<h.size){
    printf("[%d]:\n",i);
    print_dico_list(h.table[i]);
    printf("\n");
    i++;
  }
}

void dico_hashtable_add(char* mot, hashtable_t* h){
  unsigned int hash=fonction_hash(mot);
  hash=hash%(h->size);
  h->table[hash]=dico_list_add_first(mot,h->table[hash]);
}

/*verifie si le mot a déja été ajouté à la table de hachage si c'est le cas
le nombre d'occurences est implémenté et la fonction renvoie true
sinon la fonction renvoie false mais le mot n'est pas ajouté*/
bool dico_hashtable_implement(char* mot, hashtable_t* h){
  unsigned int hash = fonction_hash(mot);
  hash=hash%h->size;
  return dico_list_implement(mot, h->table+hash);
}

char* conversion_minuscule(char* mot){
  char* copy_mot = malloc(strlen(mot)+1);
  strcpy(copy_mot,mot);
   for(int i=0;mot[i]!='\0';i++){
      copy_mot[i]=tolower(copy_mot[i]);
   }
   return copy_mot;
}

bool dico_hashtable_is_in(char* mot, hashtable_t h){
  unsigned int hash=fonction_hash(mot);
  hash=hash%(h.size);
  return dico_list_is_in(mot,h.table[hash]);
}

void dico_hashtable_delete(hashtable_t h){
  for(int i=0;i<h.size;i++){
    dico_list_delete(h.table[i]);
  }
  free(h.table);
}

//utilisation de la table de hashage pour le retour des erreurs:

void hashtable_retour_erreurs(hashtable_t h, int nombre){
  int i=0;
  printf("Le programme a trouvé %d erreurs:\n\n",nombre);
  while(i<h.size){
    if(!dico_list_is_empty(h.table[i])){
      print_dico_list_occurences(h.table[i]);
    }
    i++;
  }
}
