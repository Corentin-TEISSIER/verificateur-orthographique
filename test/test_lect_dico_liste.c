#include "lecture_dico_list.h"


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

  dico_list_t dictionnaire=lecture_dico_list_t(argv[1]);

  //nombre de char maximal elevé car on considère qu'une ligne se termine par un retour à la ligne et non un point
  char line[50000];
  const char* separateurs=" ,.-/!?;:'\"()_\t\r\n";
  dico_list_t list_errors = dico_list_new();
  int compteur=0; //compte le nombre demots faux
  while (fgets(line,49999,f)!=NULL) {
    char* mot=strtok(line,separateurs);
    while (mot!=NULL) {
      //on verifie d'abord que ce mot n'a pas déja été marqué comme faux
      bool boolean=dico_list_implement(mot,&list_errors);
      if (boolean) {
        compteur++;
      }
      //si on l'avait pas encore trouvé on l'ajoute
      if (!boolean && !dico_list_is_in(mot,dictionnaire)) {
        list_errors=dico_list_add_first(mot,list_errors);
        compteur++;
      }
      mot=strtok(NULL,separateurs);
    }
  }
  printf("Le programme a retrouvé %d erreurs. Les-voici:\n\n",compteur);
  print_dico_list_occurences(list_errors);
  printf("\nNombre d'erreurs trouvées:%d\n", compteur);
  fclose(f);
  dico_list_delete(dictionnaire);
  dico_list_delete(list_errors);
  return 0;
}
