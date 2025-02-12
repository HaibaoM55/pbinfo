#include <fstream>
using namespace std;
ifstream fin("bazaxy.in");
ofstream fout("bazaxy.out");
int bx, by;
long long x, y;
bool fx[11], fy[11];
int nrz = 0, bz[20];
bool ok12 = false;
int main()
{
    fin >> bx >> by;
    fin >> x >> y;
    if(by < bx){
        swap(bx, by);
        swap(x, y);
        ok12 = true;
    }
    long long y1 = y;
    long long nr = 0;
    long long p = 1;
    do{
        nr = nr+p*(y1%10);
        p = p*by;
        y1 = y1/10;
    }while(y1 > 0);
    while(nr > 0){
        nrz++;
        bz[nrz] = nr%bx;
        nr = nr/bx;
    }
    nr = 0;
    for(int i = nrz; i >= 1; i--){
        nr = nr*10+bz[i];
        fx[bz[i]] = true;
    }
    long long x1 = x;
    do{
        fy[x1%10] = true;
        x1 = x1/10;
    }while(x1 > 0);
    int oki = -1;
    for(int i = 0; i <= 9; i++){
        if(fx[i] && fy[i]){
            oki = i;
            break;
        }
    }
    fout << oki << '\n';
    if(ok12){
        fout << nr << ' ' << x;
    }else{
        fout << x << ' ' << nr;
    }
    return 0;
}
