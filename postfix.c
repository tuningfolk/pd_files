#include<stdio.h>
#include<stdlib.h>

typedef struct stack{
    char arr[50];
    int top;
}stack;

int isoperator(char ch){
    if(ch == '^' || ch == '*' || ch == '/' || ch == '+' || ch == '-' || ch =='(' || ch == ')') return 1;
    return 0;
}

int precedence(char ch){
    if(ch == '^') return 3;
    if(ch == '/' || ch == '*') return 2;
    if(ch == '+' || ch == '-') return 1;
    return 0;
}

void push(stack* S, char ch){
    S->top = S->top+1;
    S->arr[S->top] = ch;
}

int empty(stack* S){
    if(S->top == -1) return 1;
    return 0;
}

char pop(stack* S){
    if(!empty(S)){
        S->top=S->top-1;
        return S->arr[S->top+1];
    }else{
        printf("bro\n");
        printf("%c\n", S->arr[S->top+1]);
        exit(0);
    } 
}

void print(stack* S){
    for(int i = S->top; i>=0; i--){
        printf("%c", S->arr[i]);
    }
}

void intopost(stack* s, char postfix[]){
    char ch;
    char x;
    scanf("%c", &ch);
    int i = 0;
    while(ch!='\n'){
        if(!isoperator(ch)){
            postfix[i] = ch;
            i++;
        }else
        {
            if(ch == '('){
                push(s, ch);
                
            }else if(ch == ')'){
                x = s->arr[s->top];
                while(x!='('){
                    postfix[i] = pop(s);
                    i++;
                    x = s->arr[s->top];
                }
                pop(s);
            }else if(isoperator(ch)){
                if(empty(s)){
                    push(s,ch);
                }
                else if(precedence(ch)> precedence(s->arr[s->top])){
                    push(s,ch);
                }else{
                    
                    while(precedence(ch)<=precedence(s->arr[s->top])){
                        postfix[i] = pop(s);
                        i++;
                    }
                    push(s,ch); 

                }
            }
        } 
        scanf("%c", &ch);
    }
    postfix[i] = '\0';
}

int main(){
    stack* s = malloc(sizeof(stack));
    char postfix[50];
    s->top = -1;
    intopost(s, postfix);
    printf("%s", postfix);
    print(s);
    free(s);
    return 0;
}