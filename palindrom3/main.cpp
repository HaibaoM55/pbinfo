#include <fstream>
using namespace std;
ifstream fin("palindrom3.in");
ofstream fout("palindrom3.out");
int n;
int f[12];
int l = 0;
int main()
{
    fin >> n;
    do{
        f[n%10]++;
        n = n/10;
        l++;
    }while(n > 0);
    int k = -1;
    int z = 0;
    for(int j = 9; j >= 0; j--){
        if(f[j] % 2 != 0){
            k = j;
        }
        for(int i = 1; i <= f[j]/2; i++){
            fout << j;
        }
    }
    if(k >= 0){
        fout << k;
    }
    for(int j = 0; j <= 9; j++){
        if(f[j] % 2 != 0){
            k = j;
        }
        for(int i = 1; i <= f[j]/2; i++){
            fout << j;
        }
    }
    return 0;
}
