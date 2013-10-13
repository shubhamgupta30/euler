#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

#define SIZE 1000
#define N 100

struct number {
  char buff[SIZE];
  int deci_number;
  int a_n;
  int b_n;
  bool isValid;
  int s_n;
  int msb;
} num;

void init_num() {
  for(int i = 0; i < SIZE; i++) num.buff[i] = '0';
  num.isValid = true;
  num.a_n = 0;
  num.b_n = 1;
  num.deci_number = 0;
  num.s_n = 1;
  num.msb = 0;
}

void add_one_to_num() {
  int i = 0;
  while (i < SIZE && num.buff[i] == '1') {
    num.buff[i++] = '0';
  }
  if(i >= SIZE) {
    num.isValid = false;
  } else {
    num.buff[i] = '1';
    if (i > 0) num.a_n -= i-1;
    if (i+1 < SIZE && num.buff[i+1] == '1') num.a_n++;
    num.deci_number ++;
    num.b_n = num.a_n % 2 == 0 ? 1 : -1;
    num.s_n += num.b_n;
    if(i > num.msb) num.msb = i;
  }
}

void print_number() {
  cout << "n = " << num.deci_number;
  cout << " binary = "; for(int i = num.msb; i>=0; i--) cout << num.buff[i];
  cout << " a(n) = " << num.a_n << " b(n) = " << num.b_n;
  cout << " s(n) = " << num.s_n << " msb = " << num.msb;
  cout << " isValid = " << num.isValid << "\n";
}

int main() {
  init_num();
  print_number();
  for (int i = 0; i < N; i++) {
    add_one_to_num();
    print_number();
  }
}
