//program for infix to postfix conversion and its evaluation. 

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char out[50];
char stack[50];
char str[50];
int top = 0;


void push(char ch)
{  
    top++;
    stack[top] = ch;
}

char pop()
{   if (top>-1)
    {   top--;
        return stack[top+1];
    }
}

int opr(int x, int y, char op)
{ switch (op)
    {   case '+': return x+y;
        case '-': return x-y;
        case '*': return x*y;
        case '/': return x/y;
        case '^': return pow(x,y);
}   }

void eval()
{   int o,k=0, opst[50];
    char c;
   
    for (int i=0;i<strlen(out);i++)
    {  
        c = out[i];  
        if (isdigit(c))
        {   opst[k]=c-'0';
            k++;
        }
        else
        {   int x = opst[k-1];
            int y = opst[k-2];
            o = opr(y,x,c);
            opst[k-2] = o;
            k--;
        }
    }
    printf("\nEvaluation: %d", o);
}

int icp(char ch)
{
    switch (ch)
    {   case '+': return 1;
        case '-': return 1;
        case '*': return 3;
        case '/': return 3;
        case '^': return 6;
        case '(': return 7;
        case ')': return 0;
    }
}

int isp(char ch)
{
    switch (ch)
    {   case '+': return 2;
        case '-': return 2;
        case '*': return 4;
        case '/': return 4;
        case '^': return 5;
        case '(': return 0;
    }
}

void main()
{
    int n, k=0;
    char c;
    push('(');
    char l[50];
   
    printf("enter input string:");
    scanf("%s", str);
    n = strlen(str);
    str[n] = ')';
   
   // strcat(str, l);
    printf("inpt string:(%s\n", str);


for (int i=0;i<=n; i++)
    {
        c = str[i];
        printf("output string:%s", out);
        printf("\n%c\t", c);

        if (isdigit(c))
        {
            out[k] = c;
            k++;
        }
        else
        {   char y;
            char st = stack[top];
            if (c == '(')
                push(c);

            else if (c==')')
            {   y=pop();
                while (y != '(')
                {   out[k] = y;
                    k++;
                    y = pop();
                }
            }

            else if (icp(c) > isp(st))
                push(c);

            else if (icp(c) <= isp(st))
            {       char x=pop();
                    out[k] = x;
                    k++;
                while ((icp(c)<=isp(stack[top])) && stack[top] != '(' )
                {   char x=pop();
                    out[k] = x;
                    k++;
                }
                push(c);
            }
        }
    }
    printf("\noutput string:%s", out);
    
    eval();
}
