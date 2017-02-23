/** @file PIDTEST.cpp

 * @brief PID controller unit test
 *@Author Steven Gambino
 */
#include "PID.h"
//#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file


/**
 * @brief Get error from difference , target velocity - actual velocity
 * @param target velocity and actual velocity
 * @return error, the difference of target - actual
 */
double PID::getError(double setV, double actualV) {
  return 999;

}

/**
 * @brief Get Proportional term from error and Kp
 * @param the calculated error and Kp variable
 * @return The proportional term P
 */
double PID::Pterm(double error, double Kp) {
  return 999;

}

/**
 * @brief Get Integral term from error, Ki, dT, and previous integral term. Integral Sum represents integral so far, 0 here. So term I will use the current error with dT, and Ki
 * @param the calculated error, Ki variable, change in time dT, and current integral Sum
 * @return The integral term I
 */
double PID::Iterm(double error, double Ki, int dT, double integralSum) {
  return 999;

}

/**
 * @brief Get Derivative term as slope using points current error and previous error
 * @param calculated error, previous Error, Kd, dT
 * @return The derivative term D
 */
double PID::Dterm(double error, double prevError, double Kd, int dT) {
  return 999;
}

/**
 * @brief Get Sum of P,I,and D terms for u(t)
 * @param calculated P,I,D term
 * @return control variable u
 */
double PID::getControl(double Pterm, double Iterm, double Dterm) {
  return 999;
}

/**
 * @brief Compute new velocity given setpoint and actual velocity. New velocity is u(t)*plant
 * @param target velocity and actual velocity
 * @return new velocity
 */
double PID::compute(double setV, double actualV) {
  return 999;

}










