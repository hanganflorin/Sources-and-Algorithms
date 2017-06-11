#include <fstream>
#include <cstring>
using namespace std;

ifstream is("trie.in");
ofstream os("trie.out");

struct Trie{
    int NrCuv, NrFii;
    Trie* Fiu[26];
    Trie()
    {
        NrCuv = NrFii = 0;
        memset(Fiu, 0, sizeof(Fiu));
    }
};
Trie *T = new Trie;

void AddWord(Trie* t, char* s);
bool DelWord(Trie* t, char* s);
int NrWord(Trie* t, char* s);
int NrPref(Trie* t, char* s, int l);

int op;
char c[21];

int main()
{
    while ( is >> op )
    {
        is >> c;
        switch ( op )
        {
            case 0 : AddWord(T, c); break;
            case 1 : DelWord(T, c); break;
            case 2 : os << NrWord(T, c) << '\n'; break;
            case 3 : os << NrPref(T, c, 0) << '\n'; break;
        }
    }
    is.close();
    os.close();
    return 0;
}
void AddWord(Trie* t, char* s)
{
    if ( s[0] == 0 )
    {
        t->NrCuv++;
        return;
    }
    if ( t->Fiu[s[0]-97] == 0 )
    {
        t->NrFii++;
        t->Fiu[s[0]-97] = new Trie;
    }
    AddWord(t->Fiu[s[0]-97], s+1);
}
bool DelWord(Trie* t, char* s)
{
    if ( s[0] == 0 )
        t->NrCuv--;
    else if ( DelWord( t->Fiu[s[0]-97], s+1 ) )
    {
        t->NrFii--;
        t->Fiu[s[0]-97] = 0;
    }
    if ( t->NrCuv == 0 && t->NrFii == 0 && t != T )
    {
        delete t;
        return true;
    }
    return false;
}
int NrWord(Trie* t, char* s)
{
    if ( s[0] == 0 )
        return t->NrCuv;
    else if ( t->Fiu[s[0]-97] != 0 )
        return NrWord(t->Fiu[s[0]-97], s+1);
    return 0;
}
int NrPref(Trie* t, char* s, int l)
{
    if ( t->Fiu[s[0]-97] == 0 || s[0] == 0 )
        return l;
    return NrPref(t->Fiu[s[0]-97], s+1, l+1);
}
