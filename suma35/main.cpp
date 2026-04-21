#include <fstream>
#include <vector>
using namespace std;
ifstream fin("suma35.in");
ofstream fout("suma35.out");
int n;
void kp(int x, int nr3){
    if(x >= 3){
    	kp(x-3, nr3+1);
    }
    if(x % 5 == 0){
        for(int i = 1; i <= nr3; i++){
        	fout << "3 ";
        }
        for(int i = 1; i <= x/5; i++){
        	fout << "5 ";
        }
        fout << '\n';
    }
}
int main(){
    fin >> n;
    kp(n, 0);
    return 0;
}
