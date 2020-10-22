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

//  testSimulation3();
//  testMobile2();
//  testSimulation1();
//  testMobile1();
//  testVector3D();
if (testSatellite1())
  cout << "testSatellite() works " << endl; 
if (testEarth())
  cout << "testEarth() works " << endl; 

 /*   Vector3D a(1,1,1);
    Mobile* m = new Mobile("m",a,a);
    MobileHeavy* mH = new MobileHeavy("m",a,a,1.3,1.3);
    
    Simulation s;
    s.addBody(m);
    s.addBody(mH);
    Simulation s2 = Simulation(s);
    
    cout << s.getBodies().size() << endl;
    cout << s2.getBodies().size() << endl;
*/
  return 0;
}
