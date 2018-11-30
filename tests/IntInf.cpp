#include <stdio.h>
#include <string.h>
#include "IntInf.h"

int main(){
  char const *pINF = "+infinity";
  char const *nINF = "-infinity";
  ece309::IntInf num1(1);
  ece309::IntInf num2(pINF);
  ece309::IntInf num3(nINF);
  ece309::IntInf num4;
  ece309::IntInf num0(0);
  int count = 0;

  //test operator=
  num3 = num1;  //test equals operator (1)
  if (num3 == num1){
    printf("operator= test passed\n");
  }

  num3.set(nINF);

//test operator+
  num4 = num1+num2; //number + pINF (pINF)
  if (num4 == num2) count++;
  num4 = num2+num3; //pINF + nINF (0)
  if (num4 == num0) count++;
  num4 = num1+num3; //number + nINF (nINF)
  if (num4 == num3) count++;
  num4 = num1+num1; //number + number (2)
  if(num4.number == 2) count++;
  if(count == 4) {
    printf("operator+ test passed\n");
  }

//test operator-
  count = 0;
  num4 = num1-num2; //number - pINF (nINF)
  if(num4 == num3) count++;
  num4 = num2-num3; //pINF - nINF (pINF)
  if(num4 == num2) count++;
  num4 = num1-num3; //number - nINF (pINF) **
  if(num4 == num2) count++;
  num4 = num1-num1; //number - number (0) **
  if(num4 == num0) count++;
  num4 = num2-num1; //pINF - number (pINF)
  if(num4 == num2) count++;
  num4 = num3-num1; //nINF - number (nINF)
  if(num4 == num3) count++;
  if(count == 6){
    printf("operator- test passed\n");
  }

//test operator*
  count = 0;
  num4 = num1*num2; //number * pINF (pINF)
  if(num4 == num2) count++;
  num4 = num2*num3; //pINF * nINF (nINF)
  if(num4 == num3) count++;
  num4 = num1*num3; //number * nINF (nINF)
  if(num4 == num3) count++;
  num4 = num1*num1; //number * number (1)
  if(num4.number == 1) count++;
  num4 = num2*num1; //pINF * number (pINF)
  if(num4 == num2) count++;
  num4 = num3*num1; //nINF * number (nINF)
  if(num4 == num3) count++;
  if(count == 6){
    printf("operator* test passed\n");
  }

  //test operator/
  count = 0;
  num4 = num1/num2; //number / pINF (0)
  if(num4 == num0) count++;
  num4 = num2/num3; //pINF / nINF (nINF)
  if(num4 == num3) count++;
  num4 = num1/num3; //number / nINF (0)
  if(num4 == num0) count++;
  num4 = num1/num1; //number / number (1)
  if(num4.number == 1) count++;
  num4 = num2/num1; //pINF / number (pINF)
  if(num4 == num2) count++;
  num4 = num3/num1; //nINF / number (nINF)
  if(num4 == num3) count++;
  if(count == 6){
    printf("operator/ test passed\n");
  }

  //test operator>
  count = 0;
  if(!(num3>num1)) count++; //nINF > 1 (false)
  if(num2 > num3) count++; //pINF > nINF (true)
  if(!(num2>num2)) count++; //pINF > pINF (false)
  if(num1>num0) count++; //1>0 (true)
  if(count == 4){
    printf("operator> test passed\n");
  }

  //test operator<
  count = 0;
  if(num3<num1) count++; //nINF < 1 (true)
  if(!(num2 < num3)) count++; //pINF < nINF (false)
  if(!(num2<num2)) count++; //pINF < pINF (false)
  if(!(num1<num0)) count++; //1<0 (false)
  if(count == 4){
    printf("operator< test passed\n");
  }

return 0;
}
