#ifndef INTINF_H
#define INTINF_H

#include <stdio.h>
#include <string.h>
#define  NONUM -3481057


class IntInf{
public:
  bool neg_inf;
  bool pos_inf;
  int number;
public:
  IntInf(int num=0){
    neg_inf = false;
    pos_inf = false;
    number = num;
  };
  IntInf(char const *str){
    if (strcmp(str,"+infinity") == 0){
      neg_inf = false;
      pos_inf = true;
      number = NONUM;
    };
    if  (strcmp(str,"-infinity") == 0){
      neg_inf = true;
      pos_inf = false;
      number = NONUM;
    }
  }
  void print(){
    if (pos_inf)
      printf("+infinity\n");
    else if(neg_inf)
      printf("-infinity\n");
    else{
      printf("%d\n", number);}
  }
  void set(int num=0){
    neg_inf = false;
    pos_inf = false;
    number = num;
  }
  void set(char const *str){
    if (strcmp(str,"+infinity") == 0){
      neg_inf = false;
      pos_inf = true;
      number = NONUM;
    };
    if  (strcmp(str,"-infinity") == 0){
      neg_inf = true;
      pos_inf = false;
      number = NONUM;
    }
  }
  IntInf operator= (const IntInf& rhs);
  IntInf operator+ (const IntInf& rhs);
  IntInf operator- (const IntInf& rhs);
  IntInf operator* (const IntInf& rhs);
  IntInf operator/ (const IntInf& rhs);
  bool operator== (const IntInf& rhs);
  bool operator> (const IntInf& rhs);
  bool operator< (const IntInf& rhs);
};

IntInf IntInf::operator= (const IntInf& rhs){
  if(&rhs == this){
    return *this;
  }
  pos_inf = rhs.pos_inf;
  neg_inf = rhs.neg_inf;
  number = rhs.number;
  return *this;
}
IntInf IntInf::operator+ (const IntInf& rhs){
  char const *pINF = "+infinity";
  char const *nINF = "-infinity";
  IntInf result(0);

  if((rhs.pos_inf&&neg_inf) || (rhs.neg_inf&&pos_inf)){
    result.set(0);
  }
  else if(rhs.pos_inf || pos_inf){
    result.set(pINF);
  }
  else if (rhs.neg_inf || neg_inf){
    result.set(nINF);
  }
  else{
    result.set(rhs.number + number);
  }
  return result;
}
IntInf IntInf::operator- (const IntInf& rhs){
  char const *pINF = "+infinity";
  char const *nINF = "-infinity";
  IntInf result(0);

  if(rhs.pos_inf&&neg_inf){
    result.set(nINF);
  }
  else if(rhs.neg_inf&&pos_inf){
    result.set(pINF);
  }
  else if(rhs.neg_inf || pos_inf){
    result.set(pINF);
  }
  else if (rhs.pos_inf || neg_inf){
    result.set(nINF);
  }
  else{
    result.set(number - rhs.number);
  }
  return result;
}
IntInf IntInf::operator* (const IntInf& rhs){
  char const *pINF = "+infinity";
  char const *nINF = "-infinity";
  IntInf result(1234);
  if (number == NONUM && rhs.number == NONUM){
    if((rhs.pos_inf && neg_inf) || (rhs.neg_inf && pos_inf)){
      result.set(nINF);
    }
    else if((rhs.neg_inf && neg_inf) || (rhs.pos_inf && pos_inf)){
      result.set(pINF);
    }
  }
  else if (pos_inf || rhs.pos_inf){
    if ((number > 0)||(rhs.number > 0)){
      result.set(pINF);
    }
    else result.set(nINF);
  }
  else if (neg_inf || rhs.neg_inf){
    if ((number > 0)||(rhs.number > 0)){
      result.set(nINF);
    }
    else result.set(pINF);
  }
  else if((rhs.number == 0) || (number == 0)){
    result.set(0);
    return result;
  }
  else result.set(rhs.number * number);


  return result;
}
IntInf IntInf::operator/ (const IntInf& rhs){
  char const *pINF = "+infinity";
  char const *nINF = "-infinity";
  IntInf result(1234);
  if (number == NONUM && rhs.number == NONUM){
    if((rhs.pos_inf && neg_inf) || (rhs.neg_inf && pos_inf)){
      result.set(nINF);
    }
    else if((rhs.neg_inf && neg_inf) || (rhs.pos_inf && pos_inf)){
      result.set(pINF);
    }
  }
  else if (rhs.pos_inf || rhs.neg_inf){
    result.set(0);
  }
  else if (pos_inf){
    if (rhs.number > 0){
      result.set(pINF);
    }
    else result.set(nINF);
  }
  else if (neg_inf){
    if (rhs.number > 0){
      result.set(nINF);
    }
    else result.set(pINF);
  }
  else result.set(rhs.number * number);


  return result;
}
bool IntInf::operator== (const IntInf& rhs){
  if ((rhs.number == number)&&(rhs.pos_inf == pos_inf)&&(rhs.neg_inf == neg_inf))
    return true;
  else
    return false;

}
bool IntInf::operator> (const IntInf& rhs){
  if (pos_inf){
    if(rhs.pos_inf) return false;
    return true;
  }
  else if (rhs.neg_inf){
    if(neg_inf) return false;
    return true;
  }
  else if (number > rhs.number) return true;
  else return false;
}
bool IntInf::operator< (const IntInf& rhs){
  if (rhs.pos_inf){
    if(pos_inf) return false;
    return true;
  }
  else if (neg_inf){
    if(rhs.neg_inf) return false;
    return true;
  }
  else if (number < rhs.number) return true;
  else return false;
}

#endif //INTINF_H
