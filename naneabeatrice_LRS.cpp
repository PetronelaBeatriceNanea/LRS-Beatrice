#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("input.dat");

int n;
int info[100], tata[100], desc[100];

int read_data()
{
    fin>>n;
    for(int i=1;i<=n;i++)
    {
        fin>>info[i];
    }
    for(int i=1;i<=n;i++)
    {
        fin>>tata[i];
    }
    for(int i=1;i<=n;i++)
    {
        fin>>desc[i];
    }
}

int arboreRSD(int k)
{
    cout<<info[k]<<" ";
    for(int i=1;i<=n;i++)
    {
        if(tata[i]==k)
        {
            if(desc[i]==-1)
                arboreRSD(i);
            if(desc[i]==1)
                arboreRSD(i);
        }
    }
}

int arboreSRD(int k)
{
    for(int i=1;i<=n;i++)
    {
        if(tata[i]==k && desc[i]==-1)
        {
            arboreSRD(i);
        }
    }
    cout<<info[k]<<" ";
    for(int i=1;i<=n;i++)
    {
        if(tata[i]==k && desc[i]==1)
        {
            arboreSRD(i);
        }
    }
}

int arboreSDR(int k)
{
    for(int i=1;i<=n;i++)
    {
        if(tata[i]==k && desc[i]==-1)
        {
            arboreSRD(i);
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(tata[i]==k && desc[i]==1)
        {
            arboreSRD(i);
        }
    }
    cout<<info[k]<<" ";
}

int main()
{
    read_data();
    arboreRSD(1);
    cout<<endl;
    arboreSRD(1);
    cout<<endl;
    arboreSDR(1);
}
