#include <fstream>
using namespace std;
ifstream fin("sierpinski.in");
ofstream fout("sierpinski.out");
bool sierpinski(int i, int j, int n){
    int p = 1;
    for(int i = 1; i <= n; i++){
        p = p*3;
    }
    int x = p/2+1, y = p/2+1;
    if(x-p/6 <= i && i <= x+p/6){
        if(y-p/6 <= j && j <= y+p/6){
            return 1;
        }
    }
    if(n == 1){
        return 0;
    }else{
        int i1, j1;
        if(1 <= i && i <= p/3){
            i1 = i;
        }else if(p/3+1 <= i && i <= (2*p)/3){
            i1 = i-p/3;
        }else{
            i1 = i-(2*p)/3;
        }
        if(1 <= j && j <= p/3){
            j1 = j;
        }else if(p/3+1 <= j && j <= (2*p)/3){
            j1 = j-p/3;
        }else{
            j1 = j-(2*p)/3;
        }
        return sierpinski(i1, j1, n-1);
    }
}
int n;
int main(){
    fin >> n;
    int p = 1;
    for(int i = 1; i <= n; i++){
        p = p*3;
    }
    for(int i = 1; i <= p; i++){
        for(int j = 1; j <= p; j++){
            fout << sierpinski(i, j, n) << ' ';
        }
        fout << '\n';
    }
    return 0;
}
