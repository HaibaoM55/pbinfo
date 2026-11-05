#include <fstream>
using namespace std;
ifstream fin("restart.in");
ifstream fin1("restart.in");
ofstream fout("restart.out");
int n=0, x;
int r = 0;
int main(){
    while(fin >> x){
        n++;
        r += x;
    }
    r = r/n;
    int rasp = 0;
    while(fin1 >> x){
        if(x <= r){
            rasp++;
        }
    }
    fout << rasp;
	return 0;
}
