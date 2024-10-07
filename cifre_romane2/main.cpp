#include <fstream>
#include <string.h>
using namespace std;
ifstream fin("cifre_romane2.in");
ofstream fout("cifre_romane2.out");
int a, b;
int c;
int x[20];
char v[50];
int s = 0;
char x1[20] = "IVXLCDMVXLCDM";
int putere[20] = {1, 5, 10, 50, 100, 500, 1000, 5000, 10000, 50000, 100000, 500000, 1000000};int main()
{
    fin >> c;
    if(c == 1){
        fin >> a;
        b = a;
        int z = 0;
        int nr = 1;
        do{
           z++;
           x[z] = b%10;
           nr *= 10;
           b = b/10;
        }while(b > 0);
        for(int i = z; i >= 1; i--){
            nr /= 10;
            if(nr == 1){
                if(x[i] == 1 || x[i] == 2 || x[i] == 3){
                    for(int j = 1; j <= x[i]; j++){
                        fout << "I";
                    }
                }else if(x[i] == 4){
                    fout << "IV";
                }else if(x[i] == 5){
                    fout << "V";
                }else if(x[i] == 6){
                    fout << "VI";
                }else if(x[i] == 7){
                    fout << "VII";
                }else if(x[i] == 8){
                    fout << "VIII";
                }else{
                    fout << "IX";
                }
            }else if(nr == 10){
                if(x[i] == 1 || x[i] == 2 || x[i] == 3){
                    for(int j = 1; j <= x[i]; j++){
                        fout << "X";
                    }
                }else if(x[i] == 4){
                    fout << "XL";
                }else if(x[i] == 5){
                    fout << "L";
                }else if(x[i] == 6){
                    fout << "LX";
                }else if(x[i] == 7){
                    fout << "LXX";
                }else if(x[i] == 8){
                    fout << "LXXX";
                }else{
                    fout << "XC";
                }
            }else if(nr == 100){
                if(x[i] == 1 || x[i] == 2 || x[i] == 3){
                    for(int j = 1; j <= x[i]; j++){
                        fout << "C";
                    }
                }else if(x[i] == 4){
                    fout << "CD";
                }else if(x[i] == 5){
                    fout << "D";
                }else if(x[i] == 6){
                    fout << "DC";
                }else if(x[i] == 7){
                    fout << "DCC";
                }else if(x[i] == 8){
                    fout << "DCCC";
                }else{
                    fout << "CM";
                }
            }else if(nr == 1000){
                if(x[i] == 1 || x[i] == 2 || x[i] == 3){
                    for(int j = 1; j <= x[i]; j++){
                        fout << "M";
                    }
                }else if(x[i] == 4){
                    fout << "M(V)";
                }else if(x[i] == 5){
                    fout << "(V)";
                }else if(x[i] == 6){
                    fout << "(V)M";
                }else if(x[i] == 7){
                    fout << "(V)MM";
                }else if(x[i] == 8){
                    fout << "(V)MMM";
                }else{
                    fout << "M(X)";
                }
            }else if(nr == 10000){
                if(x[i] == 1 || x[i] == 2 || x[i] == 3){
                    for(int j = 1; j <= x[i]; j++){
                        fout << "(X)";
                    }
                }else if(x[i] == 4){
                    fout << "(X)(L)";
                }else if(x[i] == 5){
                    fout << "(L)";
                }else if(x[i] == 6){
                    fout << "(L)(X)";
                }else if(x[i] == 7){
                    fout << "(L)(X)(X)";
                }else if(x[i] == 8){
                    fout << "(L)(X)(X)(X)";
                }else{
                    fout << "(X)(C)";
                }
            }else if(nr == 100000){
                if(x[i] == 1 || x[i] == 2 || x[i] == 3){
                    for(int j = 1; j <= x[i]; j++){
                        fout << "(C)";
                    }
                }else if(x[i] == 4){
                    fout << "(C)(D)";
                }else if(x[i] == 5){
                    fout << "(D)";
                }else if(x[i] == 6){
                    fout << "(D)(C)";
                }else if(x[i] == 7){
                    fout << "(D)(C)(C)";
                }else if(x[i] == 8){
                    fout << "(D)(C)(C)(C)";
                }else{
                    fout << "(C)(M)";
                }
            }else{
                if(x[i] == 1 || x[i] == 2 || x[i] == 3){
                    for(int j = 1; j <= x[i]; j++){
                        fout << "(M)";
                    }
                }
            }
        }
    }else{
        fin >> v;
        int l = strlen(v);
        bool pv = true;
        for(int i = 0; i < l; i++){
            pv = false;
            if(v[i] == '('){
                i++;
                pv = true;
            }
            int loc = 0;
            if(pv){
                for(int i = 7; i <= 13; i++){
                    if(x1[i] == v[i]){
                        loc = i;
                        break;
                    }
                }
            }else{
                for(int i = 0; i <= 6; i++){
                    if(x1[i] == v[i]){
                        loc = i;
                        break;
                    }
                }
            }
            if(v[i+1] == ')'){
                i++;
            }
        }
    }
    return 0;
}
