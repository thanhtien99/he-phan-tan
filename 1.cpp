0#include<iostream>
#include<omp.h>
using namespace std;

main()
{
    double t1 = omp_get_wtime();
    double res=0;
    for (int i=0;i<=100000;i++) {
        res+=4.0/(1.0+(double(i)/100000.0)*(double(i)/100000.0));
    }
    double t2 = omp_get_wtime();
    cout<<t2-t1<<endl;
    cout<<res/100000;
}
