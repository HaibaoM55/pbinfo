#include <fstream>
using namespace std;
ifstream fin("rabin-miller.in");
ofstream fout("rabin-miller.out");
unsigned long long n;
int main(){
    fin >> n;
    bool esteprim=true;
    for(int i = 2; i*i <= n; i++){
        if(n % i == 0){
            esteprim = false;
            break;
        }
    }
    if(esteprim){
    	fout << "DA";
    }else{
        fout << "NU";
    }
	return 0;
}   
