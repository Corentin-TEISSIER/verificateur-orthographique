#include "dico_arbreprefixe.h"

arbreprefixe_t arbreprefixe_new(){
  return NULL;
}
arbreprefixe_t arbreprefixe_init(){
  arbreprefixe_t tree=creer_noeud('\0');
  return tree;
}

bool arbreprefixe_vide(arbreprefixe_t a){
  return a==NULL;
}

arbreprefixe_t creer_noeud(char lettre){
  arbreprefixe_t ptr_node=malloc(sizeof(*ptr_node));
  for (int i = 0; i < 26; i++) {
    ptr_node->lettres_suivantes[i]=arbreprefixe_new();
  }
  ptr_node->is_mot=false;
  ptr_node->lettre = lettre;
  return ptr_node;
}

arbreprefixe_t free_arbre(arbreprefixe_t tree){
  for (int i = 0; i < 26; i++) {
    if (tree->lettres_suivantes[i]!=NULL) {
      free_arbre(tree->lettres_suivantes[i]);
    }
  }
  free(tree);
  return NULL;
}

arbreprefixe_t insertion_mot(char* mot, arbreprefixe_t tree){
  arbreprefixe_t path = tree;
  char* copy_mot=conversion_minuscule_bis(mot);
  for (int i = 0; mot[i]!='\0'; i++) {
    //on prend le numéro de la lettre correspondante
    int indice = (int) copy_mot[i] - 'a';
    if (path->lettres_suivantes[indice]==NULL) {
      //la lettre correspondante n'existe pas dans l'arbre on le cree
      path->lettres_suivantes[indice]=creer_noeud(mot[i]);
    }
    path=path->lettres_suivantes[indice];
  }
  //on marque le mot comme existant
  path->is_mot=true;
  free(copy_mot);
  return tree;
}

bool arbreprefixe_is_in(arbreprefixe_t tree, char* mot){
  //cas où le mot contient autre chose que des lettres
  char* copy_mot=conversion_minuscule_bis(mot);
  arbreprefixe_t path = tree;
  for (int i = 0; mot[i]!='\0'; i++) {
    //cas où le mot contient autre chose que des lettres
    if (!(mot[i]>='a' && mot[i]<='z')&&!(mot[i]>='A' && mot[i]<='Z')) {
      free(copy_mot);
      return false;
    }
    int indice = copy_mot[i] - 'a';
    if (path->lettres_suivantes[indice] == NULL) {
      free(copy_mot);
      return false;
    }
    path=path->lettres_suivantes[indice];
  }
  if (path!=NULL && path->is_mot) {
    free(copy_mot);
    return true;
  }
  free(copy_mot);
  return false;
}

void afficher_mot(char str[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%c", str[i]);
  }
  printf("\n");
}

void afficher_mots_arbre(arbreprefixe_t tree, char prefixe[], int position){
  if (arbreprefixe_vide(tree)) {
    return;
  }
  prefixe[position] = tree->lettre;
  position++;
  if (tree->is_mot) {
    afficher_mot(prefixe, position);
  }
  for (int i = 0; i < 26; i++) {
    afficher_mots_arbre(tree->lettres_suivantes[i], prefixe, position);
  }
}
void arbreprefixe_print(arbreprefixe_t tree){
    char prefixe[50];
    int position=0;
    afficher_mots_arbre(tree, prefixe, position);
}
char* conversion_minuscule_bis(char* mot){
  char* copy_mot = malloc(strlen(mot)+1);
  strcpy(copy_mot,mot);
   for(int i=0;mot[i]!='\0';i++){
      copy_mot[i]=tolower(copy_mot[i]);
   }
   return copy_mot;
}
