#ifndef _VECTOR_3D_H
#define _VECTOR_3D_H

#include <iostream>

#define N 3

class Vector3D {


  private:
    double coord[N];

  public:
    Vector3D();
    Vector3D(double,double,double);
    Vector3D(const Vector3D&);
    void modify(double,double,double);
    double& operator[](int n);
    Vector3D operator+(const Vector3D&);
    Vector3D operator-(const Vector3D&) const;
    Vector3D operator*(Vector3D&);
    Vector3D operator*(double);
    Vector3D operator+=(Vector3D&);
    Vector3D operator+=(double);
    Vector3D operator=(const Vector3D&) ;
    bool operator==(Vector3D);
    double norm();
    double distance( const Vector3D&);
    friend std::ostream& operator<<(std::ostream& os,Vector3D&);

};
std::ostream& operator<<(std::ostream& os,Vector3D&);
#endif
