#include<bits/stdc++.h>
using namespace std;
vector<int> solve(int A){
    vector<int> XJ(A,0);        // jeff bazos array representing ways to reach planets
    vector<int> XE(A,0);        // elon musk array representing ways to reach planets
    
    XJ[0]=1;
    XE[0]=1;        // given 
    
    int mod = 1e9+7;
    
    // in jeff's space company can reach i+1 and i+2 planet from ith planet
    for(int i=0;i<A-1;i++){
        // adding ways to reach i+1 and i+2 planet
        XJ[i+1] =(XJ[i+1]+ XJ[i])%mod;
        if(i+2<A) XJ[i+2] = (XJ[i+2]+XJ[i])%mod;       
    }
    
    // in elon musk's company 
    // we can reach from ith planet to...
    // for XJ[i] 's  every set bits k 
    // we can go to [2^k, 2^(k+1)]
    
    for(int i=0;i<A-1;i++){
        int p = XJ[i];
        unordered_set<int> planets;     // planets where i can go
        for(int j=0;j<32;j++){      // checking for every set bit in p
            if(1 & (p>>j)){     // if jth bit is set
                for(int l = pow(2,j) ; l<= pow(2,j+1); l++){
                    planets.insert(l);      // planets to go
                }
                // unset this bit
                p = p ^ (j>>1);
            }
            if(p==0) break;     // if no set bits remaining in p
        }
        
        // adding ways to planets where i can go from this planet
        
        for(int j: planets){
            if(i+j < A) XE[i+j] =(XE[i+j]+ XE[i])%mod;      // updating ways to reach the planets
        }
        
    }
    // uncomment below lines to see XJ and XE
    // cout<<"XJ\n";
    // for(int i:XJ) cout<<i<<" ";
    // cout<<endl;
    // cout<<"XE\n";
    // for(int i:XE) cout<<i<<" ";
    // cout<<endl;
    return XE;
    
}
int main(){
    int n;
    cin>>n;
    vector<int> XE = solve(n);      // calling funtion
    for(int i:XE) cout<<i<<" ";
}