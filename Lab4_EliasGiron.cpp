#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

int main(){
	char resp = 's';
	string caracteres = "";
	int fila_inicial = 0, sizefilas = 0, columnas = 0;
	while (resp == 's' || resp == 'S'){
		cout <<"Ingrese la fila inicial de la matriz: "<<endl;
		cin >> fila_inicial;
		cout <<"Ingrese el numero de filas: "<<endl;
		cin >> sizefilas;
		cout << "Ingrese cadena de caracteres: "<<endl;
		cin >> caracteres;
		char** matrizmasmorra = NULL;
		for(int i = 1; i <= caracteres.length(); i++){
			columnas++;
		}
		cout << columnas;	
		cout <<"Desea volver[s/n]: "<<endl;
		cin >> resp;
	}

}
