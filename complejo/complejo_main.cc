#include "complejo.h"

main() {
    Complejo complejo1{4, 5}, complejo2{7, -8};
    Complejo resultado;
    resultado = resultado.add(complejo1, complejo2);
    cout << resultado << endl;
    resultado = resultado.sub(complejo1, complejo2);
    cout << resultado << endl;

  return 0;
}
