#include <iostream>

using namespace std;

int n;
int grid[100][100];
int newGrid[100][100];

int corner = 0;
int lowest = 9999999999;

void rotate(int amnt)
{
	for (int k = 0; k < amnt; k++)
	{
		for (int i = 0; i < n; i++) 
		{
			for (int j = 0; j < n; j++) 
			{
				newGrid[i][j] = grid[n - 1 - j][i];
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				grid[i][j] = newGrid[i][j];
			}
		}
	}
}

void check()
{
	if (grid[0][0] < lowest)
	{
		lowest = grid[0][0];
		corner = 0;
	}
	if (grid[0][n-1] < lowest)
	{
		lowest = grid[0][n-1];
		corner = 1;
	}
	if (grid[n-1][n-1] < lowest)
	{
		lowest = grid[n-1][n-1];
		corner = 2;
	}
	if (grid[n-1][0] < lowest)
	{
		lowest = grid[n-1][0];
		corner = 3;
	}
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> grid[i][j];
		}
	}

	check();

	if (corner == 1)
		rotate(3);
	if (corner == 2)
		rotate(2);
	if (corner == 3)
		rotate(1);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}