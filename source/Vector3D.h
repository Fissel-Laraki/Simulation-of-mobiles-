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
    //Vector3D(const Vector3D&);
    void modify(double,double,double);
    double& operator[](int n) ;
    double operator[](int n) const;
    Vector3D operator+(const Vector3D&) const ;
    Vector3D operator-(const Vector3D&) const;
    Vector3D operator*(const Vector3D&) const;
    Vector3D operator*(const double) const;
    Vector3D operator+=( const Vector3D&);
    Vector3D operator+=(const double);
    Vector3D operator=(const Vector3D&) ;
    bool operator==(const Vector3D)const ;
    friend std::ostream& operator<<(std::ostream& os,Vector3D&);

};
std::ostream& operator<<(std::ostream& os,Vector3D&);
double norm(const Vector3D& );
double distance(const Vector3D&, const Vector3D&);
#endif
