//multiplication of matrices
#include <stdio.h>

void multiply(int m, int n, int p, int q, int A[m][n], int B[p][q]){
    //m,n and p,q are dimensions of the matrices
    int sum=0;
    int M[m][q];
    for(int i=0;i<m;i++){
        for(int j=0;j<q;j++){
            for(int k=0;k<p;k++){
                sum=sum+A[i][k]*B[k][j];
            }
            M[i][j]=sum;
            sum=0;
        }
    }
    printf("Product of multiplication of the matrices is: \n");
    for(int i=0;i<m;i++){
        for(int j=0;j<q;j++)
            printf("%d\t",M[i][j]);
        printf("\n");
    }
}   

void main(){
    int m,n,p,q;
    printf("Enter the number of rows and columns of the first matrix: \n");
    scanf("%d %d",&m,&n);
    printf("Enter the number of rows and columns of the second matrix: \n");
    scanf("%d %d",&p,&q);
    if(n!=p)
        printf("The matrices cannot be multiplied");
    else{
        int A[m][n];
        int B[p][q];
        printf("Enter the elements of the first matrix: \n");
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                printf("Enter the element: \n");
                scanf("%d",&A[i][j]);
            }
        }
        printf("Enter the elements of the second matrix: \n");
        for(int i=0;i<p;i++){
            for(int j=0;j<q;j++){
                printf("Enter the element: \n");
                scanf("%d",&B[i][j]);
            }
        }
        printf("The matrices are: \n");
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
                printf("%d\t",A[i][j]);
            printf("\n");
        }
        printf("\n");
        for(int i=0;i<p;i++){
            for(int j=0;j<q;j++)
                printf("%d\t",B[i][j]);
            printf("\n");
        }
        multiply(m,n,p,q,A,B);
    }       
}