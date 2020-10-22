#ifndef _MOBILE_H
#define _MOBILE_H
#include <iostream>
#include <list>
#include <ostream>
#include <string>
#include "Vector3D.h"

class Mobile {
  protected:
    std::string name;
    Vector3D position;
    Vector3D vitesse;

  public:
    Mobile();
    Mobile(std::string,Vector3D,Vector3D);
    ~Mobile();
    Mobile(const Mobile&);
    virtual Mobile* copie();
    friend std::ostream& operator<<(std::ostream&,Mobile&);
    virtual void avance(double dt);
    std::string getName() const {return name;}
    Vector3D getPosition() const {return position;}
    Vector3D getVitesse() const {return vitesse;}
    virtual Vector3D getAcceleration() const;
    virtual double mass();
    virtual void computeAcceleration(std::list<Mobile*>){}
    virtual Vector3D gravity(const Vector3D&){return Vector3D(0,0,0);}

};

std::ostream& operator<<(std::ostream&,Mobile&);
#endif
