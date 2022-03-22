#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dico_hashtable.h"
#include "dico_list.h"

int main(){

  //création d'une table de hashage
  printf("TEST CREATION DE LA TABLE:\n");
  hashtable_t h=dico_hashtable_new(5);
  print_dico_hashtable(h);

  //ajout de mots dans la TABLE
  printf("TEST AJOUT DE MOTS A LA TABLE:\n");

  char* mot1="vache";
  char* mot2="écureuil";
  char* mot3="renard";
  char* mot4="hiboux";
  char* mot5="chien";
  char* mot6="chat";
  char* mot7="mulot";
  char* mot8="serpent";
  char* mot9="pigeon";
  char* mot10="lapin";
  char* mot11="lion";
  char* mot12="antilope";
  char* mot13="albatros";
  char* mot14="perroquet";
  char* mot15="lézar";

  dico_hashtable_add(mot1,&h);
  dico_hashtable_add(mot2,&h);
  dico_hashtable_add(mot3,&h);
  dico_hashtable_add(mot4,&h);
  dico_hashtable_add(mot5,&h);
  dico_hashtable_add(mot6,&h);
  dico_hashtable_add(mot7,&h);
  dico_hashtable_add(mot8,&h);
  dico_hashtable_add(mot9,&h);
  dico_hashtable_add(mot10,&h);
  dico_hashtable_add(mot11,&h);
  dico_hashtable_add(mot12,&h);
  dico_hashtable_add(mot13,&h);
  dico_hashtable_add(mot14,&h);
  dico_hashtable_add(mot15,&h);

  print_dico_hashtable(h); getchar();

  //recherche d'un élément dans la TABLE
  printf("TEST RECHERCHE D'UN ELEMENT DANS LA TABLE:\n");
  printf("\n\tPresence de -vache- dans la liste: %s",dico_hashtable_is_in("vache",h)?"true":"false");
  printf("\n\tPresence de -perroquet- dans la liste: %s",dico_hashtable_is_in("perroquet",h)?"true":"false");
  printf("\n\tPresence de -singe- dans la liste: %s\n\n",dico_hashtable_is_in("singe",h)?"true":"false");

  //destruction de la table
  dico_hashtable_delete(h);

  return EXIT_SUCCESS;
}
