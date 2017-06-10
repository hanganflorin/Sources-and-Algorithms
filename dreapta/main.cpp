#include <fstream>
#include <cmath>
#define eps 0.0001
using namespace std;

ifstream is("dreapta.in");
ofstream os("dreapta.out");

struct Punct{
    double x, y;
    Punct(double _x, double _y ) : x(_x), y(_y)
    {
    }
};

int n, q, aa, bb, cc;
Punct P[100002];
Punct P2[100002];

void Read();
void Coeficienti(Punct A, Punct B);

int main()
{
    Read();
    Coeficienti(Punct())
    is.close();
    os.close();
    return 0;
}
void Read()
{
    is >> n;
    for ( int i = 0; i < n; ++i )
        is >> P[i].x >> P[i].y;
    is >> q;
    for ( int i = 0; i < Q; ++i )
        is >> P2[i].x >> P2[i].y;

}
void Coeficienti(Punct A, Punct B)
{
    aa = A.y - B.y;
    bb = B.x - A.x;
    cc = A.x*B.y - B.x*A.y;
}
