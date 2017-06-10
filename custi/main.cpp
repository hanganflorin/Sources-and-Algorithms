#include <cstdio>
#include <fstream>
using namespace std;

ifstream is("custi.in");
FILE * os = fopen("custi.out", "w" );

void Read();
void Dinamica();
int Suma( int Ip, int Jp, int Is, int Js );

int n, cnt[1001];
short a[1001][1001];
int s[1001][1001];
char c[2000000];

int main()
{
    Read();
    Dinamica();
    for ( int i = 1; i < n; ++i )
        for ( int j = 1; j < n; ++j )
            for ( int d = 2; i+d <= n+1 && j+d <= n+1; ++d )
                if ( Suma(i, j, i+d-1, j+d-1) == 0 )
                    cnt[d]++;
    for (int i = 1; i <= n; ++i )
        fprintf(os, "%d\n", cnt[i] );
    is.close();
    fclose(os);
    return 0;
}
void Read()
{
    int k = 0;
    is >> n;
    is.get();
    is.getline(c, 2000000, EOF );
    for ( int i = 1; i <= n; ++i )
        for ( int j = 1; j <= n; ++j )
        {
            if ( c[k] == '0' )
                a[i][j] = 1;
            else
                cnt[1]++;
            k+=2;
        }

}
void Dinamica()
{
    for ( int i = 1; i <= n; ++i )
    {
        s[i][1] = s[i-1][1] + a[i][1];
        s[1][i] = s[1][i-1] + a[1][i];
    }
    for ( int i = 2; i <= n; ++i )
            for ( int j = 2; j <= n; ++j )
                s[i][j] = s[i-1][j] + s[i][j-1] + a[i][j] - s[i-1][j-1];
}
int Suma( int Ip, int Jp, int Is, int Js )
{
    return ( s[Is][Js] - s[Is][Jp-1] - s[Ip-1][Js] + s[Ip-1][Jp-1] );
}
