#include <fstream>
using namespace std;
ifstream fin("eratostene2.in");
ofstream fout("eratostene2.out");
int n, jeni;
bool ciur[1000004];
long long s[1000004];
int main(){
    for(int i = 2; i <= 1000000; i++){
        if(ciur[i] == false){
            for(int j = 1; j <= 1000000/i; j++){
                s[i*j]++;
                ciur[i*j] = true;
            }
        }
    }
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> jeni;
        fout << s[jeni] << ' ';
    }
    return 0;
}

