// 5. WAP to check the brackets are balanced or not, using stack.

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
        if (str[i] == '(')
        PUSH(str[i]);
        i++;
    }

    int j = 0;
    while (str[j] != '\0'){
        if (str[j] == ')')
        POP();
        j++;
    }

    if (TOP == -1) printf("Brackets are balanced");
    else printf("Brackets are not balanced");
    return 0;
}