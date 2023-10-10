#include <iostream>
#include <vector>
#include <string>
#include <stack>

struct Point {
    int row;
    int col;

    Point(int r, int c) : row(r), col(c) {}
};

bool is_can_exit_from_maze(const std::vector<std::string>& maze, int startRow, int startCol) {
    int rows = maze.size();
    int cols = maze[0].size();
    
    std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));
    
    if (startRow < 0 || startRow >= rows || startCol < 0 || startCol >= cols || maze[startRow][startCol] == '#') {
        return false;
    }
    
    std::stack<Point> stack;
    stack.push(Point(startRow, startCol));
    
    while (!stack.empty()) {
        Point current = stack.top();
        stack.pop();
        int row = current.row;
        int col = current.col;
        
        if (maze[row][col] == 'E') {
            return true;
        }
        
        visited[row][col] = true;
        
        const int dr[] = {1, -1, 0, 0};
        const int dc[] = {0, 0, 1, -1};
        for (int i = 0; i < 4; ++i) {
            int newRow = row + dr[i];
            int newCol = col + dc[i];
            
            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && maze[newRow][newCol] != '#' && !visited[newRow][newCol]) {
                stack.push(Point(newRow, newCol));
            }
        }
    }
    
    return false;
}

int main(){
    int row, col, rows, cols;
    std::cin >> row >> col >> rows >> cols;
    std::cin.ignore(1);
    
    std::vector<std::string> maze(rows);
    for(auto& line : maze) std::getline(std::cin, line);
    
    std::cout << (is_can_exit_from_maze(maze, row, col) ? "YES" : "NO") << std::endl;
}

