#include <fstream>
#define MAX 100001
using namespace std;

ifstream is("rmq.in");
ofstream os("rmq.out");

int n, m, x, y, a[MAX];
int r[MAX][MAX];

void Rmq();
int Find(int x, int y);

int main()
{
    is >> n >> m;
    for ( int i = 1; i <= n; ++i )
        is >> a[i];
    Rmq();
    while ( m-- )
    {
        is >> x >> y;
        os << Find(x, y) << '\n';
    }
    is.close();
    os.close();
    return 0;
}
void Rmq()
{
    for ( int i = 1; i <= n; ++i )
        r[i][0] = i;
    for ( int j = 1; j <= n; ++j )
        for ( int i = 1; i <= n; ++i )
        {
            if ( a[r[i][j-1]] < a[r[i+ ( 1<<(j-1) )][j-1]] )
                r[i][j] = r[i][j-1];
            else
                r[i][j] = r[i+ ( 1<<(j-1) )][j-1];
        }
}
