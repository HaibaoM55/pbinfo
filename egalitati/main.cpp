#include <fstream>
#include <string.h>
using namespace std;
ifstream fin("egalitati.in");
ofstream fout("egalitati.out");
int n;
struct litera{
    bool exista = false;
    int nrop1=-1, nrop2=-1;
    bool operator1=true;
    bool cif1=true, cif2=true;
    int calc = -1;
}a[40];
char x[40];
int main(){
    fin >> n;
    fin.get();
    for(int i =1; i <= n; i++){
        fin.get(x, 40);
        fin.get();
        int l = strlen(x);
        int nrop=-1, nrop1=-1, nrop2=-1;
        bool operator1=true;
        for(int j = 0; j < l; j++){
            if('a' <= x[j] && x[j] <= 'z'){
                if(nrop == -1){
                    nrop = x[j]-'a';
                }else if(nrop1 == -1){
                    nrop1 = x[j]-'a';
                    a[nrop].cif1 = false;
                }else{
                    nrop2 = x[j]-'a';
                    a[nrop].cif2 = false;
                }
            }else if('0' <= x[j] && x[j] <= '9'){
                int nr = 0;
                while('0' <= x[j] && x[j] <= '9'){
                    nr = nr*10+(x[j]-'0');
                    j++;
                }
                if(nrop1 == -1){
                    nrop1 = nr;
                }else{
                    nrop2 = nr;
                }
                j--;
            }
            if(x[j] == '+'){
                operator1=true;
            }else if(x[j] == '*'){
                operator1=false;
            }
        }
        a[nrop].exista = true;
        a[nrop].nrop1 = nrop1;
        a[nrop].nrop2 = nrop2;
        a[nrop].operator1 = operator1;
    }
    bool x = true;
    while(x){
        x = false;
        for(int i = 0; i <= 25; i++){
            if(a[i].exista && a[i].calc == -1){
                if(a[i].nrop2 == -1){
                    if(a[i].cif1){
                        a[i].calc = a[i].nrop1;
                    }else{
                        if(a[a[i].nrop1].calc != -1){
                            a[i].calc = a[a[i].nrop1].calc;
                        }
                    }
                }else{
                    if(a[i].cif1){
                        if(a[i].cif2){
                            if(a[i].operator1){
                                a[i].calc = a[i].nrop1+a[i].nrop2;
                            }else{
                                a[i].calc = a[i].nrop1*a[i].nrop2;
                            }
                        }else{
                            if(a[a[i].nrop2].calc != -1){
                                if(a[i].operator1){
                                    a[i].calc = a[a[i].nrop2].calc+a[i].nrop1;
                                }else{
                                    a[i].calc = a[a[i].nrop2].calc*a[i].nrop1;
                                }
                            }
                        }
                    }else{
                        if(a[a[i].nrop1].calc != -1){
                            if(a[i].cif2){
                                if(a[i].operator1){
                                    a[i].calc = a[a[i].nrop1].calc+a[i].nrop2;
                                }else{
                                    a[i].calc = a[a[i].nrop1].calc*a[i].nrop2;
                                }
                            }else{
                                if(a[a[i].nrop2].calc != -1){
                                    if(a[i].operator1){
                                        a[i].calc = a[a[i].nrop1].calc+a[a[i].nrop2].calc;
                                    }else{
                                        a[i].calc = a[a[i].nrop1].calc*a[a[i].nrop2].calc;
                                    }
                                }
                            }
                        }
                    }
                }
                if(a[i].calc == -1){
                    x = true;
                }
            }
        }
    }
    for(int i = 0; i <= 25; i++){
        if(a[i].calc != -1){
            fout << (char) (i+'a') << " = " << a[i].calc << "\n";
        }
    }
    return 0;
}
