#include &lt;stdio.h&gt;
#include &lt;string.h&gt;
int main ()
{
    char txt[] = &quot;analysis of algorithm&quot;;
    char pat[] = &quot;a&quot;;
    int M = strlen (pat);
    int N = strlen (txt);
    for (int i = 0; i &lt;= N - M; i++)
    {
        int j;
        for (j = 0; j &lt; M; j++)
        if (txt[i + j] != pat[j])
        break;
        if (j == M)
        printf (&quot;\n Pattern matches at index %d &quot;, i);
    }
    return 0;
}