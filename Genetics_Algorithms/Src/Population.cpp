/*
+----------------------------------------------------------+
|     Projet : Algorithme génétique     	    		   |
|     Nom du Fichier : population.cpp					   |
|     Personnes : Yann Nebout							   |
|	  Objectifs du programme : Créer une population		   |
|	  Date de Début : 24 Avril 2018						   |
|	  Date de la dernière modification : 25 Avril 2018     |
+----------------------------------------------------------+
*/

#include "Population.hpp"

using namespace std;

Population::Population(int populationSize){
	vector<Individu*> p;
	p.resize(populationSize);
	population = p;
	fitness = -1;
}

Population::Population(int populationSize, int chromosomeLength){
	fitness = -1;
	int taille = populationSize;
	population.resize(taille);
	uint i;
	for (i=0 ; i<population.size() ; i++){
		Individu *ind = new Individu(chromosomeLength);

		population[i] = ind;
	}
}

Population::Population(const Population &p){
	population = p.population;
	fitness = p.fitness;
}

Population::~Population(){}

void Population::setIndividu(int n, Individu *i){ population[n] = i; }
void Population::setPopulation(vector<Individu*> p){ population = p; }
void Population::setFitness(double f){ fitness = f; }

vector<Individu*> Population::getPopulation(){ return population; }
Individu* Population::getIndividu(int i){ return population[i]; }
double Population::getFitness(){ return fitness; }

bool Tri(Individu *i1, Individu *i2){
	return (i1->getFitness()>i2->getFitness());	//	si l'expression est vrai renvoie true sinon false
}

Individu* Population::getFittest(int offset){
	sort(population.begin(),population.end(),Tri);	//	trie les valeur dans l'ordre décroissant

	return population[offset];
}