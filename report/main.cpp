#include <fstream>
#include <algorithm>
using namespace std;
ifstream altex("report.in");
ofstream voicu("report.out");
#define bosu 200004
int n, m, op, k;
int v[bosu];
struct usabigcia{
    int op, k;
}stiva[bosu];
bool descrescator(int a, int b){
    return a > b;
}
int dr = 0;
int main(){
    altex >> n >> m;
    for(int i = 1; i <= n; i++){
        altex >> v[i];
    }
    for(int i = 1; i <= m; i++){
        altex >> op >> k;
        if(i == 1){
            dr = 1;
            stiva[1].op = op;
            stiva[1].k = op;
        }else{
            int p1 = 1, p2 = dr, p=dr+1;
            while(p1 <= p2){
                int mij = (p1+p2)/2;
                if(stiva[mij].k < k){
                    p2 = mij-1;
                    p = mij;
                }else{
                    p1 = mij+1;
                }
            }

        }
    }
    for(int i = 1; i <= n; i++){
        voicu << q[i].k << ' ';
    }
    return 0;
}
