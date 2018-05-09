/*
+----------------------------------------------------------+
|     Projet : Algorithme génétique     	    		   |
|     Nom du Fichier : Individu.hpp						   |
|     Personnes : Yann Nebout							   |
|	  Objectifs du programme : créer un individu		   |
|	  Date de Début : 24 Avril 2018						   |
|	  Date de la dernière modification : 25 Avril 2018     |
+----------------------------------------------------------+
*/

#ifndef INDIVIDU_HPP
#define INDIVIDU_HPP

	#include "util.hpp"

	class Individu {
		public:
			//	Constructeurs & Destructeur

			/*
			+--------------------------------------------------------------------------+
			|     Constructeur par défaut de la classe Individu     				   |
			+--------------------------------------------------------------------------+
			*/	
			Individu();

			/*
			+--------------------------------------------------------------+
			|     Constructeur de la classe Individu     				   |
			|		Input :												   |
			|			chrom(vector<int>) : chromosome de l'individu      |
			+--------------------------------------------------------------+
			*/
			Individu(std::vector<int> chrom);

			/*
			+----------------------------------------------------------------+
			|     Constructeur de la classe Individu     				   	 |
			|		Input :												   	 |
			|			chromosomeLength(int) : taille de la chromosome      |
			+----------------------------------------------------------------+
			*/
			Individu(int chromosomeLength);

			/*
			+--------------------------------------------------------------------------------+
			|     Constructeur par copie de la classe Individu     				   			 |
			|		Input :												    				 |
			|			i(Individu) : Individu dont on veut copier les caractéristiques      |
			+--------------------------------------------------------------------------------+
			*/
			Individu(const Individu &i);

			/*
			+------------------------------------------+
			|     dstructeur de la classe Individu     |
			+------------------------------------------+
			*/
			~Individu();

			//	Setters

			/*
			+-----------------------------------------------------+
			|     Fonction qui change le gene à la position n     |
			|		Input : 									  |
			|			n(int) : numéro du gene     	   		  |
			|			gene(int) : valeur du gene     		 	  |
			+-----------------------------------------------------+
			*/	
			void setGene(int i, int gene);

			/*
			+------------------------------------------------------+
			|     Fonction qui change la fitness du chromosome     |
			|		Input : 									   |
			|			i(double) : fitness à affecter 	   		   |
			+------------------------------------------------------+
			*/	
			void setFitness(double i);

			/*
			+---------------------------------------------------------+
			|     Fonction qui change le chromosome de l'individu     |
			|		Input : 										  |
			|			chrom(vector<int>) : nouveau chromosome		  |
			+---------------------------------------------------------+
			*/	
			void setChromosome(std::vector<int> chrom);

			//	Getters

			/*
			+----------------------------------------------+
			|     Fonction qui renvoie le gene i		   |
			|		Input : 							   |
			|			i(int) : numéro du gène		  	   |
			|		Output : 							   |
			|			chromosome[i](int) : ième gène     |
			+----------------------------------------------+
			*/
			int getGene(int i);

			/*
			+------------------------------------------------------------------+
			|     Fonction qui renvoie le chromosoome de l'individu		  	   |
			|		Output : 												   |
			|			chromosome(vector<int>) : chromosome de l'individu     |
			+------------------------------------------------------------------+
			*/
			std::vector<int> getChromosome();

			/*
			+-------------------------------------------------------+
			|     Fonction qui renvoie la fitness de l'indvidu		|
			|		Output : 									   	|
			|			fitness(double) : fitness de l'individu     |
			+-------------------------------------------------------+
			*/
			double getFitness();

			/*
			+-------------------------------------------------------------+
			|     Fonction qui renvoie la taille du chromosome			  |
			|		Output : 											  |
			|			chromosome.size()(int) : taille du chromosome     |
			+-------------------------------------------------------------+
			*/
			int getchromosomeSize();

			//	Autres fonctions

			/*
			+------------------------------------------------------------+
			|     Fonction qui transforme un vector de int en string   	 |
			|		Output : 											 |
			|			gene(string) : version string du chromosome      |
			+------------------------------------------------------------+
			*/	
			std::string toString();
			
		protected:
			std::vector<int> chromosome;	//	chromosome de l'individu
			double fitness;					//	fitness de l'individu
	};

#endif