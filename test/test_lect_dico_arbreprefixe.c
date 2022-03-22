#include "lecture_dico_arbreprefixe.h"


int main(int argc, char* argv[]){

  if (argc!=3) {
    printf("Nombre d'arguments invalide. Allez voir le README\n");
    exit(EXIT_FAILURE);
  }

  FILE* f;

  f=fopen(argv[2], "r");
  if (f==NULL) {
    printf("Impossible d'ouvrir le fichier\n");
    exit(EXIT_FAILURE);
  }

  arbreprefixe_t dictionnaire=lecture_dico_arbreprefixe(argv[1]);

  //nombre de char maximal elevé car on considère qu'une ligne se termine par un retour à la ligne et non un point
  char line[50000];
  char* mot;
  const char* separateurs=" ,.-/!?;:'\"()_\t\r\n";
  int compteur=0; //compte le nombre de mots faux
  while (fgets(line,49999,f)!=NULL) {
    mot=strtok(line,separateurs);
    while (mot!=NULL) {
      if (!arbreprefixe_is_in(dictionnaire,mot)) {
        printf("%s\n", mot);
        compteur++;
      }
      mot=strtok(NULL,separateurs);
    }
  }
  printf("\nIl y'a %d erreurs\n", compteur);
  fclose(f);
  free_arbre(dictionnaire);
  return EXIT_SUCCESS;
}
