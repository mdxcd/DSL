// WAP to find the transpose of a sparse matrix using triplet format only.

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

    printf("Original Matrix:\n");
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++)
            printf("%d ", A[i][j]);
        printf("\n");
    }

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

        printf("Original 3-Tuple Matrix:\n");
        for (int i = 0; i < count+1; i++){
            for (int j = 0; j < 3; j++)
                printf("%d ", S[i][j]);
            printf("\n");
        }

        int T[count+1][3];
        T[0][0] = S[0][1];
        T[0][1] = S[0][0];
        T[0][2] = S[0][2];

        int t = 1;
        for (int col = 0; col < c; col++){
            for (int i = 1; i <= count; i++){
                if (S[i][1] == col){
                    T[t][0] = S[i][1];
                    T[t][1] = S[i][0];
                    T[t][2] = S[i][2];
                    t++;
                }
            }
        }

        printf("Transpose 3-Tuple Matrix:\n");
        for (int i = 0; i < count+1; i++){
            for (int j = 0; j < 3; j++)
                printf("%d ", T[i][j]);
            printf("\n");
        }
    }
    return 0;
}