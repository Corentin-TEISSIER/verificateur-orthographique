#ifndef _DICO_HASHTABLE_H
#define _DICO_HASHTABLE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <assert.h>
#include <stdbool.h>
#include <ctype.h>

#include "dico_list.h"


// 1. Définition des types maillon (link_t) et liste (list_t)
typedef struct _hashtable {
  int size;
  dico_list_t* table;
} hashtable_t;



//initialisation d'une table de hashage à n indices
hashtable_t dico_hashtable_new(int n);

//calcul du hash d'un mot
int fonction_hash(char* mot);

//vérification que le liste d'indice n de la table est vide
bool dico_hashtable_n_is_empty(hashtable_t h, int n);

//affichage de la table de hashage
void print_dico_hashtable(hashtable_t h);

/*verifie si le mot a déja été ajouté à la table de hachage si c'est le cas
le nombre d'occurences est implémenté et la fonction renvoie true
sinon la fonction renvoie false mais le mot n'est pas ajouté*/
bool dico_hashtable_implement(char* mot, hashtable_t* h);

//ajout d'un élément à la table
void dico_hashtable_add(char* mot, hashtable_t* h);

//recherche d'un élément dans la table
char* conversion_minuscule(char* mot);
bool dico_hashtable_is_in(char* mot, hashtable_t h);

//destruction de la table (libération de la mémoire)
void dico_hashtable_delete(hashtable_t h);

//affichage des erreur lors de l'utilisation de la table pour conserver les erreurs
void hashtable_retour_erreurs(hashtable_t h, int nombre);



#endif
