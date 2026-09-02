#include <fstream>
using namespace std;
ifstream fin("eratostene7.in");
ofstream fout("eratostene7.out");
int n, x, k;
bool cacatdecal(int x, int k){
    for(int i = 2; i*i <= x; i++){
        if(x % i == 0){
         	k--;
            x = x/i;
            if(x % i == 0) return false;
        }
    }
    if(x > 1) k--;
    return k == 0;
}
int main(){
    fin >> n;
    for(int i = 1; i <= n; i++){
    	fin >> x >> k;
        if(cacatdecal(x, k)){
        	fout << "DA";
        }else{
            fout << "NU";
        }
        fout << '\n';
    }
	return 0;
}
