#ifndef _DICO_LIST_H
#define _DICO_LIST_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <assert.h>
#include <stdbool.h>


// 1. Définition des types maillon (link_t) et liste (dico_list_t)
typedef struct _link {
  char* mot; /* un élément de la liste de type char* */
  int nombre;//utile pour la partie verificateur nombre d'iterations dans la liste
  struct _link *next; /* l'adresse du maillon suivant */
} link_t, *dico_list_t;


//crée une liste vide
dico_list_t dico_list_new();

//regarde si la liste est vide (vide=true ; pas vide=false)
bool dico_list_is_empty(dico_list_t l);

//affiche le dico
void print_dico_list(dico_list_t dico);
void print_dico_list_occurences(dico_list_t dico);

/*verifie si le mot a déja été ajouté à la liste si c'est le cas
le nombre d'occurences est implémenté et la fonction renvoie true
sinon la fonction renvoie false mais le mot n'est pas ajouté*/
bool dico_list_implement(char* mot, dico_list_t* l);

//créé un nouveau maillon
dico_list_t dico_list_nouveau_maillon(const char* mot);

//ajout en tete
dico_list_t dico_list_add_first(char* mot, dico_list_t dico);

//ajoute la chaine de caractère mot au dico (ajout en queue de dico_list)
dico_list_t dico_list_add_last(const char* mot,dico_list_t dico);

//recherche si un mot appartient à la dico_list (sans prendre en compte Maj)
bool dico_list_is_in(char* mot, dico_list_t dico);

//supprime le premier element de la dico_list
dico_list_t dico_list_del_first(dico_list_t dico);

//supprime l'entièreté de la liste
dico_list_t dico_list_delete(dico_list_t dico);






#endif
