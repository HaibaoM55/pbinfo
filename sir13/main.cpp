#include <fstream>
using namespace std;
ifstream fin("sir13.in");
ofstream fout("sir13.out");
int x;
int lastimp=2e9, lastpar=0;
int main(){
    while(fin >> x){
        if(x % 2 == 1){
            if(x > lastimp){
                fout << "NU";
                return 0;
            }
            lastimp = x;
        }else{
            if(x < lastpar){
                fout << "NU";
                return 0;
            }
            lastpar = x;
        }
    }
    fout << "DA";
    return 0;
}
