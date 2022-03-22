#include "dico_list.h"

int main(){

  //création d'une liste vide et vérification qu'elle est bien vide
  dico_list_t dico=dico_list_new();
  print_dico_list(dico);

  printf("TEST DICO VIDE: %s\n",dico_list_is_empty(dico)?"true":"false");

  //ajout mot a dico_list
  printf("\nTEST AJOUT D'UN MOT A LA LISTE VIDE:\n\t");
  dico=dico_list_add_last("oui",dico);
  print_dico_list(dico);

  printf("\nTEST AJOUT D'UN MOT À UNE LISTE DEJA REMPLIE:\n\t");
  dico=dico_list_add_last("non",dico);
  print_dico_list(dico);

  printf("\nTESTE AJOUT D'UNE CHAINE À UNE LISTE DEJA REMPLIE:\n\t");
  dico=dico_list_add_last("je sais pas",dico);
  print_dico_list(dico);

  //recherche d'un mot dans la LISTE
  printf("\nTEST DE RECHERCHE D'UN MOT DANS LA LISTE: \n\t");
  print_dico_list(dico);
  printf("\n\tPresence de -oui- dans la liste: %s",dico_list_is_in("oui",dico)?"true":"false");
  printf("\n\tPresence de -je sais pas- dans la liste: %s",dico_list_is_in("je sais pas",dico)?"true":"false");
  printf("\n\tPresence de -carambole- dans la liste: %s\n",dico_list_is_in("carambole",dico)?"true":"false");

  //suppression de la liste
  printf("\nTEST DE DESTRUCTION DE LISTE:\n\t");
  dico=dico_list_delete(dico);
  print_dico_list(dico);
  free(dico);


  return EXIT_SUCCESS;
}
