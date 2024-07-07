#include <iostream>
using namespace std;

int main(){

    int matrix[10][10], indeg[10], flag[10], count=0, n;
    int i,j,k;

    cout<<"Enter the no of vertices: ";
    cin>>n;

    cout<<"Enter the adjacency matrix: "<<endl;
    for(i=0; i<n; i++){
        cout<<"Enter row "<<i+1<<":"<<endl;
        for (int j=0; j<n; j++)
            cin>>matrix[i][j];
    }

    for (i=0; i<n; i++){
        indeg[i] = 0;
        flag[i] = 0;
    }

    for (i=0; i<n; i++)
        for (j=0; j<n; j++)
            indeg[i] = indeg[i] + matrix[j][i];

    cout<<endl;
    cout<<"After topological sorting: ";

    while(count<n){

        for (k = 0; k < n; k++){
            if ((indeg[k] == 0) && (flag[k] == 0)){
                cout<<k+1<<" ";
                flag[k] = 1;
            }

            for (i = 0; i < n; i++){
                if(matrix[i][k] == 1)
                    indeg[k]--;
            }
        }
        count++;
    }
    return 0;
}