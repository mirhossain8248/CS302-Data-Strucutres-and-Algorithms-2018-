/*
Mir Hossain
Proj5
This project is simulates how long a customer would stand in line using queues.
We calculate the amount of customers sevred, the average wait and the max wait time.
I was not entirely sure how to caclulate max wait time, so I just assumed the max
wait time would be how long the queue would run for.
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include "queue.h"

int main(){
  int simLength, timeArrived, waitTime;
	int totalServed = 0, totalWait = 0, maxWait = 0, numArrivals = 0, currentMinute = 0;
  Queue customerQueue;

  cout << "Enter 0 for time to end the simulator" << endl << endl;

  do{

  srand(time(NULL));

  cout << "Enter time of simulator: ";
	cin >> simLength;
  cout << "-----------------------" << endl;

  while(currentMinute <= simLength){ //while simulation is running
    currentMinute++; //add a minute
    int cusTemp = 0;

		if(!customerQueue.checkEmpty()){
			timeArrived = customerQueue.pop(); //record time when customer leaves
			waitTime = currentMinute - timeArrived; //calculate wait time
			totalWait += waitTime;
			totalServed++; //Record how many customers served

      if(waitTime > maxWait){
				maxWait = (waitTime-1); //Default case
			}
      timeArrived = cusTemp;
		}

		int r = rand() % 4; //Randomize how many customers in line

		if(r == 1){ //If r=1 we add one customer to the line
			numArrivals++;
		}

    else if (r == 2){ //If r=2 we add two customers to the line
			numArrivals+=2;
		}

    else if(r == 3 || r == 0){ //If r = 3 or 0 we don't add any customers to the line
      numArrivals += 0;
    }

		for(int x = 0; x < numArrivals; x++){
			customerQueue.push(currentMinute);
		}
		//numArrivals=0;


   }

   // Print out simulation results
  if(simLength != 0){
    cout << "Customers served: " << numArrivals << endl;
    cout << "Average wait: " << double(waitTime+=waitTime)/totalServed << " minutes" << endl;
	  cout << "Longest wait: " << maxWait << " minutes" << endl << endl;
  }

    }
  while(simLength !=0);


	return 0;
}
    /*
    //Test Cases
    Queue Q;
    Q.push(10); Q.push(20); Q.push(30);
    Q.display();
    Q.pop();Q.pop();Q.pop();
    Q.checkEmpty();
    //Q.display();
    */
