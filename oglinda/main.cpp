#include <fstream>
using namespace std;
ifstream fin("oglinda.in");
ofstream fout("oglinda.out");
int n, q;
int v[1000004];
struct intrebare{
    int t, a, b;
}a[2004];
int main(){
    fin >> n >> q;
    for(int i = 1; i <= n; i++){
        v[i] = i;
    }
    for(int j = 1; j <= q; j++){
        fin >> a[j].t;
        if(a[j].t == 1){
            fin >> a[j].a >> a[j].b;
        }else{
            fin >> a[j].a;
        }
    }
    for(int i = 1; i <= q; i++){
        if(a[i].t == 2){
            int p = a[i].a;
            for(int j = i-1; j >= 1; j--){
                if(a[j].t == 1){
                    if(a[j].a <= p && p <= a[j].b){
                        int dif = p-a[j].a;
                        p = a[j].b-dif;
                    }
                }
            }
            fout << p << '\n';
        }
    }
    return 0;
}
