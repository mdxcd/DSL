// 3. WAP to convert the decimal to binary using stack.

#include <stdio.h>

int size = 32;
int stack[32];
int TOP = -1;

void PUSH(int value){
    TOP++;
    if (TOP < size){
        stack[TOP] = value;
        return;
    } else {
        printf("OVERFLOW\n");
        TOP--;
        return;
    }
}

int POP(){
    if (TOP == -1){
        printf("UNDERFLOW\n");
    }
    return stack[TOP--];
}

int main(){
    int num;
    printf("Enter Number: ");
    scanf("%d", &num);
    
    int r;
    while (num != 0){
        r = num%2;
        num = num/2;
        PUSH(r);
    }

    printf("Binary: ");
    while (TOP != -1){
        printf("%d ", POP());
    }
}