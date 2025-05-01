#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("halfsort2.in");
ofstream fout("halfsort2.out");
int n;
int a[54], b[54];
bool compara(int a, int b){
    return b < a;
}
int main(){
    fin >> n;
    for(int i = 1; i <= n; i++){
        if(i% 2 == 0){
            fin >> a[i/2];
        }else{
            fin >> b[i/2+1];
        }
    }
    sort(a+1, a+n/2+1);
    sort(b+1, b+n/2+1, compara);
    for(int i = 1; i <= n; i++){
        if(i % 2== 0){
        	fout << a[i/2] << ' ';
        }else{
            fout << b[i/2+1] << ' ';
        }
    }
    return 0;
}
