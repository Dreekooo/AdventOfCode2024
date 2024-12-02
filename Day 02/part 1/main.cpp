#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <fstream>

int solve(std::vector<std::vector<int>>);

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
    bool safe;
    // checking which levels are safe
    for(std::vector<int> level : listOfLevels){
        safe = true;
        if(level[0] > level[1]) { // decreasing
            for (int i = 1; i < level.size(); i++) {
                if(level[i - 1] - level[i] >= 1 && level[i - 1] - level[i] <= 3)
                    continue;
                safe = false;
                break;
            }
        } else { // increasing
            for (int i = 1; i < level.size(); i++) {
                if(level[i] - level[i - 1] >= 1 && level[i] - level[i - 1] <= 3)
                    continue;
                safe = false;
                break;
            }
        }

        if (safe)
            result++;
    }

    return result;
}