nclude<stdio.h>

char st[100];
int top = -1;

void push(char el)
{
  st[++top] = el; 
}

char pop()
{
  return st[top--];
}

int isop(char val)
{
  if (val == '+' || val == '-' || val == '*' || val == '/' || val == '%')
  {
    return 1;
  } else {
    return 0;
  }
}
int main()
{
  char exp[50], v1, v2, ex;
  int i = 0;

  printf("Enter the expression: ");
  gets(exp);

  while(exp[i] != '\0')
  {
    if(isop(exp[i]))
    {
      v1 = pop();
      v2 = pop();
      ex = exp[i];

    } else {
      push(exp[i]);
    }
    i++;
  }
}