#include "IntArray.h"
#include <stdio.h>
#include <string.h>

int main() {
  int testPassCnt = 0;
  int testFailCnt = 0;

  // test ascii constructor
  IntArray ascii("AB");
  if (ascii.get(0) == 65 && ascii.get(1) == 66) {
    testPassCnt++;
  } else {
    testFailCnt++;
    printf("Test Fail: ascii should be {65, 66}, instead of {%d, %d}\n",
           ascii.get(0), ascii.get(1));
  }

  // test (length,val) constructor
  // generate lhs = {6, 6, 6}
  IntArray lhs(3, 6);
  if (lhs.get(0) == 6 && lhs.get(1) == 6 && lhs.get(2) == 6) {
    testPassCnt++;
  } else {
    testFailCnt++;
    printf("Test Fail: lhs should be {6, 6, 6}, instead of {%d, %d, %d}\n",
           lhs.get(0), lhs.get(1), lhs.get(2));
  }

  // test IntArray operator+(const IntArray &rhs) const
  // reuslting sum = {6,6,6} + {1,1,1} = {7,7,7}
  IntArray nlhs(3, 6);
  IntArray nrhs(3, 1);
  IntArray sum = nlhs + nrhs;
  /*if (sum.get(0) == 7 && sum.get(1) == 7 && sum.get(2) == 7) {
    testPassCnt++;
  } else {
    testFailCnt++;
    printf("Test Fail: sum should be {7, 7, 7}, instead of {%d, %d, %d}\n",
           sum.get(0), sum.get(1), sum.get(2));
  }*/

  // print test result
  printf("Tests passed: %d, tests failed: %d\n", testPassCnt, testFailCnt);

  if (testFailCnt)
    return 1;
  else
    return 0;
}
