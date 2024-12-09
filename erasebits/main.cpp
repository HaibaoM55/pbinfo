#include <iostream>
using namespace std;
long long n;
int main()
{
    cin >> n;
    long long i = n;
    do{
        i = i-((i ^ (i - 1)) & i);
        cout << i <<' ';
    }while(i);
    return 0;
}
