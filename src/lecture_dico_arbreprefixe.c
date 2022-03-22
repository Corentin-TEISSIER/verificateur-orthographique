#include "lecture_dico_arbreprefixe.h"

arbreprefixe_t lecture_dico_arbreprefixe(char* fichier){
  FILE* f;
  char mot[25];
  arbreprefixe_t dictionnaire=arbreprefixe_init();
  f=fopen(fichier, "r");
  if (f==NULL) {
    printf("Impossible d'ouvrir le fichier pour la lecture du dictionnaire\n");
    exit(EXIT_FAILURE);
  }
  while (fgets(mot,24,f)!=NULL) {
    //on enleve le dernier caractère qui marque la fin de la ligne
    if (mot[strlen(mot)-1]<32) { mot[strlen(mot)-1]=0;}
    dictionnaire=insertion_mot(mot,dictionnaire);;
  }
  fclose(f);
  return dictionnaire;
}
