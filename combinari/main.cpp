#include <fstream>
using namespace std;

ifstream is("a.in");
ofstream os("a.out");

int n, p, x[102];

void B(int k);
void Afis();

int main()
{
    is >> n >> p;
    //for ( n = 2; n <= N; ++n )
        B(1);
    is.close();
    os.close();
    return 0;
}
void B(int k)
{
    if ( k == p + 1)
    {
        Afis();
        return;
    }
    for ( int i = x[k-1] + 1; i <= n-p+k; ++i )
    {
        x[k] = i;
        B(k+1);
    }
}
void Afis()
{
    for ( int i = 1; i <= p; ++i )
        os << x[i] << ' ';
    os << '\n';
}
