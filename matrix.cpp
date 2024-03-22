#include<iostream>
using namespace std;
void ReadArray(double* a,int m,int n)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<"enter element "<<i+1<<" , "<<j+1<<endl;
            cin>>*(a+i*m+j);
        }
    }
}
void PrintArray(double* a,int m,int n)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<*(a+i*m+j)<<" ";
        }
        cout<<endl;
    }
}
void MatrixPdt(double* a,double* b,double* c,int m, int n, int r)//a->m*r and b->r*n matrix pdt saves to c->m*n
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<r;k++)
                (*(c+i*m+j))+=(*(a+i*m+k))*(*(b+k*r+j));
        }
    }
}
void XRow(double* a,int n,double x)//row operation a->ax
{
    for (int i = 0; i < n; i++)
    {
        (*(a+i))*=x;
    }    
}
void RowDiff(double* a,double* b,double x, int n)//row operation a->a+bx
{
    for (int i = 0; i < n; i++)
    {
        (*(a+i))+=(*(b+i))*x;
    }
    
}
void Swap(double* a,double* b,int n)//swaps row a and b
{
    double c;
    for (int i = 0; i < n; i++)
    {
        c=*(a+i);
        *(a+i)=*(b+i);
        *(b+i)=c;
    }
    
}
void inverse(double* a,double* I,int n)
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            {
                if(i==j)
                    *(I+n*i+j)=1;
                else
                    *(I+n*i+j)=0;
            }
    for(int i=0;i<n;i++)//gauss elimination
    {
        int f=1;
        label:
        cout<<*(a+n*i+i)<<endl<<endl;
        if(*(a+n*i+i)==0)
        {
            cout<<i+f<<endl<<endl;
            if(i+f>=n)
            {
                cout<<"matrix is not invertable";
                break;
            }
            else
                Swap(a+n*i,a+n*(i+f),n);
            f++;
            goto label;
        }
        else
        {
            double y=*(a+n*i+i);
            XRow(a+n*i,n,1/y);
            XRow(I+n*i,n,1/(y));
        }
        for (int j = 0; j < n; j++)
        {
            if(j!=i)
            {
                double x=*(a+n*j+i);
                //cout<<x<<endl<<endl;
                RowDiff(I+n*j,I+n*i,-x,n);
                RowDiff(a+n*j,a+n*i,-x,n);
                PrintArray(a,3,3);
                cout<<endl<<endl;
            }
        }
        PrintArray(a,3,3);
        cout<<endl<<endl;
    }
}
int main()
{
    double a[3][3],I[3][3],p[3][3];
    ReadArray(a[0],3,3);
    inverse(a[0],I[0],3);
    MatrixPdt(a[0],I[0],p[0],3,3,3);
    PrintArray(p[0],3,3);
    return 0;
}