#include <fstream>
using namespace std;
ifstream fin("becuri1.in");
ofstream fout("becuri1.out");
int p, n;
int x;
int nr = 0;
int v[104][12];
int c[104], nr1[104];
int z  = 0;
int bec[104];
int main()
{
    fin >> p;
    fin >> n;
    if(p == 1){
        for(int i = 1; i <= n; i++){
            fin >> x;
            while(x > 9){
                x = x/10;
            }
            int cif = x;
            if(cif == 2 || cif == 3 || cif == 5 || cif == 7){
                nr++;
            }
        }
        fout << nr;
    }else if(p == 2){
        int maxim = 0;
        for(int i = 1; i <= n; i++){
            fin >> x;
            int nrc = 0;
            do{
                nrc++;
                v[i][nrc] = x%10;
                x = x / 10;
            }while(x > 0);
            v[i][11] = nrc;
            int z = nrc;
            for(int j = 1; j <= nrc/2; j++){
                int aux = v[i][j];
                v[i][j] = v[i][z];
                v[i][z] = aux;
                z--;
            }
            maxim = max(maxim, nrc);
        }
        int maximnr = -1;
        for(int i = 1; i <= maxim; i++){
            int nr = 0;
            for(int j = 1; j <= n; j++){
                c[j]++;
                if(c[j]== v[j][11]+1){
                    c[j] = 1;
                }
                int cif = v[j][c[j]];
                if(cif == 2 || cif == 3 || cif == 5 || cif == 7){
                    nr++;
                }
            }
            maximnr = max(maximnr, nr);
        }
        fout << maximnr;
    }else{
        int maxim = 0;
        for(int i = 1; i <= n; i++){
            fin >> x;
            int nrc = 0;
            do{
                nrc++;
                v[i][nrc] = x%10;
                x = x / 10;
            }while(x > 0);
            v[i][11] = nrc;
            int z = nrc;
            for(int j = 1; j <= nrc/2; j++){
                int aux = v[i][j];
                v[i][j] = v[i][z];
                v[i][z] = aux;
                z--;
            }
            maxim = max(maxim, nrc);
        }
        int maximnr = 1, maximi=-1;
        for(int i = 1; i <= maxim; i++){
            for(int j = 1; j <= n; j++){
                c[j]++;
                if(c[j]== v[j][11]+1){
                    c[j] = 1;
                }
                int cif = v[j][c[j]];
                if(cif == 2 || cif == 3 || cif == 5 || cif == 7){
                    nr1[j]++;
                }
            }
        }
        for(int i = 1; i <= n; i++){
            if(nr1[i] > maximnr){
                z=1;
                bec[1] = i;
                maximnr = nr1[i];
                maximi = i;
            }else if(nr1[i] == maximnr){
                z++;
                bec[z] = i;
            }
        }
        if(z == 0){
            fout << -1;
        }
        for(int i = 1; i <= z; i++){
            fout << bec[i] << ' ';
        }
    }
    return 0;
}
