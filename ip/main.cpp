#include <fstream>
using namespace std;
ifstream fin("ip.in");
ofstream fout("ip.out");
#define NRDMAX 160
int n, q;
int v[122505];
int nrdv[122505];
int bloc[355][162];
int tip, x, y, d1;
int main(){
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
        int nrd = 0;
        for(int d = 1; d*d <= v[i]; d++){
            if(v[i] % d == 0){
                nrd++;
                if(d*d < v[i]){
                    nrd++;
                }
            }
        }
        int nrbloc = i/350;
        for(int z = nrd; z <= NRDMAX; z++){
            bloc[nrbloc][z]++;
        }
        nrdv[i] = nrd;
    }
    fin >> q;
    for(int i = 1; i <= q; i++){
        fin >> tip >> x >> y;
        x++;
        if(tip == 1){
            int nrbloc = x/350;
            int nrd = nrdv[x];
            for(int zz = nrd; zz <= NRDMAX; zz++){
                bloc[nrbloc][zz]--;
            }
            v[x] = y;
            nrd = 0;
            for(int d = 1; d*d <= v[x]; d++){
                if(v[x] % d == 0){
                    nrd++;
                    if(d*d < v[x]){
                        nrd++;
                    }
                }
            }
            for(int zz = nrd; zz <= NRDMAX; zz++){
                bloc[nrbloc][zz]++;
            }
            nrdv[x] = nrd;
        }else{
            y++;
            fin >> d1;
            if(d1 > NRDMAX){
                d1 = NRDMAX;
            }
            int nr = 0;
            int blocx = x/350;
            int blocy = y/350;
            if(blocx >= blocy - 1){
                for(int j = x; j <= y; j++){
                    if(nrdv[j] <= d1){
                        nr++;
                    }
                }
                fout << nr << '\n';
            }else{
                for(int j = blocx+1; j <= blocy-1; j++){
                    nr += bloc[j][d1];
                }
                int limita = (blocx+1)*350;
                for(int j = x; j < limita; j++){
                    if(nrdv[j] <= d1){
                        nr++;
                    }
                }
                limita = blocy*350;
                for(int j = limita; j <= y; j++){
                    if(nrdv[j] <= d1){
                        nr++;
                    }
                }
                fout << nr << '\n';
            }
        }
    }
    return 0;
}
