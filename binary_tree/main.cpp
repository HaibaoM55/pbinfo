#include <iostream>
using namespace std;
int q;
int a, b;
int nivel(int p){
    if(p == 1) return 1;
    return 1+nivel(p/2);
}
int lca(int x, int y){
    int nx = nivel(x);
    int ny = nivel(y);
    int rasp = 0;
    while(nx > ny){
        x = x/2;
        nx--;
        rasp++;
    }
    while(ny > nx){
        y = y/2;
        ny--;
        rasp++;
    }
    while(x != y){
        x = x/2;
        y = y/2;
        rasp += 2;
    }
    return rasp;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> q;
    while(q){
        cin >> a >> b;
        cout << lca(a, b) << '\n';;
        q--;
    }
    return 0;
}
