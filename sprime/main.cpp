#include <fstream>
using namespace std;
ifstream fein("sprime.in");
ofstream fout("sprime.out");
int s;
bool ciur[100004];
int nrp = 0;
int prm[100004];
int nr = 0;
int main()
{
    fein >> s;
    for(int i = 2; i <= s; i++){
        if(ciur[i] == false){
            nrp++;
            prm[nrp] = i;
            for(int j = i; j <= s/i; j++){
                ciur[j*i]=true;
            }
        }
    }
    for(int i = 1; i <= nrp; i++){
        for(int j = i; j <= nrp; j++){
            int x = s-prm[i]-prm[j];
            if(x < prm[j]){
                break;
            }else{
                if(ciur[x] == false){
                    nr++;
                }
            }
        }
    }
    fout << nr;
    return 0;
}
