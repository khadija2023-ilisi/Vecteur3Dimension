#include "pch.h"
#include "Vecteur3D.h"
#include <assert.h>
#include <math.h>
using namespace geometre;
geometre::Vecteur3D::Vecteur3D(float x, float y, float z)
{
	this->vect[0] = x;
	this->vect[1] = y;
	this->vect[2] = z;
}

void geometre::Vecteur3D::print() const
{
	cout << "Vecteur [";
	for (int ind=0; ind < 3; ind++)
		cout << this->at(ind) << " ";
	cout << "]\n";
}

float geometre::Vecteur3D::at(unsigned int i) const
{
	assert(i >= 0 && i < 3);//debug
	try//mode release
	{
		if (i < 0 || i >= 3)throw "rang error";
		return this->vect[i];
	}
	catch(char* e)
	{
		cout << e << endl;
	}
}
float& geometre::Vecteur3D::operator[](unsigned int i)
{
	assert(i > 0 && i < 3);//debug
	try//mode release
	{
		if (i < 0 || i >= 3)throw "rang error";
		return this->vect[i];
	}
	catch (char* e)
	{
		cout << e << endl;
	}
}
//fin de la fonction at


bool geometre::Vecteur3D::operator==(const Vecteur3D& v) const
{
	bool res = true;
	for (int i = 0; i < 3; i++)
	{
		//res = res && (this->vect[i] == v.vect[i]);
		res = res && (this->at(i) == v.at(i));
	}
	return res;
}

bool geometre::Vecteur3D::operator!=(const Vecteur3D& v) const
{
	bool res = !(*this == v);
	return res;
}

float geometre::Vecteur3D::norme() const
{
	return sqrt(pow(this->at(0),2)+pow(this->at(1),2)+pow(this->at(2),2));
}

float geometre::Vecteur3D::P_scalaire(const Vecteur3D& v) const
{
	float res=0;
	for (int i = 0; i < 3; i++)
	{
		res += this->at(i) * v.at(i);
	}
	return res;
}

void geometre::Vecteur3D::P_vectoriel(const Vecteur3D& v) 
{
	
	float a = (this->at(1) * v.at(2)) - (this->at(2) * v.at(1));
	float b = (this->at(2) * v.at(0)) - (this->at(0) * v.at(2));
	float c = (this->at(0) * v.at(1)) - (this->at(1) * v.at(0));
	this->vect[0] = a;
	this->vect[1] = b;
	this->vect[2] = c;
}

bool geometre::Vecteur3D::perpendiculaire(const Vecteur3D& a) const
{

	return (this->P_scalaire(a)==0.0);
}

bool geometre::Vecteur3D::isVectNull() const
{
	for (int i = 0; i < 3; i++)
		if (this->at(i) != 0.0) return false;
	return true;
}

bool geometre::Vecteur3D::parallele(const Vecteur3D& a) const
{
	Vecteur3D tmp(this->at(0), this->at(1), this->at(2));
	tmp.P_vectoriel(a);
	return tmp.isVectNull();
}

/*void geometre::display(Vecteur3D& V)
{
	cout << "Vecteur [";
	for (int ind = 0; ind < 3; ind++)
		cout << V.vect[ind] << " ";
	cout << "]\n";
}
*/