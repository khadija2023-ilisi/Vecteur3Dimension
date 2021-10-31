#pragma once
#include <iostream>
using namespace std;
namespace geometre {

	class Vecteur3D
	{
	private:
		float vect[3];
	public:
		Vecteur3D(float x=0.0 ,float y=0.0,float z=0.0);
		//l'interdiction du constructeur de recoupie et =
		Vecteur3D(const Vecteur3D&)=delete;//impossible d'utiliser cette methode
		Vecteur3D& operator=(const Vecteur3D&) = delete;//,,
		void print()const;
		float at(unsigned int)const;
		float& operator[](unsigned int);//accede en mode lecture et ecriure
		bool operator==(const Vecteur3D&)const;
		bool operator!=(const Vecteur3D&)const;
		//friend void display(Vecteur3D& V);
		float norme()const;
		float P_scalaire(const Vecteur3D&)const;
		void P_vectoriel(const Vecteur3D&);
		bool perpendiculaire(const Vecteur3D&)const;
		bool isVectNull()const;
		bool parallele(const Vecteur3D&)const;
	};
	//void display(Vecteur3D& V);
};
