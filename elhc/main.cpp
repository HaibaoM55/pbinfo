#include <fstream>
using namespace std;
ifstream fin("elhc.in");
ofstream fout("elhc.out");
int t;
int g, p;
bool b[1000004];
int main(){
    fin >> t;
    for(int i = 1; i <= t; i++){
        fin >> g >> p;
        for(int j = 1; j <= p; j++){
            b[j] = false;
        }
        long long nr = 1;
        bool ok = true;
        for(int j = 1; j < p; j++){
            nr = nr*g;
            nr = nr%p;
            if(b[nr]){
                ok = false;
                break;
            }else{
                b[nr] = true;
            }
        }
        fout << ok;
    }
    return 0;
}
