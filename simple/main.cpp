#include <iostream>
using namespace std;
long long v[200005],i,q,n,minpar,maximp;
long long t, a, b, x;
struct elem{
    long long minpar,minimpar,maximpar,maxpar,lazy;
}A[800004];
void updatelazy(int nod,long long st,long long dr)
{
    if (A[nod].lazy>0)
    {
        if (A[nod].lazy%2==1)
        {
            swap(A[nod].minimpar,A[nod].minpar);
            swap(A[nod].maxpar,A[nod].maximpar);
        }

            if (A[nod].minimpar!=-1)
                A[nod].minimpar+=A[nod].lazy;

            if (A[nod].maximpar!=-1)
                A[nod].maximpar+=A[nod].lazy;

            if (A[nod].minpar!=-1)
                A[nod].minpar+=A[nod].lazy;

            if (A[nod].maxpar!=-1)
                A[nod].maxpar+=A[nod].lazy;
    }

    if (st!=dr)
    {
        A[2*nod].lazy+=A[nod].lazy;
        A[2*nod+1].lazy+=A[nod].lazy;
    }

    A[nod].lazy=0;
}


void updatenod(int nod)
{
    A[nod].maximpar=max(A[2*nod].maximpar,A[2*nod+1].maximpar);

    A[nod].maxpar=max(A[2*nod].maxpar,A[2*nod+1].maxpar);

    A[nod].minpar=A[2*nod].minpar;

    if (A[2*nod+1].minpar!=-1)
    {
        if (A[nod].minpar==-1)
            A[nod].minpar=A[2*nod+1].minpar;
        else
            A[nod].minpar=min(A[2*nod+1].minpar,A[nod].minpar);
    }

    A[nod].minimpar=A[2*nod].minimpar;

    if (A[2*nod+1].minimpar!=-1)
    {
        if (A[nod].minimpar==-1)
            A[nod].minimpar=A[2*nod+1].minimpar;
        else
            A[nod].minimpar=min(A[2*nod+1].minimpar,A[nod].minimpar);
    }

}

void build(int nod, long long st ,long long dr)
{
    if (st==dr)
    {
        A[nod].lazy=0;
        if (v[st]%2==0)
        {
            A[nod].minpar=v[st];
            A[nod].maxpar=v[st];
            A[nod].minimpar=-1;
            A[nod].maximpar=-1;
        }
        else
        {
            A[nod].minimpar=v[st];
            A[nod].maximpar=v[st];
            A[nod].minpar=-1;
            A[nod].maxpar=-1;
        }
    }
    else
    {
        long long mij=(st+dr)>>1;

        build(2*nod,st,mij);
        build(2*nod+1,mij+1,dr);

        A[nod].lazy=0;
        updatenod(nod);
    }


}

void update(int nod ,int  st,int dr ,long long a, long long b, long long x)
{
    updatelazy(nod,st,dr);

    if (a<=st && dr<=b)
    {
        A[nod].lazy+=x;
        updatelazy(nod,st,dr);
    }
    else
    {
        long long mij=(st+dr)>>1;

        if (a<=mij)
        update(2*nod,st,mij,a,b,x);

        if (b>=mij+1)
        update(2*nod+1,mij+1,dr,a,b,x);

        updatelazy(2*nod,st,mij);
        updatelazy(2*nod+1,mij+1,dr);

        updatenod(nod);
    }
}

void query(int  nod, int st, int dr ,long long a ,long long b)
{
    updatelazy(nod,st,dr);

    if (a<=st && dr<=b)
    {
        if (A[nod].minpar!=-1)
            minpar=min(minpar,A[nod].minpar);

        if (A[nod].maximpar!=-1)
            maximp=max(maximp,A[nod].maximpar);
    }
    else
    {
        long long mij=(st+dr)>>1;

        if (a<=mij)
            query(2*nod,st,mij,a,b);

        if (b>=mij+1)
            query(2*nod+1,mij+1,dr,a,b);

        updatelazy(2*nod,st,mij);
        updatelazy(2*nod+1,mij+1,dr);

        updatenod(nod);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    for (i=1; i<=n; i++)
        cin>>v[i];

    build(1,1,n);

    cin>>q;

    for(long long i = 1; i <= q; i++)
    {
        cin>>t>>a>>b;
        if (t==0){
            cin>>x;
            update(1,1,n,a,b,x);
        }else{
            maximp=-1;
            minpar=1e18;
            query(1,1,n,a,b);
            if (minpar==1e18)
                minpar=-1;
            cout<<minpar<<" "<<maximp<<"\n";
        }
    }
    return 0;
}
