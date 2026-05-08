#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m, x, y;
vector<pair<int, int>> v;
int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> x >> y;
        v.push_back({x, y});
    }
    sort(v.begin(), v.end());
    long long r = 0;
    for(int i = 0; i < m; i++){
        if(v[i].second < n){
            n -= v[i].second;
            r += v[i].second*v[i].first;
        }else{
            r += v[i].first*n;
            n = 0;
            break;
        }
    }
    if(n == 0){
        cout << r;
    }else{
        cout << "imposibil";
    }
    return 0;
}
