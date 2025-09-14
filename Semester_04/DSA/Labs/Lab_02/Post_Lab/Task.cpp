#include <iostream>
using namespace std;

// Function to input maze entries and validate them
bool mazeEntry(int **maze, int targetX, int targetY);

// Function to solve the maze using backtracking
bool rateInMaze(int **maze, int x, int y, int targetX, int targetY, int **sol);

int main()
{
    cout << "Welcome to Rat in Maze Game Solver!" << endl;

    // Get dimensions for the maze (rows and columns)
    int targetX, targetY;
    cout << "Enter rows for maze: ";
    cin >> targetX;
    cout << "Enter columns for maze: ";
    cin >> targetY;

    // Dynamically allocate memory for the maze matrix
    int **maze = new int *[targetX];
    for (int i = 0; i < targetX; i++)
    {
        maze[i] = new int[targetY];
    }

    // Dynamically allocate memory for the solution matrix and initialize it with 0s
    int **sol = new int *[targetX];
    for (int i = 0; i < targetX; i++)
    {
        sol[i] = new int[targetY];
        for (int j = 0; j < targetY; j++)
        {
            sol[i][j] = 0;
        }
    }

    // Call the mazeEntry function to input the maze
    if (mazeEntry(maze, targetX, targetY))
    {
        // Call rateInMaze function to solve the maze
        if (rateInMaze(maze, 0, 0, targetX, targetY, sol))
        {
            // If a solution exists, print the solution path
            cout << "\nSolved Path for the Rat:" << endl;
            for (int i = 0; i < targetX; i++)
            {
                for (int j = 0; j < targetY; j++)
                {
                    cout << sol[i][j] << " ";
                }
                cout << endl;
            }
        }
        else
        {
            cout << "No solution exists for this maze." << endl;
        }
    }
    else
    {
        cout << "Matrix values are wrongly entered." << endl;
    }

    // Free dynamically allocated memory to avoid memory leaks
    for (int i = 0; i < targetX; i++)
    {
        delete[] maze[i];
        delete[] sol[i];
    }
    delete[] maze;
    delete[] sol;

    cout << "\tGoodbye!\t" << endl;
    return 0;
}

// This function takes the maze input from the user, validates it, and displays the original maze
bool mazeEntry(int **maze, int targetX, int targetY)
{
    cout << "\n--Enter 0 for block and 1 for path in maze--" << endl;
    for (int i = 0; i < targetX; i++)
    {
        cout << "Row no " << i + 1 << endl;
        for (int j = 0; j < targetY; j++)
        {
            cin >> maze[i][j];
            // Validating the input; maze can only contain 0 (block) or 1 (path)
            if (maze[i][j] != 0 && maze[i][j] != 1)
            {
                cout << "Sorry! You can only enter 1 or 0" << endl;
                return false; // Return false if the input is invalid
            }
        }
    }

    // Displaying the original maze matrix entered by the user
    cout << "\nOriginal Maze:" << endl;
    for (int i = 0; i < targetX; i++)
    {
        for (int j = 0; j < targetY; j++)
        {
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }
    return true;
}

// This function uses backtracking to find the path in the maze
bool rateInMaze(int **maze, int x, int y, int targetX, int targetY, int **sol)
{
    // Base case
    if (x == targetX - 1 && y == targetY - 1 && maze[x][y] == 1)
    {
        sol[x][y] = 1;
        return true; // Solution found
    }

    // Check if the current cell (x, y) is a valid cell to proceed
    if (x >= 0 && x < targetX && y >= 0 && y < targetY && maze[x][y] == 1)
    {
        // Mark the current cell as part of the solution
        sol[x][y] = 1;

        // Try moving in the x direction (downwards)
        if (rateInMaze(maze, x + 1, y, targetX, targetY, sol))
        {
            return true;
        }

        // If above doesn't work, try to moving in y direction
        if (rateInMaze(maze, x, y + 1, targetX, targetY, sol))
        {
            return true;
        }

        // If neither direction works
        sol[x][y] = 0;
        return false; // Backtrack to the previous step
    }

    return false; // Return false if the cell is not valid
}

/*
Time Complexity Analysis: O(2^(2n)) = O(2^(n))
Explaination:
The `rateInMaze` function explores all possible paths from the starting point (0, 0) to the destination (targetX-1, targetY-1).
- In the worst case, it explores every possible cell in the maze, making recursive calls to explore both the x (down) and y (right) directions.
- Since there are targetX * targetY cells, the time complexity is O(2^(targetX + targetY)), as each recursive call has two options (down or right), leading to an exponential number of recursive calls in the worst case.

Space Complexity Analysis: O(n^2)
- The space complexity is determined by the space required for the maze, the solution matrix, and the recursive call stack.
- The maze and solution matrices each take O(targetX * targetY) space.
- The depth of the recursion is at most targetX + targetY in the worst case, which contributes O(targetX + targetY) space for the call stack.
- Thus, the overall space complexity is O(targetX * targetY) due to the matrices.

*/
