#include <iostream>
#include <iterator>
#include <sstream>
#include "Earth.h"
#include "Mobile.h"
#include "MobileHeavy.h"
#include "Vector3D.h"
#include <cmath>
#include <algorithm>

#define _USE_MATH_DEFINES

using namespace std;

MobileHeavy::MobileHeavy():Mobile(),density(0),radius(0){
}

MobileHeavy::MobileHeavy(string n,Vector3D p, Vector3D v,double radius, double density):Mobile(n,p,v),radius(radius),density(density){
}

MobileHeavy::MobileHeavy(const MobileHeavy& m):MobileHeavy(m.getName(),m.getPosition(),m.getVitesse(),m.getRadius(),m.getDensity()){}

MobileHeavy* MobileHeavy::copie() {
   return new MobileHeavy(*this);
}

void MobileHeavy::avance(double dt){

  // La methode parente pour changer le vecteur position
  Mobile::avance(dt);
  // On modifie aussi son vecteur vitesse
  this->vitesse = this->vitesse +  (this->acceleration*dt);

}

Vector3D MobileHeavy::gravity(const Vector3D& p) {
  double d = ( p - this->position).norm();
  return  (p - (this->position))*(-(this->mass()*6.6708e-11)/(d*d*d));
}

void MobileHeavy::computeAcceleration(list<Mobile *> l) {

  Vector3D somme;
  list<Mobile*>::iterator it;
  for (it = l.begin(); it != l.end(); it++) {
    if ((*it) != this)
      somme = somme + (*it)->gravity(this->position);
  }
  this->acceleration = somme;
}
