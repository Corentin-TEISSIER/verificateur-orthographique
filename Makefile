# Ce Makefile permet de générer les executables
# - pour les tests f1main et f2main du repertoire tests
#-  pour le programme pccmain du repertoire src

# les fichiezrs executables sont situés sdnas le repertoire bin


#Les repertoires
#Pour les fichiers d'entete
INCDIR=./include
#Pour les fichiers executables
BINDIR=./bin
#Pour les fichiers binaires (.o)
OBJDIR=./obj
#Pour les fichiers de tests
TEST=./test
#Pour les fichiers sources .c
SRCDIR=./src

#Le nom du compilateur
CC=gcc

#Les options du compilateur : compilation (-c) et debug (-g). On peut ajouter -O3 pour optimiser quand le code est juste
CFLAGS= -O3 -std=c99 -Wall -Wextra -g -pg -I$(INCDIR) -lm

EXEDIR=$(OBJDIR) $(BINDIR) $(BINDIR)/testdicoliste $(BINDIR)/test_lect_dico_liste $(BINDIR)/testdicohashtable $(BINDIR)/test_lect_dico_hashtable $(BINDIR)/testdicoarbreprefixe $(BINDIR)/test_lect_dico_arbreprefixe $(BINDIR)/verificateur_orthographique

#Regle par défaut (make)
all: $(EXEDIR)

#Règle de construction d'exécutable
$(BINDIR)/testdicoliste : $(OBJDIR)/dico_list.o $(OBJDIR)/testdicoliste.o
	$(CC) -o $@ $^ $(CFLAGS)

$(BINDIR)/test_lect_dico_liste : $(OBJDIR)/test_lect_dico_liste.o  $(OBJDIR)/lecture_dico_list.o $(OBJDIR)/dico_list.o
	$(CC) -o $@ $^ $(CFLAGS)

$(BINDIR)/testdicohashtable : $(OBJDIR)/dico_hashtable.o $(OBJDIR)/dico_list.o $(OBJDIR)/testdicohashtable.o
	$(CC) -o $@ $^ $(CFLAGS)

$(BINDIR)/test_lect_dico_hashtable : $(OBJDIR)/test_lect_dico_hashtable.o  $(OBJDIR)/lecture_dico_hashtable.o $(OBJDIR)/dico_hashtable.o $(OBJDIR)/dico_list.o
	$(CC) -o $@ $^ $(CFLAGS)

$(BINDIR)/testdicoarbreprefixe : $(OBJDIR)/dico_arbreprefixe.o $(OBJDIR)/testdicoarbreprefixe.o
	$(CC) -o $@ $^ $(CFLAGS)

$(BINDIR)/test_lect_dico_arbreprefixe : $(OBJDIR)/test_lect_dico_arbreprefixe.o  $(OBJDIR)/lecture_dico_arbreprefixe.o $(OBJDIR)/dico_arbreprefixe.o
	$(CC) -o $@ $^ $(CFLAGS)

$(BINDIR)/verificateur_orthographique : $(OBJDIR)/verificateur_orthographique.o  $(OBJDIR)/lecture_dico_list.o $(OBJDIR)/dico_list.o  $(OBJDIR)/lecture_dico_hashtable.o $(OBJDIR)/dico_hashtable.o $(OBJDIR)/dico_list.o $(OBJDIR)/lecture_dico_arbreprefixe.o $(OBJDIR)/dico_arbreprefixe.o
	$(CC) -o $@ $^ $(CFLAGS)

# pour construire les fichiers binaires .o
$(OBJDIR)/%.o : $(TEST)/%.c
	$(CC) -c $(CFLAGS) $^ -o $@

$(OBJDIR)/%.o : $(SRCDIR)/%.c
	$(CC) -c $(CFLAGS) $^ -o $@

#Création des dossiers obj et bin
$(OBJDIR):
	mkdir $@
$(BINDIR):
	mkdir $@

clean:
	rm -rf $(OBJDIR)/* $(BINDIR)/* *.dSYM
	rm -f gmon.out
