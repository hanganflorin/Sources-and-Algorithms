#include <fstream>
#include <cstdio>
#include <algorithm>
using namespace std;

FILE* is = fopen("jocul.in", "r");
ofstream os("jocul.out");

int n, a[1001], s;
bool x[100001], p = true;

int main()
{
    fscanf(is, "%d", &n);
    for ( int i = 0; i < n; ++i )
    {
        fscanf(is, "%d", &a[i]);
        s += a[i];
    }
    x[0] = true;
   // sort(a, a + n);
    for ( int i = 0; i < n; ++i )
    {
        for ( int j = s/2; j >= 0; --j )
            if ( x[j] == true )
            {
                x[j+a[i]] = true;
               // if ( j+a[i] >= s/2 )
                 //   p = false;

            }
    }
    int nr = s/2;
    while ( x[nr] == false )
        nr--;
    if ( nr < s-nr )
        os << nr << ' ' << s-nr;
    else
        os << s-nr << ' ' << nr;
    fclose(is);
    os.close();
    return 0;
}
