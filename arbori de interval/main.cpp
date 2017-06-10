#include <fstream>
#define MAX 100000
using namespace std;

ifstream is("arbint.in");
ofstream os("arbint.out");

int arb[4*MAX];
int n, m, op, poz, A, B;

void Update(int nod, int st, int dr );
//void Query(int nod, int st, int dr );
int Query(int nod, int st, int dr );

int main()
{
    is >> n >> m;
    for ( int i = 1; i <= n; ++i )
    {
        is >> B;
        A = i;
        Update(1, 1, n);
    }
    while(m--)
    {
        is >> op >> A >> B;
        if ( op )
            Update(1, 1, n);
        else
            os << Query(1, 1, n) << '\n';
    }
    is.close();
    os.close();
    return 0;
}
void Update(int nod, int st, int dr )
{
    // A - pozitie
    // B - valoare
    if (st == dr )
    {
        arb[nod] = B;
        return;
    }
    int mid = (st+dr)/2;
    if ( A <= mid )
        Update(2*nod, st, mid);
    else
        Update(2*nod+1, mid+1, dr );
    arb[nod] = max( arb[2*nod], arb[2*nod+1] );
}
int Query(int nod, int st, int dr )
{
    // A - pozitie
    // B - pozitie
    if ( A <= st && dr <= B )
        return arb[nod];
    int m1 = 0, m2 = 0;
    int mid = (st+dr)/2;
    if ( mid >= A )
        m1 = Query(2*nod, st, mid);
    if ( mid < B )
        m2 = Query(2*nod+1, mid+1, dr);
    return max(m1, m2);
}
/*
void Query(int nod, int st, int dr )
{
    // A - pozitie
    // B - pozitie
    if ( A <= st && dr <= B )
    {
        mx = max(mx, arb[nod] );
        return;
    }
    int mid = (st+dr)/2;
    if ( mid >= A )
        Query(2*nod, st, mid);
    if ( mid < B )
        Query(2*nod+1, mid+1, dr);
}
*/
