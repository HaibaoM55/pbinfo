#include <iostream>
#include <bitset>
using namespace std;
int n;
char x;
int b[27];
int f[250004][26];
void update(int pos, int delta) {
    for (; pos <= n; pos += pos & (-pos)) {
        f[pos] += delta;
    }
}
long long query(int pos){
    long long sum = 0;
    for (; pos > 0; pos -= pos & (-pos)) {
        sum += f[pos];
    }
    return sum;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    int nrb = 0;
    for(int i = 1; i <= n; i++){
        cin >> x;
        if(i % 20 == 0){
            nrb++;
        }
        if(b[x-'a'] == 0){
    z
        }
    }
    return 0;
}
