#include &lt;stdio.h&gt;
#include &lt;limits.h&gt;
#define V 4 
int graph[V][V] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
};
int visited[V]; 
int final_res = INT_MAX; 
void tsp(int curr_pos, int count, int cost, int
start) 
{
    if (count == V &amp;&amp; graph[curr_pos][start]) 
    {
        int total_cost = cost + graph[curr_pos][start];
        if (total_cost &lt; final_res)
        final_res = total_cost;
        return;
    }
    for (int i = 0; i &lt; V; i++) 
    {
        if (!visited[i] &amp;&amp; graph[curr_pos][i]) 
        {
            visited[i] = 1; 
            tsp(i, count + 1, cost + graph[curr_pos][i], start);
            visited[i] = 0; 
        }
    }
}
int main() 
{
    for (int i = 0; i &lt; V; i++)
    visited[i] = 0;
    int start = 0; 
    visited[start] = 1; 
    tsp(start, 1, 0, start);
    printf(&quot;Minimum cost of visiting all cities:
    %d\n&quot;, final_res);
    return 0;
}