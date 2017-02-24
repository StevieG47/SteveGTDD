/** @file PIDTEST.h

 * @brief PID controller unit test
 *@Author Steven Gambino
 */
#ifndef PIDTEST_H_
#define PIDTEST_H_

#include"PID.h"

/**
 * @brief For PID unit test
 * @param
 * @return none
 */
class PIDtest {
  PID test;

 public:
  /**
   * @brief check error computation works
   * @param target velocity and actual velocity
   * @return 0 for success, 1 for fail
   */
  double errTest() {
    if (test.getError(50, 40) == 10) {
      return 0;
    }

    else {
      return 1;
    }
  }

  /**
   * @brief check D term computation works
   * @param error, previous error, Kd, dT
   * @return 0 for success, 1 for fail
   */
  double DTest() {
    if (test.Dterm(10, 5, 2, 1) == 10) {
      return 0;
    }
    else {
      return 1;
    }
  }

  /**
   * @brief check computation for controller works
   * @param target velocity, actual velocity
   * @return 0 for success, 1 for fail
   */
  double computeTest() {
    if (test.compute(10, 0) > 52 && test.compute(10,0) < 53) {
      return 0;
    } else {
      return 1;
    }
  }
};







#endif /* PIDTEST_H_ */
