#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for (i = 0; i < n; ++i)
#define REP(i,k,n) for (i = k; i <= n; ++i)
#define REPR(i,k,n) for (i = k; i >= n; --i)

vector<vector<int>> bfs_search(int grid_size){


    vector<vector<int>> distance(grid_size, vector<int>(grid_size, -1)); // fill the grid with -1 to see whether we have not visited yet
    vector<pair<int,int>> knight_moves = {{-1, 2}, {-2, 1}, { 1, 2}, { 2, 1}, {-2,-1}, {-1,-2}, { 2,-1}, { 1,-2}}; // moves to make

    queue<pair<int,int>> queue_grid;
    queue_grid.push({0, 0}); // we should add the start point
    distance[0][0] = 0; // the distance to get to the (0, 0) is 0 because we do not make any move

    while(!queue_grid.empty()){ // do while we are not run out of passes, when the queue has elements
        auto [x, y] = queue_grid.front(); // take the first elem from the que to search
        queue_grid.pop(); // delete this element

        for(auto [dx, dy]: knight_moves){
            int current_x = x + dx;
            int current_y = y + dy;

            // we should make sure we are not going to escape the grid and check whether we have not visited the field
            if (current_x >= 0 && current_y < grid_size && current_y >= 0 && current_x < grid_size && distance[current_x][current_y] == -1) {
                distance[current_x][current_y] = distance[x][y] + 1;
                queue_grid.push({current_x, current_y});
            }
        }
    }
    return distance;
}

int main(){
    int n; 
    cin >> n;
    vector<vector<int>> result = bfs_search(n);

    int i, j;
    rep(i, n){
        rep(j, n){
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// Solution for the problem
// For this input the correct solution is this: 

// Input:
// 8

// Output:

// 0 3 2 3 2 3 4 5                  
// 3 4 1 2 3 4 3 4 
// 2 1 4 3 2 3 4 5 
// 3 2 3 2 3 4 3 4 
// 2 3 2 3 4 3 4 5 
// 3 4 3 4 3 4 5 4 
// 4 3 4 3 4 5 4 5 
// 5 4 5 4 5 4 5 6 

// so lets see where the knight can move taking the same grid (8, 8)
//       . . . . . . . .       From this we can see that the knight has 8 possible moves:
//       . . . # . # . .       considering (x, y)> {(-1, 2); (-2, 1), (1, 2); (2, 1), (-2, -1); (-1, -2); (2, -1); (1,-2)} 
//       . . # . . . # .
//       . . . . K . . .
//       . . # . . . # .
//       . . . # . # . .
//       . . . . . . . .
//       . . . . . . . .

// So the solution is implementing the bfs algorithm, where we calculate the distance to the (0, 0) cordinate
// as bfs finds the shortest way we should implement the function to fill the resutl matrix
