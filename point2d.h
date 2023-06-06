#ifndef __POINT2D_H__
#define __POINT2D_H__

#include <iostream>
#include <cmath>
#include <cassert>
#include <vector>
#include <string>


typedef double dble;


class Affichage{
    public:
        virtual dble getX()const = 0;
        virtual dble getY()const = 0;
        virtual std::string getName()const = 0;
        virtual void setName(std::string &name) = 0;
        
};

class Point2D: public Affichage{
    public:
        std::string nom;
        dble x,y;
        
        Point2D(/**/):nom("O"),x(0),y(0){};
        Point2D(const std::string& nnom, const dble&xx, const dble& yy):nom(nnom),x(xx),y(yy){}
        Point2D(const Point2D& p) = default;//copy constructor
        Point2D& operator=(const Point2D& p) = default;//copy by assignment
        Point2D(const Point2D& A, const Point2D& B):nom(A.nom+B.nom),x(B.x-A.x),y(B.y-A.y){};
        
        bool operator==(const Point2D& p);
        
        Point2D& operator+=(const Point2D& p);
        Point2D& operator-=(const Point2D& p);
        Point2D  operator+(const Point2D& p);
        Point2D  operator-(const Point2D& p);
        Point2D  operator*(const Point2D& p);
        Point2D  operator*(const dble& val);
        Point2D  operator/(const Point2D& p);
        Point2D  operator/(const int& c);
        
        void setPoint2D(const Point2D& p);
        Point2D getPoint2D();
        
        dble normeL2();
        

        virtual dble getX()const {return x;}
        virtual dble getY()const {return y;}
        virtual std::string getName() const {return nom;}
        virtual void setName(std::string &name){nom = name;}
        
        friend std::ostream& operator<<(std::ostream& f, const Point2D& p){
            f << p.nom << "(" << p.x << "," << p.y << ")";
            return f;
        }
        
        
//         Point2D CG(std::vector<Point2D> vpts2d);
        

        
};


Point2D& Point2D::operator-=(const Point2D&p)
{
    x -= p.x;
    y -= p.y;
    return (*this);
}


Point2D& Point2D::operator+=(const Point2D&p)
{
    nom = p.nom;
    x += p.x;
    y += p.y;
    return (*this);
}

Point2D Point2D::operator*(const dble& val)
{
    Point2D tmp;
    tmp.nom = nom;
    tmp.x = x*val;
    tmp.y = y*val;
    return tmp;    
}



Point2D Point2D::operator/(const int& c)
{
    assert(c != 0);
    Point2D tmp;
    tmp.nom = nom;
    tmp.x = x/c;
    tmp.y = y/c;
    return tmp;
}

  

Point2D Point2D::operator+(const Point2D& p)
{
    Point2D Q;
    Q.nom = p.nom;
    Q.x = x + p.x;
    Q.y = y + p.y;
    return Q;
}

Point2D Point2D::operator-(const Point2D& p)
{
    Point2D Q;
    Q.nom = p.nom;
    Q.x = x - p.x;
    Q.y = y - p.y;
    return Q;
}

// /* Centre de gravite CG: G */
// Point2D Point2D::CG(std::vector<Point2D> vpts2d)
// {
//     int n = vpts2d.size();
//     Point2D G;
//     for(auto p:vpts2d)
//     {
//         x += p.x;
//         y += p.y;
//     }
//     G.x = x;
//     G.y = y;
//     G.nom = "G";
//     G = G/n;
//     return G;
// }






bool Point2D::operator==(const Point2D& p)
{
    bool test = false;
    if(x == p.x)
        if(y == p.y)
            if(nom == p.nom)
                test = true;
    return test;
}


Point2D Point2D::getPoint2D()
{
    return Point2D(nom,x,y);
}

void Point2D::setPoint2D(const Point2D& p)
{
    nom = p.nom;
    x = p.x;
    y = p.y;
}


dble Point2D::normeL2()
{
    dble d;
    d = pow(x,2) + pow(y,2);
    return pow(d,0.5);
}

#endif /*__POINT2D_H__*/

