#ifndef _DICO_ARBREPREFIXE_H
#define _DICO_ARBREPREFIXE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <assert.h>
#include <stdbool.h>
#include <ctype.h>


typedef struct _node{
  char lettre;
  bool is_mot;
  struct _node* lettres_suivantes[26];
} node_t;


typedef node_t* arbreprefixe_t;


//renvoit un arbre comme pointeur null
arbreprefixe_t arbreprefixe_new();

//initialise l'arbre en mettant comme racine '\0'
arbreprefixe_t arbreprefixe_init();

//verifie que l'arbre n'est pas encore rempli
bool arbreprefixe_vide(arbreprefixe_t a);

//création d'un noeud (lettre et allocation des possibles branches)
arbreprefixe_t creer_noeud(char lettre);

//ajout du mot "mot" a l'arbre prefixe
arbreprefixe_t insertion_mot(char* mot, arbreprefixe_t tree);

//affichage de l'arbre arbreprefixe
void afficher_mot(char str[], int n);
void afficher_mots_arbre(arbreprefixe_t tree, char prefixe[], int position);
void arbreprefixe_print(arbreprefixe_t tree);

//recherche d'un mot dans l'arbre (true: le mot appartient/ false: le mot n'appartient pas)
bool arbreprefixe_is_in(arbreprefixe_t tree, char* mot);

//destruction de l'arbre
arbreprefixe_t free_arbre(arbreprefixe_t tree);

//conversion des mots avec majuscule pour coller avec laforme du dictionnaire (tout enminuscule)
char* conversion_minuscule_bis(char* mot);



#endif
