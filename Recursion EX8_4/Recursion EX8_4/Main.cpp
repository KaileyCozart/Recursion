#include <iostream>
using namespace std;

/* Backtracking Explanation Begins on 435 */

// Create and Enum for the Type of Square
enum squareType {possiblePath, barrier, temporaryPath, validatedPath};
const int numberOfRows = 9; // Enums Must Have Constant Value
const int numberOfColumns = 9; // Enums Must Have Constant Value

// Function Prototypes
bool findPath(squareType[numberOfRows][numberOfColumns]);
bool findPath(squareType[numberOfRows][numberOfColumns], int, int);

int main() {
	// Test Code Using Parallel Array Here
	squareType grid[numberOfRows][numberOfColumns] = 
	{
		{possiblePath, barrier, possiblePath, possiblePath, barrier, barrier , barrier , barrier , barrier},
		{possiblePath, barrier, possiblePath, barrier, possiblePath, possiblePath, possiblePath, possiblePath, possiblePath},
		{possiblePath, barrier, possiblePath, barrier, possiblePath, barrier, barrier, barrier, possiblePath},
		{possiblePath, barrier, possiblePath, barrier, possiblePath, barrier, barrier, barrier, possiblePath},
		{possiblePath, barrier, possiblePath, possiblePath, possiblePath, possiblePath, barrier, barrier, possiblePath},
		{possiblePath, possiblePath, possiblePath, possiblePath, barrier, possiblePath, barrier, barrier, possiblePath},
		{barrier, barrier, possiblePath, barrier, barrier, possiblePath, possiblePath, barrier, barrier},
		{possiblePath, barrier, possiblePath, barrier, barrier, barrier, possiblePath, possiblePath, possiblePath},
		{possiblePath, possiblePath, possiblePath, barrier, barrier, barrier, barrier, barrier, possiblePath},
	};

	cout << boolalpha << findPath(grid) << endl;
}

bool findPath(squareType grid[numberOfRows][numberOfColumns]) {
	return findPath(grid, 0, 0);
}

bool findPath(squareType grid[numberOfRows][numberOfColumns], int row, int column) {

	// If the cell is outside of the grid, return false
	if (row >= numberOfRows || column >= numberOfColumns || row < 0 || column < 0) {
		return false;
	}

	// If the cell is on the edge of a barrier or at a dead end, return false
	else if (grid[row][column] != possiblePath) {
		return false;
	}

	// If the cell is on the path and is at the exit of the maze, return true
	else if(row == numberOfRows - 1 && column == numberOfColumns - 1) {
		grid[row][column] = validatedPath;
		return true;
	}

	// Try to find a path to the pot of gold, return true
	else {
		grid[row][column] = validatedPath;
		if (findPath(grid, row - 1, column) ||
			findPath(grid, row + 1, column) ||
			findPath(grid, row, column + 1) ||
			findPath(grid, row, column - 1)) {
			return true;
		}
		// If the path was a dead end, return false
		else {
			grid[row][column] = temporaryPath;
			return false;
		}
	}
}
