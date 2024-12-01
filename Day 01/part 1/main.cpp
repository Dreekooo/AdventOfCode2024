#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <fstream>

int solve(std::vector<int>, std::vector<int>);

int main() {
    std::string row;
    std::vector<int> listLeft, listRight;
    std::ifstream file("input.txt");

    // Getting maps of list values and their positions
    if(file.is_open()){
        while(std::getline(file, row)){
            std::stringstream ss;
            int temp;
            ss << row;
            ss >> temp;
            listLeft.push_back(temp);
            ss >> temp;
            listRight.push_back(temp);
        }
    }

    file.close();

    int result = solve(listLeft, listRight);
    std::cout << result;

    return 0;
}

int solve(std::vector<int> listLeft, std::vector<int> listRight){
    int result = 0;
    std::sort(listLeft.begin(), listLeft.end());
    std::sort(listRight.begin(), listRight.end());
    for(int i = 0; i < listLeft.size(); i++){
        int temp = listLeft[i] - listRight[i];
        if(temp < 0)
            temp *= -1;
        result += temp;
    }
    return result;
}