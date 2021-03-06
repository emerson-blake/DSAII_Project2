/************************************************
 * Student Name:	Blake Emerson
 * File Name:		"calculator.hpp"
 * Assignment Number:	Project 2: Customer/Service Simulator - Due 10/07/2021
 * 
 * Definition of Calculator class
 * class object performs analytical and simulated calculations and prints results
 * controlled by Simulator class object
 */

#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

#include <time.h>

#include "customer.hpp"

class Calculator{
public:
	Calculator(int seed = time(0));

	void processCustomerStats(Customer* customer);
	void startIdle(float eventTime);
	void stopIdle(float eventTime);
	void setSimulationTime(float eventTime);
	float calculateRandomInterval(int avg);

	void showSimulationResults(int lambda, int mu, int M, int N);
private:
	int   customersWaitedCnt;
	float totalWaitTime;
	float totalServiceTime;
	float totalSimulationTime;
	float totalIdleTime;
	float idleStartTime;	// used for calcuating totalIdleTime

	// private member functions called by showSimulationResults()
	float analytical_PercentIdleTime(int lambda, int mu, int M);		
	float analytical_AvgCustomersInSystem(int lambda, int mu, int M);	
	float analytical_AvgTimeSpentInSystem(int lambda, int mu, int M);	
	float analytical_AvgCustomersWaiting(int lambda, int mu, int M);	
	float analytical_AvgTimeSpentWaiting(int lambda, int mu, int M);	
	float analytical_UtilizationFactor(int lambda, int mu, int M);		

	float simulated_PercentIdleTime();
	float simulated_AvgTimeSpentInSystem(int N);
	float simulated_AvgTimeSpentWaiting(int N);
	float simulated_UtilizationFactor(int M);
	float simulated_ProbabilityOfWaiting(int N);				


};

#endif
