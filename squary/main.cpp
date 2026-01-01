#include <iostream>
#include <bitset>
#include <unordered_map>
using namespace std;
int n;
bitset<304> a[304];
int v[100004];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= 300; i++){
        int x = i;
        for(int j = 2; j * j <= i; j++){
            while(x % j == 0){
                x = x/j;
                a[i][j] = !a[i][j];
            }
        }
        if(x > 1) a[i][x] = !a[i][x];
    }
    long long nr = 0;
    unordered_map<bitset<304>, int> last;
    bitset<304> prefix;
    last[prefix] = 0;
    for(int i = 1; i <= n; i++){
        prefix ^= a[v[i]];
        if(last.count(prefix)){
            nr += i - last[prefix];
        }
        last[prefix] = i;
    }
    cout << nr;
    return 0;
}
