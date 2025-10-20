#include <fstream>
using namespace std;
ifstream fin("nume1.in");
ofstream fout("nume1.out");
int n;
char f[67];
char rez[200004];
int main(){
    fin >> n;
    for(int i = 1; i <= 26; i++){
        f[i] = i+'A'-1;
    }
    int p = 0,z = 1;
    rez[0] = 'A';
    while(p < n){
        if(rez[z-1] == 'A'){
            rez[z] = 'Z';
        }else{
            rez[z] = 'A';
        }
        p += 25;
        z++;
    }
    if(n < 25){
        rez[1] = f[n+1];
    }else if(p != n){
        for(int i = 25; i >= 1; i--){
            rez[1] = f[i];
            p -= 2;
            if(p <= n+1){
                break;
            }
        }
        if(p == n+1){
            if(rez[z-1]=='Z'){
                rez[z-1] = 'Y';
            }else{
                rez[z-1] = 'B';
            }
        }
    }
    fout << rez;
    return 0;
}
