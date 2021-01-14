#include "complejo.h"

Complejo::Complejo(void):

    real_(1),
    imaginary_(1)

{}

Complejo::Complejo(int real, int imaginario):

    real_(real),
    imaginary_(imaginario)

{}

Complejo::Complejo(const Complejo& copia):
    real_(copia.real_),
    imaginary_(copia.imaginary_)

{}

Complejo::~Complejo(){

    setReal(0);
    setImaginary(0);

}

Complejo Complejo::add(Complejo a, Complejo b){

    Complejo resultado;

    resultado.setReal(a.getReal() + b.getReal());
    resultado.setImaginary(a.getImaginary() + b.getImaginary());

    return (resultado);
}

Complejo Complejo::sub(Complejo a, Complejo b){

    Complejo resultado;

    resultado.setReal(a.getReal() - b.getReal());
    resultado.setImaginary(a.getImaginary() - b.getImaginary());

    return (resultado);
}

int Complejo::getReal(void){
    return (this->real_);
}

void Complejo::setReal(int real){
    this->real_ = real;
}

int Complejo::getImaginary(void){
    return (this->imaginary_);
}

void Complejo::setImaginary(int imaginario){
    this->imaginary_ = imaginario;
}

ostream& operator<< (ostream& salida, Complejo& aux){
    salida << "(" << aux.getReal() << ", " << aux.getImaginary() << ")" << endl;


    return (salida);
}