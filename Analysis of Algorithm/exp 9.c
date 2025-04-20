#include &lt;stdio.h&gt;
#include &lt;stdbool.h&gt;
#define N 8
void print_solution(int board[N][N]) 
{
    for (int i = 0; i &lt; N; i++) 
    {
        for (int j = 0; j &lt; N; j++) 
        {
            printf(&quot;%d &quot;, board[i][j]);
        }
        printf(&quot;\n&quot;);
    }
}
bool is_safe(int board[N][N], int row, int col) 
{
    int i, j;
    for (i = 0; i &lt; col; i++) 
    {
        if (board[row][i])
        return false;
    }
    for (i = row, j = col; i &gt;= 0 &amp;&amp; j &gt;= 0; i--, j--) 
    {
        if (board[i][j])
        return false;
    }
    for (i = row, j = col; j &gt;= 0 &amp;&amp; i &lt; N; i++, j--) 
    {
        if (board[i][j])
        return false;
    }
    return true;
}
bool solve_n_queens_util(int board[N][N], int col) 
{
    if (col &gt;= N)
    return true;
    for (int i = 0; i &lt; N; i++) 
    {
        if (is_safe(board, i, col)) 
        {
            board[i][col] = 1;
            if (solve_n_queens_util(board, col + 1))
            return true;
            board[i][col] = 0;
        }
    }
    return false;
}
bool solve_n_queens() 
{
    int board[N][N] = { 
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0} 
    };
    if (solve_n_queens_util(board, 0) == false) 
    {
        printf(&quot;Solution does not exist&quot;);
        return false;
    }
    printf(&quot;Solution exists:\n&quot;);
    print_solution(board);
    return true;
}
int main() 
{
solve_n_queens();
return 0;
}