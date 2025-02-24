#include <vector>
using namespace std;
vector<long long> solve(
	int N, int Q,
	vector<int> A,
	vector<int> L,
	vector<int> R,
	vector<int> M
){
    vector<long long> S;
    vector<long long> sp;
    bool ok = true;
    for(int i = 1; i < Q; i++){
        if(M[i] != M[i-1]){
            ok = false;
            break;
        }
    }
    if(ok){
        //subtask 2
        sp.push_back(A[0]%M[0]);
        for(int i = 1; i < N; i++){
            sp.push_back(sp[i-1]+A[i]%M[0]);
        }
        for(int i = 0; i < Q; i++){
            long long sm;
            if(L[i] > 0){
                sm = sp[R[i]]-sp[L[i]-1];
            }else{
                sm = sp[R[i]];
            }
            S.push_back(sm);
        }
    }
    else if(N <= 1000 && Q <= 1000){
        //subtask 1
        for(int i = 0; i < Q; i++){
            long long sm = 0;
            for(int j = L[i]; j <= R[i]; j++){
                sm = sm+(A[j]%M[i]);
            }
            S.push_back(sm);
        }
    }else{
        //subtask 3
        vector<long long> sumap[304];
        for(int j = 1; j <= 304; j++){
            sumap[j].push_back(A[0]%j);
            for(int i = 1; i < N; i++){
                sumap[j].push_back(sumap[j][i-1]+A[i]%j);
            }
        }
        for(int i = 0; i < Q; i++){
            long long sm;
            if(L[i] > 0){
                sm = sumap[M[i]][R[i]]-sumap[M[i]][L[i]-1];
            }else{
                sm = sumap[M[i]][R[i]];
            }
            S.push_back(sm);
        }
    }
    return S;
}
