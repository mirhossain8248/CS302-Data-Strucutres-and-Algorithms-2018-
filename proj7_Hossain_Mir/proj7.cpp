/*
Mir Hossain
Driver Program for Proj7
This program creates a vector with 100 random integers then sorts using heap sort
*/
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <ctime>
#include <chrono>

//Helper print function
void print(std::vector<int> const &v)
{
  for (int i: v) {
    std::cout << i << ' ';
  }
}

//Fills the vector
int fillVector()
{
    int n = rand() % 7;
    static int i = n;
    //i = i % n;
    i+=n;
}

int main() {


  	std::vector<int> dataSet(100);

    srand(time(NULL));
    std::generate(dataSet.begin(), dataSet.end(), fillVector); //generates dataSet
    std::random_shuffle(std::begin(dataSet), std::end(dataSet)); //randomizes dataSet

    int average = accumulate(dataSet.begin(), dataSet.end(), 0)/dataSet.size(); //Finds the average

    std::cout << "Generating Data Set:" << std::endl;
    std::cout << "---------------------" << std::endl;
    print(dataSet);
    std::cout << std::endl << std:: endl;

    std::cout << "Converting to Heap" << std::endl;
    std::cout << "------------------" << std::endl;
    make_heap(dataSet.begin(), dataSet.end());
    print(dataSet);
    std::cout << std::endl << std::endl;

    std::cout << "Average of set: "<< average;
    std::cout << std::endl << std::endl;

    std::cout << "Pushing average into set: "<< std::endl;
    std::cout <<"-------------------------" << std::endl;
    dataSet.push_back(average);
    print(dataSet);
    std::cout << std::endl << std::endl;

    std::cout << "Deleting max element" << std::endl;
    std::cout << "--------------------" << std::endl;
    pop_heap(dataSet.begin(), dataSet.end());
    dataSet.pop_back();
    print(dataSet);
    std::cout << std::endl << std::endl;

    std::cout << "Resorting Heap" << std::endl;
    std::cout <<"---------------" << std::endl;
    sort_heap(dataSet.begin(), dataSet.end());
    print(dataSet);

    return 0;
}
