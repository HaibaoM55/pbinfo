#include <iostream>
using namespace std;
int n, m, tip, x, y, vmax=1;
int rad[100004], card[100004];
int Find(int x) {
    if (rad[x] == x) {
        return x;
    }
    rad[x] = Find(rad[x]);
    return rad[x];
}
void Union(int a, int b) {
    if (card[a] < card[b]) {
        swap(a, b);
    }
    if(Find(a) == Find(b)) return;
    rad[b] = a;
    card[a] += card[b];
    vmax = max(vmax, card[a]);
}
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        rad[i] = i;
        card[i] = 1;
    }
    for(int i = 1; i <= m; i++){
        cin >> tip;
        if(tip == 1){
            cin >> x >> y;
            Union(Find(x), Find(y));
        }else if(tip == 2){
            cin >> x >> y;
            if(Find(x) == Find(y)){
                cout << "DA\n";
            }else{
                cout << "NU\n";
            }
        }else{
            cout << vmax << '\n';
        }
    }
    return 0;
}
