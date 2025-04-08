#include <fstream>
#include <math.h>
using namespace std;
ifstream fin("pavare1.in");
ofstream fout("pavare1.out");
int c, n;
int f[50004];
int main(){
    fin >> c;
    fin >> n;
    //1+2+...+x1=n1
    /*
        x1*(x1+1)/2=n1
        x1^2+x1=2*n1
        x1^2+x1-2*n1=0
        delta = 1+8*n1
        x1 = (-b+sqrt(delta))/2;
        x1 = (sqrt(1+8*n1)-b)/2;
    */
    if(c == 1){
        int n1 = n/2;
        int x1 = (sqrt(1+8*n1)-1)/2;
        for(int i = 1; i <= x1; i++){
            f[i]++;
        }
        int z = x1*(x1+1)/2;
        z = n1-z;
        if(z > 0){
            f[z]++;
        }
        int n2 = n/2+n%2;
        int x2 = (sqrt(1+8*n2)-1)/2;
        for(int i = 1; i <= x2; i++){
            f[i]++;
        }
        z = x2*(x2+1)/2;
        z = n2-z;
        if(z > 0){
            f[z]++;
        }
        for(int i = 1; i <= x2; i++){
            if(f[i] >= 3){
                if(x2-i+1 != i){
                    if(f[x2-i+1] >= 3){
                        f[x2-i+1]--;
                        f[i]--;
                        x2++;
                        f[x2]++;
                    }
                }else{
                    if(f[x2-i+1] >= 4){
                        f[x2-i+1]--;
                        f[i]--;
                        x2++;
                        f[x2]++;
                    }
                }
                for(int j = x2-i; j >= 1; j--){
                    if(i == j && f[j] >= 4){
                        f[j] -= 2;
                        f[2*j]++;
                    }else if(i != j && f[j] >= 3){
                        f[j]--;
                        f[i]--;
                        f[i+j]++;
                    }
                }
            }
        }
        int s = 0;
        for(int i = 1; i <= x2; i++){
            s += f[i];
        }
        fout << s;
    }else{
        int x=1, s = 1;
        while(s <= n){
            s += 2 * x + 1;
            x++;
        }
        x--;
        s -= (2 * x + 1);
        int nr = 2 * x - 1;
        s = n - s;
        int nr1 = -1;
        int nr2 = -1;
        if(s > 0 && s <= x){
            nr++;
            nr1 = s;
        }else if(s > x){
            nr += 2;
            nr1 = s - x;
            nr2 = x;
        }
        for(int i = 1; i <= x; i++){
            fout << i << ' ';
            if(nr1 == i){
                fout << i << ' ';
            }
            if(nr2 == i){
                fout << i << ' ';
            }
        }
        for(int i = x - 1; i >= 1; i--){
            fout << i << ' ';
        }
    }
    return 0;
}
