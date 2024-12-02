#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
#include <fstream>

int solve(std::vector<int>, std::map<int, int>);

int main() {
    std::string row;
    std::vector<int> listLeft;
    std::map<int, int> listRight;
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
            if(listRight.find(temp) == listRight.end())
                listRight.insert({temp, 1});
            else
                listRight[temp]++;
        }
    }

    file.close();

    int result = solve(listLeft, listRight);
    std::cout << result;

    return 0;
}

int solve(std::vector<int> listLeft, std::map<int, int> listRight){
    int result = 0;

    for(int number : listLeft){
        if(listRight.find(number) == listRight.end())
            continue;
        result += number * listRight[number];
    }

    return result;
}