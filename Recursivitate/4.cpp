#include<iostream>
#include<fstream>
using namespace std;

ifstream is("a.in");
ofstream os("a.out");

bool F(char* a[100], char* b[100]);

int main()
{
    int n;
    char a[] = "aeiou";
    char b[] = "eouia"
    cout << F(a, b);
    is.close();
    os.close();
    return 0;
}
bool F(char* a[100], char* b[100])
{
    for ( int i = 0; i < strlen(a); ++i )
    {
        for ( int j = 0; j < strlen(b); ++j )
        {

        }
    }
}
