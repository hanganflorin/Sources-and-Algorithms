#include <fstream>
#include <cstring>
using namespace std;

ifstream is("a.in");
ofstream os("a.out");

struct nod{
    string key;
    nod* next;
};
struct node{
    long long key;
    node*next;
};

nod*prim, *ultim;
node*first, *last;

void Add(long long  v );

void Read();
void List();
void Adauga();
void AdS(string v );
bool Posibil(string v );
string Modifica( string v );

int main()
{
    //Read();
   // Adauga();
    //List();
    while ( true )
        Add(9645635234335143);
    is.close();
    os.close();
    return 0;
}
void Read()
{
    string x;
    while ( is >> x )
        AdS(x);
}
void List()
{
    for ( nod* p = prim; p; p= p->next )
        os << p->key << ' ';
}
void Adauga()
{
    if (prim == 0 ) return;
    if ( prim == ultim && Posibil(prim->key))
    {
        AdS(Modifica(prim->key));
        return;
    }
    for ( nod*p = prim; p; p=p->next )
    {
        if ( Posibil(p->key) )
        {
            if ( p != ultim )
            {
                nod*q = new nod;
                q->key = Modifica(p->key);
                q->next = p->next;
                p->next = q;
                //p = p->next;
            }
            else
            {
                AdS(Modifica(p->key));
                return;
            }

        }
    }
}
void AdS(string v )
{
    if ( prim == 0 )
    {
        prim = new nod;
        prim->key = v;
        prim->next = 0;
        ultim = prim;
    }
    else
    {
        nod * p = new nod;
        p->key = v;
        p->next = 0;
        ultim->next = p;
        ultim = p;
    }
}
bool Posibil(string v )
{
    int nr = 0;
    for ( int i = 0; i < v.size(); ++i )
    {
        if ( strchr("aeiouAEIOU", v[i]) )
            nr++;
        if ( nr >= 2 ) return true;
    }
    return false;
}
string Modifica( string v )
{
    for ( int i = 0; i < v.size(); ++i )
        v[i] = toupper(v[i]);
    return v;
}
void Add(long long  v )
{
    if ( first == 0 )
    {
        first = new node;
        first->key = v;
        first->next = 0;
        last = first;
    }
    else
    {
        node*p = new node;
        p->key = v;
        p->next = 0;
        last->next = p;
        last = p;
    }
}
