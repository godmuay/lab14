#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double A[],int N, double B[]){
    double sum =0, sqsum = 0, sqmean ;
    for (int i=0 ; i<N;i+=1 ){
        sum+=A[i];
    }
    
     B[0] = sum/N ; //mean

    for(int i=0;i<N;i+=1){
    sqsum+=pow(A[i],2);
    }
    sqmean = pow(sum/N,2);
    B[1] = sqrt(((sqsum)/N)-sqmean); //SD

    double mul = 1;
    for(int i=0;i<N;i+=1){
        mul*=A[i];
    }
    B[2] = pow(mul,1.0/N); //GM

    double invsum = 0;
    for(int i=0;i<N;i+=1){
        invsum+=(1/A[i]);
    }
    B[3] = N/invsum; //HM

    B[4] = A[0];
    B[5] = A[0];
    for(int i=0;i<N;i+=1){
        if(A[i]<B[5])
        {
            B[5] = A[i];
        }//min
        if(A[i]>B[4]){
            B[4] = A[i];
        }//max
    }
}
