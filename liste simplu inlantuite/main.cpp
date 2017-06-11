#include <fstream>
using namespace std;

ifstream is("a.in");
ofstream os("a.out");

struct nod{
    int key;
    nod* next;
};

nod* prim;
nod* ultim;

void Push_back(int x);
void Push_front(int x);
void Print();
void Read();

int main()
{
    Read();
    Push_back(12345);
    Push_front(3698);
    Print();
    is.close();
    os.close();
    return 0;
}
void Read()
{
    int x;
    while ( is >> x )
        Push_back(x);
}
void Push_back(int x)
{
    if ( prim == 0 )
    {
        prim = new nod;
        prim->key = x;
        prim->next = 0;
        ultim = prim;
    }
    else
    {
        nod*p = new nod;
        p->key = x;
        p->next = 0;
        ultim->next = p;
        ultim = p;
    }
}
void Print()
{
    for ( nod*p = prim; p; p = p->next )
        os << p->key << ' ';
}
void Push_front(int x)
{
    if ( prim == 0 )
    {
        prim = new nod;
        prim->key = x;
        prim->next = 0;
        ultim = prim;
    }
    else
    {
        nod * p = new nod;
        p->key = x;
        p->next = prim;
        prim = p;
    }

}
