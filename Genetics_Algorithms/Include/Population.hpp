/*
+----------------------------------------------------------+
|     Projet : Algorithme génétique     	    		   |
|     Nom du Fichier : population.hpp					   |
|     Personnes : Yann Nebout							   |
|	  Objectifs du programme : Créer une population		   |
|	  Date de Début : 24 Avril 2018						   |
|	  Date de la dernière modification : 25 Avril 2018     |
+----------------------------------------------------------+
*/

#ifndef POPULATION_HPP
#define POPULATION_HPP

	#include "Individu.hpp"

	class Population {
		public:
			//	Constructeurs & Destructeur

			/*
			+--------------------------------------------------------------+
			|     Constructeur de la classe Population     				   |
			|		Input :												   |
			|			populationSize(int) : taille de la population      |
			+--------------------------------------------------------------+
			*/		
			Population(int populationSize);

			/*
			+--------------------------------------------------------------+
			|     Constructeur de la classe Population     				   |
			|		Input :												   |
			|			populationSize(int) : taille de la population      |
			|			chromosomeLength(int) : taille d'un chromosome     |
			+--------------------------------------------------------------+
			*/		
			Population(int populationSize, int chromosomeLength);

			/*
			+-------------------------------------------------------------+
			|     Constructeur par copie de la classe Population 		  |
			|		Input :												  |
			|			p(Population) : référence vers une Population     |
			+-------------------------------------------------------------+
			*/	
			Population(const Population &p);

			/*
			+-----------------------------------+
			|     Destructeur de Population     |
			+-----------------------------------+
			*/		
			~Population();

			//	Setters

			/*
			+--------------------------------------------------------+
			|     Fonction qui change l'individu à la position n     |
			|		Input : 										 |
			|			n(int) : numéro de l'individu     	   		 |
			|			i(Individu*) : individu remplaçant     		 |
			+--------------------------------------------------------+
			*/		
			void setIndividu(int n, Individu *i);

			/*
			+------------------------------------------------------------+
			|     Fonction qui change la population étudiée     		 |
			|		Input : 											 |
			|			p(vector<Individu>) : Population remplaçante     |
			+------------------------------------------------------------+
			*/			
			void setPopulation(std::vector<Individu*> p);

			/*
			+-----------------------------------------------------------------+
			|     Fonction qui change la fitness de la population étudiée     |
			|		Input : 												  |
			|			f(double) : fitness à affecter						  |
			+-----------------------------------------------------------------+
			*/			
			void setFitness(double f);

			//	Getters

			/*
			+------------------------------------------------------------------+
			|     Fonction qui renvoie la population étudiée			  	   |
			|		Output : 												   |
			|			population(vector<Individu*>) : population étudiée     |
			+------------------------------------------------------------------+
			*/			
			std::vector<Individu*> getPopulation();

			/*
			+----------------------------------------------------------------------+
			|     Fonction qui renvoie un individu de la population étudiée        |
			|		Input : 													   |
			|			i(int) : numéro de l'individu à renvoyer     	  		   |
			|		Output : 													   |
			|			population[i](Individu*) : pointeur sur une population     |
			+----------------------------------------------------------------------+
			*/			
			Individu* getIndividu(int i);

			/*
			+-------------------------------------------------------------------------+
			|     Fonction qui renvoie fitness de la population     				  |
			|		Output : 														  |
			|			new Population(Population*) : pointeur sur une population     |
			+-------------------------------------------------------------------------+
			*/			
			double getFitness();

			/*
			+---------------------------------------------------------------------------+
			|     Fonction qui renvoie l'individu avec la meilleur fitness 				|
			|		Input : 														  	|
			|			offset(int) : nombre de gene du chromosome     	  				|
			|		Output : 														  	|
			|			population[offset](Individu*) : pointeur sur une population     |
			+---------------------------------------------------------------------------+
			*/	
			Individu* getFittest(int offset);

		protected:
			std::vector<Individu*> population;	//	Population d'individu
			double fitness;						//	Fitness de la population

	};

/*
+---------------------------------------------------------------------+
|     Fonction qui tri les individus selon la fitness 				  |
|		Input : 													  |
|			i1(Individu*) : pointeur sur un individu     			  |
|			i2(Individu*) : pointeur sur un individu     			  |
|		Output : 													  |
|			(bool) : vrai si l'expression est vérifiée faux sinon     |
+---------------------------------------------------------------------+
*/	
bool Tri(Individu *i1, Individu *i2);

#endif