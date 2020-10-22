#ifndef _EARTH_H
#define _EARTH_H

#include "MobileHeavy.h"
#include <iostream>


class Earth : public MobileHeavy {
  
  private:
    Earth();
    static Earth* instance;

  public:
    Earth(Earth& other) = delete;
    ~Earth();
    void operator=(const Earth&) = delete;
    static Earth* GetInstance();


};

#endif
