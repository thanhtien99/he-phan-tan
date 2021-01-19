#include<iostream>
#include<omp.h>
using namespace std;
main()
{
    int a = 100000000;
    double res=0;
    omp_set_num_threads(1);
     double t1 = omp_get_wtime();
    #pragma omp parallel for reduction(+:res)
    for (int i=0;i<=a;i++){
        res+=4.0/(1.0+(double(i)/double(a))*(double(i)/double(a)));
    }
    double t2 = omp_get_wtime();
    cout<<t2-t1<<endl;
    cout<<res/a;
}
