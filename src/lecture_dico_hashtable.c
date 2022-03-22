#include "lecture_dico_hashtable.h"

hashtable_t lecture_dico_hashtable_t(char* fichier){
  FILE* f;
  char mot[512];
  hashtable_t dictionnaire=dico_hashtable_new(100000);
  f=fopen(fichier, "r");
  if (f==NULL) {
    printf("Impossible d'ouvrir le fichier pour la lecture du dictionnaire\n");
    exit(EXIT_FAILURE);
  }
  while (fgets(mot,511,f)!=NULL) {
    //on enleve le dernier caractère qui marque la fin de la ligne
    if (mot[strlen(mot)-1]<32) { mot[strlen(mot)-1]=0;}
    dico_hashtable_add(mot,&dictionnaire);;
  }
  fclose(f);
  return dictionnaire;
}
