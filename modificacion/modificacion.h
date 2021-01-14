#include <iostream>

using namespace std;

class Complejo{

public:

    Complejo();
    Complejo(float real, float imaginario);
    Complejo(const Complejo& copia);
    ~Complejo();

    Complejo add(Complejo a, Complejo b);
    Complejo sub(Complejo a, Complejo b);
    

    void setReal(float real_);
    float getReal(void);
    void setImaginary(float imaginary_);
    float getImaginary(void);

    Complejo operator + (Complejo a);
    Complejo operator + (const int numero);
    Complejo operator + (const float numero);
    Complejo operator + (const double numero);

    Complejo operator - (const Complejo a);
    Complejo operator - (const int numero);
    Complejo operator - (const float numero);
    Complejo operator - (const double numero);


    friend ostream& operator<< (ostream& salida, Complejo& aux);

private:

    float real_;
    float imaginary_;
};