#include <cstdio>
#include <cstring>
using namespace std;

FILE * is = fopen("pufu.in", "r" );
FILE * os = fopen("pufu.out", "w" );

int t, n, cnt1, cnt2, cnt3;
char s[15];

int main()
{
    fscanf(is, "%d", &t);
    for ( int k = 0; k < t; ++k )
    {
        cnt1 = 0;
        cnt2 = 0;
        cnt3 = 0;
        fscanf(is, "%d", &n);
        for ( int i = 0; i < n; ++i )
        {
            fscanf(is, "%s", &s);
            if ( s[2] == 'o' )
                cnt1++;
            else if ( s[2] == 's' )
                cnt2++;
            else
                cnt3++;
        }
        fprintf(os, "%d %d %d\n", cnt1, cnt2, cnt3 );
    }
    fclose(is);
    fclose(os);
    return 0;
}
