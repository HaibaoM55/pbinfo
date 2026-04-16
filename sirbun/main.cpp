#include <fstream>
using namespace std;
ifstream fin("sirbun.in");
ofstream fout("sirbun.out");
int n;
int v[100004];
int aib[100004];
void update(int poz, int val){
    for(; poz <= n; poz += poz&(-poz)){
        aib[poz] += val;
    }
}
int query(int poz){
    int rasp = 0;
    for(; poz >= 1; poz -= poz&(-poz)){
        rasp += aib[poz];
    }
    return rasp;
}
int main(){
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
        aib[i] = 0;
    }
    int nr = 0;
    int p1 = 0;
    for(int i = 1; i <= n; i++){
        if(p1 < i){
            p1 = i-1;
        }
        while(p1+1 <= n){
            update(v[p1+1], 1);
            bool mergef = true;
            if(n <= 7000){
                for(int j = v[p1+1]; j <= n; j++){
                    if(query(j) > j){
                        mergef = false;
                        break;
                    }
                }
            }else{
                if(query(v[p1+1]) > v[p1+1]){
                    mergef = false;
                }
            }
            if(!mergef){
                update(v[p1+1], -1);
                break;
            }
            p1++;
        }
        nr += (p1-i+1);
        if(p1 >= i){
            update(v[i], -1);
        }
    }
    fout << nr;
    return 0;
}
