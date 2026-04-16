#include <fstream>
#include <algorithm>
#include <math.h>
#include <map>
using namespace std;
ifstream fin("minish.in");
ofstream fout("minish.out");
int v[28];
bool b[28][32];
int val1=0;
int vmax = 0, vmaxi = 0;
int vmin = 2e9, vmini = 0;
int nrmin = 0;
int cnt = 0;
bool subtask1 = true;
bool verif(int div, int a){
    int r = div;
    while(r < a){
        r += r;
    }
    return r == a;
}
int a1=0, b1=0;
bool bz[100004];
int finaf=0;
bool care = false;
bool mergeb=true;
map<pair<int, int>, pair<int, int>> f;
int finalx=0, finaly=0;
int z = 0;
pair<int, int> rasp[10004];
void kp(int x, int y){
    if(!mergeb){
        return;
    }
    if(x == 0 || y == 0){
        finalx = x;
        finaly = y;
        mergeb = false;
        return;
    }
    if(y % 2 == 0){
        f[{x, y/2}] = {x,y};
        kp(x, y/2);
    }
    if(y >= x){
        f[{x, y-x}] = {x, y};
        kp(x, y-x);
    }
    if(x % 2 == 0){
        f[{x/2, y}] = {x,y};
        kp(x/2, y);
    }
    if(x > y){
        f[{x-y, y}] = {x,y};
        kp(x-y, y);
    }
}
int main(){
    for(int i = 1; i <= 26; i++){
        fin >> v[i];
        if(v[i] > vmax){
            vmax = v[i];
            vmaxi = i;
        }
        if(v[i] > 1){
            subtask1 = false;
        }
        if(v[i] < vmin && v[i] != 0){
            vmin = v[i];
            vmini = i;
        }
        if(v[i] > 0){
            cnt++;
        }
        int x = v[i];
        for(int j = 0; j <= 30; j++){
            b[i][j] = x%2;
            x = x/2;
        }
        if(v[i] == 1){
            val1 = i;
        }
    }
//    for(int i = 1; i <= 26; i++){
//        for(int j = 0; j < 30; j++){
//            fout << b[i][j] << ' ';
//        }
//        fout << '\n';
//    }
    if(subtask1){
        fout << (char) (val1-1+'a') << '=' << 1 << '\n';
        for(int i = 1; i <= 26; i++){
            if(i == val1){
                continue;
            }
            for(int j = 1; j <= v[i]; j++){
                fout << (char) (i-1+'a') << "+=" << (char)(val1-1+'a') << '\n';
            }
        }
        return 0;
    }
    if(cnt == 2){
        int a = 0, b = 0, ai=0, bi=0;
        for(int i = 1; i <= 26; i++){
            if(v[i] > 0){
                if(a == 0){
                    a = v[i];
                    ai = i;
                }else{
                    b = v[i];
                    bi = i;
                }
            }
        }
        if(a > b){
            swap(a, b);
            swap(ai, bi);
        }
        kp(a, b);
        if(finalx > 0){
            fout << (char)(ai-1+'a') << '=' << finalx<<'\n';
        }else{
            fout << (char)(bi-1+'a') << '=' << finaly<<'\n';
        }
        while(true){
            z++;
            rasp[z] = {finalx, finaly};
            //fout << finalx << ' ' << finaly << '\n';
            if(finalx == a && finaly == b){
                break;
            }
            pair<int, int> aux = f[{finalx, finaly}];
            finalx = aux.first;
            finaly = aux.second;
        }
        for(int i = 2; i <= z; i++){
            if(rasp[i-1].first*2 == rasp[i].first && rasp[i-1].first != 0){
                fout << (char) (ai-1+'a') << "+=" << (char) (ai-1+'a');
            }else if(rasp[i-1].second*2 == rasp[i].second && rasp[i-1].second != 0){
                fout << (char) (bi-1+'a') << "+=" << (char) (bi-1+'a');
            }else if(rasp[i-1].first+rasp[i-1].second == rasp[i].first && rasp[i-1].second != 0){
                fout << (char) (ai-1+'a') << "+=" << (char) (bi-1+'a');
            }else if(rasp[i-1].first+rasp[i-1].second == rasp[i].second && rasp[i-1].first != 0){
                fout << (char) (bi-1+'a') << "+=" << (char) (ai-1+'a');
            }
            fout << '\n';
        }
        return 0;
    }
    int vmaxj = 0;
    for(int i = 1; i <= 26; i++){
        for(int j = 0; j <= 30; j++){
            if(b[i][j] && j > vmaxj){
                vmaxj = j;
            }
        }
    }
    int nrf = 1;
    fout << (char) (vmaxi-1+'a') << '=' << 1 << '\n';
    for(int j = 0; j <= vmaxj; j++){
        int val = 0;
        for(int i = 1; i <= 26; i++){
            if(i == vmaxi){
                continue;
            }
            if(b[i][j]){
                fout << (char) (i-1+'a') << "+=" << (char) (vmaxi-1+'a')  << '\n';
            }
        }
        if(j != vmaxj){
            fout << (char) (vmaxi-1+'a') << "+=" << (char) (vmaxi-1+'a') << '\n';
            nrf = nrf*2;
        }
    }
    fout << (char) (vmaxi-1+'a') << '=' << vmax << '\n';

    return 0;
}
