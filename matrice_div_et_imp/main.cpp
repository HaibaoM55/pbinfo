#include <fstream>
using namespace std;
ifstream cin("matrice_div_et_imp.in");
ofstream cout("matrice_div_et_imp.out");
int n;
int a[1041][1041];
void citeste(int i1, int j1, int i2, int j2){
    if(i1 == 0 || j1 == 0 || i2 == 0 || j2 == 0){
        return;
    }
    if(i1 > i2 || j1 > j2){
        return;
    }
    if(i2 == i1+1 && j2 == j1+1){
        cout << a[i1][j1] << ' ' << a[i2][j2] << ' ' << a[i1][j2] << ' '<<a[i2][j1] << ' ';
        return;
    }
    if(i1 == j1 && j1 == i2 && i2 == j2){
        cout << a[i1][j1] << ' ';
    }else{
        int l = (i2-i1+1)/2;
        citeste(i1, j1, i1+l-1, j1+l-1);
        citeste(i1+l,j1+l,i2,j2);
        citeste(i1,j1+l,i1+l-1,j2);
        citeste(i1+l,j1,i2,j1+l-1);
    }
}
int main(){
    cin >> n;
    int p = 1;
    for(int i = 1; i <= n; i++){
        p = p*2;
    }
    for(int i = 1; i <= p; i++){
        for(int j = 1; j <= p; j++){
            cin >> a[i][j];
        }
    }
    citeste(1,1,p,p);
    return 0;
}
