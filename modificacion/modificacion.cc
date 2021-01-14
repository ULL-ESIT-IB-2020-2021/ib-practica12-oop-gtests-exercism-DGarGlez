#include "modificacion.h"

Complejo::Complejo(void):

    real_(0),
    imaginary_(0)

{}

Complejo::Complejo(float real, float imaginario):

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

float Complejo::getReal(void){
    return (this->real_);
}

void Complejo::setReal(float real){
    this->real_ = real;
}

float Complejo::getImaginary(void){
    return (this->imaginary_);
}

void Complejo::setImaginary(float imaginario){
    this->imaginary_ = imaginario;
}

Complejo Complejo::operator + (Complejo a){
    Complejo resultado;
    resultado.setReal(getReal() + a.getReal());
    resultado.setImaginary(getImaginary() + a.getImaginary());
    return(resultado);
}

Complejo Complejo::operator + (const int numero){
    Complejo resultado;
    resultado.setImaginary(getImaginary();
    float numeroF = ((float) (numero));
    resultado.setReal(getReal() + (numeroF));
    return(resultado);
}

Complejo Complejo::operator + (const float numero){
    Complejo resultado;
    resultado.setImaginary(getImaginary();
    resultado.setReal(getReal() + numero);
    return(resultado);
}

Complejo Complejo::operator + (const double numero){
    Complejo resultado;
    resultado.setImaginary(getImaginary();
    resultado.setReal(getReal() + ((float) numero));
    return(resultado);
}

Complejo Complejo::operator - (Complejo a){
    Complejo resultado;
    resultado.setReal(getReal() - a.getReal());
    resultado.setImaginary(getImaginary() - a.getImaginary());
    return(resultado);
}

Complejo Complejo::operator - (const int numero){
    Complejo resultado;
    resultado.setImaginary(getImaginary();
    float numeroF = ((float) (numero));
    resultado.setReal(getReal() - (numeroF));
    return(resultado);
}

Complejo Complejo::operator - (const float numero){
    Complejo resultado;
    resultado.setImaginary(getImaginary();
    resultado.setReal(getReal() - numero);
    return(resultado);
}

Complejo Complejo::operator - (const double numero){
    Complejo resultado;
    resultado.setImaginary(getImaginary();
    resultado.setReal(getReal() - ((float) numero));
    return(resultado);
}

ostream& operator<< (ostream& salida, Complejo& aux){
    salida << "(" << aux.getReal() << ", " << aux.getImaginary() << ")" << endl;

    return (salida);
}