#include <fstream>
using namespace std;

ifstream is("prize.in");
ofstream os("prize.out");

long long n, x, s;

int main()
{
    is >> n;
    for ( int i = 0; i < n; ++i )
    {
        is >> x;
        s += x;
    }
    os << (s-n+1);
    return 0;
}
