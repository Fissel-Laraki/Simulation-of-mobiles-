#include <iostream>
#include <cassert>
#include "Mobile.h"
#include "MobileHeavy.h"
#include "Simulation.h"
#include "Vector3D.h"
#include "test.h"
#include "Earth.h"

using namespace std;

int main() {

  testSimulation4();
  testSimulation3();
  testMobile2();
  testSimulation1();
  testMobile1();
  testVector3D();

  bool value = true;
  if (testSatellite1() == false)
    cout << "err" << endl;
  if (testEarth() == false)
    cout << "err2" << endl;

  return 0;
}
