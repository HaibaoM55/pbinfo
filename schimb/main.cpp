#include <fstream>
#include <string.h>
using namespace std;
ifstream fin("schimb.in");
ofstream fout("schimb.out");
int n, k, p;
char x[504];
int nr =0 ;
int main(){
    fin >> n >> k >> p;
    p--;
    while(fin >> x){
        nr++;
        int l = strlen(x);
        if(l >= k){
            x[k-1] = (char)(p+'a');
            fout << x;
        }else{
            for(int i = l-1; i >= 0; i--){
                fout << x[i];
            }
        }
        fout << '\n';
    }
    return 0;
}
