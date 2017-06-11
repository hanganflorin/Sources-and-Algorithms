#include <fstream>
#include <cstring>
using namespace std;

ifstream is("reziston.in");
ofstream os("reziston.out");

string s;
struct {
    int a, b;
} p[300];
int n, nr_p, aux, nr_r;
int r[400];
void Calc(int &i );

int main()
{
    is >> s;
    n = s.size();
    for ( int i = 0; i < n; ++i )
    {
        if ( s[i] == '(' )
        {
            p[nr_p++].a = nr_r;
            aux = nr_p;
        }
        else if ( s[i] == ')' )
        {
            aux--;
            p[aux].b = nr_r-1;
        }
        else if ( s[i] == 'R' )
        {
            Calc(i);
            i--;
        }
    }
    for ( int i = 0; i < nr_p; ++i )
        os << p[i].a << ' ' << p[i].b << '\n';
    is.close();
    os.close();
    return 0;
}
void Calc(int &i )
{
    i++;
    while ( s[i] >= 48 && s[i] <= 57 )
    {
        r[nr_r] = r[nr_r] * 10 + s[i] - 48;
        i++;
    }
    nr_r++;
}
void B(int k)
{
    if ( sp == n )
    {
        Afis(k-1);
        return;
    }
    if ( sp > n ) return;

    if ( x[k-1] == 3 )
    {
        x[k] = 3;
        sp += 3;
        B(k+1);
        sp-=3;
    }


    x[k] = 5;
    sp += 5;
    B(k+1);
    sp -=5;
}
