#include <iostream>
#include <algorithm>
using namespace std;
struct cif{
    int nrcifra = 0;
    int nraparitii = 0;
}c[11];
int n,x;
bool compara(cif a, cif b){
    if(a.nraparitii < b.nraparitii){
        return true;
    }else if(a.nraparitii == b.nraparitii){
        if(a.nrcifra < a.nrcifra){
            return true;
        }
    }
    return false;
}
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> x;
        int y = x;
        do{
            c[y%10].nrcifra = y%10;
            c[y%10].nraparitii++;
            y = y / 10;
        }while(y > 0);
    }
    sort(c, c+10, compara);
    for(int i = 0; i <= 9; i++){
        if(c[i].nraparitii > 0){
            cout << c[i].nrcifra << ' ';
        }
    }
    return 0;
}
