#include <bits/stdc++.h>
using namespace std;

/*
   第一行输入两个整数n和x表示电脑零件数量和小红的最大预算
   接下来3*n行，每三行用来描述一个零件的不同型号的价格和性能。
   对于每个零件，第一行输入一个正整数m，表示该零件有多少个型号
   如果无法完成组装，输入-1，否则输出最终的最大性能是多少
*/
long long w[50][50], v[50][50];
long long ans;
int num[50];
// 选第几个零件
void dfs(int n, long long target, long long sum){
    if(n == 0){
        ans = max(ans, sum);
        return;
    }
    for(int i=0; i<num[n-1]; i++){
        if(target - w[n-1][i] > 0){
            dfs(n-1, target - w[n-1][i], sum + v[n-1][i]);
        }
    }
}
int main()
{
    int n , x;
    
    cin >> n >> x;
    for(int i = 0;i<n;i++){
        int m;
        cin>>m;
        num[i] = m;
        for(int j =0; j<m;j++){
            cin>>w[i][j];
        }
        for(int j =0; j<m;j++){
            cin>>v[i][j];
        }
    }
    ans = -1;
    dfs(n, x, 0);
    cout<< ans <<endl;
    return 0;    
}
