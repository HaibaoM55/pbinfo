#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("cmmdcsecv.in");
ofstream fout("cmmdcsecv.out");
int n;
int v[100003];
bool ciur[1004];
int prm[500];
int nrp = 0;
int main()
{
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
    }
    for(int i = 2; i <= 1000; i++){
        if(ciur[i] == false){
            for(int j =i; j*i <= 1000; j++){
                ciur[j*i] = true;
            }
            nrp++;
            prm[nrp] = i;
        }
    }
    int vmax = 1;
    for(int k=1; k <= nrp; k++){
        int i = 1;
        for(int j = 1; j <= n; j++){
            if(v[j] % prm[k] !=0){
                i=j+1;
            }else{
                if(j-i+1 > vmax){
                    vmax = j-i+1;
                }
            }
        }
    }
    fout << vmax;
    return 0;
}
