#include <fstream>
#include<math.h>
using namespace std;

ifstream is("chiftea.in");
ofstream os("chiftea.out");

int n, rad, sol, t;

int main()
{
    is >> t;
    for ( int i = 0; i < t; ++i )
    {
        is >> n;
        rad = sqrt(n);
        sol = 4 * rad;
        n -= rad * rad;
        if ( n > 0 )
        {
            if ( n && n <= rad )
                sol+=2;
            else if ( n > rad )
                sol += 4;
        }

        os << sol << '\n';
    }
    is.close();
    os.close();
    return 0;
}
