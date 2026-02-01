#include <iostream>
#include <vector>
using namespace std;
int n, m, q;
char a[1004][1004];
int p[1004][1004];
bool viz[1004][1004];
int dirx[6] = {0,1};
int diry[7] = {1,0};
struct poz{
    int i, j;
}c[1000004];
bitset<1004*1004> a;
void initviz(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            viz[i][j] = false;
        }
    }
}
int main(){
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    int nr = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i][j] == '#'){
                continue;
            }
            initviz();
            int st = 1, dr = 1;
            c[1] = {i, j};
            while(st <= dr){
                for(int z = 0; z < 2; z++){
                    int i1 = c[st].i+dirx[z];
                    int j1 = c[st].j+diry[z];
                    if(1 <= i1 && i1 <= n){
                        if(1 <= j1 && j1 <= m){
                            if(!viz[i1][j1] && a[i1][j1] == '$'){
                                dr++;
                                c[dr].i = i1;
                                c[dr].j = j1;
                                b[i1][j1].push_back({i, j});
                                viz[i1][j1] = true;
                            }
                        }
                    }
                }
                st++;
            }
            p[i][j] = dr;
            nr += dr;
        }
    }
    cout << nr << '\n';
    for(int i = 1; i <= m; i++){
        char pv;
        int x, y;
        cin >> pv >> x >> y;
        if(pv == '!'){
            for(auto a: b[x][y]){
                p[a.i][a.j]--;
            }
        }else{
            cout << p[x][y]<< '\n';
        }
    }
    return 0;
}
