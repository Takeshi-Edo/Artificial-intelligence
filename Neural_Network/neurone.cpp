#include <iostream>		// Entrée sortie
#include <fstream>		// Fichier
#include <string>		// Ouvre la possibilité d'utilisé la classe String
#include <cmath>		// Accès à la bibliothèque C math.h
#include <vector>

// Bibliothèques de base du C
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

struct Data{
	int i;
	vector<vector<float> > data;
};

class Neurone{
	protected:
		vector<double> input;
		vector<double> output;
		string etage;
		int entree;
		int sortie;
		double poids;

	public:
		Neurone(){};
		virtual ~Neurone(){};

		virtual double calcul(){};
		virtual double activation(){};
		virtual void initEntree(){};
		virtual void initSortie(){};
};

class NeuroneConv : public Neurone{
	public:
		NeuroneConv(){
			entree = 1;
			sortie = 1;
			etage = "aucun";

			initEntree();
			initSortie();
		};
		NeuroneConv(int nb_entree, int nb_sortie, string e){
			entree = nb_entree;
			sortie = nb_sortie;
			etage = e;

			initEntree();
			initSortie();
		};
		~NeuroneConv(){};

		double getInput(int i){ return input[i]; };
		double getOutput(int i){ return output[i]; };
		double getEntree(){ return entree; };
		double getSortie(){ return sortie; };
		string getEtage(){ return etage; };

		virtual double calcul(){ return 0; };
		virtual double activation(){ return 0; };
		virtual void initEntree(){
			int i;
			for (i=0 ; i<entree ; i++){
				input.push_back(double(i+1));
			}
		};
		virtual void initSortie(){
			int i;
			for (i=0 ; i<sortie ; i++){
				output.push_back(double(i+1));
			}};
};

class Couche{
	protected:
		int nb_neurone;
		string numero;
	public:
		Couche(){};
		virtual ~Couche(){};
		virtual void consturctionCouche(){};
};

class CoucheConv : public Couche{
	protected:
		vector<NeuroneConv> couche;
	public:
		CoucheConv(int nb_n, string num){
			numero = num;
			nb_neurone = nb_n;

			consturctionCouche();
		};
		~CoucheConv(){};

		int getNbNeurone() { return nb_neurone; };
		string getNumero() { return numero; };
		NeuroneConv getNeurone(int i) { return couche[i]; };

		virtual void consturctionCouche(){
			int i;

			for (i=0 ; i<nb_neurone ; i++){
				NeuroneConv neurone = NeuroneConv(2,1,numero);
				couche.push_back(neurone);
			}
		};
};

class Reseau{
	protected:
		int nb_couche;
		string type;
	public:
		Reseau(){};
		~Reseau(){};

		void creationReseau(){};
		void init(){};
		void apprentissage(){};
		void test(){};
};

int main(){
	int i=0,j;

	j=i;

	i=j;

	return 0;
}
