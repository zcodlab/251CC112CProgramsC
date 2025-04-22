#include <iostream>
using namespace std;
void ordBurbuja(int*A, int n){
    for(int i=0;i<n-1;i++ ){
        for(int j=0;j<n-i-1;j++ ){
                if( *(A+j) > *(A+j+1) ){
                        int temp=*(A+j);
                        *(A+j)=*(A+j+1) ;
                        *(A+j+1) =temp;
                }
        }
    }
}

int main()
{
    int A[]={5,2,9,4,1,8,5,6,3,0,7};
    int n=sizeof(A)/sizeof(int);
    ordBurbuja(A,n);

    cout << "Visualizando el array despues de ordenado" << endl;
    for(int i=0;i<n;i++ )
        cout<<*(A+i)<<" ";
    return 0;
}
