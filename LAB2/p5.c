// WAP to find the addition of two sparse matrices using triplet format.

#include <stdio.h>

int main(){
    int r, c;
    printf("Enter the no. of rows and columns: ");
    scanf("%d %d", &r, &c);

    int A[r][c];
    printf("Enter the Elements for Matrix A:\n");
    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            printf("Element %d%d: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    int B[r][c];
    printf("Enter the Elements for Matrix B:\n");
    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            printf("Element %d%d: ", i, j);
            scanf("%d", &B[i][j]);
        }
    }

    int countA = 0;
    for (int i=0; i<r; i++)
        for (int j=0; j<c; j++)
            if (A[i][j] != 0)
                countA++;

    int countB = 0;
    for (int i=0; i<r; i++)
        for (int j=0; j<c; j++)
            if (B[i][j] != 0)
                countB++;

    if (((r*c)-countA) >= ((r*c)/2) && ((r*c)-countB) >= ((r*c)/2)){
        int SA[countA+1][3];
        SA[0][0] = r;
        SA[0][1] = c;
        SA[0][2] = countA;

        int k=1;
        for (int i=0; i<r; i++)
            for (int j=0; j<c; j++)
                if (A[i][j] != 0){
                    SA[k][0] = i;
                    SA[k][1] = j;
                    SA[k][2] = A[i][j];
                    k++;
                }

        int SB[countB+1][3];
        SB[0][0] = r;
        SB[0][1] = c;
        SB[0][2] = countB;

        k=1;
        for (int i=0; i<r; i++)
            for (int j=0; j<c; j++)
                if (B[i][j] != 0){
                    SB[k][0] = i;
                    SB[k][1] = j;
                    SB[k][2] = B[i][j];
                    k++;
                }

        printf("Sparse Matrix A:\n");
        for (int i = 0; i < countA+1; i++){
            for (int j = 0; j < 3; j++)
                printf("%d ", SA[i][j]);
            printf("\n");
        }

        printf("Sparse Matrix B:\n");
        for (int i = 0; i < countB+1; i++){
            for (int j = 0; j < 3; j++)
                printf("%d ", SB[i][j]);
            printf("\n");
        }

        int SC[countA+countB+1][3];
        SC[0][0] = r;
        SC[0][1] = c;
        SC[0][2] = countA+countB;

        for (int i=1; i<=countA; i++){
            SC[i][0] = SA[i][0];
            SC[i][1] = SA[i][1];
            SC[i][2] = SA[i][2];
        }

        int t = countA + 1;
        for (int i=1; i<=countB; i++){
            SC[t][0] = SB[i][0];
            SC[t][1] = SB[i][1];
            SC[t][2] = SB[i][2];
            t++;
        }

        printf("Sparse Matrix Sum (3-Tuple):\n");
        for (int i = 0; i < t; i++){
            for (int j = 0; j < 3; j++)
                printf("%d ", SC[i][j]);
            printf("\n");
        }
    }
    return 0;
}
