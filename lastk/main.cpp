#include <iostream>
#include <queue>
#include <vector>
using namespace std;
priority_queue<int, vector<int>, greater<int>> f;
int main(){
    long long n, k, a, b, c, d;
    cin >> n >> k >> a >> b >> c >> d;
    f.push(a);
    for(int i = 2; i <= n; i++){
        a = (b*a+c) % d;
        if(i <= k){
            f.push(a);
        }else{
            if(a > f.top()){
                f.pop();
                f.push(a);
            }
        }
    }
    while(!f.empty()){
        cout << f.top() << ' ';
        f.pop();
    }
    return 0;
}
