#include <fstream>
using namespace std;
#pragma GCC optimize("O1")
ifstream fin("eratostene4.in");
ofstream fout("eratostene4.out");
int n, x;
bool ciurp[10000004];
int p2[34];
int ciur[10000004];
int main(){
    for(int i = 2; i <= 10000000; i++){
        if(ciurp[i] == false){
            for(int j = 1; j <= 10000000/i; j++){
                ciurp[j*i] = true;
                ciur[j*i]++;
            }
        }
    }
    p2[0] = 1;
    for(int i = 1; i <= 30; i++){
        p2[i] = p2[i-1]*2;
    }
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> x;
        fout << p2[ciur[x]] << ' ';
    }
    return 0;
}
