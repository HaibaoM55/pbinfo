#include <fstream>
using namespace std;
ifstream fin("biarbore1.in");
ofstream fout("biarbore1.out");
int x = 0, y = 0;
int st = 0, dr=0;
int n, rad;
int z = 0;
int main(){

    fin >> rad;
    fin >> st;
    int nrc = 0;
    if(st != 0){
        nrc += 2;
    }
    while(nrc){
        fin >> x;
        if(x != 0){
            nrc += 2;
        }
        nrc--;
    }
    fin >> dr;
    fout << st << ' ' << dr;
    return 0;
}
