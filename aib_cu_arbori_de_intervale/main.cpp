#include <fstream>
#define MAX 100000
using namespace std;

ifstream is("aib.in");
ofstream os("aib.out");

int n, m, arb[4*MAX], A, B, op;

void Update(int nod, int st, int dr );
int Suma(int nod, int st, int dr );
int Bs(int x);

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
        is >> op;
        if ( op == 0 )
        {
            is >> A >> B;
            Update(1, 1, n);
        }
        else if ( op == 1 )
        {
            is >> A >> B;
            os << Suma(1, 1, n) << '\n';
        }
        else
        {
            is >> A;
            os << Bs(A) << '\n';
        }
    }
    is.close();
    os.close();
    return 0;
}
void Update(int nod, int st, int dr )
{
    if ( st == dr )
    {
        arb[nod] = B;
        return;
    }
    int mid = (st+dr)/2;
    if ( A <= mid )
        Update(2*nod, st, mid);
    else
        Update(2*nod+1, mid+1, dr);
    arb[nod] = arb[2*nod] + arb[2*nod+1];

}
int Suma(int nod, int st, int dr )
{
    if ( B <= A )
        return 0;
    if ( A <= st && dr <= B )
        return arb[nod];
    int s1 = 0, s2 = 0, mid = (st+dr)/2;
    if ( A <= mid )
        s1 = Suma(2*nod, st, mid);
    if ( B > mid )
        s2 = Suma(2*nod+1, mid+1, dr);
    return s1+s2;
}
int Bs(int x)
{
    A = 1;
    B = 0;
    for ( int p = 1 << 17; p; p >>= 1 )
        if ( B + p <= n )
        {
            if ( Suma(1, 1, n) <= x )
                B += p;
        }
    if ( Suma(1, 1, n) == x && B != 0 )
        return B;
    return -1;
}
