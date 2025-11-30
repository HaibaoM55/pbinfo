#include <fstream>
#include <set>
using namespace std;
ifstream fin("intersectie.in");
ofstream fout("intersectie.out");
int x, nrs=0;
int v[100004], v1[100004];
int nr = 0, nr1 = 0;
int nrf = 0;
int main(){
    while(fin >> x){
        if(x == 0){
            nrs++;
            if(nrs >= 2){
            	int i = 1, j = 1;
                nrf = 0;
                while(i <= nr && j <= nr1){
                    if(v[i] > v1[j]){
                    	j++;
                    }else if(v[i] < v1[j]){
                    	i++;
                    }else{
                        nrf++;
                        v[nrf] = v[i];
                     	i++;
                        j++;
                    }
                }
                nr1 = 0;
                nr = nrf;
            }
        }else{
            if(nrs == 0){
                nr++;
                v[nr] = x;
            }else{
                nr1++;
                v1[nr1] = x;
            }
        }
    }
    if(nrf == 0){
        fout << "nu exista";
        return 0;
    }
    for(int i = 1; i <= nrf; i++){
    	fout << v[i] << ' ';
    }
    return 0;
}
