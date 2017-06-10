#include <cstdio>
#include <algorithm>
using namespace std;

FILE * is = fopen("bitonic.in", "r" );
FILE * os = fopen("bitonic.out", "w" );

int t, n, a[1002], m;
int C1[1002]; // crescator, se termina pe i
int C2[1002]; // crescator, incepe pe i
int D1[1002]; // descrescator, incepe i
int D2[1002]; // descrescator, se termina pe i

void Dinamica();
void Debug()
{
    for ( int i = 1; i <= n; ++i )
        fprintf(os, "%d ", C1[i] );
    fprintf(os, "\n" );

    for ( int i = 1; i <= n; ++i )
        fprintf(os, "%d ", C2[i] );
    fprintf(os, "\n" );

    for ( int i = 1; i <= n; ++i )
        fprintf(os, "%d ", D1[i] );
    fprintf(os, "\n" );

    for ( int i = 1; i <= n; ++i )
        fprintf(os, "%d ", D2[i] );
    fprintf(os, "\n" );

}

int main()
{
    fscanf(is, "%d", &t );
    for ( int k = 0; k < t; ++k )
    {
        m = 0;
        fscanf(is, "%d", &n );
        for ( int i = 1; i <= n; ++i )
            fscanf(is, "%d", &a[i] );
        Dinamica();
        for ( int i = 1; i <= n; ++i )
            m = max( max(m, C1[i]+D1[i]-1), max(m, C2[i]+D2[i]-1) );
        fprintf(os, "%d\n", m);
    }

    fclose(is);
    fclose(os);
    return 0;
}
void Dinamica()
{
    // crescator, se termina pe i
    for ( int i = 1; i <= n; ++i )
    {
        C1[i] = 0;
        for ( int j = 0; j < i; ++j )
            if ( a[j] < a[i] && C1[i] < C1[j] + 1 )
                C1[i] = C1[j] + 1;
    }

    // crescator, incepe pe i
    for ( int i = n; i > 0; --i )
    {
        C2[i] = 1;
        for ( int j = i+1; j <= n; ++j )
            if ( a[j] > a[i] && C2[i] < C2[j]+1 )
                C2[i] = C2[j]+1;
    }
    // descrescator, incepe pe i
    for ( int i = n; i > 0; --i )
    {
        D1[i] = 1;
        for ( int j = n; j > i; --j )
            if ( a[j] < a[i] && D1[i] < D1[j]+1 )
                D1[i] = D1[j]+1;
    }
    // descrescator, se termina pe i
    for ( int i = 1; i <= n; ++i )
    {
        D2[i] = 1;
        for ( int j = 0; j < i; ++j )
            if ( a[j] > a[i] && D2[i] < D2[j]+1 )
                D2[i] = D2[j]+1;
    }
}

