#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream is("viena.in");
ofstream os("viena.out");

int n, nr, p1, p2, x;
vector<int> V;

int main()
{
    is >> n;
    for ( int i = 0; i < n; ++i )
    {
        is >> x;
        V.push_back(x);
    }
    sort(V.begin(), V.end(), greater<int>() );
    for ( int i = 0; i < V.size(); ++i )
    {
        if ( V[i]%2 )
        {
            if ( p1 <= p2 )
                p1 += V[i];
            else
                p2 += V[i];
        }
        else
        {
            if ( p1 == p2 )
            {
                p1 += V[i]/2;
                p2 += V[i]/2;
            }
            else if ( p1 < p2 )
            {
                if ( max(p1+V[i], p2) < p2+V[i]/2 )
                    p1 += V[i];
                else
                {
                    p2 += V[i]/2;
                    p1 = p2;
                }
            }
            else
            {
                if ( max(p2+V[i], p1) < p1+V[i]/2 )
                    p2 += V[i];
                else
                {
                    p1 += V[i]/2;
                    p2 = p1;
                }
            }
        }
    }
    os << max(p1, p2);
    is.close();
    os.close();
    return 0;
}
