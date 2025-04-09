#include <fstream>
using namespace std;
ifstream fin("sstabil.in");
ofstream fout("sstabil.out");
int n;
int v[1000004];
int a[1000004];
int main(){
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
    }
    int z = 0;
    a[0] = 9;
    v[0] = 9;
    for(int i = n; i >= 1; i--){
        int s = 0;
        int aux = i;
        while(s < 10){
            s += v[aux];
            aux--;
        }
        int x = v[i];
        while((s-x>9 || x+a[z]<10)){
            i--;
            x+=v[i];
        }
        z++;
        a[z] = x;
    }
    for(int i = z; i >= 1; i--){
        fout << a[i];
    }
    return 0;
}
