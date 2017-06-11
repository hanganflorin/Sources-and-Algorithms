#include <fstream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

ifstream is("a.in");
ofstream os("a.out");

int n, a[100], v[100];
vector <int> A;

void Debug();

int main()
{

    is >> n;
    for ( int i = 0; i < n; ++i )
    {
        is >> a[i];
        v[i] = a[i];
        A.push_back(v[i]);
        os << a[i] << ' ';
    }
    os << "\n\n";
    sort(A.begin(), A.end() );
    Debug();

    A.erase( unique(A.begin(), A.end()), A.end() );
    Debug();

    for ( int i = 0; i < n; ++i  )
        if ( A[i] > A[i-1] + 1 )
        {
            A.insert(A.begin()+i, 0 );
            i++;
        }
    Debug();
    is.close();
    os.close();
    return 0;
}
void Debug()
{
    for ( const auto &c : A )
        os << c << ' ';
    os << '\n';
}
