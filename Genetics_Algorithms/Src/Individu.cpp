/*
+----------------------------------------------------------+
|     Projet : Algorithme génétique     	    		   |
|     Nom du Fichier : Individu.cpp						   |
|     Personnes : Yann Nebout							   |
|	  Objectifs du programme : Créer un individu		   |
|	  Date de Début : 24 Avril 2018						   |
|	  Date de la dernière modification : 25 Avril 2018     |
+----------------------------------------------------------+
*/

#include "Individu.hpp"

using namespace std;

Individu::Individu(){}

Individu::Individu(vector<int> chrom){
	chromosome = chrom;
	fitness = -1;
}

Individu::Individu(int chromosomeLength){
	int taille = chromosomeLength, gene;
	vector<int> v;
	v.resize(taille);
	chromosome = v;
	fitness = -1;

	for (gene=0 ; gene<chromosomeLength ; gene++)
		setGene(gene, rand()%2);
}

Individu::Individu(const Individu &i){
	fitness = i.fitness;
	chromosome = i.chromosome;
}

Individu::~Individu(){}

void Individu::setGene(int i, int gene){ chromosome[i] = gene; }

void Individu::setFitness(double i){ fitness = i; }

void Individu::setChromosome(vector<int> chrom){ chromosome = chrom; }

int Individu::getGene(int i) { return chromosome[i]; }
vector<int> Individu::getChromosome() { return chromosome; }
double Individu::getFitness() {return fitness; }
int Individu::getchromosomeSize(){ return chromosome.size(); }

string Individu::toString(){
	string gene = "";
	uint i;

	for (i=0 ; i<chromosome.size() ; i++){	//	On transforme chaque int en string et on le rajoute au string gene
		gene += std::to_string(chromosome[i]);
	}
	return gene;
}