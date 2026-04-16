#include <fstream>
using namespace std;
ifstream fin("candidati.in");
ofstream fout("candidati.out");
#define int long long
#define MOD 1000000007
int cer, x;
int n, m, k;
int st, dr;
struct interval{
    long long x, y;
};
struct partidcandidat{
    int k;
    interval vol[104];
}p[1004],c[1004];
int mars[100004], mars2[100004];
signed main(){
    fin >> cer;
    if(cer == 1 || cer == 2){
        fin >> x;
    }
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> p[i].k;
        for(int j = 1; j <= p[i].k; j++){
            fin >> p[i].vol[j].x >> p[i].vol[j].y;
        }
    }
    fin >> m;
    for(int i = 1; i <= m; i++){
        fin >> c[i].k;
        for(int j = 1; j <= c[i].k; j++){
            fin >> c[i].vol[j].x >> c[i].vol[j].y;
            if(n > 10 || m > 10){
                for(int j1 = 1; j1 < j; j1++){
                    if(c[i].vol[j1].x < c[i].vol[j].y && c[i].vol[j1].y > c[i].vol[j].x){
                        c[i].vol[j].y = c[i].vol[j1].x-1;
                    }
                    if(c[i].vol[j1].y > c[i].vol[j].x && c[i].vol[j1].x < c[i].vol[j].y){
                        c[i].vol[j].x = c[i].vol[j1].y+1;
                    }
                }
                if(c[i].vol[j].x > c[i].vol[j].y){
                    c[i].k--;
                    j--;
                }
            }
        }
    }
    if(cer == 1){
        if(n <= 10 && m <= 10){
            for(int i = 1; i <= p[x].k; i++){
                mars2[p[x].vol[i].x]++;
                mars2[p[x].vol[i].y+1]--;
            }
            for(int j = 1; j <= 100000; j++){
                mars2[j] = mars2[j-1]+mars2[j];
            }
            for(int i = 1; i <= m; i++){
                int nr = 0;
                for(int j = 1; j <= 100000; j++){
                    mars[j] = 0;
                }
                for(int j = 1; j <= c[i].k; j++){
                    mars[c[i].vol[j].x]++;
                    mars[c[i].vol[j].y+1]--;
                }
                for(int j = 1; j <= 100000; j++){
                    mars[j] = mars[j-1]+mars[j];
                    if(mars[j] > 0 && mars2[j] > 0){
                        nr++;
                    }
                }
                fout << nr << '\n';
            }
        }
        else{
//        for(int i = 1; i <= m; i++){
//            for(int j = 1; j <= c[i].k; j++){
//                fout << c[i].vol[j].x << ' ' << c[i].vol[j].y << '\n';
//            }
//            fout << '\n';
//            fout << '\n';
//        }
            for(int i = 1; i <= m; i++){
                long long nr = 0;
                for(int j = 1; j <= c[i].k; j++){
                    for(int j1 = 1; j1 <= p[x].k; j1++){
                        int xmax = max(c[i].vol[j].x, p[x].vol[j1].x);
                        int ymin = min(c[i].vol[j].y, p[x].vol[j1].y);
                        nr += max(0LL, ymin-xmax+1);
                    }
                }
                fout << nr << '\n';
            }
        }
    }else if(cer == 2){

    }else if(cer == 3){
        long long rasp = 0;
        for(int x = 1;  x <= n; x++){
            /*if(n <= 10 && m <= 10){
            for(int i = 1; i <= p[x].k; i++){
                mars2[p[x].vol[i].x]++;
                mars2[p[x].vol[i].y+1]--;
            }
            for(int j = 1; j <= 100000; j++){
                mars2[j] = mars2[j-1]+mars2[j];
            }
            for(int i = 1; i <= m; i++){
                int nr = 0;
                for(int j = 1; j <= 100000; j++){
                    mars[j] = 0;
                }
                for(int j = 1; j <= c[i].k; j++){
                    mars[c[i].vol[j].x]++;
                    mars[c[i].vol[j].y+1]--;
                }
                for(int j = 1; j <= 100000; j++){
                    mars[j] = mars[j-1]+mars[j];
                    if(mars[j] > 0 && mars2[j] > 0){
                        nr++;
                    }
                }
                fout << nr << '\n';
            }
        }
        else{

        }*/
//        for(int i = 1; i <= m; i++){
//            for(int j = 1; j <= c[i].k; j++){
//                fout << c[i].vol[j].x << ' ' << c[i].vol[j].y << '\n';
//            }
//            fout << '\n';
//            fout << '\n';
//        }
            for(int i = 1; i <= m; i++){
                long long nr = 0;
                for(int j = 1; j <= c[i].k; j++){
                    for(int j1 = 1; j1 <= p[x].k; j1++){
                        int xmax = max(c[i].vol[j].x, p[x].vol[j1].x);
                        int ymin = min(c[i].vol[j].y, p[x].vol[j1].y);
                        nr += max(0LL, ymin-xmax+1);
                    }
                }
                rasp += nr;
                rasp = rasp % MOD;
            }
        }
        fout << rasp << '\n';
        for(int i = 1; i <= m; i++){
            fout << "-1\n";
        }
    }
    return 0;
}
