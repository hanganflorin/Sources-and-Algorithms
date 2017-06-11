#include <fstream>
#include <cmath>
#define eps 0.00001
using namespace std;

ifstream is("a.in");
ofstream os("a.out");

struct Punct{
    double x, y;
};

int aa, bb, cc;
void Coeficienti(Punct A, Punct B); // coeficientii aa, bb, cc
int Panta(Punct A, Punct B); // panta dreptei AB
int Compar(double a, double b ); // -1 daca a < b // 0 daca a == b // 1 daca a > b

bool Vertical(Punct A, Punct B);
bool Orizontal(Punct A, Punct B);

bool Paralele(Punct A, Punct B, Punct C, punct D) // daca drepele AB si CD sunt paralele
bool Perpendiculare(Punct A, Punct B, Punct C, punct D) // daca drepele AB si CD sunt perpendiculare

double Dist(Punct A, Punct B, Punct C ) // dist de la punctul A la dreapta AB

bool Coliniare ( Punct A, Punct B, Punct C ); // daca Punctele A, B, C sunt pe aceasi dreapta

int ArieTriunghi(Punct A, Punct B, Punct C);
int AriePoligon(n, Punct*p);

bool PeCerc(Punct O, double r, Punct A ); // daca A se afla pe cercul de raza r si centru O

double a, b;

int main()
{
    is >> a >> b;
    os << Compar(a, b);
    is.close();
    os.close();
    return 0;
}
void Coeficienti(Punct A, Punct B)
{
    aa = A.y - B.y;
    bb = B.x - A.x;
    cc = A.x*B.y - B.x*A.y;
}
int Panta(Punct A, Punct B)
{
    return ( B.y - A.y ) / (B.x - A.x);
}
int Compar(double a, double b )
{
    if ( fabs(a-b) < eps )
        return 0;
    if ( a < b )
        return -1;
    return 1;
}
bool Vertical(Punct A, Punct B)
{
    if ( Compar(A.x, B.x) == 0 )
        return true;
    return false;
}
bool Orizontal(Punct A, Punct B)
{
    if ( Compar(A.y, B.y) == 0 )
        return true;
    return false;
}

bool Paralele(Punct A, Punct B, Punct C, punct D)
{
    if ( Vertical(A, B) || Vertical(C, D) )
    {
        if ( Vertical(A, B) && Vertical(C, D) ) return true;
        return false;
    }
    if ( Compar( Panta(A, B), Panta(C, D) ) == 0 ) return true;
        return false;

}
bool Perpendiculare(Punct A, Punct B, Punct C, punct D)
{
    if ( Orizontal(A, B) )
    {
        if ( Vertical(C, D) ) return true;
            return false;
    }
    if ( Vertical(A, B) )
    {
        if ( Orizontal(C, D) ) return true;
            return false;
    }
    double aux = Panta(A, B) * Panta(C, D);
    if ( Compar(aux, -1) == 0 ) return true;
        return false;
}

double Dist(Punct A, Punct B, Punct C )
{
    Coeficienti(B, C);
    return fabs( aa*A.x + bb*A.y + cc  ) / sqrt(aa*aa + bb*bb ) );
}

bool Coliniare ( Punct A, Punct B, Punct C )
{
    Coeficienti(A, B);
    double aux = aa*C.x + bb*C.y + cc;
    if ( Compar(aux, 0) == 0 ) return true;
    return false;
}

int ArieTriunghi(Punct A, Punct B, Punct C);
int AriePoligon(n, Punct*p);

bool PeCerc(Punct O, double r, Punct A );
