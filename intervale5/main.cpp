#include <fstream>
using namespace std;
ifstream fin("intervale5.in");
ofstream fout("intervale5.out");
bool f[104];
int main() {
    int x=0, y=0;
    while(fin >> x){
        f[x]=true;
    }
    bool exista = false;
    for(int i = 0; i <= 100; i++){
        if(f[i]){
            x = i;
        }
        while(!f[i+1] && i <= 99){
            i++;
        }
        if(f[i+1]){
            y = i+1;
        }
        if(y-x >= 2){
            fout << x << ' ' << y << '\n';
            exista = true;
        }
    }
    if(!exista){
        fout << "nu exista";
    }
}
