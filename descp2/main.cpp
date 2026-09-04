#include <fstream>
using namespace std;
ifstream fin("descp2.in");
ofstream fout("descp2.out");
int n;
int v[204];
bool ok = false;
void kp(int vmax, int s){
    if(s == 0){
        ok = true;
        for(int i = 1; i <= v[0]; i++){
            fout << v[i] << ' ';
        }
        fout << '\n';
        return;
    }else{
        for(int i = vmax; i <= s; i = i*2){
            v[0]++;
            v[v[0]] = i;
            kp(i, s-i);
            v[0]--;
        }
    }
}
int main(){
    fin >> n;
    kp(2, n);
    return 0;
}
