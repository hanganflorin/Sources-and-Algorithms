#include <cstdio>
using namespace std;

FILE* is = fopen("datorii.in", "r" );
FILE* os = fopen("datorii.out", "w" );

int n, m, v, k, a, b;
int aib[15020];
void Update(int p, int v);
int Suma(int p);

int main()
{
    fscanf(is, "%d%d", &n, &m );
    for ( int i = 1; i <= n; ++i )
    {
        fscanf(is, "%d", &v );
        Update(i, v);
    }
    for ( int i = 0 ; i < m; ++i )
    {
        fscanf(is, "%d%d%d", &k, &a, &b );
        if ( k )
        {
            v = Suma(b) - Suma(a-1);
            fprintf(os, "%d\n", v );
        }
        else
            Update(a, -1*b);
    }

    return 0;
}
void Update(int p, int v)
{
    for ( int i = p; i <= n; i += i & -i )
        aib[i] += v;
}
int Suma(int p)
{
    int s = 0;
    for ( int i = p; i; i -= i & -i )
        s += aib[i];
    return s;
}
