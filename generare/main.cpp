#include <fstream>
using namespace std;

ifstream is ("a.in");
ofstream os("a.out");

int x[100], n, nr;
int m[100];
int s;
void Generare(int k);
void Afisare(int k);

int main()
{
    is >> n;
    Generare(1);
   // os << nr;
    is.close();
    os.close();
    return 0;
}
void Generare(int k)
{
    for ( int i = 1; i <= n-k+1; ++i )
    {
        x[k] = i;
        if ( s + i <= n && i >= m[k-1] )
        {
            if ( s + i == n )
            {
                Afisare(k);
                return;
            }
            s += i;
            m[k] = max(m[k-1], i);
            Generare(k+1);
            s -= i;
        }
    }
}
void Afisare(int k)
{
    for ( int i = 1; i <= k; ++i )
        os << x[i] << ' ';
    os << '\n';
}
