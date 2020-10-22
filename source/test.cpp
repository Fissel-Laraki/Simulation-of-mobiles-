#include <algorithm>
#include <cmath>
#include <iostream>
#include <cassert>
#include "test.h"
#include <iterator>
#include <list>
#include "Vector3D.h"
#include "Mobile.h"
#include "MobileHeavy.h"
#include "Simulation.h"
#include "Earth.h"


using namespace std;

bool testSatellite1() {
    
    Mobile* satellite = new MobileHeavy("satellite",Vector3D(6571000.0,0,0),Vector3D(0.0,7784.3,0.0),1.0,1.0);
    Earth* earth = Earth::GetInstance();
    Simulation* s = new Simulation();
    s->addBody(satellite);
    s->addBody(earth);
    
    double T = 2.0*M_PI*sqrt(pow(6578000.0,3.0)/norm(earth->gravity(Vector3D(1.0,0,0))));
    Vector3D depart = satellite->getPosition();
    s->simulate(T);
    
    double d =  distance(depart,satellite->getPosition());
    
    
    double max = 70000.0; // 70 km la distance maximale

    s->removeBody(earth);

    delete s;
    delete earth;
    
    if (d >= max ) 
      return false;
    return true;

}

bool testEarth() {
    Earth* e1 = Earth::GetInstance();
    Vector3D position = e1->getPosition();
    bool var = true;

    // On s'assure qu'on se situe bien à la position (0,0,0)
    for (int i = 0 ; i < 3 ; i++ ) {
        if (position[i] != 0)
          var =  false;
    }

    double GM = norm(e1->gravity(Vector3D(1.0,0,0)));
    double g =  GM/pow(e1->getRadius(),2); // On est censé obtenir quelque chose proche de 9.81

    if ( g < 9.0 || g > 10.0)
      var =  false;

    delete e1;
    return var;
}

void testSimulation4() {
    
    Simulation* s1 = new Simulation();

    Mobile* satellite1 = new MobileHeavy("satellite1",Vector3D(6578000.0,0,0),Vector3D(0.0,7784.3,0.0),0.0,0.0);
    Mobile* satellite2 = new MobileHeavy("satellite2",Vector3D(6578000.0,0,0),Vector3D(0.0,7784.3,0.0),0.0,0.0);

    Earth* earth = Earth::GetInstance();

    s1->addBody(satellite1);
    s1->addBody(satellite2);
    s1->addBody(earth);


    Simulation* s2 =  new Simulation(*s1);

    s1->simulate(1000);
    s2->simulate(1000);

    // Si les deux simulations contiennent les mêmes mobiles, alors ils devraient subir exactement la meme simulation et donc le meme temps.
    assert(s1->getTime() == s2->getTime());
    
    s1->removeBody(earth);
    s2->removeBody(earth);

    delete s1;
    delete s2;
    delete earth;
}
void testSimulation3(){

    
    Earth* earth = Earth::GetInstance();
    

    Vector3D position(0,0,100 + earth->getRadius());
    Vector3D vitesse(0,0,0);

    MobileHeavy* mH = new MobileHeavy("mobileHeavy",position,vitesse,0,0);
    Mobile* m = new Mobile("mobile",position,vitesse);

    Simulation s;

    s.addBody(earth);
    s.addBody(mH);
    s.addBody(m);

    Vector3D tmp ;
    while ( mH->getPosition()[2] >= earth->getRadius() && m->getPosition()[2] >= earth->getRadius()) {
        s.step(0.1);
    }

    // D'apres l'exercice precedente, on sait que notre objet mobileHeavy arrive au sol au bout de 4.5 sol
    // De plus l'objet Mobile a une vitesse constante car la gravité ne s'applique pas dessus donc il n'atteindra pas le sol aussi vite que l'objet pesant
    // On s'attend donc a avoir un temps de simulation proche de 4.5s

    double delta = 0.1 ;
    Vector3D vite = mH->getVitesse();
    assert(s.getTime() <= 4.5 + delta && s.getTime() >= 4.5 - delta /*&& m->getPosition()[2] > 0*/ );

    s.removeBody(earth);

}

