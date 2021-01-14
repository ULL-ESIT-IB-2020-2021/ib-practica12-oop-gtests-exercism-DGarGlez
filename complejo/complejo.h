#include <iostream>

using namespace std;

class Complejo{

public:

    Complejo();
    Complejo(int real, int imaginario);
    Complejo(const Complejo& copia);
    ~Complejo();

    Complejo add(Complejo a, Complejo b);
    Complejo sub(Complejo a, Complejo b);

    void setReal(int real_);
    int getReal(void);
    void setImaginary(int imaginary_);
    int getImaginary(void);

    friend ostream& operator<< (ostream& salida, Complejo& aux);

private:

    int real_;
    int imaginary_;
};