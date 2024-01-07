#include<bits/stdc++.h>

using namespace std;

int main()
{   
    int n = 8;
    vector<int> systemState = {0,1,0,0,1,1,0,0};
    vector<int> dist = {3,5,10,12,13,23,30,38};
    
    //Solution - DFS approach
    vector<int> connect_min(n,INT_MAX);  //store min cost to connect for each node
    vector<int> on_nodes;  //nodes which are ON in the beginning
    for(int i=0; i<n; i++){
        if(systemState[i] == 1){
            on_nodes.push_back(i);
            connect_min[i] = 0;
        }
    }
    
    for(int i=0; i<on_nodes.size(); i++){
        //nodes on the left
        int index = on_nodes[i];
        for(int j=index-1; j>=0; j--){
            if(systemState[j] == 1) break;
            connect_min[j] = min(connect_min[j], abs(dist[j+1] - dist[j]));
        }
        
        //nodes on the right
        for(int j=index+1; j<n; j++){
            if(systemState[j] == 1) break;
            connect_min[j] = min(connect_min[j], abs(dist[j] - dist[j-1]));
        }
    }
    
    int answer = 0;
    for(int i=0; i<n; i++){
        answer += connect_min[i];
    }
    
    cout<<answer;
    

    return 0;
}