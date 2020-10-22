#include <iostream>
#include <ostream>
#include <string>
#include <iomanip>
#include "Mobile.h"
#include "Vector3D.h"

using namespace std;

Mobile::Mobile() {
}

Mobile::Mobile(string n, Vector3D p, Vector3D v):name(n),position(p),vitesse(v) {
}

Mobile::~Mobile() {
}


Mobile::Mobile(const Mobile& m) {
    Mobile(m.name,m.position,m.vitesse);
}

Mobile* Mobile::copie() {
    return new Mobile(*this);//appel du constructeur par copie 
}


// Calcule (vitesse *  le temps) ensuite incremente la position de cette somme
void Mobile::avance(double dt) {
    position = position + (vitesse*dt);
}

ostream& operator<<(ostream& os, Mobile& m) {
    os << setw(10) << m.name << m.position << m.vitesse << endl;
    return os;
}

double Mobile::mass(){
  return 0;
}

Vector3D Mobile::getAcceleration() const{
  return Vector3D(0,0,0);
}
