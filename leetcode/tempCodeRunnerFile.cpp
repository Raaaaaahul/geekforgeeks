#include<bits/stdc++.h>
using namespace std;

int solve(int a[],int b[],int n,int m)
{
    sort(a,a+n);
    sort(b,b+m);
    int idx_a = 0;
    int idx_b = 0;
    int sum_a = 0;
    int sum_b = 0;
    for(int i=0;i<n;i++)
    {
        sum_a += a[i];
    }
    for(int j=0;j<m;j++)
    {
        sum_b += b[j];
    }
    while(idx_a<n and idx_b<m)
    {
        int temp1 = sum_a - a[idx_a] + b[idx_b];
        int temp2 = sum_b - b[idx_b] + a[idx_a];
        if(temp1>temp2)
        {
            idx_a++;
        }
        else if(temp1<temp2)
        {
            idx_b++;
        }
        else
        {
            return 1;
        }
    }
    return -1;

}

int main()
{
    int A[] = {4, 1, 2, 1, 1, 2};
    int B[] = {3,6,3,3};
    int n = sizeof(A)/sizeof(int);
    int m = sizeof(B)/sizeof(int);
    cout<<solve(A,B,n,m);
    return 0;
}