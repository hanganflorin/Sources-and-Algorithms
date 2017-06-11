#include <cstdio>
#include <cstring>
using namespace std;

FILE * is = fopen("rucsac.in", "r" );
FILE * os = fopen("rucsac.out", "w" );

int n, d[10002], G, g[5002], v[5002], mx;

int main()
{
    fscanf(is, "%d%d", &n, &G );
    for ( int i = 1; i <= n; ++i )
        fscanf(is, "%d%d", &g[i], &v[i] );

    memset(d, 0xff, sizeof(d));
    d[0] = 0;
    for ( int i = 1; i <= n; ++i )
        for ( int j = G - g[i]; j >=0; --j )
            if ( d[j] != -1 &&  d[j+g[i]] < d[j] + v[i] )
            {
                d[j+g[i]] = d[j] + v[i];
                if ( d[j+g[i]] > mx )
                    mx = d[j+g[i]];
            }
    fprintf(os, "%d", mx);
    fclose(is);
    fclose(os);
    return 0;
}
