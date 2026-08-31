#include <fstream>
using namespace std;
ifstream fin("preordine1.in");
ofstream fout("preordine1.out");
int n, x, y;
int main(){
	fin >> n;
    int nrp = 1;
    while(nrp){
        fin >> x;
        if(x != 0){
    		fout << x << ' ';
            nrp += 2;
        }
        nrp--;
	}
}
