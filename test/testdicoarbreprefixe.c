#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dico_arbreprefixe.h"

int main(){

  printf("TEST CREATION D'UN ARBRE VIDE:\n");

  arbreprefixe_t tree=arbreprefixe_init();
  arbreprefixe_print(tree);

  // tree=creer_noeud_vide();
  // tree->mot="root";
  // tree->a=creer_noeud_vide();
  // tree->a->mot="a";
  // tree->a->a=creer_noeud_vide();
  // tree->a->a->mot="aa";
  // arbreprefixe_print(tree);

  printf("TEST D'AJOUT DE MOTS:\n");
  printf("=====================\n");

  tree=insertion_mot("a",tree);
  arbreprefixe_print(tree);

  printf("=====================\n");

  tree=insertion_mot("aa",tree);
  arbreprefixe_print(tree);

  printf("=====================\n");

  tree=insertion_mot("abc",tree);
  arbreprefixe_print(tree);

  printf("=====================\n");

  tree=insertion_mot("brosse",tree);
  tree=insertion_mot("brosser",tree);
  tree=insertion_mot("arbre",tree);
  tree=insertion_mot("arbitre",tree);
  tree=insertion_mot("mais",tree);
  tree=insertion_mot("maison",tree);
  tree=insertion_mot("maisonne",tree);
  tree=insertion_mot("Bonjour",tree);
  arbreprefixe_print(tree);

  printf("=====================\n");

  printf("TEST RECHERCHE D'UN MOT DANS L'ARBRE:\n");

  printf("\n\tPresence de -arbre- dans la liste: %s\n",arbreprefixe_is_in(tree,"arbre")?"true":"false");
  printf("\n\tPresence de -mais- dans la liste: %s\n",arbreprefixe_is_in(tree,"mais")?"true":"false");
  printf("\n\tPresence de -singe- dans la liste: %s\n",arbreprefixe_is_in(tree,"singe")?"true":"false");
  printf("\n\tPresence de -maisonne- dans la liste: %s\n",arbreprefixe_is_in(tree,"maisonne")?"true":"false");
  printf("\n\tPresence de -Maisonne- dans la liste: %s\n",arbreprefixe_is_in(tree,"Maisonne")?"true":"false");
  printf("\n\tPresence de -Bonjour- dans la liste: %s\n\n",arbreprefixe_is_in(tree,"Bonjour")?"true":"false");

  printf("TEST DESTRUCTION D'UN ARBRE:\n");

  tree=free_arbre(tree);
  arbreprefixe_print(tree);







}
