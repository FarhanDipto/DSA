#include<bits/stdc++.h>
using namespace std;
vector <int> graph[100];
vector <int> cost[100];

void withoutWeight(){
    int start, finish;
    int nodes, edges;

    cout<<"Enter the number of nodes and edges: ";
    cin>>nodes>>edges;

    for(int i=1; i<=edges; i++){
        cout<<"Enter start and finish: ";
        cin>>start;
        cin>>finish;
        graph[start].push_back(finish);
        // graph[finish].push_back(start); 
    }
    cout<<"Relations"<<endl;
    for(int j=1; j<=nodes; j++){
        cout<<"From node "<<j<<" to : ";
        for(int k=0; k<graph[j].size(); k++){
            cout<<graph[j][k]<<" ";
        }
        cout<<endl;
    }
    
}

void withWeight(){
    int start, finish, weight;
    int nodes, edges;

    cout<<"Enter the number of nodes and edges: ";
    cin>>nodes>>edges;

    for(int i=1; i<=edges; i++){
        cout<<"Enter start and finish and the weight: ";
        cin>>start>>finish>>weight;
        graph[start].push_back(finish);
        cost[start].push_back(weight);      
    }
    cout<<"Node adjacency list with weight: "<<endl;
    for(int i=1; i<=nodes; i++){
        cout<<"From node "<<i<<" to : ";
        for(int j=0; j<graph[i].size(); i++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
        cout<<"weight: ";
        for(int k=0; k<cost[i].size(); k++){
            // cout<<k<<"->"<<endl;
            cout<<cost[i][k]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    withWeight();
    // withoutWeight();
}