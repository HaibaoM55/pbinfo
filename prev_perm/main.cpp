#include <algorithm>
using namespace std;
void prev_perm(int n, int P[]){
    prev_permutation(P+1, P+n+1);
}
