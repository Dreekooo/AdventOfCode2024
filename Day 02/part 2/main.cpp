#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

int solve(std::vector<std::vector<int>>);
bool checkIfSafe(std::vector<int>);
bool checkIfSafeSimplified(std::vector<int>);

int main() {
    std::string row;
    std::vector<std::vector<int>> listOfLevels;
    std::ifstream file("input.txt");

    //getting vector of levels values
    if(file.is_open()){
        while(std::getline(file, row)){
            std::vector<int> tempVector;
            std::stringstream ss;
            int tempInt;
            ss << row;
            while(ss >> tempInt)
                tempVector.push_back(tempInt);
            listOfLevels.push_back(tempVector);
        }
    }

    file.close();

    std::cout << solve(listOfLevels);

    return 0;
}

int solve(std::vector<std::vector<int>> listOfLevels){
    int result = 0;
    // checking which levels are safe
    for(std::vector<int> level : listOfLevels){
        if (checkIfSafe(level))
            result++;
    }

    return result;
}

bool checkIfSafe(std::vector<int> level){
    std::vector<int> levelCopy;
    bool safe = true;
    bool deleted = false;
    // decreasing
    for (int i = 1; i < level.size(); i++) {
        if(level[i - 1] - level[i] >= 1 && level[i - 1] - level[i] <= 3)
            continue;

        levelCopy = level;
        levelCopy.erase(levelCopy.begin() + i);
        if(checkIfSafeSimplified(levelCopy))
            break;

        levelCopy = level;
        levelCopy.erase(levelCopy.begin() + i - 1);
        if(checkIfSafeSimplified(levelCopy))
            break;

        levelCopy = level;
        levelCopy.erase(levelCopy.begin());
        if(checkIfSafeSimplified(levelCopy))
            break;

        safe = false;
        break;
    }
    // increasing
    if(!safe) {
        safe = true;
        for (int i = 1; i < level.size(); i++) {
            if (level[i] - level[i - 1] >= 1 && level[i] - level[i - 1] <= 3)
                continue;

            levelCopy = level;
            levelCopy.erase(levelCopy.begin() + i);
            if(checkIfSafeSimplified(levelCopy))
                break;

            levelCopy = level;
            levelCopy.erase(levelCopy.begin() + i - 1);
            if(checkIfSafeSimplified(levelCopy))
                break;

            levelCopy = level;
            levelCopy.erase(levelCopy.begin());
            if(checkIfSafeSimplified(levelCopy))
                break;

            safe = false;
            break;
        }
    }

    return safe;
}

bool checkIfSafeSimplified(std::vector<int> level){
    bool safe = true;
    // decreasing
    for (int i = 1; i < level.size(); i++) {
        if(level[i - 1] - level[i] >= 1 && level[i - 1] - level[i] <= 3)
            continue;
        safe = false;
        break;
    }
    if(!safe) {
        safe = true;
        // increasing
        for (int i = 1; i < level.size(); i++) {
            if (level[i] - level[i - 1] >= 1 && level[i] - level[i - 1] <= 3)
                continue;
            safe = false;
            break;
        }
    }
    return safe;
}