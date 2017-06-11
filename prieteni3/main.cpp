#include <fstream>
#include <vector>
#include <queue>
#include <bitset>
#include <algorithm>
using namespace std;

ifstream is("prieteni3.in");
ofstream os("prieteni3.out");

int n, A, K, nod, dim;
vector<int> G[101], aux;
queue<int> Q1, Q2;
bitset<101> b;

void Read();
void Write();

int main()
{
    Read();
    for ( int k = 0; k < K-1; ++k )
    {
        while ( !Q1.empty() )
        {
            nod = Q1.front();
            Q1.pop();
            for ( vector<int>::iterator it = G[nod].begin(); it != G[nod].end(); it++ )
                if ( !b[*it] )
                {
                    b[*it] = true;
                    Q2.push(*it);
                }
        }
        swap(Q1, Q2);
    }
    Write();
    is.close();
    os.close();
    return 0;
}
void Read()
{
    int nr, x;
    is >> n >> A >> K;
    b[A] = true;
    for ( int i = 1; i <= n; ++i )
    {
        is >> nr;
        for ( int j = 0; j < nr; ++j )
        {
            is >> x;
            G[i].push_back(x);
            if (i == A)
            {
                Q1.push(x);
                b[x] = true;
            }
        }
    }
}
void Write()
{
    dim = Q1.size();
    os << dim << '\n';
    while ( !Q1.empty())
    {
        aux.push_back(Q1.front());
        Q1.pop();
    }
    sort(aux.begin(), aux.end() );
    for ( int i = 0; i < dim; ++i )
        os << aux[i] << ' ';
}
