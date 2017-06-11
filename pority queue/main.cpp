#include <iostream>
#include <queue>
#include <vector>
using namespace std;

priority_queue< pair<int, int>, vector< pair<int, int> >, greater<pair<int, int> > > Q;

int main()
{
    Q.push({3, 9});
    Q.push({1, 8});
    Q.push({1, 5});

    cout << Q.top().first << ' ' << Q.top().second << '\n'; Q.pop();
    cout << Q.top().first << ' ' << Q.top().second << '\n'; Q.pop();
    cout << Q.top().first << ' ' << Q.top().second << '\n'; Q.pop();
    return 0;
}
