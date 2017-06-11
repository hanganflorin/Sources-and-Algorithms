#include <fstream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <queue>
using namespace std;

ifstream is("prieteni3.in");
ofstream os("prieteni3.out");

int n, A, k, nod, dist[101];
vector<int> G[101], d;
bitset<101> b;
queue<int> Q;

void Read();

int main()
{
    Read();
    b[A] = true;
    Q.push(A);


    while ( !Q.empty() )
    {
        nod = Q.front();
        Q.pop();
        for ( vector<int>::iterator it = G[nod].begin(); it != G[nod].end(); it++ )
            if ( !b[*it] )
            {
                Q.push(*it);
                b[*it] = true;
                dist[*it] = dist[nod]+1;
                if ( dist[*it] == k )
                    d.push_back(*it);
            }
    }
    os << d.size() << '\n';
    sort(d.begin(), d.end());
    for ( vector<int>::iterator it = d.begin(); it != d.end(); it++ )
        os << *it << ' ';
    is.close();
    os.close();
    return 0;
}
void Read()
{
    in.t nr, x;
    is >> n >> A >> k;
    for ( int i = 1; i <= n; ++i )
    {
        is >> nr;
        for ( int j = 0; j < nr; ++j )
        {
            is >> x;
            G[i].push_back(x);
        }
    }
}
