#include<bits/stdc++.h>
using namespace std;
#define R 4
#define C 4
int mat[R][C];
int solve(int mat[R][C])
{
    int rowInd = -1;
    int maxCount = 0;
     int cnt = 0;
    for(int i=0;i<R;i++)
    {
       
        int count = 0;
        for(int j=0;j<C;j++)
        {
            if(mat[i][j]==1)
            {
                count++;
            }
        }
        if(count>=maxCount)
        {
            cnt++;
            maxCount = count;
            rowInd = i;
        }


    }
    if(cnt>=3)
    {
        return -1;
    }
    
    return rowInd+1;
}
int main()
{
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            cin>>mat[i][j];
        }
    }
    int ans = solve(mat);
    cout<<ans;
    return 0;
}