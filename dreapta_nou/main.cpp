#include <fstream>
#include <cmath>
#include <vector>
#define eps 0.001
#define MAX 100002
#define PR pair<double,double>
using namespace std;

ifstream is("dreapta.in");
ofstream os("dreapta.out");

PR P[MAX];
PR Q[MAX];
vector<PR> V;

int n, q, aa, bb, cc, a, b, c;
int aux;

void Read();
void Coeficienti(PR A, PR B);
void Intersectie(PR A, PR B);
bool Se_Intersecteaza(PR A, PR B);

int main()
{
    Read();
    for ( int i = 0; i < n; ++i )
        Intersectie(P[i], P[i+1]);
    for ( const auto& c : V)
        os << c.first << ' ' << c.second << '\n';
    is.close();
    os.close();
    return 0;
}
void Read()
{
    is >> n;
    for ( int i = 0; i < n; ++i )
        is >> P[i].first >> P[i].second;
    is >> q;
    for ( int i = 0; i < q; ++i )
        is >> Q[i].first >> Q[i].second;

    P[n] = P[0];

    aa = Q[0].second - Q[1].second;
    bb = Q[1].first - Q[0].first;
    cc = Q[0].first*Q[1].second - Q[1].first*Q[0].second;
}
void Coeficienti(PR A, PR B)
{
    a = A.second - B.second;
    b = B.first - A.first;
    c = A.first*B.second - B.first*A.second;
}
void Intersectie(PR A, PR B)
{
    double x, y;
    if ( Se_Intersecteaza(A, B) )
    {
        Coeficienti(A, B);
        x = (cc*b - c*bb) / (a*bb-aa*b);
        y = (-c - a*x) / b;
        V.push_back({x, y});
        aux++;
    }

}
bool Se_Intersecteaza(PR A, PR B)
{
    if ( ( aa*A.first + bb*A.second + cc ) *
         ( aa*B.first + bb*B.second + cc ) < 0 )
        return true;
    return false;
}
