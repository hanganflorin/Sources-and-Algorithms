#include <fstream>
using namespace std;

ofstream os("a.out");

bool Prim(int x);

int main()
{
    for ( int i = 0; i <= 100; ++i )
        if ( Prim(i) )
            os << "1, ";
        else
            os << "0, ";
    os.close();
    return 0;
}
bool Prim(int x)
{
    if ( x == 1 || x == 0 )
        return false;
    if ( x == 2 )
        return true;
    if ( x % 2 == 0 )
        return false;
    for ( int d = 3; d * d <= x; d += 2 )
        if ( x % d == 0 )
            return false;
    return true;
}
