/*
Mir Hossain
Driver Program for Proj7
This program creates a vector with 100 random integers then sorts using heap sort
*/
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <iostream>
#include <fstream>
#include <ctime>
#include <iterator>

//Helper print function
void print(std::vector<int> const &v)
{
  for (int i: v) {
    std::cout << i << ' ';
  }
}

int main()
{
  std::vector<int> dataSet;
  std::srand ( unsigned ( std::time(0) ) );

  for (int i=0; i<100; ++i){
    dataSet.push_back(i); // 1 2 3 4 5 6 7 8 9
  }

  std::random_shuffle (dataSet.begin(), dataSet.end() );

  int average = accumulate(dataSet.begin(), dataSet.end(), 0.0)/dataSet.size(); //Finds the average

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
