#include <fstream>
using namespace std;
ifstream fin("scara.in");
ofstream fout("scara.out");
int n;
int v[2004], a[2004];
int maxdr = 0;
int nr = 0;
int vmaxdr = 0;
void rezolva(){
    //mutam v[v[0]] la a[maxdr]
    nr++;
    int maxdr = 0;
    int aux = v[v[0]];
    v[0]--;
    for(int i = 1; i <= n; i++){
        if(a[i] == 0){
            maxdr = i;
            vmaxdr = max(vmaxdr, maxdr);
            break;
        }else{
            v[0]++;
            v[v[0]] = a[i];
        }
    }
    for(int i = 1; i < maxdr; i++){
        a[i] = 0;
    }
    a[maxdr] = aux;
//    for(int i = 1; i <= v[0]; i++){
//        fout << v[i] << ' ';
//    }
//    fout << ':';
//    for(int i = 1; i <= vmaxdr; i++){
//        fout << a[i] << ' ';
//    }
//    fout << '\n';
    if(v[0] != 0){
        rezolva();
    }else{
        for(int i = 1; i <= n; i++){
            fout << a[i] <<' ';
        }
    }
}
int main(){
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
    }
    v[0] = n;
    if(n <= 15){
        rezolva();
    }
    return 0;
}
