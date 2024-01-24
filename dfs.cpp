// Algorithm:
// Step 1: SET STATUS = 1 (ready state) for each node in G
// Step 2: Push the starting node A on the stack and set its STATUS = 2 (waiting state)
// Step 3: Repeat Steps 4 and 5 until STACK is empty
// Step 4: Pop the top node N. Process it and set its STATUS = 3 (processed state)
// Step 5: Push on the stack all the neighbors of N that are in the ready state (whose STATUS = 1) and set their STATUS = 2 (waiting state)
// [END OF LOOP]
// Step 6: EXIT

#include <iostream>
using namespace std;

int n, a[10][10], i, j, v[10], count = 0;

void dfs(int x)
{
    count++;
    v[x] = count;
    if (v[x] != 0)
        cout << x << "\t";

    int k;
    for (k = 1; k <= n; k++)
        if (a[x][k] == 1 && v[k] == 0)
            dfs(k);
}

int main()
{   int s;
    cout << "\nEnter no. of Nodes: ";
    cin >> n;
    cout << "\nEnter the Adjacency Matrix:-\n";
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            cin >> a[i][j];
    //         cout<<"source";
    // cin>>s;
    for (i = 1; i <= n; i++)
        v[i] = 0;
    cout << "\nDFS:\t";

    clock_t start= clock();
    //dfs(s);
    for (i = 1; i <= n; i++)
        if (v[i] == 0)
            dfs(i);
    cout << "\n";
    clock_t end=clock();
    double time=double(end-start)/double(CLOCKS_PER_SEC);
    cout<<"EXECUTION TIME :"<<fixed<<time;
    return 0;
}
