#include <fstream>
using namespace std;
ifstream fin("div3.in");
ofstream fout("div3.out");
bool estedivcu3(int x){
    int s = 0;
    do{
        s += x%10;
        x = x/10;
    }while(x > 0);
    if(s % 3 == 0){
    	return true;
    }
    return false;
}
int n, x;
int main(){
	fin >> n;
    for(int i = 1; i <= n; i++){
    	fin >> x;
        if(estedivcu3(x)){
        	fout << x << ' ';
        }
    }
    return 0;
}
