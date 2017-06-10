#include <fstream>
#define MOD 666013
using namespace std;

ifstream is("a.in");
ofstream os("a.out");

int n, f[1000000];
int Fib(int k);

int main()
{
    is >> n;
    f[0] = f[1] = 1;
    os << Fib(n-1);
    is.close();
    os.close();
    return 0;
}
int Fib(int k)
{
    if ( f[k] ) return f[k];
    return ( f[k] = ( Fib(k-1) + Fib(k-2) ) % MOD );
}
