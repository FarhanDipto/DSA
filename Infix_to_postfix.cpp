#include<stdio.h>
#include<ctype.h>
#define SIZE 50            

char stack[SIZE];
int top=0;       
 
void push(char item){                      
    stack[++top]=item;
}
 
char pop(){                     
    return(stack[top--]);
}
 
int precedence(char symbol){                 
    
	if(symbol == '^') return(3);
	else if(symbol == '*' || symbol == '/') return(2);
	else if(symbol == '+' || symbol == '-') return(1);     
	else return(0);
}


int main(){

    char infix[SIZE],postfix[SIZE],ch,item;
    int i=0,k=0;
    printf("Enter the infix expression: ");
    scanf("%s",infix);
    push('#');
    while( (ch=infix[i++]) != '\0')
    {
        if(ch=='('){
            push(ch);
        }
        else{
            if(isalnum(ch)){
                postfix[k++]=ch;
            }
            else
                if(ch == ')'){

                    while(stack[top]!='(')
                        postfix[k++]=pop();
                    item=pop(); 
                }
                else{  
                         
                    while(precedence(stack[top])>=precedence(ch))
                        postfix[k++]=pop();
                    push(ch);
                }
        }
    }
    while(stack[top]!='#')     
        postfix[k++]=pop();
    postfix[k]='\0';          
    printf("\nPostfix expression: %s\n",postfix);
}