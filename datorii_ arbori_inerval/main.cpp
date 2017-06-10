#include <fstream>
#define MAX 10000
using namespace std;

ifstream is("datorii.in");
ofstream os("datorii.out");

int n, m, arb[4*MAX], A, B, op;
void Update(int nod, int st, int dr);
int Suma(int nod, int st, int dr);

int main()
{
    is >> n >> m;
    for ( int i = 1; i <= n; ++i )
    {
        is >> B;
        A = i;
        Update(1, 1, n);
    }
    while ( m-- )
    {
        is >> op >> A >> B;
        if ( op )
            os << Suma(1, 1, n) << '\n';
        else
            B *= -1, Update(1, 1, n);
    }
    is.close();
    os.close();
    return 0;
}
void Update(int nod, int st, int dr)
{
    if ( st == dr )
    {
        arb[nod] += B;
        return;
    }
    int mid = (st+dr)/2;
    if ( A <= mid )
        Update(2*nod, st, mid);
    else
        Update(2*nod+1, mid+1, dr);
    arb[nod] = arb[2*nod]+arb[2*nod+1];
}
int Suma(int nod, int st, int dr)
{
    if ( A <= st && dr <= B )
        return arb[nod];
    int s1 = 0, s2 = 0, mid = (st+dr)/2;
    if ( A <= mid )
        s1 = Suma(2*nod, st, mid );
    if ( mid < B )
        s2 = Suma(2*nod+1, mid+1, dr );
    return s1+s2;
}
