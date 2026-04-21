#include <fstream>
#include <vector>
using namespace std;
ifstream fin("partitiinumar.in");
ofstream fout("partitiinumar.out");
int n;
void kp(int x, vector<int> v, int vmax){
    if(x == 0){
        for(int i = 1; i <= v[0]; i++){
            fout << v[i] << ' ';
        }
        fout << '\n';
    }else{
        v[0]++;
        for(int i = vmax; i <= x; i++){
            v[v[0]] = i;
            kp(x-i, v, i);
        }
    }
}
vector<int> clearv(67);
int main(){
    fin >> n;
    kp(n, clearv, 1);
    return 0;
}
