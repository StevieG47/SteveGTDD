/** @file PID.h
 * @brief PID class header
 *@Author Steven Gambino
 *
 * Contains class for PID
 */

#ifndef PID_H_
#define PID_H_
#include <math.h>
#include <iostream>
#include <cassert>

using std::cout;
using std::endl;

/**

 * @brief Defines components of PID controller

 * @return none

 */
class PID {
 public:
  double getError(double setV, double actualV);  //get the error
  double Pterm(double error, double Kp);  //get the P term
  double Iterm(double error, double Ki, int dT, double integralSum);  //get the I term
  double Dterm(double error, double prevError, double Kd, int dT);  //get the D term
  double getControl(double Pterm, double Iterm, double Dterm);  //get u(t) from P,I,D terms
  double compute(double setV, double actualV);  //compute new velocity from target V and actual V
  double setV, actualV;  //target and actual C
  static double prevError;  // = 0;  //previous error
  static double integralSum;  // = 0;  //integral sum
  static int dT;  // = 1;  //change in time
  static double plant;  // = .1;  //plant. Used with u(t) to get new velocity
 private:
  static double Kp;  // = 32;  //variables for the PID controller
  static double Ki;  // = 17;
  static double Kd;  // = 3.2;
};
#endif /* PID_H_ */
