void dfs(int i, int** isConnected, int isConnectedColSize, int *visited){
    if (visited[i] == 1){
        return;
    }
    visited[i] = 1;

    for(int j=0; j <isConnectedColSize; j++){
        if (visited[j] == 0 && isConnected[i][j] == 1){
            dfs(j, isConnected, isConnectedColSize, visited);
        }
    }
    return;
}


int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize) {
    int visited[isConnectedSize];
    for(int i=0; i <isConnectedSize; i++){
        visited[i] = 0;
    }

    int province = 0;
    for(int i=0; i <isConnectedColSize; i++){
        if (visited[i] == 0 && isConnected[i] == 1){
            province++;
            dfs(i, isConnected, isConnectedColSize, visited);
        }
    }
    return province;
}
