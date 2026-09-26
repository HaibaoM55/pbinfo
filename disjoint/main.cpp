#include <iostream>
using namespace std;
int n, m;
int tip, x, y;
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
    rad[b] = a;
    card[a] += card[b];
}
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        rad[i] = i;
    }
    for(int i = 1; i <= m; i++){
        cin >> tip >> x >> y;
        if(tip == 1){
            Union(Find(x), Find(y));
        }else{
            if(Find(x) == Find(y)){
                cout << "DA";
            }else{
                cout << "NU";
            }
            cout << '\n';
        }
    }
    return 0;
}
