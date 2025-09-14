#include <iostream>
using namespace std;

bool mazeEntry(int **maze, int targetX, int targetY);
bool rateInMaze(int **maze, int x, int y, int targetX, int targetY, int **sol);

int main()
{
    cout << "Welcome to Rat in Maze Game Solver!" << endl;
    int targetX, targetY;
    cout << "Enter rows for maze: ";
    cin >> targetX;
    cout << "Enter columns for maze: ";
    cin >> targetY;

    // Allocating memory for maze
    int **maze = new int *[targetX];
    for (int i = 0; i < targetX; i++)
    {
        maze[i] = new int[targetY];
    }

    // Matrix for solution
    int **sol = new int *[targetX];
    for (int i = 0; i < targetX; i++)
    {
        sol[i] = new int[targetY];
        for (int j = 0; j < targetY; j++)
        {
            sol[i][j] = 0; // Initialize solution array
        }
    }

    if (mazeEntry(maze, targetX, targetY))
    {
        if (rateInMaze(maze, 0, 0, targetX, targetY, sol))
        {
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

    // Free dynamically allocated memory
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

bool mazeEntry(int **maze, int targetX, int targetY)
{
    cout << "\n--Enter 0 for block and 1 for path in maze--" << endl;
    for (int i = 0; i < targetX; i++)
    {
        cout << "Row no " << i + 1 << endl;
        for (int j = 0; j < targetY; j++)
        {
            cin >> maze[i][j];
            if (maze[i][j] != 0 && maze[i][j] != 1)
            {
                cout << "Sorry! You can only enter 1 or 0" << endl;
                return false;
            }
        }
    }

    // Original Maze Display
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

bool rateInMaze(int **maze, int x, int y, int targetX, int targetY, int **sol)
{
    // Base case: If the destination is reached
    if (x == targetX - 1 && y == targetY - 1 && maze[x][y] == 1)
    {
        sol[x][y] = 1;
        return true;
    }

    // Check if current position is valid
    if (x >= 0 && x < targetX && y >= 0 && y < targetY && maze[x][y] == 1)
    {
        // Mark the current cell as part of the solution path
        sol[x][y] = 1;

        // Move in the x direction
        if (rateInMaze(maze, x + 1, y, targetX, targetY, sol))
        {
            return true;
        }

        // Move in the y direction
        if (rateInMaze(maze, x, y + 1, targetX, targetY, sol))
        {
            return true;
        }

        // If neither move works, backtrack
        sol[x][y] = 0;
        return false;
    }

    return false;
}
