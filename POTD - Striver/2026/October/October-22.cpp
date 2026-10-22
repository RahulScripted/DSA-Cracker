// Design a Snake game that is played on a device with screen size height x width. Play the game online if you are not familiar with the game. The snake is initially positioned at the top left corner (0, 0) with a length of 1 unit. You are given an array food where food[i] = (ri, ci) is the row and column position of a piece of food that the snake can eat. When a snake eats a piece of food, its length and the game's score both increase by 1. Each piece of food appears one by one on the screen, meaning the second piece of food will not appear until the snake eats the first piece of food. When a piece of food appears on the screen, it is guaranteed that it will not appear on a block occupied by the snake. The game is over if the snake goes out of bounds (hits a wall) or if its head occupies a space that its body occupies after moving (i.e. a snake of length 4 cannot run into itself). Implement the SnakeGame class:

//     1- SnakeGame(int width, int height, int[][] food) Initializes the object with a screen of size height x width and the positions of the food.
//     2 - int move(String direction) Returns the score of the game after applying one direction move by the snake. If the game is over, return -1.








#include <bits/stdc++.h>
using namespace std;

class SnakeGame {
    unordered_set<string> snakeSet;
    deque<pair<int, int>> snake;
    vector<vector<int>> food;
    int foodIndex;
    int width;
    int height;

    string pairToString(int row, int col) {
        return to_string(row) + "," + to_string(col);
    }

public:
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        this->width = width;
        this->height = height;
        this->food = food;
        this->foodIndex = 0;
        this->snakeSet.insert(pairToString(0, 0));
        this->snake.push_back({0, 0});
    }

    int move(string direction) {
        pair<int, int> snakeCell = this->snake.front();
        int newHeadRow = snakeCell.first;
        int newHeadColumn = snakeCell.second;

        if (direction == "U") newHeadRow--;
        else if (direction == "D") newHeadRow++;
        else if (direction == "L") newHeadColumn--;
        else if (direction == "R") newHeadColumn++;

        pair<int, int> newHead = {newHeadRow, newHeadColumn};
        pair<int, int> currentTail = this->snake.back();

        bool crossesBoundary1 = newHeadRow < 0 || newHeadRow >= this->height;
        bool crossesBoundary2 = newHeadColumn < 0 || newHeadColumn >= this->width;
        bool bitesItself = this->snakeSet.count(pairToString(newHeadRow, newHeadColumn)) && !(newHead.first == currentTail.first && newHead.second == currentTail.second);

        if (crossesBoundary1 || crossesBoundary2 || bitesItself) return -1;

        if ((this->foodIndex < this->food.size())
            && (this->food[this->foodIndex][0] == newHeadRow)
            && (this->food[this->foodIndex][1] == newHeadColumn)) {
            this->foodIndex++;
        } else {
            this->snake.pop_back();
            this->snakeSet.erase(pairToString(currentTail.first, currentTail.second));
        }

        this->snake.push_front(newHead);
        this->snakeSet.insert(pairToString(newHeadRow, newHeadColumn));
        return this->snake.size() - 1;
    }
};

int main() {
    vector<vector<int>> food = {{1, 2}, {0, 1}};
    SnakeGame snakeGame(3, 2, food);
    cout << snakeGame.move("R") << endl;
    cout << snakeGame.move("D") << endl;
    cout << snakeGame.move("R") << endl;
    cout << snakeGame.move("U") << endl;
    cout << snakeGame.move("L") << endl;
    cout << snakeGame.move("U") << endl;
}