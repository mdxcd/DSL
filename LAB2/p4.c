// WAP to create the triplet representation of a sparse matrix.

#include <stdio.h>

int main(){
    int r,c;
    printf("Enter the no. of rows and columns: ");
    scanf("%d %d", &r, &c);

    int A[r][c];
    printf("Enter the Elements:\n");
    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            printf("Element %d%d: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    for (int i = 0; i < r; i++)
    for (int j = 0; j < c; j++)
    printf("%d ", A[i][j]);
    printf("\n");

    int count = 0;
    for (int i=0; i<r; i++)
    for (int j=0; j<c; j++)
    if (A[i][j] != 0)
    count++;

    if (((r*c)-count) >= ((r*c)/2)){

        int S[count+1][3];
        S[0][0] = r;
        S[0][1] = c;
        S[0][2] = count;

        int k=1;
        for (int i=0; i<r; i++)
        for (int j=0; j<c; j++)
        if (A[i][j] != 0){
            S[k][0] = i;
            S[k][1] = j;
            S[k][2] = A[i][j];
            k++;
        }

        for (int i = 0; i < count+1; i++){
            for (int j = 0; j < 3; j++)
                printf("%d ", S[i][j]);
            printf("\n");
        }
    }

    return 0;
}