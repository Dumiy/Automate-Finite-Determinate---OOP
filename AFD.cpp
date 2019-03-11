#include <iostream>
#include <vector>
#include <fstream>
#include <string.h>

using namespace std;

class AFD
{
private:
    bool f;
    vector <AFD *>per;
    int s;
public:
    friend void co(AFD []);
    friend void pa(AFD []);
    friend void prop(AFD []);
    friend istream& operator >> (istream&,AFD[]);
    friend ostream& operator << (ostream&,AFD[]);
};
void prop(AFD a[])
{
    int i=0;
    ifstream f("date.in");
    int n;
    f>>n;
    for(i=0;i<n;i++)
    {
        cout<<"Nodul "<<i<<"Final ? 1-Da 0-Nu";
        int k;
        cin>>k;
        if(k==0 || k==1)
            a[i].f=k;
        else {cout<<"Nu se poate"<<endl;
        i--;
        }

    }
}
void co(AFD a[])
{
    ifstream f("date.in");
    int n,m,c,aux;
    f>>n>>m>>c;
      char g[m];
    for(int i=0;i<m;i++)
            f>>g[i];
    aux=c;
    for(int i=0;i<n;i++)
    a[i].per.resize(m);
    while(1)
    {
        int ok=0;
        if(aux==0)
            break;
        int o,i,e;
        char d;
        f>>o;
        f>>d;
        f>>e;
        a[e].s=e;
        for(i=0;i<m;i++)
            if(g[i]==d)
                break;

        a[o].per[i]=&a[e];
        aux--;
    }

}
void pa(AFD a[])
{
    char u[]="ba";
      int p;
    p=strlen(u);
    AFD *h;

    ifstream f("date.in");
    int n,m,c,aux;
    f>>n>>m>>c;
      char g[m];
    for(int i=0;i<m;i++)
            f>>g[i];
    int i=0,j=0,k=0,ok=0;
    while(1)
    {
        if(j==p)
            break;
        char d;
        d=u[j];
        for(i=0;i<m;i++)
            if(g[i]==d)
                {
                    ok=1;
                    break;

                }
        if(ok==0)
            {cout<<"Nu se poate, nu se afla in aflabet"<<endl;
            break;
            }
        if(a[k].per[i]!=NULL)
        h=a[k].per[i];
        k=h->s;
        j++;
        }
    if(h->f==true)
        cout<<"Acceptat"<<endl;
    else cout<<"Nu este acceptat";

}
istream& operator >> (istream& in,AFD a[])
{
    co(a);
    prop(a);
    return in;
}
ostream& operator << (ostream& out,AFD a[])
{
    pa(a);
    return out;
}
int main()
{
    ifstream f("date.in");
    int n;
    f>>n;
    AFD a[n];
    cin>>a;
    cout<<a;


    return 0;
}
