#include <stdio.h>
int right_left = 1;
int left_right = 0;
int searchArr(int a[], int n, int mobile)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == mobile)
        {
            return i + 1;
        }
    }
}
int getMobile(int a[], int dir[], int n)
{
    int mobile_prev = 0, mobile = 0;
    for (int i = 0; i < n; i++)
    {
        if (dir[a[i] - 1] == right_left && i != 0)
        {
            if (a[i] > a[i - 1] && a[i] > mobile_prev)
            {
                mobile = a[i];
                mobile_prev = mobile;
            }
        }

        if (dir[a[i] - 1] == left_right && i != n - 1)
        {
            if (a[i] > a[i + 1] && a[i] > mobile_prev)
            {
                mobile = a[i];
                mobile_prev = mobile;
            }
        }
    }
    if (mobile == 0 && mobile_prev == 0)
        return 0;
    else
        return mobile;
}
void swap(int *p, int *q)
{
    int t;
    t = *p;
    *p = *q;
    *q = t;
}
int printOnePerm(int a[], int dir[], int n)
{
    int mobile = getMobile(a, dir, n);
    int pos = searchArr(a, n, mobile);

    if (dir[a[pos - 1] - 1] == right_left)
        swap(&a[pos - 1], &a[pos - 2]);

    else if (dir[a[pos - 1] - 1] == left_right)
        swap(&a[pos], &a[pos - 1]);

    for (int i = 0; i < n; i++)
    {
        if (a[i] > mobile)
        {
            if (dir[a[i] - 1] == left_right)
                dir[a[i] - 1] = right_left;
            else if (dir[a[i] - 1] == right_left)
                dir[a[i] - 1] = left_right;
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
int fact(int n)
{
    int res = 1;
    for (int i = 1; i <= n; i++)
        res = res * i;
    return res;
}
void printPermutation(int n)
{
    int a[n];
    int dir[n];

    for (int i = 0; i < n; i++)
    {
        a[i] = i + 1;
        printf("%d ", a[i]);
    }
    printf("\n");

    for (int i = 0; i < n; i++)
        dir[i] = right_left;

    for (int i = 1; i < fact(n); i++)
        printOnePerm(a, dir, n);
}
void main()
{
    int n;
    printf("enter the number to find the permutation of that number\n");
    scanf("%d",&n);
    printPermutation(n);
}
