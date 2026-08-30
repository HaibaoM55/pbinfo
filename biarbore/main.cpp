#include <fstream>
using namespace std;
ifstream fin("biarbore.in");
ofstream fout("biarbore.out");
int x = 0, y = 0;
int st = 0, dr=0;
int n, rad;
void citeste(int z){
    fin >> x;
    if(z == 0){
        st = x;
    }
    if(x != 0){
        citeste(z+1);
    }
    fin >> y;
    if(z == 0){
        dr = y;
    }
    if(y != 0){
        citeste(z+1);
    }
}
int main(){

    fin >> rad;
    citeste(0);
    fout << st << ' ' << dr;
    return 0;
}
