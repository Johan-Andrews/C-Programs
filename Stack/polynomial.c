
#include <stdio.h>

struct polynomial
        {       int coeff;
                int exp;
        };

struct polynomial p[100];
struct polynomial q[100];
struct polynomial r[100];
int re;

int add(struct polynomial*p, struct polynomial*q, int n, int m, struct polynomial*r)
{

        int i=0, j=0, k=0;
        while (i<n && j<m)
        {
                if (p[i].exp == q[j].exp)
                {       r[k].coeff = p[i].coeff + q[j].coeff;
                        r[k].exp = p[i].exp;
                        i++;
                        j++;
                        k++;
                }

                else if (p[i].exp > q[j].exp)
                {       r[k].coeff = p[i].coeff;
                        r[k].exp = p[i].exp;
                        i++;
                        k++;
                }

                else if (p[i].exp < q[j].exp)
                {       r[k].coeff = q[j].coeff;
                        r[k].exp = q[j].exp;
                        j++;
                        k++;
                }

        }

      while (i<n)
        {       r[k].coeff = p[i].coeff;
                r[k].exp = p[i].exp;
                i++;
                k++;
        }

        while (j<(m))
        {       r[k].coeff = q[j].coeff;
                r[k].exp = q[j].exp;
                j++;
                k++;
        }

        return k;
}

void display(int n, int m, int k)
{       printf("\n1st polynomial: \n");
        for (int i=0; i<m; i++)
                printf("%dx^%d + ", p[i].coeff, p[i].exp);


        printf("\n2nd polynomial: \n");
        for (int i=0; i<n; i++)
               printf("%dx^%d + ", q[i].coeff, q[i].exp);


        printf("\n\nresultant polynomial: \n");
        for (int i=0; i<k; i++)
                printf("%dx^%d + ", r[i].coeff, r[i].exp);

}


void main()
{

        int m, n;

        printf("enter number of terms in 1st poly:");
        scanf("%d",&m);
        for (int i=0; i<m; i++)
        {       printf("coeff %d and exp %d:",i,i);
                scanf("%d %d",&p[i].coeff, &p[i].exp);

        }

        printf("\n enter number of terms in 2nd poly:");
        scanf("%d",&n);
        for (int i=0; i<n; i++)
        {       printf("term %d:", i);
                scanf("%d %d",&q[i].coeff, &q[i].exp);
        }


        re = add(p, q, m,n, r);
        display(m,n, re);
}


