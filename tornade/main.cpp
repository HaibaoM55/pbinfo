#include <fstream>
using namespace std;
ifstream fin("tornade.in");
ofstream fout("tornade.out");
int n;
int v[1000004];
char t[1000004];
int main(){
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
    }
    for(int i = 1; i <= n; i++){
        fin >> t[i];
    }
    if(n <= 1000){
        int z = n;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j < z; j++){
                if(t[i] == 'm'){
                    v[j] = min(v[j], v[j+1]);
                }else{
                    v[j] = max(v[j], v[j+1]);
                }
            }
            z--;
        }
        fout << v[1];
    }else{

    }
    return 0;
}
