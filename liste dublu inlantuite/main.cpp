#include <fstream>
using namespace std;

ifstream is("a.in");
ofstream os("a.out");

struct nod{
    int key;
    nod* urmator;
    nod* anterior;
};

nod * prim, * ultim;

void AdS(int v );
void AdF(int v );
void Print();
void Print_R();
void Read();

int main()
{
    Read();
    Print();
    Print_R();
    is.close();
    os.close();
    return 0;
}
void AdS(int v )
{
    if ( prim == 0 )
    {
        prim = new nod;
        prim->key = v;
        prim->urmator = 0;
        prim->anterior = 0;
        ultim = prim;
    }
    else
    {
        nod * p = new nod;
        p->key = v;
        p->urmator = 0;
        p->anterior = ultim;
        ultim->urmator = p;
        ultim = p;
    }
}
void AdF(int v )
{
    if ( prim == 0 )
    {
        prim = new nod;
        prim->key = v;
        prim->anterior = 0;
        prim->urmator = 0;
        ultim = prim;
    }
    else
    {
        nod* p = new nod;
        p->key = v;
        p->urmator = prim;
        p->anterior = 0;
        prim->anterior = p;
        prim = p;
    }
}
void Print()
{
    for ( nod* p = prim; p; p = p->urmator )
        os << p->key << ' ';
    os << '\n';
}
void Read()
{
    int x;
    while ( is >> x )
    {
        if ( x % 2 == 0 )
            AdS(x);
        else
            AdF(x);
    }
}
void Print_R()
{
    for ( nod * p = ultim; p; p = p->anterior )
        os << p->key << ' ';
    os << '\n';
}
