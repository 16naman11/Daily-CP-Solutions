#include <stdio.h>

int getdata(int a1[100][100],int a2[100][100], int *m1, int *m2, int *n1, int *n2)
{
    int i,j,i2,j2;
    printf("enter the number of rows in matrix 1 : ");
    scanf("%d",m1);
    printf("enter the number of columns in matrix 1 : ");
    scanf("%d",n1);
    printf("enter elements of matrix 1 :\n ");
    for(i=0;i<*m1;i++)
    {
        for(j=0;j<*n1;j++)
        {
            scanf("%d", &a1[i][j]);
        }
    }
    printf("matrix 1 looks like :\n");
    for(i=0;i<*m1;i++)
    {
        for(j=0;j<*n1;j++)
        {
            printf("%d\t",a1[i][j]);
        }
        printf("\n");
    }
    
    printf("\n\n");
    
    printf("enter the number of rows in matrix 2 : ");
    scanf("%d",m2);
    printf("enter the number of columns in matrix 2 : ");
    scanf("%d",n2);
    printf("enter elements of matrix 2 :\n ");
    for(i2=0;i2<*m2;i2++)
    {
        for(j2=0;j2<*n2;j2++)
        {
            scanf("%d", &a2[i2][j2]);
        }
    }
    printf("matrix 2 looks like :\n");
    for(i2=0;i2<*m2;i2++)
    {
        for(j2=0;j2<*n2;j2++)
        {
            printf("%d\t",a2[i2][j2]);
        }
        printf("\n");
    }
    printf("\n\n");
    
    return 0;
}

int addition(int a1[100][100], int a2[100][100], int b[100][100], int m1, int m2, int n1, int n2)
{
    int i,j;
    if(m1==m2&&n1==n2)
    {
        printf("the sum of the matrices is :\n");
        for(i=0;i<m1;i++)
        {
            for(j=0;j<n1;j++)
            {
                b[i][j]=a1[i][j]+a2[i][j];
                printf("%d\t",b[i][j]);
            }
            printf("\n");
            
        }
    }
    else
    {
        printf("the rows or columns of the two matrices are unequal, hence addition is not possible\n");
    }
    printf("\n\n");
    return 0;
}

int transpose(int a1[100][100], int a2[100][100], int at1[100][100], int at2[100][100],int m1, int m2, int n1, int n2)
{
    int i,j,i2,j2;
    printf("the transpose of matrix 1 :\n ");
    for(i=0;i<n1;i++)
    {
        for(j=0;j<m1;j++)
        {
            at1[i][j]=a1[j][i];
            printf("%d\t", at1[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
    printf("the transpose of matrix 2 :\n ");
    for(i2=0;i2<n2;i2++)
    {
        for(j2=0;j2<m2;j2++)
        {
            at2[i2][j2]=a2[j2][i2];
            printf("%d\t", at2[i2][j2]);
        }
        printf("\n\n");
    }
    return 0;
}

int determinant(int a1[100][100], int m1, int n1, int det)
{
    if(m1==2&&n1==2)
    {
        det=(a1[0][0]*a1[1][1])-(a1[0][1]*a1[1][0]);
        printf("the determinant of matrix 1 is %d",det);
    }
    if(m1==3&&n1==3)
    {
        det=a1[0][0]*(a1[1][1]*a1[2][2]-a1[1][2]*a1[2][1])-a1[0][1]*(a1[1][0]*a1[2][2]-a1[1][2]*a1[2][0])+a1[0][2]*(a1[1][0]*a1[2][1]-a1[1][1]*a1[2][0]);
        printf("the determinant of matrix 1 is %d",det);
    }
    return 0;
}


int main() {
    int a1[100][100],a2[100][100],b[100][100],at1[100][100],at2[100][100],n1,n2,m1,m2,det;
    getdata(a1,a2,&m1,&m2,&n1,&n2);
    addition(a1,a2,b,m1,m2,n1,n2);
    transpose(a1,a2,at1,at2,m1,m2,n1,n2);
    determinant(a1,m1,n1,det);

    return 0;
}
