#include <fstream>
using namespace std;
ifstream fin("n311.in");
ofstream fout("n311.out");
int n;
int v[104];
int main(){
    fin >> n;
    int x = n;
    int i = 0;
    while(x > 1){
        if(x % 3 == 0){
            i++;
            v[i] = 3;
            x = x/3;
        }else{
            for(int j = 1; j <= x%3; j++){
                i++;
                v[i] = 1;
                x--;
            }
        }
    }
    for(i; i >= 1; i--){
        fout << v[i] << ' ';
    }
    return 0;
}
