#include <fstream>
#include <algorithm>
using namespace std;

ifstream is("apm.in");
ofstream os("apm.out");

struct Edge{
    int x, y, c;
} G[200001];

int n, m, N, k, C;
int rad[200001];
Edge aux[200001];

void Read();
void Kruskal();
void Write();
void SetRoot();
int GetRoot(int x);
void Merge(int x, int y);
bool Cmp(const Edge& e1, const Edge& e2 )
{
    return e1.c < e2.c;
}

int main()
{
    Read();
    Kruskal();
    Write();
    is.close();
    os.close();
    return 0;
}
void Read()
{
    is >> n >> m;
    for ( int i = 0; i < m; ++i )
        is >> G[i].x >> G[i].y >> G[i].c;
}
void Kruskal()
{
    int x, y;
    sort(G, G+m, Cmp );
    SetRoot();
    for ( int i = 0; i < m; ++i )
    {
        x = G[i].x;
        y = G[i].y;
        if ( GetRoot(x) != GetRoot(y) )
        {
            k++;
            Merge(x, y);
            aux[N++] = G[i];
            C += G[i].c;
            if ( k == n-1 )
                return;
        }

    }
}
void Write()
{
    os << C << '\n' << N << '\n';
    for ( int i = 0; i < N; ++i )
        os << aux[i].x << ' ' << aux[i].y << '\n';
}
void SetRoot()
{
    for ( int i = 1; i <= n; ++i )
        rad[i] = i;
}
int GetRoot(int x)
{
    if ( rad[x] == x )
        return x;
    int f = GetRoot(rad[x]);
    rad[x] = f;
    return f;
}
void Merge(int x, int y)
{
    rad[GetRoot(x)] = GetRoot(y);
}
