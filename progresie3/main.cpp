#include <fstream>
using namespace std;
ifstream fin("progresie3.in");
ofstream fout("progresie3.out");
int x;
bool f[1004];
int main(){
    while(fin >> x){
        f[x] = true;
    }
    int i;
    for(i = 0; i <= 1000; i++){
        if(f[i]){
            x = i;
            break;
        }
    }
    i++;
    int r = 0;
    for(i; i <= 1000; i++){
        if(f[i]){
            r = i-x;
            x = i;
            break;
        }
    }
    bool ok = true;
    i++;
    for(i; i <= 1000; i++){
        if(f[i]){
            if(i-x != r){
                ok=false;
                break;
            }
            x = i;
        }
    }
    if(ok){
        fout << r;
    }else{
        fout << "NU";
    }
    return 0;
}
