#include <iostream>
#include <algorithm>
using namespace std;
int a, b, r;
int n;
pair<int, int> v[10004];
int main(){
    cin >> a >> b;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> v[i].first >> v[i].second;
    }
    sort(v+1, v+n+1);
    r = a;
    int vmax = 0;
    int nr = 0;
    for(int i = 1; i <= n; i++){
        if(v[i].first > r){
            r = vmax;
            vmax = 0;
            nr++;
            if(r >= b){
                break;
            }
        }
        vmax = max(vmax, v[i].second);
    }
    if(r < b){
        r = vmax;
        nr++;
    }
    cout << nr;
	return 0;
}
