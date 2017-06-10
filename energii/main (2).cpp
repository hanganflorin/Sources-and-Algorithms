//#include <cstdio>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <vector>
#define INF 0x3f3f3f3f
using namespace std;

//FILE * is = fopen("energii.in", "r");
//FILE * os = fopen("energii.in", "w");
ifstream is("energii.in");
ofstream os("energii.out");

int n, w, e, c, s;
int mn = INF;
vector<int> d; // d[i] =  costul minim pt cantitatea i de energie

int main()
{
    //fscanf(is, "%d%d", &n, &w );
    is >> n >> w;
    memset(d, 63, sizeof(d));
    d[0] = 0;
    for ( int i = 1; i <= n; ++i )
    {
        //fscanf(is, "%d%d", &e, &c );
        is >> e >> c;
        s += e;
        d.resize(s);
        for ( int j = s - e; j >= 0; --j )
            if ( d[j+e] > d[j] + c )
            {
                d[j+e] = d[j] + c;
            }
    }
    if ( s < w )
        os << -1;
    else
    {
        for ( int i = w; i < s; ++i )
            mn = min(mn, d[i] );
        //fprintf(os, "%d", mn );
        //fclose(is);
        //fclose(os);
        os << mn;
    }
    is.close();
    os.close();
    return 0;
}
