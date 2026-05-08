#include <fstream>
using namespace std;
ifstream fin("a1z26.in");
ofstream fout("a1z26.out");
int cer, n, nr;
char x;
int main(){
    fin >> cer;
    if(cer == 1){
        while(fin >> x){
            fout <<(int) (x-'A'+1) << ' ';
        }
    }else{
        fin >> n;
        for(int i = 0; i < n; i++){
            fin >> nr;
            fout << (char) (nr+'A'-1);
        }
    }
    return 0;
}
