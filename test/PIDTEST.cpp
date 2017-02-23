/** @file PIDTEST.h

 * @brief PID controller unit test
 *@Author Steven Gambino
 */
#include <gtest/gtest.h>
#include "PID.cpp"
#include "PID.h"
#include"PIDTEST.h"
#include<iostream>

using std::cout;
using std::endl;

//Values for running this test
double PID::prevError = 0;  //previous error
double PID::integralSum = 0;  //integral sum
int PID::dT = 1;  //change in time
double PID::plant = .1;  //plant. Used with u(t) to get new velocity
double PID::Kp = 32;  //variables for the PID controller
double PID::Ki = 17;
double PID::Kd = 3.2;

//Testing the PID

TEST(testPID, test_1) {
  PIDtest A;
  EXPECT_EQ(A.errTest(), 0);  //check if computing error correctly
}

TEST(testPID,test_2) {
  PIDtest A;
  EXPECT_EQ(A.DTest(), 0);  //check if getting Derivative term correctly
}

TEST(testPID,test_3) {
  PIDtest A;
  EXPECT_EQ(A.computeTest(), 0);  //check if compute works
}


//TESTING
//want to return 3 0's , 1 means a test in PIDTEST.h failed
/*
int main() {
  PIDtest A;
  double A1 = A.errTest();
  cout << A1 << endl;
  double A2 = A.DTest();
  cout << A2 << endl;
  double A3 = A.computeTest();
  cout << A3 << endl;

  return 0;
}
 */


