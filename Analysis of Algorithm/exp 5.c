#include &lt;stdio.h&gt;
#include &lt;limits.h&gt;
#include&lt;conio.h&gt;
#define V 5 // Number of vertices in the graph
int minDistance(int dist[], int visited[]) 
{
    int v,min = INT_MAX, minIndex;
    for (v = 0; v &lt; V; v++)
    if (!visited[v] &amp;&amp; dist[v] &lt;= min) 
    {
        min = dist[v];
        minIndex = v;
    }
    return minIndex;
}
void dijkstra(int graph[V][V], int src) 
{
    int i,v,count,dist[V], visited[V] = {0};
    for (i = 0; i &lt; V; i++)
    dist[i] = INT_MAX;
    dist[src] = 0;
    for (count = 0; count &lt; V - 1; count++) 
    {
        int u = minDistance(dist, visited);
        visited[u] = 1;
        for (v = 0; v &lt; V; v++)
        if (!visited[v] &amp;&amp; graph[u][v] &amp;&amp; dist[u] != INT_MAX&amp;&amp; dist[u] + graph[u][v] &lt; dist[v])
        dist[v] = dist[u] + graph[u][v];
    }
    for (i = 0; i &lt; V; i++)
    printf(&quot;Vertex %d -&gt; Distance from Source: %d\n&quot;, i, dist[i]);
}
int main() 
{
    int graph[V][V] = {
        {0, 10, 0, 5, 0},
        {0, 0, 1, 2, 0},
        {0, 0, 0, 0, 4},
        {0, 3, 9, 0, 2},
        {7, 0, 6, 0, 0},
    };
    clrscr();
    dijkstra(graph, 0);
    getch();
    return 0;
}