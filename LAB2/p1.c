// WAP for representing the polynomial using an array. Take the input from the user and display it in appropriate format.

#include <stdio.h>

int main(){
    int n;
    printf("Enter the highest exponent: ");
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

    printf("Entered Polynomial: ");
    for (int i=n; i>=0; i--){
        if (p[i]==0) continue;
        if (p[i]>0) printf("+%dx^%d", p[i], i);
        if (p[i]<0) printf("%dx^%d", p[i], i);
    }

    printf("\n");
    return 0;
}