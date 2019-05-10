#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

int main(){
	char resp = 's';
	int fila_inicial = 0, sizefilas = 0;
	while (resp == 's' || resp == 'S'){
		cout <<"Ingrese la fila inicial de la matriz: "<<endl;
		cin >> fila_inicial;
		cout <<"Ingrese el numero de filas: "<<endl;
		cin >> sizefilas;
		cout <<"Desea volver[s/n]: "<<endl;
		cin >> resp;
	}

}
