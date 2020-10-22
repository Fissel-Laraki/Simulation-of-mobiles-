#include <cstdlib>
#include <cmath>
#include <cassert>
#include <ostream>
#include <iostream>
#include "Vector3D.h"

using namespace std;



Vector3D::Vector3D() {
    coord[0] = 0.0;
    coord[1] = 0.0;
    coord[2] = 0.0;
}

Vector3D::Vector3D(double a, double b, double c) {
    coord[0] = a;
    coord[1] = b;
    coord[2] = c;
}
/*
Vector3D::Vector3D( const Vector3D& v) : Vector3D(v.coord[0],v.coord[1],v.coord[2]){
}*/


// Fonction qui modifie les valeurs du vecteur
void Vector3D::modify(double a, double b, double c) {
    coord[0] = a;
    coord[1] = b;
    coord[2] = c;
}

double Vector3D::operator[](int n) const {
    assert(n >= 0 && n < N);
    return coord[n];
}


double& Vector3D::operator[](int n) {
    assert(n >= 0 && n < N);
    return coord[n];
}


Vector3D Vector3D::operator+( const Vector3D& v) const{
    return Vector3D(v.coord[0]+coord[0],v.coord[1]+coord[1],v.coord[2]+coord[2]);
}

Vector3D Vector3D::operator-(const Vector3D& v) const {
    return Vector3D(coord[0]-v.coord[0],coord[1]-v.coord[1],coord[2]-v.coord[2]);
}

Vector3D Vector3D::operator*(const Vector3D& v) const {
    return Vector3D(v.coord[0]*coord[0],v.coord[1]*coord[1],v.coord[2]*coord[2]);
}

Vector3D Vector3D::operator*(double l)const {
    return Vector3D(l*coord[0],l*coord[1],l*coord[2]);
}

Vector3D Vector3D::operator+=( const Vector3D& v) {
    for ( int i = 0; i < N ; i++) {
        coord[i] += v.coord[i];
    }
    return *this;
}

Vector3D Vector3D::operator+=(double l) {
    for ( int i = 0; i < N ; i++) {
        coord[i] += l;
    }
    return *this;
}
bool Vector3D::operator==(Vector3D v) const  {
    for ( int i = 0 ; i < N ; i++) {
        if (coord[i] != v.coord[i] )
          return false;
    }
    return true;
}

Vector3D Vector3D::operator=(const Vector3D& v) {

    for (int i = 0 ; i < N ; i++) {
        coord[i] = v.coord[i];
    }

    return *this;
}

ostream& operator<<(ostream& os,Vector3D& v) {
    os << "(";
    int i = 0 ;
    for (i = 0; i < 2 ; i++) {
        os << v.coord[i] << "," ;
    }
    os << v.coord[i] << ")" << endl;
    return os;
}

// Calcule la Norme d'un vecteur sachante que norme(v) = sqrt( x^2 + y^2 + z^2)
double norm(const Vector3D& v) {
    double somme = 0.0;
    for (int i = 0 ; i < N ; i++)
    {
      somme += v[i]*v[i];
    }
    return sqrt(somme);
}

double distance(const Vector3D& v1 ,const Vector3D& v) {
    double somme = 0.0;
    for (int i = 0 ; i < N ; i++)
    {
      somme += pow(v[i]-v1[i],2);
    }
    return sqrt(somme);
}

