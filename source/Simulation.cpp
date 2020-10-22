#include <iostream>
#include <algorithm>
#include <list>
#include <sstream>
#include <string>
#include "Mobile.h"
#include "Simulation.h"
#include "Vector3D.h"

using namespace std;

Simulation::Simulation():time(0.0),time_step(0.1) {
}

Simulation::~Simulation(){
    std::list<Mobile*>::iterator it;
    for  (it = bodies.begin() ; it != bodies.end() ; it++)
      delete *it;
}


Simulation::Simulation(const Simulation& s){
    time = s.time;
    time_step = s.time_step; 
    list<Mobile*> l = s.getBodies();
    for (Mobile* m : l){
        bodies.push_back(m->copie());
    }
}

void Simulation::addBody(Mobile* m ) {
    bodies.push_back(m);
}

void Simulation::removeBody(Mobile *m) {
    bodies.remove_if([m](Mobile*n) {return n==m;});
}

void Simulation::step(double dt){
    list<Mobile*>::iterator it;
    for (it = bodies.begin(); it != bodies.end(); it++) {
        (*it)->computeAcceleration(bodies);
        (*it)->avance(dt); 
    }
    time += dt;
}


void Simulation::simulate(double stop) {
    
  double time= 0.0;
  while (time < stop) {
    this->step(this->time_step);
    time += this->time_step;
  }
}

string Simulation::to_string() {
    ostringstream ss;
    ss << time;
    string s = "time : " + ss.str();
    ss << bodies.size();
    s += "\nmobiles : " + ss.str()+"\n" ;
    return s;
}
