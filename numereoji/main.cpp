#include <fstream>
using namespace std;
ifstream fin("numereoji.in");
ofstream fout("numereoji.out");
int v[14];
bool x1[14], x2[14];
int nr = 0;
int main()
{
    for(int i = 1; i <= 10; i++){
        fin >> v[i];
    }
    /*
    3^10->
    1...59048
    34502 11500 3833 1277 425 141 47 15 5 1
    2 1 2 2 2 0 2 0 2 1
    */
    int s1 = 0, s2 = 0;
    int smax = 0;
    for(int i = 1; i <= 59048; i++){
        int x = i;
        s1 = 0;
        s2 = 0;
        for(int j = 1; j <= 10; j++){
            if(x%3 == 1){
                s1 += v[j];
            }else if(x % 3 == 2){
                s2 += v[j];
            }
            x = x / 3;
        }
        if(s1 == s2){
            nr++;
            if(s1 > smax){
                smax = s1;
                x = i;
                for(int j = 1; j <= 10; j++){
                    x1[j] = false;
                    x2[j] = false;
                    if(x%3 == 1){
                        x1[j] = true;
                    }else if(x % 3 == 2){
                        x2[j] = true;
                    }
                    x = x / 3;
                }
            }
        }
    }
    fout << nr/2 << ' ' << smax << '\n';
    for(int i = 1; i <= 10; i++){
        if(x1[i]){
            fout << v[i] << ' ';
        }
    }
    fout << '\n';
    for(int i = 1; i <= 10; i++){
        if(x2[i]){
            fout << v[i] << ' ';
        }
    }
    return 0;
}
