#include <fstream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

ifstream is("labir.in");
ofstream os("labir.out");

const int d1[] = {-1, 0, 1, 0};
const int d2[] = {0, 1, 0, -1};
unsigned short n, m, Ip, Jp, Is, Js, aux1, aux2, x, y, c[5001][5001];
int K;
bool b[5001][5001];

void Lee();
void Normalizare();
void Read();
bool Ok(int i, int j);

queue<pair<int, int > > Q;
vector<int> A;
vector<int> B;
vector<int> X;
vector<int> Y;


int main()
{
    Read();
    Normalizare();
    Q.push(make_pair(Ip, Jp));
    Lee();
    os << c[Is][Js];
    is.close();
    os.close();
    return 0;
}
void Lee()
{
    memset(c, 63, sizeof(c) );
    c[Ip][Jp] = 0;
    int i, j, iv, jv, aux;
    while ( !Q.empty() )
    {
        i = Q.front().first;
        j = Q.front().second;
        Q.pop();
        for ( int d = 0; d < 4; ++d )
        {
            iv = i + d1[d];
            jv = j + d2[d];
            if ( Ok(iv, jv) )
            {
                aux = b[iv][jv];
                if ( c[iv][jv] > c[i][j] + aux )
                {
                    c[iv][jv] = c[i][j] + aux;
                    Q.push(make_pair(iv, jv));
                }
            }
        }
    }
}
bool Ok(int i, int j)
{
    if ( i < 1 || j < 1 || i > n || j > m )
        return false;
    return true;
}
void Read()
{
    is >> n >> m >> Ip >> Jp >> Is >> Js >> K;
    for ( int k = 0; k < K; ++k )
    {
        is >> x >> y;
        A.push_back(x);
        B.push_back(y);
        X.push_back(x);
        Y.push_back(y);
    }
    n = 0;
    m = 0;
}
void Normalizare()
{
    A.push_back(Ip);
    A.push_back(Is);
    B.push_back(Jp);
    B.push_back(Js);
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    B.erase(unique(B.begin(), B.end()), B.end());
    for ( int i = 1; i < A.size(); ++i )
        if ( A[i] > A[i-1]+1)
        {
            A.insert(A.begin()+i, A[i-1]);
            i++;
        }
    for ( int i = 1; i < B.size(); ++i )
        if ( B[i] > B[i-1]+1)
        {
            B.insert(B.begin()+i, B[i-1]);
            i++;
        }
    for ( int k = 0; k < K; ++k )
    {
        aux1 = 1 + lower_bound(A.begin(), A.end(), X[k] ) - A.begin();
        aux2 = 1 + lower_bound(B.begin(), B.end(), Y[k] ) - B.begin();
        n = max(n, aux1 );
        m = max(m, aux2 );
        b[aux1][aux2] = 1;
    }
    Ip = 1 + lower_bound(A.begin(), A.end(), Ip ) - A.begin();
    Jp = 1 + lower_bound(B.begin(), B.end(), Jp ) - B.begin();
    Is = 1 + lower_bound(A.begin(), A.end(), Is ) - A.begin();
    Js = 1 + lower_bound(B.begin(), B.end(), Js ) - B.begin();
    n = max(n, Ip );
    n = max(n, Is );
    m = max(m, Jp );
    m = max(m, Js );
}
