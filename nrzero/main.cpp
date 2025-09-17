#include <iostream>
using namespace std;
int NrZero(int a[], int n){
	int p1 = 1, p2 = n;
    int p = -1;
    while(p1 <= p2){
        int mij = (p1+p2)/2;
        if(a[mij] % 2 != 0){
            p1 = mij+1;
        }else{
            p = mij;
            p2 = mij-1;
        }
    }
    p1 = p, p2 = n;
    int pf = p-1;
    while(p1 <= p2){
        int mij = (p1+p2)/2;
        if(a[mij] == 0){
            p1 = mij+1;
            pf = mij;
        }else{
            p2 = mij-1;
        }
    }
    return pf-p+1;
}/*
int main()
{
    int obamahavdih[67] = {7,1,2,2,4,4,8};
    cout << NrZero(obamahavdih, 7);
    return 0;
}
*/
