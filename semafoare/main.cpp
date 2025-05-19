#include <fstream>
using namespace std;
ifstream fin("semafoare.in");
ofstream fout("semafoare.out");
int c;
int t1, r1, g1, v1;
int t2, r2, g2, v2;
int rez(int t, int r, int g, int v){
    int c=r+g+v+g;
    t=t%c;
    if(r+g>t){
        return r+g-t;
    }else{
        if(r+g+v > t){
            return 0;
        }
        else{
           return c-t+r+g;
        }
    }
}
int main(){
    fin >> c;
    fin >> r1 >> g1 >> v1;
    fin >> r2 >> g2 >> v2;
    fin >> t1 >> t2;
    if(c == 1){
        if(t1 == t2 && t1 == 0){
            fout << min(r1+g1, r2+g2);
        }else{
            fout << min(rez(t1, r1, g1, v1), rez(t2, r2, g2, v2));
        }
    }else{
         long long c1 = r1 + 2*g1 + v1;
         long long c2 = r2 + 2*g2 + v2;
         for(int t = 0; t <= 1e6; t++){
            long long p1= (t1+t)%c1;
            long long p2 = (t2+t)%c2;
            long long s11, s12 ;
            if(p1 < r1){
                s11 =0;
            }else if(p1 < r1 + g1){
                s11 = 1;
            }else if(p1 < r1 + g1 + v1){
                s11 = 2;
            }else{
                s11 = 1;
            }
            if(p2 < r2){
                s12 = 0;
            }else if(p2 < r2 + g2){
                s12 = 1;
            }else if(p2 < r2 + g2 + v2){
                s12 = 2;
            }else{
                s12 = 1;
            }
            if(s11 == s12){
                fout << t << '\n';
                break;
            }
        }
    }
    return 0;
}
