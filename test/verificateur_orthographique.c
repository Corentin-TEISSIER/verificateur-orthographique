#include "verificateur_orthographique.h"

int main(int argc, char* argv[]){
  char* structure;
  int b_argc=3;
  char* b_argv[3];


  if (argc!=4) {
    printf("Nombre d'arguments invalide. Allez voir le README\n");
    exit(EXIT_FAILURE);
  }

  if (!strcasecmp(argv[3],"1")) {
    structure="liste";
  }
  else if (!strcasecmp(argv[3],"2")) {
    structure="table_de_hachage";
  }
  else if (!strcasecmp(argv[3],"3")) {
    structure="arbreprefixe";
  }
  else{
    printf("Le dernier argument passé en ligne de commande doit etre un chiffre entre 1 et 3. Voir le README \n");
    exit(EXIT_FAILURE);
  }

  printf("===================================================\n");
  printf("|| BIENVENUE DANS LE VERIFICATEUR ORTHOGRAPHIQUE ||\n");
  printf("===================================================\n\n\n");
  printf("Vous avez choisi le dictionnaire %s, le texte à vérifier est %s et la structure choisie est %s\n\n", argv[1], argv[2], structure);

  if (!strcasecmp(argv[3],"1") && !strcasecmp(argv[2], "a_la_recherche_du_temps_perdu.txt")) {
    printf("Attention vous vous appretez à appeler la structure liste qui n'est pas optimale sur un fichier très grand.\n\n");
    printf("Cette opération va prendre plus de 40 minutes. On vous conseille de changer de fichier à vérifier\n\n");
    printf("On vous propose de n'utiliser que la première partie du texte. Si cela vous convient taper 1. Sinon, si vous restez sur votre choix de base taper 0\n\n");
    int i=0;
    scanf("%d", &i);
    if (i==1) {
      argv[2]="premiere_partie.txt";
    }
  }

  for (int i = 0; i < 3; i++) {
    b_argv[i]=argv[i];
  }
  if (!strcasecmp(argv[3],"1")) {
    test_lect_dico_liste(b_argc,b_argv);
  }
  else if (!strcasecmp(argv[3],"2")) {
    test_lect_dico_hashtable(b_argc,b_argv);
  }
  else if (!strcasecmp(argv[3],"3")) {
    test_lect_dico_arbreprefixe(b_argc,b_argv);
  }
  return EXIT_SUCCESS;

}








int test_lect_dico_arbreprefixe(int argc, char* argv[]){

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

int test_lect_dico_hashtable(int argc, char* argv[]) {

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

int test_lect_dico_liste(int argc, char* argv[]){

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
