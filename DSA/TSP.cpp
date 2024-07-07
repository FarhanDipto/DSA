#include <bits/stdc++.h>
using namespace std;
#define N 5
int shortest_path[N+1];
bool visited[N];
int res_final = INT_MAX;
 
void res_copy(int curr[]){
    for (int i=0; i<N; i++)
        shortest_path[i] = curr[i];
    shortest_path[N] = curr[0];
}
 
int reduced(int matrix[N][N], int i){
    int min = INT_MAX;
    for (int k=0; k<N; k++)
        if (matrix[i][k]<min && i != k)
            min = matrix[i][k];
    return min;
}
 
int reduced_f(int matrix[N][N], int i){
    int first = INT_MAX, second = INT_MAX;
    for (int j=0; j<N; j++){
        if (i == j)
            continue;
 
        if (matrix[i][j] <= first){
            second = first;
            first = matrix[i][j];
        }
        else if (matrix[i][j] <= second && matrix[i][j] != first)
            second = matrix[i][j];
    }
    return second;
}
 
void tsp(int matrix[N][N], int next, int cost, int level, int curr[]){

    if (level==N){
        if (matrix[curr[level-1]][curr[0]] != 0){
            int res_curr = cost+matrix[curr[level-1]][curr[0]];
            if (res_curr < res_final){
                res_copy(curr);
                res_final = res_curr;
            }
        }
        return;
    }
 
    for (int i=0; i<N; i++){
        if (matrix[curr[level-1]][i] != 0 && visited[i] == false){
            int temp = next;
            cost += matrix[curr[level-1]][i];
 
            if (level==1)
              next-=((reduced(matrix,curr[level-1])+reduced(matrix, i))/2);
            else
              next-=((reduced_f(matrix,curr[level-1])+reduced(matrix,i))/2);
 
            if (next + cost < res_final){
                curr[level] = i;
                visited[i] = true;
                tsp(matrix, next, cost, level+1, curr);
            }
 
            cost -= matrix[curr[level-1]][i];
            next = temp;
 
            memset(visited, false, sizeof(visited));
            for (int j=0; j<=level-1; j++)
                visited[curr[j]] = true;
        }
    }
}
 
void sol(int matrix[N][N], int start){

    int curr[N+1];
    int next = 0;
    memset(curr, -1, sizeof(curr));
    memset(visited, 0, sizeof(curr));
 
    for (int i=0; i<N; i++)
        next+=(reduced(matrix,i)+reduced_f(matrix,i));
 
    next=(next&1)?next/2+1:next/2;
    visited[0]=true;
    curr[0]=start;
    tsp(matrix, next, 0, 1, curr);
}
 
int main(){
    int matrix[N][N] = {{999, 20, 30, 10, 11},
                        {15, 999, 16, 4, 2},
                        {3, 5, 999, 2, 4},
                        {19, 6, 18, 999, 3},
                        {16, 4, 7, 16, 999}
    };

    int start;
    cout<<"Enter a node to start from between 0 and 4: ";
    cin>>start; 

    sol(matrix, start);
    cout<<"Minimum cost to traverse the graph: "<<res_final<<endl;
    cout<<"Shortest path: ";
    for (int i=0; i<=N; i++) cout<<shortest_path[i]<<" -> ";
    return 0;
}