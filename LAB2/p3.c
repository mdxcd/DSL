// WAP for multiplication of two polynomials using arrays.

#include <stdio.h>

int main(){
    int n;
    printf("Enter the highest exponent of P: ");
    scanf("%d", &n);

    int p[n+1];
    for (int i=0; i<n+1; i++) p[i]=0;
    
    int e; char ch;
    do{
        printf("Enter the exponent: ");
        scanf("%d", &e);
        printf("Enter the coefficient: ");
        scanf("%d", &p[e]);
        printf("Do you have another term? (y/n): ");
        scanf(" %c", &ch);
    } while (ch=='y');

    printf("P : ");
    for (int i=n; i>=0; i--){
        if (p[i]==0) continue;
        if (p[i]>0) printf("+%dx^%d", p[i], i);
        if (p[i]<0) printf("%dx^%d", p[i], i);
    }
    printf("\n");

    int m;
    printf("Enter the highest exponent of Q: ");
    scanf("%d", &m);

    int q[m+1];
    for (int i=0; i<m+1; i++) q[i]=0;
    
    do{
        printf("Enter the exponent: ");
        scanf("%d", &e);
        printf("Enter the coefficient: ");
        scanf("%d", &q[e]);
        printf("Do you have another term? (y/n): ");
        scanf(" %c", &ch);
    } while (ch=='y');

    printf("Q : ");
    for (int i=m; i>=0; i--){
        if (q[i]==0) continue;
        if (q[i]>0) printf("+%dx^%d", q[i], i);
        if (q[i]<0) printf("%dx^%d", q[i], i);
    }
    printf("\n");

    int size = m*n;

    int R[size+1];
    for (int i=0; i<size+1; i++) R[i] = 0;

    for (int i=0; i<n+1; i++){
        for (int j=0; j<m+1; j++){
            R[i+j] = R[i+j] + (p[i]*q[j]);
        }
    }

    printf("Resultant Polynomail:");
    for (int i=size; i>=0; i--){
        if (R[i]==0) continue;
        if (R[i]>0) printf("+%dx^%d", R[i], i);
        if (R[i]<0) printf("%dx^%d", R[i], i);
    }
    printf("\n");

    return 0;
}