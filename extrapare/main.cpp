#include <fstream>
#include <string.h>
using namespace std;
#pragma GCC optimize("O1")
ifstream fin("extrapare.in");
ofstream fout("extrapare.out");
int n, k;
char v[1000004];
int main()
{
    fin >> n >> k;
    if(k == 0){
        for(int i = 1; i <= n; i++){
            fin >> v;
            int l = strlen(v);
            bool ok = true;
            for(int j = 0; j <= l-1; j++){
                if(v[j] == '1' && j % 2 != 0){
                    ok = false;
                    break;
                }
            }
            if(ok){
                fout << v << '\n';
            }else{
                fout << "-1" << '\n';
            }
        }
    }else{
        for(int i = 1; i <= n; i++){
            fin >> v;
            int l = strlen(v);
            int j2 = l-1;
            for(int j1 = 0; j1 <= (l-1)/2; j1++){
                swap(v[j1],v[j2]);
                j2--;
            }
            bool okm = false;
            int p = 0;
            for(int j = 1; j < l-k; j += 2){
                if(v[j] == '1'){
                    p = j;
                    break;
                }
            }
            if(p == 0){
                int i1=l-k-1;
                while(v[i1] == '0' && i1 > 0){
                    i1--;
                }
                for(int j = i1; j >= 0; j--){
                    fout << v[j];
                }
            }else{
                bool ok = true;
                int i1 = p+k;
                for(int j = i1; j < l; j++){
                    if(v[j] == '1'){
                        if(j%2 != k%2){
                            ok=false;
                        }
                    }
                }
                if(ok == false){
                    fout<< "-1";
                }else{
                    bool merge = false;
                    for(int j = l-1; j >= i1; j--){
                        fout << v[j];
                        merge = true;
                    }
                    if(merge){
                        for(int j = p-1; j >= 0; j--){
                            fout << v[j];
                        }
                    }else{
                        int i2 = p-1;
                        if(i1 > 0){
                            while(v[i2]=='0'){
                                i2--;
                            }
                        }
                        for(int j = i2; j >= 0; j--){
                            fout << v[j];
                        }
                    }
                }
            }
            fout << '\n';
        }
    }
    return 0;
}
