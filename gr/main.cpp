#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("gr.in");
ofstream fout("gr.out");
int n;
int a[1000004], b[1000004];
int main()
{
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        fin >> b[i];
    }
    int vmax = 0;
    int r=0;
    int c=0;
    for(int i=1; i <= n;i++){
        if(a[i] == c){
            c = 0;
        }else if(a[i] < c){
            r = max(r,a[i]);
        }else{
            r = max(r,c);
            c = a[i];
        }
    }
    vmax = max(r, c);
    r=0;
    c=0;
    for(int i=1; i <= n;i++){
        if(b[i] == c){
            c = 0;
        }else if(b[i] < c){
            r = max(r,b[i]);
        }else{
            r = max(r,c);
            c = b[i];
        }
    }
    vmax = max(vmax, r);
    vmax = max(vmax, c);
    fout << vmax;
    return 0;
}
