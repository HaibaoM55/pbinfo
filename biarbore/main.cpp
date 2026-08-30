#include <fstream>
using namespace std;
ifstream fin("biarbore.in");
ofstream fout("biarbore.out");
int x = 0, y = 0;
int st = 0, dr=0;
int n, rad;
int z = 0;
void citeste(){
    bool eRad = false;
    if(z == 0){
        eRad = true;
    }
    z++;
    fin >> x;
    if(eRad){
        st = x;
    }
    if(x != 0){
        citeste();
    }
    fin >> y;
    if(eRad){
        dr = y;
    }
    if(y != 0){
        citeste();
    }
}
int main(){

    fin >> rad;
    citeste();
    fout << st << ' ' << dr;
    return 0;
}
