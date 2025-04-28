#include <fstream>
#include <bitset>
using namespace std;
ifstream fin("eratostene1.in");
ofstream fout("eratostene1.out");
int n, x;
int nr = 0;
bitset<500004> ciur;
int main(){
    fin >> n;
    ciur[1] = true;
    for(int i = 3; i <= 1000000; i += 2){
        if(ciur[(i+1)/2] == false){
            for(int j = i; j <= 1000000/i; j++){
                if((j*i)%2 == 1){
                    ciur[(j*i+1)/2] = true;
                }
            }
        }
    }
    for(int i= 1; i <=n ; i++){
        fin >> x;
        if(x == 2){
            nr++;
        }else{
            if(x % 2 == 1 && ciur[(x+1)/2] == false){
                nr++;
            }
        }
    }
    fout << nr;
    return 0;
}
