#include <iostream>
#include <map>
using namespace std;
int n;
map<int, map<int, int>> aib;
void add(int x, int idx, int delta) {
    while (idx <= 1000000000) {
        aib[x][idx] += delta;
        idx += idx & -idx;
    }
}
int prefix_sum(int x, int idx) {
    int sum = 0;
    while (idx > 0) {
        if (aib[x].count(idx)) {
            sum += aib[x][idx];
        }
        idx -= idx & -idx;
    }
    return sum;
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int tip, moment, x;
        cin >> tip >> moment >> x;
        if(tip == 1){
            add(x, moment, 1);
        }else if(tip == 2){
            add(x, moment, -1);
        }else{
            cout << prefix_sum(x, moment) << "\n";
        }
    }
    return 0;
}
