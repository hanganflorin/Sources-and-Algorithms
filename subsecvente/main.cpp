#include <fstream>
#include <cstring>
using namespace std;

ifstream is("subsecvente.in");
ofstream os("subsecvente.out");

struct Trie{
    int NrFii, l;
    Trie* Fiu[10];
    Trie()
    {
        NrFii = l = 0;
        for ( int i = 0; i < 10; ++i )
            Fiu[i] = 0;
    }
};

Trie * T = new Trie;
int n, m, nr;
char a[10], b[10];

void Add(Trie* t, char* s, int l);
void Rez(Trie* t);

int main()
{
    is >> a >> b;
    n = strlen(a);
    m = strlen(b);
    for ( int i = 0; i < n; ++i )
        if ( s[i] != '0' )
            Add(T, s+i, 0);
    Rez(T);
    os << nr;
    is.close();
    os.close();
    return 0;
}
void Add(Trie* t, char* s, int l)
{
    if ( s[0] == 0 || l > m )
        return;
    t->l = l;
    if ( t->Fiu[s[0]-48] == 0 )
    {
        t->NrFii++;
        t->Fiu[s[0]-48] = new Trie;
    }
    Add(t->Fiu[s[0]-48], s+1);
}
void Rez(Trie* t)
{
    if ( t->NrFii == 0 )
        return;
    for ( int i = 0; i < 10; ++i )
        if ( t->Fiu[i] != 0 )
        {
            if ( (t->l + 1 < m) || (t->l + 1 >= m && i <= b[t->l]) )
            {
                nr++;
                Rez(t->Fiu[i]);
            }
        }
}
