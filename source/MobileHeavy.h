#ifndef _MOBILE_HEAVY_H
#define _MOBILE_HEAVY_H

#include "Mobile.h"
#include "Vector3D.h"
#include <cmath>
#include <iostream>
#include <list>
#include <string>

class MobileHeavy:public Mobile{
  private:
    const double radius;
    const double density;
    Vector3D acceleration;

  public:

    MobileHeavy();
    MobileHeavy(std::string n, Vector3D, Vector3D, double, double);
    MobileHeavy(const MobileHeavy& m);
    MobileHeavy* copie();
    void avance(double);
    Vector3D gravity(const Vector3D& p);
    void computeAcceleration(std::list<Mobile*>);

    double getDensity()const {return density;}
    double getRadius()const { return radius;}
    Vector3D getAcceleration() const{return acceleration;}

    double mass(){return 0.001*density*(4.0/3.0)*M_PI*pow(radius,3.0);}
};

#endif
