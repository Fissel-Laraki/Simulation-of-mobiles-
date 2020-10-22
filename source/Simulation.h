#ifndef _SIMULATION_H
#define _SIMULATION_H

#include <iostream>
#include <string>
#include <list>
#include "Mobile.h"




class Simulation{

  private:
    double time;
    std::list<Mobile*> bodies;
    double time_step;

  public:
    Simulation();
    Simulation(const Simulation& s);
    void addBody(Mobile*);
    void removeBody(Mobile*);
    void step(double);
    std::string to_string();
    void simulate(double stop);

    std::list<Mobile*> getBodies() const {return bodies;}
    double getTime(){return time;}
};



#endif
