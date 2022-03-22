#include "lecture_dico_list.h"

dico_list_t lecture_dico_list_t(char* fichier){
  FILE* f;
  char mot[512];
  dico_list_t dictionnaire=dico_list_new();
  f=fopen(fichier, "r");
  if (f==NULL) {
    printf("Impossible d'ouvrir le fichier\n");
    exit(EXIT_FAILURE);
  }
  while (fgets(mot,511,f)!=NULL) {
    //on enleve le dernier caractère qui marque la fin de la ligne
    if (mot[strlen(mot)-1]<32) { mot[strlen(mot)-1]=0;}
    dictionnaire=dico_list_add_first(mot,dictionnaire);
  }
  fclose(f);
  return dictionnaire;
}
