#include <iostream>
#include <unordered_map>
using namespace std;
int n, v[100004];
long long a[301];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= 300; i++){
        int x = i;
        long long hash_val = 0;
        for(int j = 2; j * j <= i; j++){
            int cnt = 0;
            while(x % j == 0){
                x /= j;
                cnt++;
            }
            if(cnt % 2 == 1){
                hash_val ^= (1LL * j * 1000000007LL);
            }
        }
        if(x > 1){
            hash_val ^= (1LL * x * 1000000007LL);
        }
        a[i] = hash_val;
    }
    unordered_map<long long, int> f;
    long long nr = 0;
    long long curent = 0;
    f[0] = 1;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
        curent ^= a[v[i]];
        nr += f[curent];
        f[curent]++;
    }
    cout << nr;
    return 0;
}
