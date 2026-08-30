// 4. WAP to print the reverse of a string using stack.

#include <stdio.h>

int size = 100;
char stack[100];
int TOP = -1;

void PUSH(char value){
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

char POP(){
    if (TOP == -1){
        printf("UNDERFLOW\n");
    } else if (TOP >= 0){
        return stack[TOP--];
    } return '\0';
}

int main(){
    char str[100];
    printf("Enter String: ");
    scanf("%s", str);
    
    int i = 0;
    while (str[i] != '\0'){
        PUSH(str[i]);
        i++;
    }
    printf("Reverse String: ");
    while (TOP != -1){
        printf("%c", POP());
    }
    return 0;
}