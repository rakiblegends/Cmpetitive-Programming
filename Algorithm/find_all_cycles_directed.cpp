
// Find all the cycle and its vertexes in a directed graph.

void dfs(int vertex){
    path.pb(vertex);
    vis[vertex] = 1;
    int to = g[vertex];
 
    if(vis[to]!=2){ //Not gonna visit this one when dfs for disconnected components.
        if(vis[to]==1){
            cycles.emplace_back();
            //Whenever i visit some vertex that has already been visited,
            //then this path (NOT THE ENTIRE PATH) is the cycle.
            int sz = path.size()-1;
            while(path[sz]!=to){
                cycles.back().pb(path[sz--]);
            }
            cycles.back().pb(to);
            // path.clear();
        }else{
            dfs(to);
        }
    }
    path.pop_back(); //Less time complexity than path.clear();
    vis[vertex] = 2;
}