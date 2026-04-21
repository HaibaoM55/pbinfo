#include <fstream>
#include <vector>
using namespace std;
ifstream fin("partitiinumar1.in");
ofstream fout("partitiinumar1.out");
int n;
void kp(int x, vector<int> v, int vmax){
    if(x == 0){
        for(int i = 1; i <= v[0]; i++){
            fout << v[i] << ' ';
        }
        fout << '\n';
    }else{
        v[0]++;
        for(int i = vmax+1; i <= x; i++){
            v[v[0]] = i;
            kp(x-i, v, i);
        }
    }
}
vector<int> clearv(67);
int main(){
    fin >> n;
    kp(n, clearv, 0);
    return 0;
}
