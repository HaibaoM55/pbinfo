#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    char x[260];
    cin.get(x, 260);
    int l = strlen(x);
    vector<string> cuvinte_identice;
    string cuvant;
    for (int i = 0; i < l; i++) {
        if ('a' <= x[i] && x[i] <= 'z') {
            cuvant += x[i];
        }else{
            if (!cuvant.empty()) {
                bool ok = true;
                for(int j = 1; j < cuvant.size(); j++){
                    if (cuvant[j] != cuvant[0]) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    cuvinte_identice.push_back(cuvant);
                }
                cuvant.clear();
            }
        }
    }
    if (!cuvant.empty()) {
        bool ok = true;
        for (int j = 1; j < cuvant.size(); j++) {
            if (cuvant[j] != cuvant[0]) {
                ok = false;
                break;
            }
        }
        if(ok){
            cuvinte_identice.push_back(cuvant);
        }
    }
    if(!cuvinte_identice.empty()){
        sort(cuvinte_identice.begin(), cuvinte_identice.end());
        for (const string& cuvant : cuvinte_identice) {
            cout << cuvant << '\n';
        }
    }else{
        cout << "nu exista";
    }
    return 0;
}
