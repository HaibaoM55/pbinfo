#include <iostream>
using namespace std;
int a, b, x, y, z, nr, c, d;
int main()
{
    cin >> a >> b;
    for(x=b/a;x<=3*b/a;x++)
    {
        for(y=x;y<=50000;y++)
        {
            ///1/z = a/b-1/x-1/y
            c=b*x*y;
            d=a*x*y-b*y-b*x;
            if(d!=0 && c%d==0)
            {
                z=c/d;
                if(y<=z)
                {
                    nr++;
                    cout<<x<<" "<<y<<" "<<z<<"\n";
                }
            }
        }
    }
    if(nr==0)
    {
        cout<<"NU ARE SOLUTII";
    }
    return 0;
}
