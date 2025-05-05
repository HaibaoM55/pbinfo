#include <fstream>
using namespace std;
ifstream fin("eratostene.in");
ofstream fout("eratostene.out");
int n, x;
bool ciur[1000004];
int main(){
    ciur[1] = true;
    for(int i = 2; i <= 1000000; i++){
        if(ciur[i] == false){
            for(int j = i; j <= 1000000/i; j++){
                ciur[j*i] = true;
            }
        }
    }
    fin >> n;
    int nr = 0;
    for(int i = 1; i <= n; i++){
        fin >> x;
        if(ciur[x] == false){
            nr++;
        }
    }
    fout << nr;
    return 0;
}
