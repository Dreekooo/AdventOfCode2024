#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <fstream>


int solve(std::string);
bool checkIfCorrect(std::string);
int multiply(std::string);


int main() {
   std::string row, memory = "";
   std::ifstream file("input.txt");


   //getting memory string
   if(file.is_open()){
       while(std::getline(file, row)){
           memory += row;
       }
   }


   file.close();


   std::cout << solve(memory);


   return 0;
}


int solve(std::string memory) {
   int result = 0, currentIndex = 0;
   while ((currentIndex = memory.find("mul(", currentIndex + 1)) != std::string::npos) {
       int LastIndex = memory.find(")", currentIndex + 1);
       std::string function = memory.substr(currentIndex, LastIndex - currentIndex + 1);
       if(checkIfCorrect(function) == true)
           result += multiply(function);
   }
   return result;
}


bool checkIfCorrect(std::string function) {
   int currentIndex = 4;
   std::string num1, num2;
   while (std::isdigit(function[currentIndex]))
       num1 += function[currentIndex++];


   if(num1.length() == 0 || function[currentIndex] != ',')
       return false;
   currentIndex++;


   while (std::isdigit(function[currentIndex]))
       num2 += function[currentIndex++];


   if(num2.length() == 0 || function[currentIndex] != ')')
       return false;


   return true;
}


int multiply(std::string function) {
   int currentIndex = 4;
   std::string num1, num2;
   while (std::isdigit(function[currentIndex]))
       num1 += function[currentIndex++];


   currentIndex++;


   while (std::isdigit(function[currentIndex]))
       num2 += function[currentIndex++];


   return std::stoi(num1)*std::stoi(num2);
}

