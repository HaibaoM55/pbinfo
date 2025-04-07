#include <fstream>
using namespace std;
ifstream fin("sipet.in");
ofstream fout("sipet.out");
int t;
int n, x;
bool ciur[10000004];
int prm[1000004], nrp=0;
int main(){
    for(int i = 2; i <= 10000000; i++){
        if(ciur[i] == false){
            nrp++;
            prm[nrp] = i;
            for(int j = i; j <= 10000000/i; j++){
                ciur[j*i] = true;
            }
        }
    }
    fin >> t;
    for(int z1 = 1; z1 <= t; z1++){
        fin >> n >> x;
        int p1 = 1, p2 = nrp, p = 1;
        while(p1 <= p2){
            int mij = (p1+p2)/2;
            if(prm[mij] <= x){
                p1 = mij+1;
                p = mij;
            }else{
                p2 = mij-1;
            }
        }
        int y = prm[p+1];
        int z = prm[p+2];
        int restmin = 2e9, restmini, restminj, restmink;
        for(int i = n/x; i >= 0 && restmin > 0; i--){
            for(int j = (n-i*x)/y; j >= 0; j--){
                //i*x+j*y+z*k= n
                //z*k=n-i*x-j*y;
                //k = (n-i*x-j*y)/z;
                int k = (n-i*x-j*y)/z;
                if(n-i*x-j*y-k*z < restmin){
                    restmin = n-i*x-j*y-k*z;
                    restmini = i;
                    restminj = j;
                    restmink = k;
                }
                if(restmin == 0){
                    break;
                }
            }
        }
        int s = restmini+restminj+restmink;
        fout << s << ' ' << restmini << ' ' << restminj << ' ' << restmink << ' ' << restmin << '\n';
    }
    return 0;
}
