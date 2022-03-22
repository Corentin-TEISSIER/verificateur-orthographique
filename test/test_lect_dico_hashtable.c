#include "lecture_dico_hashtable.h"


int main(int argc, char* argv[]) {

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
  hashtable_t dictionnaire=lecture_dico_hashtable_t(argv[1]);
  //nombre de char maximal elevé car on considère qu'une ligne se termine par un retour à la ligne et non un point
  char line[50000];
  const char* separateurs=" ,.-/!?;:'\"()_\t\r\n";
  hashtable_t table_errors = dico_hashtable_new(200);
  int compteur=0;
  while (fgets(line,49999,f)!=NULL) {
    char* mot=strtok(line,separateurs);
    while (mot!=NULL) {
      if (!dico_hashtable_is_in(mot,dictionnaire)) {
        compteur++;
        //on verifie que le mot n'a pas déja été marqué comme erreur
        bool boolean=dico_hashtable_implement(mot,&table_errors);
        //si on l'avait pas encore trouvé on l'ajoute
        if (!boolean) {
          dico_hashtable_add(mot,&table_errors);
        }

      }
      mot=strtok(NULL,separateurs);
    }
  }
  hashtable_retour_erreurs(table_errors,compteur);
  printf("\nNombre d'erreurs trouvées:%d\n", compteur);
  fclose(f);
  dico_hashtable_delete(dictionnaire);
  dico_hashtable_delete(table_errors);
  return EXIT_SUCCESS;
}
