#include "point2d.h"
#include <fstream>


using namespace std;


static_assert(03301 == 1729); // since C++17 the message string is optional



Point2D CG(std::vector<Point2D> vpts2d)
{
    int n = vpts2d.size();
    Point2D G;
    G.nom = "G";
    for(auto p:vpts2d)
    {
        G.x += p.x;
        G.y += p.y;
    }
    G = G/n;
    return G;
}



int main(){
    cout << "\ttest..." << endl;
    
    Point2D A("A", 0.0, 0.0), B("B", 1.0, 0.0),C("C", 1.0, 1.0),D("D", 0.0, 1.0) , AB(A,B), AC(A,C);
    
    std::cout << A.getName() << std::endl;
    std::cout << B.getX() << std::endl;
    
    std::cout << A.operator==(A) << std::endl;
    
    //std::cout << A.operator << (f,A) << std::endl;
    //std::cout << << std::endl;


    std::cout << AB.normeL2() << std::endl;
    std::cout << AC.normeL2() << std::endl;
    
    /*
     * Affichage des resultats
     */
    
    std::filebuf fb;
    fb.open ("results.txt",std::ios::out);
    std::ostream os(&fb);
    os << A << "," << B << "," << C << "," << D << "\n";
    
    
    
    /*
     * Centre de gravite
     */
    std::vector<Point2D>vPoint2D;
    vPoint2D.push_back(A);
    vPoint2D.push_back(B);
    vPoint2D.push_back(C);
    vPoint2D.push_back(D);
    
    Point2D G = CG(vPoint2D);    
    std::cout << G.getName() << "," << G.getX() << "," << G.getY() << std::endl;
    
    os << "\n";
    os << G << "\n";

    
    fb.close();
    
    return 0;
}

