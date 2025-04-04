#include "sort.h"
using namespace std;

void bubbleSort(int X[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<(n-1)-i;j++){
            if(X[j]>X[j+1]){
                    //intercambio
                    int temp=X[j];
                    X[j]=X[j+1];
                    X[j+1]=temp;
            }

        }
    }
}
