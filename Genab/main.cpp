#include <fstream>
using namespace std;

ifstream is("genab.in");
ofstream os("genab.out");

int n;
char s[22];

void Perm(int k);
void Afis();

int main()
{
    is >> n;
    Perm(1);
    is.close();
    os.close();
    return 0;
}
void Perm(int k)
{
    if ( k == n+1 )
    {
        Afis();
        return;
    }
    for (char i = 'a'; i <= 'b'; ++i )
    {
        s[k] = i;
        if ( i == 'b' && s[k-1] == 'b' )
            continue;
        Perm(k+1);
    }
}
void Afis()
{
    for ( int i = 1; i <= n; ++i )
        os << s[i];
    os << '\n';
}
