#include <fstream>
#include <string.h>
using namespace std;
ifstream fin("cifre12.in");
ofstream fout("cifre12.out");
int c;
unsigned long long n;
int cif[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int cif1[10] ={1, 5, 1, 2, 2, 3, 1, 2, 0, 0};
int cif2[10] ={2, 7, 2, 3, 3, 4, 2, 5, 1, 2};
int f[10];
char ni[20];
int nr[20];
unsigned long long s=0;
int main()
{
    fin >> c;
    if(c == 1){
        fin >> n;
        int s = 0;
        do{
            s = s + cif[n%10];
            n = n / 10;
        }while(n > 0);
        fout << s;
    }else{
        fin >> ni;
        int l = strlen(ni);
        for(int i = 0; i < l; i++){
            nr[i+1] = ni[i]-'0';
        }
        for(int i = 1; i <= l; i++){
            unsigned long long pr = 1;
            for(int j = i+1; j <= l; j++){
                pr = pr*cif2[nr[j]];
            }
            s = s + cif1[nr[i]]*pr;
        }
        fout << s;
    }
    return 0;
}
