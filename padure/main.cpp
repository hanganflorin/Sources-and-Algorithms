#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

FILE * is = fopen("padure.in", "r");
FILE * os = fopen("padure.out", "w");

void Read();
void Lee();
void Debug();
bool Ok(int i, int j );

int n, m, Ip, Jp, Is, Js;
int a[1001][1001], c[1001][1001];
queue<pair<int, int> > Q;
queue<pair<int, int> > Q1;
const int d1[] = { -1, 0, 1, 0 };
const int d2[] = { 0, 1, 0, -1 };

int main()
{
    Read();
    Lee();
    //Debug();
    fprintf(os, "%d", c[Is][Js] );
    fclose(is);
    fclose(os);
    return 0;
}
void Read()
{
    fscanf(is, "%d%d%d%d%d%d", &n, &m, &Ip, &Jp, &Is, &Js);
    Q.push(make_pair(Ip, Jp));
    memset(c, 63, sizeof(c) );
    c[Ip][Jp] = 0;
    for ( int i = 1; i <= n; ++i )
        for ( int j = 1; j <= m; ++j )
            fscanf(is, "%d", &a[i][j] );
}
void Lee()
{
    int i, j, iv, jv;
    while ( !Q.empty() )
    {
        Q1.push( Q.front() );
        Q.pop();
        while ( !Q1.empty() )
        {
            i = Q1.front().first;
            j = Q1.front().second;
            Q1.pop();
            for ( int d = 0; d < 4; ++d )
            {
                iv = i+d1[d];
                jv = j+d2[d];
                if ( Ok(iv, jv ) && c[iv][jv] > c[i][j] )
                {
                    if ( a[iv][jv] == a[i][j] )
                    {
                        Q1.push(make_pair(iv, jv) );
                        c[iv][jv] = c[i][j];
                    }
                    else
                    {
                        Q.push(make_pair(iv, jv) );
                        c[iv][jv] = c[i][j]+1;
                    }
                }
            }
        }
    }
}
bool Ok(int i, int j )
{
    if ( i < 1 || j < 1 || i > n || j > m )
        return false;
    return true;
}
void Debug()
{
    for ( int i = 1; i <= n; ++i )
    {
        for (int j = 1; j <= m; ++j)
        {
            fprintf(os, "%d ", c[i][j] );
        }
        fprintf(os, "\n");
    }
}