void testMobile2(){

    Earth* earth = Earth::GetInstance();

    // On créé nos vecteurs position et vitesse qu'on pourra attribuer au mobile m
    Vector3D position(0,0,100+earth->getRadius());
    Vector3D vitesse(0,0,0);
    MobileHeavy* m = new MobileHeavy("mobileHeavy",position,vitesse,1,1);
    // On utilise la classe Simulation, pour obtenir un temps a la fin
    Simulation s;
    s.addBody(m);
    s.addBody(earth);

    // On verifie que position[2] -- donc la coordonnée z -- n'est pas négatif
    while(m->getPosition()[2] >=earth->getRadius()){
        s.step(0.1);
    }
    // Delta est notre marge d'erreur
    double delta = 0.1 ;
    assert(s.getTime() <= 4.5 + delta && s.getTime() >= 4.5 - delta);
    s.removeBody(earth);
}
void testSimulation1(){

    Simulation s;

    Vector3D a = Vector3D(1.0,1.0,1.0);
    Mobile* m = new Mobile("voiture1",a,a);
    Mobile* n = new Mobile("voiture2",a,a);


    // Notre liste est vide, on test getBodies() qui renverra une liste vide
    list<Mobile*> liste;
    liste = s.getBodies();

    // On teste getBodies() dont la taille devrait etre nulle vu qu'on vient de creer notre simulation
    assert(liste.size() == 0);

    // On teste addBody() et removeBody()
    s.addBody(m);
    s.addBody(n);

    liste = s.getBodies();
    // On verifie qu'après avoir ajouté m et n, la taille de la liste a bien changé
    assert(liste.size() == 2);
    // On parcourt toute la liste pour verifier que non seulement la taille a changé mais aussi qu'on retrouve les bonnes valeurs dans la liste
    for_each(liste.begin(), liste.end(), [m,n](Mobile* x){
      assert(x == m || x ==n);
    });

    // On verifie que lorsqu'on retire m et n de la liste, sa taille passe à 0
    s.removeBody(m);
    s.removeBody(n);
    liste = s.getBodies();
    assert(liste.size() == 0);

    s.step(1);
    assert(s.getTime() == 1);

    delete m;
    delete n;
}

void testMobile1() {

    Vector3D p(0,0,0);
    Vector3D v(1,1,1);
    Mobile m1("mobile",p,v);

    // On teste les accesseurs
    assert( p == m1.getPosition());
    assert( v == m1.getVitesse());
    assert("mobile" == m1.getName());

    // On teste la fonction avance en verifiant si la position change correctement
    m1.avance(2);
    assert( m1.getPosition() == Vector3D(2,2,2));
}

void testVector3D() {

    int i = 0 ;
    Vector3D a(1.0,2.0,3.0);
    Vector3D temp = Vector3D(a);
    Vector3D b(2.0,1.0,0.0);
    Vector3D c(1,1,1);

    // On s'assure que l'operateur == marche correctement afin de pouvoir l'utiliser par la suite

    assert( a == temp);
    for ( i  = 0 ; i < N ; i++)
    {
      assert( a[i] == temp[i] );
    }

    // On teste l'operateur []
    assert(c[0] == 1);
    assert(c[1] == 1);
    assert(c[2] == 1);

    // On teste aussi modify pour pouvoir l'utiliser librement par la suite
    c.modify(0,1,2);
    assert(c[0] == 0);
    assert(c[1] == 1);
    assert(c[2] == 2);


    // On teste l'operateur +
    c.modify(3.0,3.0,3.0);
    assert( c == a+b);

    // On teste l'operateur *
    c.modify(2.0,2.0,0.0);
    assert( c == a*b);

    // On teste l'operateur -
    c.modify(-1.0,1.0,3.0);
    assert( c == a-b);

    // On teste la multiplication par un scalaire
    c.modify(2.0,4.0,6.0);
    assert( c == a*2);

    // On teste l'operateur += Vector3D
    c.modify(4,2,0);
    b += b; // b = (4,2,0) dorenavant
    assert(c == b);

    // On teste l'operateur += scalaire

    c.modify(5,3,1);
    b += 1;
    assert( c == b);

    c.modify(1.0,2.0,3.0);
    assert(distance(c,a) == 0);

    c.modify(6, 0, 0 );
    assert(norm(c) == 6.0);
}
