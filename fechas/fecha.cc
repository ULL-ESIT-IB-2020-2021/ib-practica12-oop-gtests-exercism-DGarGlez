#include "fecha.h"

Date::Date(void):

    day_(1),
    month_(1),
    year_(1970),
    fechaDiaMesAno_(0)

{}

Date::Date(int dia, int mes, int ano):

    day_(dia),
    month_(mes),
    year_(ano),
    fechaDiaMesAno_()

{setFecha(dia, mes, ano);}

Date::Date(const Date& copia):
    day_(copia.day_),
    month_(copia.month_),
    year_(copia.year_),
    fechaDiaMesAno_(copia.fechaDiaMesAno_)

{}

Date::~Date(){

    setYear(0);
    setMonth(0);
    setDay(0);

}


bool Date::isFechaValida(){

    if((getYear() > 0) && (getMonth() > 0) && (getMonth() < 13) && (getDay() > 0) && (getDay() < 32)){

        switch(getMonth()){
            //meses de 31 dias
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:{
                break;
            }
            //meses de 30 dias
            case 4: 
            case 6:
            case 9:
            case 11:{
                if(getDay() > 30){
                    return (false);
                }
                break; 
            }               
            //febrero
            case 2:{
                if(isBisiesto(getYear())){
                    if(getDay() > 29){
                        return (false);
                    }
                }
                else {
                    if(getDay() > 28){
                        return (false);
                    }
                }
                break;
            }  
            default:{
                cout << "No existe este mes";
                break;
            }  
        }
        
    }
    return(true);
}

bool Date::isBisiesto(int ano){

    bool bisiesto = false;

    if(getYear() % 4 == 0){
        bisiesto = true;
        if(getYear() % 100 == 0){
            bisiesto = false;
            if(getYear() % 400 == 0){
                bisiesto = true;
            }            
        }
    }
    return bisiesto;
}

vector<Date> Date::openFileAndParse(int argc, char* argv[]){

    vector<Date> fechasOrdenar;

    ifstream fichero_programa;
    fichero_programa.open(argv[1]);

    if (fichero_programa.is_open()){

        string linea = " ";

        while(!fichero_programa.eof()){
            
            vector<int> fechaAux;

            getline(fichero_programa, linea);

            fechaAux = parseToInt(linea);

            Date fecha1(fechaAux[0], fechaAux[1], fechaAux[2]);

            fechasOrdenar.push_back(fecha1);
        };

    }
    else{
        cout << "Incapaz de abrir el archivo" << endl;
    }
    fichero_programa.close();

    return(fechasOrdenar);
}

vector<int> Date :: parseToInt(string linea){

    string aux;
    vector<int> dateAux;

    for(int i = 0; i <= linea.size(); i++){
        if((linea[i] != '/') && (i != linea.size())){
            aux += linea[i]; 
        }
        else{
            dateAux.push_back(atoi(aux.c_str())); 
            aux.clear();

        }
    }
    return (dateAux);
}

vector<Date> Date::ordenarFechas(vector<Date> fechas){
    Date temporal;

    for (int i = 0;i < fechas.size(); i++){
		for (int j = 0; j< fechas.size()-1; j++){
			if (fechas[j] > fechas[j+1]){ // Ordena el date de menor a mayor
			temporal = fechas[j]; 
			fechas[j] = fechas[j+1]; 
			fechas[j+1] = temporal;
			}
		}
	}
    return(fechas);
}

void Date::escribirFechas(vector<Date> fechitas, int argc, char* argv[]){
    ofstream fichero_programa;
    fichero_programa.open(argv[2]);

    if (fichero_programa.is_open()){
        for(int i = 0; i < fechitas.size(); i++){
            fichero_programa << fechitas[i];
        }
    }
    else{
        cout << "Incapaz de abrir el archivo" << endl;
    }
}

int Date::getDay(void){
    return (this->day_);
}

void Date::setDay(int dia){
    this->day_ = dia;
}

int Date::getMonth(void){
    return (this->month_);
}

void Date::setMonth(int mes){
    this->month_ = mes;
}

int Date::getYear(void){
    return (this->year_);
}

void Date::setYear(int ano){
    this->year_ = ano;
}

int Date::getFechaDiaMesAno(void){
    return(this->fechaDiaMesAno_);    
}

void Date::setFechaDiaMesAno(int dia, int mes, int ano){
    string aux;

    aux += to_string(year_);
    aux += to_string(month_);
    aux += to_string(day_);
    
    this->fechaDiaMesAno_ = atoi(aux.c_str());
}

void Date::setFecha(int dia, int mes, int ano){
    setDay(dia);
    setMonth(mes);
    setYear(ano);
    if(!isFechaValida()){

        cout << "Fecha rechazada" << endl;
        setYear(1970);
        setMonth(1);
        setDay(1);
    }
}

bool Date::operator< (Date& fecha2){
    bool aux = false;

    if(getYear() == fecha2.getYear()){
        if(getMonth() == fecha2.getMonth()){
            if(getDay() == fecha2.getDay()){
               aux = false; 
            }
            else if(getDay() < fecha2.getDay()){
                aux = true;
            }
            else{
                aux = false;
            }
        }
        else if(getMonth() < fecha2.getMonth()){
            aux = true;
        }
        else{
            aux = false;
        }
        
    }
    else if(getYear() < fecha2.getYear()){
        aux = true;
    }
    else{
        aux = false;
    }
    return (aux);
}

bool Date::operator> (Date& fecha2){
    bool aux = false;

    if(getYear() == fecha2.getYear()){
        if(getMonth() == fecha2.getMonth()){
            if(getDay() == fecha2.getDay()){
               aux = false; 
            }
            else if(getDay() > fecha2.getDay()){
                aux = true;
            }
            else{
                aux = false;
            }
        }
        else if(getMonth() > fecha2.getMonth()){
            aux = true;
        }
        else{
            aux = false;
        }
        
    }
    else if(getYear() > fecha2.getYear()){
        aux = true;
    }
    else{
        aux = false;
    }
    return (aux);
}

ostream& operator<< (ostream& salida, Date& aux){
    salida << aux.getDay() << "/" << aux.getMonth() << "/" << aux.getYear()<< endl;


    return (salida);
}

