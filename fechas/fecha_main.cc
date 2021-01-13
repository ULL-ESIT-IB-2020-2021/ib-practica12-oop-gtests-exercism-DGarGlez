#include "fecha.h"

main(int argc, char* argv[]){

    Date fecha; 

    vector<Date> fechAux = fecha.openFileAndParse(argc, argv);

    vector<Date> fechaFinal = fecha.ordenarFechas(fechAux);

    fecha.escribirFechas(fechaFinal, argc, argv);


    return 0;
}