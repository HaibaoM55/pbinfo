#include <iostream>
#define p1 9999991
#define p2 9999973
using namespace std;
int n, s;
int sp[1000004];
int f1[10000004];
int f2[10000004];
long long nr = 0;
int main()
{
    cin >> n >> s;
    f1[1000000000%p1] = 1;
    f2[1000000000%p2] = 1;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        sp[i] = sp[i-1]+x;
        if(sp[i]-s+1000000000 >= 0){
            unsigned int y1 = (sp[i]+1000000000-s)%p1;
            unsigned int y2 = (sp[i]+1000000000-s)%p2;
            if(f1[y1] > 0){
                nr += f1[y1];
            }
        }
        f1[(sp[i]+1000000000)%p1]++;
        f2[(sp[i]+1000000000)%p2]++;
    }
    cout << nr;
    return 0;
}
