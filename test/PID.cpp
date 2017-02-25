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
  return (setV-actualV);

}

/**
 * @brief Get Proportional term from error and Kp
 * @param the calculated error and Kp variable
 * @return The proportional term P
 */
double PID::Pterm(double error, double Kp) {
  return (error*Kp);

}

/**
 * @brief Get Integral term from error, Ki, dT, and previous integral term. Integral Sum represents integral so far, 0 here. So term I will use the current error with dT, and Ki
 * @param the calculated error, Ki variable, change in time dT, and current integral Sum
 * @return The integral term I
 */
double PID::Iterm(double error, double Ki, int dT, double integralSum) {
  integralSum+=error*dT;
  return (Ki*integralSum);
}

/**
 * @brief Get Derivative term as slope using points current error and previous error
 * @param calculated error, previous Error, Kd, dT
 * @return The derivative term D
 */
double PID::Dterm(double error, double prevError, double Kd, int dT) {
    return (Kd*((error-prevError)/dT));
}

/**
 * @brief Get Sum of P,I,and D terms for u(t)
 * @param calculated P,I,D term
 * @return control variable u
 */
double PID::getControl(double Pterm, double Iterm, double Dterm) {
  return (Pterm+Iterm+Dterm);

}

/**
 * @brief Compute new velocity given setpoint and actual velocity. New velocity is u(t)*plant
 * @param target velocity and actual velocity
 * @return new velocity
 */
double PID::compute(double setV, double actualV) {
  double error=getError(setV, actualV);
  double pterm=Pterm(error, Kp);
  double iterm=Iterm(error, Ki, dT, integralSum);
  double dterm=Dterm(error, prevError, Kd, dT);
  double out=getControl(pterm, iterm, dterm);
  //prevError=error;

  return (out*plant);

}
