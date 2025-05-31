#include <fstream>
using namespace std;
ifstream fin("secventa4.in");
ofstream fout("secventa4.out");
int n, x;
int vmax = 0;
int vmaxi, vmaxj;
int main(){
    fin >> n;
    int secv = 1;
    int oldcif = -1;
    for(int i = 1; i <= n; i++){
        fin >> x;
        if(x % 10 == oldcif){
            secv++;
        }else{
            secv = 1;
        }
        oldcif = x%10;
        if(secv > vmax){
            vmax = secv;
            vmaxj = i;
            vmaxi = i-secv+1;
        }
    }
    fout << vmaxi << ' ' << vmaxj;
    return 0;
}
