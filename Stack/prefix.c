#include <ctype.h>
#include <string.h>
#include <stdio.h>

char str2[50], post[50], stack[50];
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

void reverse(char str1[50])
{	int s=strlen(str1);
	for (int i=0; i<s; i++)
	{	char c = str1[s-i-1];
		if (c=='(') 		str2[i] = ')';
		else if (c == ')')	str2[i] = '(';
		else 			str2[i] = str1[s-1-i];
	}
	printf("%s\n", str2);
}

void reverse2(char stri[50])
{	int s=strlen(stri), i=0;
	char c = stri[s-i-1];
	while (c != '\0')
	{	c = stri[s-i-1];
		str2[i] = stri[s-1-i];
		i++;
	}
	printf("%s\n", str2);
}

void postfix(char str3[50])
{	char c;
	int k=0, size;
	size = strlen(str3);
	push('(');

	for (int i=0;i<=size; i++)
	{
	       	c = str3[i];
	        if (isdigit(c))
	        {
	            post[k] = c;
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
	                {   post[k] = y;
	                    k++;
	                    y = pop();
	                }
	            }

	            else if (icp(c) > isp(st))
	                push(c);

	            else if (icp(c) <= isp(st))
	            {       char x=pop();
	                    post[k] = x;
	                    k++;
	                while ((icp(c)<=isp(stack[top])) && stack[top] != '(' )
	                {   char x=pop();
	                    post[k] = x;
	                    k++;
	                }
	                push(c);
	            }
	        }
 	   }
	printf("Postfix is: %s", post);
}

void main()
{
	char str[50];


	printf("Enter infix expression:");
	scanf("%s", str);
	int n = strlen(str);

	printf("Reverse:");
	reverse(str);
	postfix(str2);
	printf("\nPrefix is:");
	reverse2(post);
}

