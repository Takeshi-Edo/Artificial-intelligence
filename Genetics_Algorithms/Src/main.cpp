/*
+----------------------------------------------------------+
|     Projet : Algorithme génétique     	    		   |
|     Nom du Fichier : main.cpp							   |
|     Personnes : Yann Nebout							   |
|	  Objectifs du programme : programme principale		   |
|	  Date de Début : 24 Avril 2018						   |
|	  Date de la dernière modification : 25 Avril 2018     |
+----------------------------------------------------------+
*/

#include "GeneticAlgorithm.hpp"

using namespace std;

int main(){
	srand(time(NULL));	//	Initialisation pour le tirage aléatoire
	
	//	Création de l'algo
	GeneticAlgorithm ga(100,0.001,0.95,2);	//	Initialisation des paramètres de mutation/crossover
	Population *population = new Population(*ga.initPopulation(500));	//	Initialisation de la population
	ga.evalPopulation(population);	//	Evaluation de la population

	int generation = 0;	//	Numéro de la génération

	while(!ga.isTeminationConditionMet(population)){
		generation++;

		population=ga.crossoverPopulation(population);	//	Application du crossover
		population=ga.mutatePopulation(population);		//	Application de la mutation
		ga.evalPopulation(population);					//	Evaluation de la génération n+1
	}

	//	Affichage de la génération à laquelle le meilleur chromosome est trouvé
	cout << "Soultion trouvée en : " << generation << " generations" << endl;

	return 0; 
}