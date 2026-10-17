#include <fstream>
using namespace std;
ifstream fin("determinant.in");
ofstream fout("determinant.out");
int n;
int a[14][14];
int det(int x, int m[14][14]){
    if(x == 2){
        return (m[1][1]*m[2][2])-(m[1][2]*m[2][1]);
    }
    int s = 0;
    for(int i = 1; i <= x; i++){
        int b[14][14];
        for(int i1 = 2; i1 <= x; i1++){
            int j = 0;
            for(int j1 = 1; j1 <= x; j1++){
                if(j1 == i) continue;
                j++;
                b[i1-1][j] = m[i1][j1];
                //fout << b[i1-1][j] << ' ';
            }
            //fout << '\n';
        }
        //fout << '\n';
        if(i % 2 == 1){
            s += m[1][i]*det(x-1, b);
        }else{
            s -= m[1][i]*det(x-1, b);
        }
    }
    return s;
}
int main(){
    fin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            fin >> a[i][j];
        }
    }
    fout << det(n, a);
    return 0;
}
