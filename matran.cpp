#include<iostream>
#include<omp.h>
#include <stdlib.h>
#include <time.h>
using namespace std;


void ma(int** &a,int m,int n)
{
    a = (int**)malloc(m*sizeof(int*));
    for(int i=0; i<m; i++)
    {
        a[i]= (int*)malloc(n*sizeof(int));
    }
}

void randmatrix(int** &a,int m,int n)
{
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
        {
            a[i][j] = rand()%11;
        }
}

void printmatrix(int** a,int m,int n)
{
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
                cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

main()
{
    int m,n,p;
    int **a,**b,**c;
    m=n=p=1000;
    srand((int)time(0));
    ma(a,m,n);
    randmatrix(a,m,n);
    ma(b,n,p);
    randmatrix(b,n,p);
    ma(c,m,p);
    omp_set_num_threads(4);
    double t1 = omp_get_wtime();
    #pragma omp parallel for

    for (int i=0; i<m; i++)
    {
        for (int j=0; j<p; j++)
        {
            c[i][j]=0;
            for (int k=0; k<n; k++)
            {
                c[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
    double t2 = omp_get_wtime();
    cout<<t2-t1<<endl;
}
