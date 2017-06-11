#include <fstream>
#include <vector>
using namespace std;

ifstream is("gears.in");
ofstream os("gears.out");

int n, p;
char c[101];
bool b[101];
vector<int> G[101];
void Read();
void Df(int x, char dir);

int main()
{
    Read();
    Df(p, 'D');
    os << c;
    is.close();
    os.close();
    return 0;
}
void Read()
{
    is >> n >> p;
    for ( int i = 1, x, y; i < n; ++i )
    {
        is >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
}
void Df(int x, char dir)
{
    c[x-1] = dir;
    b[x] = true;
    for (vector<int>::iterator it = G[x].begin(); it != G[x].end(); ++it )
        if ( !b[*it] )
            Df(*it, dir == 'D' ? 'S' : 'D' );
}
