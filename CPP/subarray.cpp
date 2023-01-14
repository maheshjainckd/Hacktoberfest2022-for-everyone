#include<iostream>
using namespace std;
int main(){
int n1,n2,n3;
cin>>n1>>n2>>n3;
int m1[n1][n2];
int m2[n2][n3];
for(int i=0;i<n1;i++){

    for(int j=0;j<n2;j++)
    cin>>m1[i][j];

}
for(int i=0;i<n2;i++){

    for(int j=0;j<n3;j++)
    cin>>m2[i][j];
    
}
int ans [n1][n2];
for(int i=0;i<n1;i++){

    for(int j=0;j<n3;j++)
    ans[i][j]=0;

    
}

//pahale matrix ki sari row ko iterate kar rahe he ham
for(int i=0;i<n1;i++){
{
//coloum se itrate kar rahe he 2nd matrix ke
    for(int j=0;j<n3;j++){

        fir(int k=0; k<n2; k++){

            ans += m[i][j]*m2[k][j];

        }
    }

}

for(int i=0;i<n1;i++){

    for(int j=0; j<n3;j++){


        cout<<ans[i][j]<<" ";
        cout<<endl;
    }
}


return 0;
}
}