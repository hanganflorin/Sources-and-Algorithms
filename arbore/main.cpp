#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

FILE * is = fopen("arbore.in", "r" );
FILE * os = fopen("arbore.out", "w" );

int n, m, a[100001], op, p, s;
bool b[100001];
vector<vector<int> > G;

void Df(int x);
int Find(int s);

int main()
{
    fscanf(is, "%d%d", &n, &m );
    G.resize(n+1);
    for ( int i = 1, x, y; i < n; ++i )
    {
        fscanf(is, "%d%d", &x, &y );
        G[x].push_back(y);
    }
    while(m--)
    {
        fscanf(is, "%d", &op );
        if ( op == 1 )
        {
            fscanf(is, "%d%d", &p, &s );
            memset(b, 0, sizeof (b) );
            Df(p);
        }
        else
        {
            fscanf(is, "%d", &s );
            fprintf(os, "%d\n", Find(s) );
        }
    }
    fclose(is);
    fclose(os);
    return 0;
}
void Df(int x)
{
    a[x] += s;
    b[x] = true;
    for ( const auto & c : G[x] )
        if ( !b[c] )
            Df(c);

}
int Find(int s)
{
    for ( int i = 1; i <= n; ++i )
        if ( a[i] == s )
            return i;
    return -1;
}
