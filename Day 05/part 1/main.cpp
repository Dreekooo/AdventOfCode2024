#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <fstream>

int solve(std::vector<std::pair<int, int>>, std::vector<std::vector<int>>);
int count(std::vector<std::vector<int>>);

int main() {
    std::string row;
    std::vector<std::pair<int, int>> orderingRules;
    std::vector<std::vector<int>> produceList;
    std::ifstream file("input.txt");
    bool gettingRules = true;
    if(file.is_open()){
        while(std::getline(file, row)){
            if(row.length() == 0){
                gettingRules = false;
                continue;
            }
            if(gettingRules){
                row.replace(2, 1, " ");
                std::stringstream ss(row);
                int temp1, temp2;
                ss >> temp1;
                ss >> temp2;
                std::pair<int, int> pair = {temp1, temp2};
                orderingRules.push_back(pair);
            } else {
                char del = ',';
                size_t pos = 0;
                std::string token;
                std::vector<int> temp;
                while ((pos = row.find(del)) != std::string::npos) {
                    token = row.substr(0, pos);
                    temp.push_back(std::stoi(token));
                    row.erase(0, pos + 1);
                }
                temp.push_back(std::stoi(row));
                produceList.push_back(temp);
            }
        }
    }
    file.close();

    std::cout << solve(orderingRules, produceList);

    return 0;
}

int solve(std::vector<std::pair<int, int>> orderingRules, std::vector<std::vector<int>> produceList){
    std::vector<std::vector<int>> correctList;
    for(std::vector<int> list : produceList){
        bool correct = true;
        for(int i = 0; i < list.size(); i++){
            int value = list[i];
            auto it = find_if(orderingRules.begin(), orderingRules.end(), [value](const auto& p) { return p.second == value; });
            if(it != orderingRules.end()){
                do {
                    int target = it->first;
                    int cnt = count(list.begin() + i, list.end(), target);
                    if(cnt > 0){
                        correct = false;
                        break;
                    }
                    it = find_if(it + 1, orderingRules.end(), [value](const auto& p) { return p.second == value; });
                } while (it != orderingRules.end());
            }
        }
        if(correct)
            correctList.push_back(list);
    }
    return count(correctList);
}

int count(std::vector<std::vector<int>> correctList){
    int result = 0;
    for(std::vector<int> elements : correctList){
        result += elements[elements.size()/2];
    }
    return result;
}