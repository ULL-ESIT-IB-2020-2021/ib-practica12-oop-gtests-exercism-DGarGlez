#include "modificacion.h"

int main(void) {
  
  int a = 1;
  float b = 2.1;
  double c = 2.111;
  Complejo d(1, 1);

  Complejo complejo1{4, 5}, complejo2{7, -8};
  Complejo resultado;

  resultado = resultado + a;
  cout << resultado << endl;

  resultado = resultado + b;
  cout << resultado << endl;

  resultado = resultado + c;
  cout << resultado << endl;

  resultado = resultado - a;
  cout << resultado << endl;

  resultado = resultado - b;
  cout << resultado << endl;

  resultado = resultado - c;
  cout << resultado << endl;

  return 0;
}
