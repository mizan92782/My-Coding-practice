#include<bits/stdc++.h>
using namespace std;
#define V 9

int minDistance(int dist[],bool spt[])
{
     int mini=INT_MAX;
     int index=0;

     for(int i=0;i<V;i++)
     {
          if(spt[i]==false &&  dist[i]<mini)
          {
            mini=dist[i];
            index=i;
          }
     }

return index;
}




void printSolution(int dist[])
{
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << i << " \t\t\t\t" << dist[i] << endl;
}




void Dijkstra(int graph[V][V],int src)
{
      //* for storing shotest path  distance in every node
      int dist[V];
      

      //* storing node add spt or not
      bool spt[V];

      for(int i=0;i<V;i++)
      {
         dist[i]=INT_MAX;
         spt[i]=false;
      }
      



      // * make src spt minimum
      dist[src]=0;

      for(int i=0;i<V-1;i++)
      {
            // * find minimum shortest path
            int u= minDistance(dist,spt);
             

             // * adding in shortest path
             spt[u]=true;


             for(int v=0;v<V;v++)
             {

                  /*

                  graph[u][v] : have a edge
                  spt[v]==false : not yet adding spt
                  dist[u]+graph[u][v]<dist[v] : Relaxation accure
                  
                  */

                 
                 if(graph[u][v] !=0 && spt[v]==false  && dist[u]+graph[u][v]<dist[v])
                 {
                    dist[v]=dist[u]+graph[u][v];
                 }
             }
      }


      printSolution(dist); 

}




int main()
{

    // https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/
    
          int graph[V][V] =
                     { 
                        { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11,0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0,0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0,0 },
                        { 0, 0, 4, 14, 10, 0, 2,0,0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0,7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } 
                    };


                Dijkstra(graph,0);
   
}