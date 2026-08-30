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
    int flag = 1;
    while (str[i] != '\0'){
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        PUSH(str[i]);
        else if (str[i] == ')' || str[i] == '}' || str[i] == ']'){
            char popped = POP();
            if ((str[i] == ')' && popped != '(') ||
                (str[i] == '}' && popped != '{') ||
                (str[i] == ']' && popped != '[')) {
                flag = 0;
                break;
            }
        }
        i++;
    }

    if (TOP == -1 && flag == 1) printf("Brackets are balanced\n");
    else printf("Brackets are not balanced\n");
    return 0;
}