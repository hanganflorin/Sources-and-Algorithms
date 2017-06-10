#include <fstream>
using namespace std;

ifstream is("classictask.in");
ofstream os("classictask.out");

unsigned long long a, b, c, sol;
unsigned long long Pow(unsigned long long x, unsigned long long n );

int main()
{
    is >> a >> b >> c;
    os << Pow(a, b);
    is.close();
    os.close();
    return 0;
}
unsigned long long Pow(unsigned long long x, unsigned long long n )
{
    if ( n == 0 ) return 1;
    sol = Pow(x, n >> 1);
    sol = ( 1LL * sol * sol ) % c;
    if ( n % 2 == 1)
        sol = ( 1LL * sol * x ) % c;
    return sol;
}
