#include <iostream>
#include <algorithm>
using namespace std;
int t;
long long n, m, h, w;
int main(){
    cin >> t;
    while(t){
        cin >> n >> m >> h >> w;
        if(n > m){
            swap(n, m);
        }
        if(h > w){
            swap(h, w);
        }
        int g = __gcd(h, w);
        if(g == 1 && (h+w) % 2 == 1 && n >= h+w && w <= m/2){
            cout << "YES";
        }else{
            cout << "NO";
        }
        cout << '\n';
        t--;
    }
	return 0;
}
