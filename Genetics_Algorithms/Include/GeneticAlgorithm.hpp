/*
+---------------------------------------------------------------------------------------------+
|     Projet : Algorithme génétique     	    		   									  |
|     Nom du Fichier : GeneticAlgorithm.hpp				   									  |
|     Personnes : Yann Nebout							   									  |
|	  Objectifs du programme : Application des modifications possibles pour la génération     |
|	  Date de Début : 24 Avril 2018						   									  |
|	  Date de la dernière modification : 25 Avril 2018     									  |
+---------------------------------------------------------------------------------------------+
*/

#ifndef GENETICALGORITHM_HPP
#define GENETICALGORITHM_HPP

	#include "Population.hpp"

	class GeneticAlgorithm {
		public:
			//	Constructeurs & Destructeur

			/*
			+-----------------------------------------------------------+
			|     Constructeur de la classe GeneticAlgorithm     		|
			|		Input :												|
			|			pSize(int) : taille de la population     		|
			|			mRate(int) : Pourcentage de mutation     		|
			|			cRate(int) : Pourcentage de crossingover     	|
			|			eCount(int) : nombre de parent sélectionner     |
			+-----------------------------------------------------------+
			*/			
			GeneticAlgorithm(int pSize, double mRate, double cRate, int eCount);

			/*
			+-------------------------------------------------------------------------+
			|     Constructeur par copie de la classe GeneticAlgorithm 				  |
			|		Input :															  |
			|			ga(GeneticAlgorithm) : référence vers un geneticalgorithm     |
			+-------------------------------------------------------------------------+
			*/		
			GeneticAlgorithm(const GeneticAlgorithm &ga);

			/*
			+-----------------------------------------+
			|     Destructeur de GeneticAlgorithm     |
			+-----------------------------------------+
			*/		
			~GeneticAlgorithm();

			//	Autres fonctions

			/*
			+-------------------------------------------------------------------------+
			|     Fonction qui inititialise la population étudiée     				  |
			|		Input : 														  |
			|			chromosomeLength(int) : nombre de gene du chromosome     	  |
			|		Output : 														  |
			|			new Population(Population*) : pointeur sur une population     |
			+-------------------------------------------------------------------------+
			*/		
			Population* initPopulation(int chromosomeLength);

			/*
			+-------------------------------------------------------+
			|     Fonction qui calcul la fitness d'un individu     	|
			|		Input : 										|
			|			i(Individu*) : pointeur sur un individu     |
			|		Output : 										|
			|			fitness(double) : fitness de l'individu     |
			+-------------------------------------------------------+
			*/	
			double calcFitness(Individu* i);
			
			/*
			+-------------------------------------------------------------------+
			|     Fonction qui évalue la fitness de la population     			|
			|		Input : 													|
			|			p(Population*) : pointeur ver la population étudiée     |
			+-------------------------------------------------------------------+
			*/			
			void evalPopulation(Population* p);

			/*
			+-------------------------------------------------------------------+
			|     Fonction qui vérifie si le chromosome est optimal   			|
			|		Input : 													|
			|			p(Population*) : pointeur ver la population étudiée     |
			|		Output : 												  	|
			|			(bool) : booleen sur la validité du test     		    |
			+-------------------------------------------------------------------+
			*/	
			bool isTeminationConditionMet(Population* p);

			/*
			+---------------------------------------------------------------------------+
			|     Fonction qui sélectionne les parents     				  				|
			|		Input : 														  	|
			|			parent(Population) : Population dont sont issus les parents     |
			|		Output : 														  	|
			|			(Individu*) : pointeur sur un individu     						|
			+---------------------------------------------------------------------------+
			*/		
			Individu* selectParent(Population* parent);

			/*
			+---------------------------------------------------------------------------------------------+
			|     Fonction qui réalise un crossing over sur les chromosome enfant	  					  |
			|		Input : 														  					  |
			|			p(Population*) : Population dont on veut donner des enfant avec crossing over     |
			|		Output : 														  					  |
			|			pop(Population*) : pointeur sur une population ayant subi un crossingover     	  |
			+---------------------------------------------------------------------------------------------+
			*/			
			Population* crossoverPopulation(Population* p);

			/*
			+---------------------------------------------------------------------------------------+
			|     Fonction qui réalise des mutations sur les chromosomes enfants	  	   			|
			|		Input : 														  	   			|
			|			p(Population*) : Population dont on veut muter les chromosomes     			|
			|		Output : 														  				|
			|			pop(Population*) : pointeur sur une population ayant subi des mutations     |
			+---------------------------------------------------------------------------------------+
			*/		
			Population* mutatePopulation(Population* p);

		protected:
			int populationSize;		//	Taille de la population
			double mutationRate;	//	Pourcentage de mutation
			double crossoverRate;	//	Pourcentage de crossover
			int elitismCount;		//	Nombre d'individu de la génération qui sont les meilleur
	};


#endif