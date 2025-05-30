#include <iostream>
using namespace std;
const int MAX_INT=1<<30; //2^30=1'073,741,824
int corteVarilla(int precio[],int n,int **dp){
    if(n==0)//caso base
        return 0;
    if(dp[n][n]!=-1)
        return dp[n][n];
    int maxValor= -MAX_INT;
    for(int i=1;i<=n;i++){
            int p=precio[i-1];
            int cv=corteVarilla(precio,n-i,dp);
            //int costo=precio[i-1]+corteVarilla(precio,n-i,dp);
            int costo=p+cv;
            cout<<"precio[i-1]"<<" i:"<<i<<" i-1: "<<i-1<<" p: "<<p<<" corteVarilla(precio,n-i,dp):"<<" n: "<<n<<" i: "<<i<<" n-i: "<<n-i<<" cv:"<<cv<<" p+cv:"<<p+cv<<endl;
            if(costo>maxValor)
                    maxValor=costo;
    }
    dp[n][n]=maxValor;
    return maxValor;
}

int main()
{
    int precio[]={1,5,8,9,10,17,17,20};//cuando el corte i=1-> ganancia es 1, i=2-> ganancia es 5 etc.
    int n=4;
    //instanciando e inicializando dp
    int **dp=new int*[n+1];
    for(int i=0;i<=n;i++){
            dp[i]=new int[n+1];
            for(int j=0;j<=n;j++)
                dp[i][j]=-1;
    }

    cout << "El beneficio es:" <<corteVarilla(precio,n,dp)<<endl;
    //liberando memoria
    for(int i=0;i<=n;i++)
        delete[] dp[i];
    delete[] dp;
    return 0;
}
