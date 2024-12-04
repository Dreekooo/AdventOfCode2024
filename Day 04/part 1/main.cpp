#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <fstream>


int solve(std::vector<std::string>);
bool checkTop(std::vector<std::string>, int, int);
bool checkBottom(std::vector<std::string>, int, int);
bool checkLeft(std::vector<std::string>, int, int);
bool checkRight(std::vector<std::string>, int, int);
bool checkLeftTop(std::vector<std::string>, int, int);
bool checkRightTop(std::vector<std::string>, int, int);
bool checkLeftBottom(std::vector<std::string>, int, int);
bool checkRightBottom(std::vector<std::string>, int, int);


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
        while ((currentIndex = rows[i].find("X", currentIndex + 1)) != std::string::npos) {
            if(checkTop(rows, i, currentIndex)) result++;
            if(checkBottom(rows, i, currentIndex)) result++;
            if(checkLeft(rows, i, currentIndex)) result++;
            if(checkRight(rows, i, currentIndex)) result++;
            if(checkLeftTop(rows, i, currentIndex)) result++;
            if(checkRightTop(rows, i, currentIndex)) result++;
            if(checkLeftBottom(rows, i, currentIndex)) result++;
            if(checkRightBottom(rows, i, currentIndex)) result++;
        }
    }
    return result;
}


bool checkTop(std::vector<std::string> rows, int row, int column) {
    std::string word = "XMAS";
    int currentIndex = 1;
    while(currentIndex < word.length()) {
        row--;
        if(row < 0)
            return false;
        if(rows[row][column] != word[currentIndex])
            return false;
        currentIndex++;
    }
    return true;
}
bool checkBottom(std::vector<std::string> rows, int row, int column) {
    std::string word = "XMAS";
    int currentIndex = 1;
    while(currentIndex < word.length()) {
        row++;
        if(row >= rows.size())
            return false;
        if(rows[row][column] != word[currentIndex])
            return false;
        currentIndex++;
    }
    return true;
}
bool checkLeft(std::vector<std::string> rows, int row, int column) {
    std::string word = "XMAS";
    int currentIndex = 1;
    while(currentIndex < word.length()) {
        column--;
        if(column < 0)
            return false;
        if(rows[row][column] != word[currentIndex])
            return false;
        currentIndex++;
    }
    return true;
}
bool checkRight(std::vector<std::string> rows, int row, int column) {
    std::string word = "XMAS";
    int currentIndex = 1;
    while(currentIndex < word.length()) {
        column++;
        if(column >= rows[row].length())
            return false;
        if(rows[row][column] != word[currentIndex])
            return false;
        currentIndex++;
    }
    return true;
}
bool checkLeftTop(std::vector<std::string> rows, int row, int column) {
    std::string word = "XMAS";
    int currentIndex = 1;
    while(currentIndex < word.length()) {
        row--;
        column--;
        if(column < 0 || row < 0)
            return false;
        if(rows[row][column] != word[currentIndex])
            return false;
        currentIndex++;
    }
    return true;
}
bool checkRightTop(std::vector<std::string> rows, int row, int column) {
    std::string word = "XMAS";
    int currentIndex = 1;
    while(currentIndex < word.length()) {
        row--;
        column++;
        if(column >= rows[row].length() || row < 0)
            return false;
        if(rows[row][column] != word[currentIndex])
            return false;
        currentIndex++;
    }
    return true;
}
bool checkLeftBottom(std::vector<std::string> rows, int row, int column) {
    std::string word = "XMAS";
    int currentIndex = 1;
    while(currentIndex < word.length()) {
        row++;
        column--;
        if(column < 0 || row >= rows.size())
            return false;
        if(rows[row][column] != word[currentIndex])
            return false;
        currentIndex++;
    }
    return true;
}
bool checkRightBottom(std::vector<std::string> rows, int row, int column) {
    std::string word = "XMAS";
    int currentIndex = 1;
    while(currentIndex < word.length()) {
        row++;
        column++;
        if(column >= rows[row].length() || row >= rows.size())
            return false;
        if(rows[row][column] != word[currentIndex])
            return false;
        currentIndex++;
    }
    return true;
}



