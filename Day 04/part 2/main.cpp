#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <fstream>


int solve(std::vector<std::string>);
bool checkLeftTop(std::vector<std::string>, int, int);
bool checkRightTop(std::vector<std::string>, int, int);


int main() {
    std::string row;
    std::vector<std::string> rows;
    std::ifstream file("input.txt");


    //getting all rows from the input
    if(file.is_open()){
        while(std::getline(file, row)){
            rows.push_back(row);
        }
    }


    file.close();


    std::cout << solve(rows);
    return 0;
}


int solve(std::vector<std::string> rows) {
    int result = 0;
    for(int i = 0; i < rows.size(); i++) {
        int currentIndex = -1;
        while ((currentIndex = rows[i].find("A", currentIndex + 1)) != std::string::npos) {
            int MASCounter = 0;
            if(checkLeftTop(rows, i, currentIndex)) MASCounter++;
            if(checkRightTop(rows, i, currentIndex)) MASCounter++;
            if(MASCounter == 2) result++;
        }
    }
    return result;
}


bool checkLeftTop(std::vector<std::string> rows, int row, int column) {
    row--;
    column--;
    if(column < 0 || row < 0)
        return false;
    if(rows[row][column] == 'M') {
        row += 2;
        column += 2;
        if (column >= rows[row].length() || row >= rows.size())
            return false;
        if (rows[row][column] != 'S')
            return false;
        return true;
    }
    if(rows[row][column] == 'S') {
        row += 2;
        column += 2;
        if (column >= rows[row].length() || row >= rows.size())
            return false;
        if (rows[row][column] != 'M')
            return false;
        return true;
    }
    return false;
}
bool checkRightTop(std::vector<std::string> rows, int row, int column) {
    row--;
    column++;
    if(column >= rows[row].length() || row < 0)
        return false;
    if(rows[row][column] == 'M') {
        row += 2;
        column -= 2;
        if (column < 0 || row >= rows.size())
            return false;
        if (rows[row][column] != 'S')
            return false;
        return true;
    }
    if(rows[row][column] == 'S') {
        row += 2;
        column -= 2;
        if (column < 0 || row >= rows.size())
            return false;
        if (rows[row][column] != 'M')
            return false;
        return true;
    }
    return false;
}


