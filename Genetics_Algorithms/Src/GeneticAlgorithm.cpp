/*
+---------------------------------------------------------------------------------------------+
|     Projet : Algorithme génétique     	    		   									  |
|     Nom du Fichier : GeneticAlgorithm.cpp				   									  |
|     Personnes : Yann Nebout							   									  |
|	  Objectifs du programme : Application des modifications possibles pour la génération     |
|	  Date de Début : 24 Avril 2018						   									  |
|	  Date de la dernière modification : 25 Avril 2018     									  |
+---------------------------------------------------------------------------------------------+
*/

#include "GeneticAlgorithm.hpp"

using namespace std;

GeneticAlgorithm::GeneticAlgorithm(int pSize, double mRate, double cRate, int eCount){
	populationSize = pSize;
	mutationRate = mRate;
	crossoverRate = cRate;
	elitismCount = eCount;
}

GeneticAlgorithm::GeneticAlgorithm(const GeneticAlgorithm &ga){
	populationSize = ga.populationSize;
	mutationRate = ga.mutationRate;
	crossoverRate = ga.crossoverRate;
	elitismCount = ga.elitismCount;
}

GeneticAlgorithm::~GeneticAlgorithm(){}

Population* GeneticAlgorithm::initPopulation(int chromosomeLength){ return new Population (populationSize, chromosomeLength); }

double GeneticAlgorithm::calcFitness(Individu* i){
	int correctGenes=0, geneIndex;

	for (geneIndex=0 ; geneIndex<i->getchromosomeSize() ; geneIndex++)	//	A chaque fois que la valeur 1 est rencontrée alors on incrémente une variable
		if (i->getGene(geneIndex)==1)
			correctGenes += 1;

	double fitness = double(correctGenes)/double(i->getchromosomeSize());	//	La fitness correspond au rapport de la somme des bons gènes et le nombre total de gène

	i->setFitness(fitness);
	return fitness;
}

void GeneticAlgorithm::evalPopulation(Population *p){
	double popFitness = 0;
	Individu individu;
	int i;

	for (i=0 ; i<populationSize ; i++)
		popFitness += calcFitness(p->getIndividu(i));	//	La fitness d'une population correspond à la somme des fitness des individus

	p->setFitness(popFitness);
}

bool GeneticAlgorithm::isTeminationConditionMet(Population *p){
	int it;

	for (it=0 ; it<populationSize ; it++)
		if (p->getIndividu(it)->getFitness()==1)	//	Si tous les gènes sont à 1 alors l'individu est parfait
			return true;

	return false;
}

Individu *GeneticAlgorithm::selectParent(Population* parent){
	Individu* ind;
	Population* individu = parent;
	double populationFitness = parent->getFitness();
	double rouletteWhelPosition = ((rand()%1000)/1000)*populationFitness;	//	Seuil pour sélectionner le second parent

	double spinWheel = 0;	//	permet de sélectionner le second parent

	int i;
	for (i=0 ; i<populationSize ; i++){
		ind = individu->getIndividu(i);
		spinWheel += ind->getFitness();

		if (spinWheel>=rouletteWhelPosition)
			return ind;
	}

	return individu->getIndividu(individu->getPopulation().size()-1);
}

Population* GeneticAlgorithm::crossoverPopulation(Population* p){
	int popIndex;
	int geneIndex;
	Population* pop = p;

	for (popIndex=0 ; popIndex<populationSize ; popIndex++){
		Individu *parent1 = pop->getFittest(popIndex);

		if (crossoverRate>double(rand()%1000)/1000.0 && popIndex>=elitismCount){
			Individu *offspring = new Individu(parent1->getchromosomeSize());
			Individu *parent2 = selectParent(p);

			for (geneIndex=0 ; geneIndex<parent1->getchromosomeSize() ; geneIndex++)
				offspring->setGene(geneIndex,0.5>(double(rand()%1000)/1000)?parent1->getGene(geneIndex):parent2->getGene(geneIndex));	//	si 0.5>nombre_random alors on prend le gène du parent 1 sinon on prend celui du parent 2
			pop->setIndividu(popIndex,offspring);
		} 
		else
			pop->setIndividu(popIndex,parent1);
	}
	return pop;
}

Population* GeneticAlgorithm::mutatePopulation(Population* p){
	Population *pop = new Population(populationSize);
	int popIndex, geneIndex;

	for (popIndex=0 ; popIndex<populationSize ; popIndex++){
		Individu *individu = p->getFittest(popIndex);

		for (geneIndex=0 ; geneIndex<individu->getchromosomeSize() ; geneIndex++){
			if (popIndex > elitismCount){
				if (mutationRate>double(rand()%1000)/1000.0){
					int gene = individu->getGene(geneIndex)==1?0:1;	//	si le gène = 1 alors 0 sinon 1
					individu->setGene(geneIndex,gene);
				}
			}
		}
		pop->setIndividu(popIndex,individu);
	}
	return pop;
}