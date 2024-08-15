#include <iostream>
#include <queue>
using namespace std;
priority_queue<int> Q;
int i, x, y, n, s;
int main(){
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> x;
        Q.push(-x);
    }
    s = 0;
    for (i = 1; i < n; i++)
    {
        x = -Q.top();
        Q.pop();
        y = -Q.top();
        Q.pop();
        s += x+y;
        x = x+y;
        Q.push(-x);
    }
    cout << s;

}
