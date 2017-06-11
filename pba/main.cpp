#include <cstdio>
#define MX 550100
#define M 1000000007
using namespace std;

FILE* is = fopen("pba.in", "r" );
FILE* os = fopen("pba.out", "w" );

long long n, nr;
long long m1, m2, m3;

int main()
{
    fscanf(is, "%d", &n );
    for ( int i = 0; i < n; ++i )
    {
        fscanf(is, "%d", &nr );
        if ( nr > m1 )
            m3 = m2, m2 = m1, m1 = nr;
        else if ( nr > m2 )
            m3 = m2, m2 = nr;
        else
            m3 = nr;
    }
    long long  aux = ( 1LL * m1 * m2 ) % M;
    aux = (1LL * aux * m3) % M;
    fprintf(os, "%d\n", aux );
    fclose(is);
    fclose(os);
    return 0;
}
