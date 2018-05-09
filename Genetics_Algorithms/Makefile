############################################################
#     Projet : Algorithme génétique     	    		   #
#     Nom du Fichier : Makefile							   #
#     Personnes : Yann Nebout							   #
#	  Date de Début : 24 Avril 2018						   #
#	  Date de la dernière modification : 25 Avril 2018     #
############################################################

CC=gcc
PP=g++

SRCDIR=Src
HEADDIR=Include
# Option de compilation : 
#	 Wall : affiche les warnings
#	 Werror : warning = erreur
#	 Wextra : Ajoute des warning specifique en plus a Wall
#	 g : analyse gdb & valgrind
CXXFLAGS= -I$(HEADDIR) -Wall -cpp

# Executable
EXEC = Algogene

# Où trouver les différents sources *.cpp qu'il faudra compiler pour créer les objets correspondants
SRC= $(wildcard $(SRCDIR)/*.cpp)
OBJ= $(SRC:$(SRCDIR)/%.cpp=%.o)

all: $(EXEC) .PHONY

Algogene: main.o GeneticAlgorithm.o Population.o Individu.o 
	$(PP) -o $@  $^ $(CXXFLAGS)
	./Algogene
	
# Création des différents *.o à partir des *.cpp
%.o: $(SRCDIR)/%.cpp
	$(PP) -o $@ -c $< $(CXXFLAGS) -std=c++0x
	
clean:
	rm -rf *.o *~
	
vclean:
	rm -rf $(EXEC)
	
.PHONY: clean
