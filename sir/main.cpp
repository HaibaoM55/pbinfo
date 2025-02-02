#include <fstream>
using namespace std;
ifstream fin("sir.in");
ofstream fout("sir.out");
int n;
int a[100004];
bool b1[100004], b2[100004];
int main()
{
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> a[i];
    }
    int s = a[n];
    for(int i = n-1; i >= 1; i--){
        if(a[i] <= s){
            s = s-a[i];
            b1[i] = true;
        }else{
            s = a[i]-s;
            b2[i] = true;
        }
    }
    bool x = false;
    for(int i = 1; i <= n; i++){
        if(b1[i] != x){
            fout << '-';
        }else{
            fout<<'+';
        }
        if(b2[i] != x){
            x = true;
        }else{
            x = false;
        }
    }
    return 0;
}
