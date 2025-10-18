#include <iostream>
using namespace std;
#define int long long
int n, m;
int v[100004];
int arbore[400004];
int urm_putere2(int x){
    int p = 1;
    while(p < x){
        p = p*2;
    }
    return p;
}
int p;
void initializare(){
    int p = urm_putere2(n);
    for(int i = p; i <= p+n-1; i++){
        arbore[i] = v[i-p+1];
    }
    for(int i = p+n; i <= 2*p-1; i++){
        arbore[i] = 0;
    }
    int j = p-1;
    int i = 2*p-1;
    while(j >= 1){
        arbore[j] = arbore[i]+arbore[i-1];
        i-=2;
        j--;
    }
}
void debug(){
    for(int i = 1; i <= 2*p-1; i++){
        cout << arbore[i] << ' ';
    }
}
void update(int p, int x){
    int old = arbore[p];
    arbore[p] = x;
    int p1 = p;
    while(p1 >= 1){
        p1 = p1/2;
        arbore[p1] = arbore[p1]-old+arbore[p];
    }
}
int query(int nod, int st, int dr, int a, int b){
    if(st > b || dr < a){
        return 0;
    }
    if(a <= st && dr <= b){
        return arbore[nod];
    }
    int mid = (st + dr) / 2;
    return query(nod*2, st, mid, a, b) + query(nod*2+1, mid+1, dr, a, b);
}
signed main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    p = urm_putere2(n);
    initializare();
    //debug();
    for(int i = 1; i <= m; i++){
        int op, x, y;
        cin >> op >> x >> y;
        if(op == 1){
            update(p+x-1, y);
        }else{
            cout << query(1, 0, p - 1, x - 1, y - 1) << '\n';
        }
    }
    return 0;
}
