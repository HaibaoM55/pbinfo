#include <fstream>
using namespace std;
ifstream fin("balansoar.in");
ofstream fout("balansoar.out");
long long n;
void fct(long long a[200004], long long b[200004]){
    long long s;
    if(n%4==3){
        s = 3;
	}else{
        s = n%4+4;
	}
	s*=2;
	int j = s/2;
    for(long long i=0;n%4+4*i+4<=n;i++){
        a[j+4*i+1]=s+7;
        a[j+4*i+2]=s+6;
        a[j+4*i+3]=s+4;
        a[j+4*i+4]=s+1;
        b[j+4*i+1]=s+8;
        b[j+4*i+2]=s+5;
        b[j+4*i+3]=s+3;
        b[j+4*i+4]=s+2;
        s+=8;
    }
    for(long long i=n;i>=1;i--){
        fout<<b[i]<<" ";
    }
    for(long long i=1;i<=n;i++){
        fout<<a[i]<<" ";
    }
}
int main()
{
    fin >> n;
    if(n == 1){
        fout << "1\n1 2";
    }else if(n == 2){
        fout << "1\n3 1 4 2";
    }else if(n == 3){
        fout << "0\n5 1 4 3 6 2";
    }else if(n == 4){
        fout << "0\n1 3 8 7 6 5 4 2";
    }else if(n == 5){
        fout << "0\n10 2 1 5 7 8 6 9 4 3";
    }else if(n == 6){
        fout << "0\n11 10 2 1 6 8 7 5 9 4 3 12";
    }else{
        fout << "0\n";
        if(n%4==0){
            long long st[200004] = {0,6,5,4,2};
            long long dr[200004] = {0,7,8,3,1};
            fct(st, dr);
        }
        else if(n%4==1){
            long long st[200004] = {0,7,6,5,4,3};
            long long dr[200004] = {0,10,9,8,2,1};
            fct(st, dr);
        }
        else if(n%4==2){
            long long st[200004] = {0,10,8,7,5,4,3};
            long long dr[200004] = {0,11,12,6,9,2,1};
            fct(st, dr);
        }
        else{
            long long st[200004] = {0,3,6,2};
            long long dr[200004] = {0,4,1,5};
            fct(st, dr);
        }
    }
    return 0;
}
