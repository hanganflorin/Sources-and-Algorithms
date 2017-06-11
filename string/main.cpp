#include <fstream>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;

ifstream is("a.in");
ofstream os("a.out");

string s, sep(" .,!?\n"), voc("aeiouAEIOU");

int main()
{
    getline(is, s, (char)EOF);
    size_t p = s.find_first_not_of(sep);
    size_t q = s.find_first_of(sep, p);
    while ( p != string::npos )
    {
        size_t x = s.find_first_of(voc, p);
        size_t y = s.find_last_of(voc, q);
        if ( x >= p && y < q && x != y )
            s.erase(p, q-p);
        p = s.find_first_not_of(sep);
        q = s.find_first_of(sep, p);
    }
    os << s;
    is.close();
    os.close();
    return 0;
}
