#include<stdio.h>
#include<stdlib.h>

int* mergesort(int *a,int *b, int m,int n){
    int i=0,j=0,k=0;

    int*c = malloc(sizeof(int)*(m*n));

    while(i<=m && j<=n){
        if (a[i]<b[j])
            c[k++]=a[i++];

        else
            c[k++]=b[j++];
        
    }
    for ( ; i < m; i++){
        c[k++]=a[i++];
    }

    for ( ; j < m; j++){
        c[k++]=b[j++];
    }
    return c;
}

int main(){
    int i,n1,n2;
    printf("enter the number of element you want to enter in the first array  ");
    scanf("%d",&n1);
    int *a=malloc(sizeof(int)*n1);
    for ( i = 0; i < n1; i++){
        scanf("%d",&a[i]);
    }

    printf("enter the number of element you want to enter in the first array  ");
    scanf("%d",&n2);
    int *b=malloc(sizeof(int)*n2);
    for ( i = 0; i < n2; i++){
        scanf("%d",&b[i]);
    }

    int *c=mergesort(a,b,n1,n2);

    for ( i = 0; i < n1+n2; i++)
    {
        printf("%d\t",c[i]);
    }
    
    return 0;
}