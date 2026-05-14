//dan rezolva programu te rog
#include <fstream>
using namespace std;
ifstream fin("partitiinr.in");
ofstream fout("partitiinr.out");
int n;
int v[104];
void kp(int i, int s, int vmax){
    if(s == 0){
        for(int j = 1; j < i; j++){
            fout << v[j] << ' ';
        }
        fout << '\n';
        return;
    }
    for(int j = vmax+2; j <= s; j++){
        v[i] = j;
        kp(i+1, s-j, j);
    }
}
int main(){
    fin >> n;
    kp(1, n, -1);
    return 0;
}
