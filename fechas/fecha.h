#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Date{

public:

    // Constructores y destructores de la clase
    Date();
    Date(int dia, int mes, int ano);
    Date(string fecha);
    Date(int argc, char* argv[]);
    Date(const Date& copia);
    ~Date();

    //Funcion que comprueba o modifica fechas
    bool isFechaValida();
    bool isBisiesto(int ano);
    vector<Date> openFileAndParse(int argc, char* argv[]);
    vector<int> parseToInt(string linea);
    vector<Date> ordenarFechas(vector<Date> fechas);
    void escribirFechas(vector<Date>, int argc, char* argv[]);


    // Setters y getters de la clase Date 
    void setDay(int dia);
    /*const*/ int getDay(void);
    void setMonth(int mes);
    int getMonth(void);
    void setYear(int ano);
    int getYear(void);
    void setFechaDiaMesAno(int dia, int mes, int ano);
    int getFechaDiaMesAno(void);
    void setFecha(int dia, int mes, int ano);


    bool operator< (Date& fecha2);
    bool operator> (Date& fecha2);

    friend ostream& operator<< (ostream& salida, Date& aux);

// Atributos privados de la clase
private:
    int day_;
    int month_;
    int year_;
    int fechaDiaMesAno_;
};