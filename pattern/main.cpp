#include <iostream>
using namespace std;
bool a[1032][1032];
int n;
void kaka(int latura, int is, int js){
    if(latura > 0){
        for(int i = is; i <= is+latura-1; i++){
            for(int j = js; j <= js+latura-1; j++){
                a[i][j] = 1;
            }
        }
        kaka((latura/2), is, js+latura);
        kaka((latura/2), is+latura, js);
        kaka((latura/2), is+latura, js+latura);
    }
}
int main(){
    cin >> n;
    int p2 = 1 << n;
    kaka(p2/2, 1, 1);
    for(int i = 1; i <= p2; i++){
        for(int j = 1; j <= p2; j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}
