#include <iostream>
using namespace std;
#define vizv coada[dr].ind = st;
#define vizf vizitat[coada[dr].a][coada[dr].b] = true;
struct coadastr{
    int a, b;
    int op;
    int ind;
}coada[1000004];
bool vizitat[1004][1004];
int A, B, C;
int st = 1, dr = 1;
void operatie(int x){
    if(x == 1) cout << "R A";
    if(x == 2) cout << "R B";
    if(x == 3) cout << "A C";
    if(x == 4) cout << "B C";
    if(x == 5) cout << "A B";
    if(x == 6) cout << "B A";
}
int v[1000004];
int main(){
    cin >> A >> B >> C;
    coada[1].a = 0;
    coada[1].b = 0;
    coada[1].ind = -1;
    vizitat[0][0] = true;
    int indice = -1;
    while(st <= dr){
        if(coada[st].a == C || coada[st].b == C){
            indice = st;
            break;
        }
        int a = coada[st].a;
        int b = coada[st].b;
        if(!vizitat[A][b]){
            dr++;
            coada[dr].a = A;
            coada[dr].b = b;
            coada[dr].op = 1; // R A
            vizitat[0][b] = true;
            vizv
            vizf
        }
        if(!vizitat[a][B]){
            dr++;
            coada[dr].a = a;
            coada[dr].b = B;
            coada[dr].op = 2; //R B
            vizv
            vizf
        }
        if(!vizitat[0][b]){
            dr++;
            coada[dr].a = 0;
            coada[dr].b = b;
            coada[dr].op = 3; //A C
            vizv
            vizf
        }
        if(!vizitat[a][0]){
            dr++;
            coada[dr].a = a;
            coada[dr].b = 0;
            coada[dr].op = 4; //B C
            vizv
            vizf
        }
        if(a+b <= B){
            if(!vizitat[0][a+b]){
                dr++;
                coada[dr].a = 0;
                coada[dr].b = a+b;
                coada[dr].op = 5; //A B
                vizv
                vizf
            }
        }else{
            if(!vizitat[a+b-B][B]){
                dr++;
                coada[dr].a = a+b-B;
                coada[dr].b = B;
                coada[dr].op = 5; //A B
                vizv
                vizf
            }
        }
        if(a+b <= A){
            if(!vizitat[a+b][0]){
                dr++;
                coada[dr].a = a+b;
                coada[dr].b = 0;
                coada[dr].op = 6; //B A
                vizv
                vizf
            }
        }else{
            if(!vizitat[A][a+b-A]){
                dr++;
                coada[dr].a = A;
                coada[dr].b = a+b-A;
                coada[dr].op = 6; //B A
                vizv
                vizf
            }
        }
        st++;
    }
    int nr = 0;
    while(coada[indice].ind != -1){
        nr++;
        v[nr] = coada[indice].op;
        indice = coada[indice].ind;
    }
    cout << nr << '\n';
    for(int i = nr; i >= 1; i--){
        operatie(v[i]);
        cout << '\n';
    }
    return 0;
}
