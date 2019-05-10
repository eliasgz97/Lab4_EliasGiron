#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stringstream;

void imprimirmatriz(char** matrizmasmorra, int sizefilas, int columnas){
	for(int i = 0; i < sizefilas; i++){
        	for(int j = 0; j < columnas; j++){
			cout << matrizmasmorra[i][j] << " ";
                }
		cout << endl;
         }
}

int main(){
	char resp = 's';
	string caracteres = "";
	int fila_inicial = 0, sizefilas = 0, columnas = 0;
	while (resp == 's' || resp == 'S'){
		cout <<"Ingrese el numero de filas: "<<endl;
		cin >> sizefilas;
		cout << "Ingrese cadena de caracteres: "<<endl;
		cin >> caracteres;
		columnas = caracteres.length();
		char** matrizmasmorra = NULL;
		matrizmasmorra = new char*[sizefilas];
		for(int i = 0; i < columnas; i++){
			matrizmasmorra[i] = new char[columnas];
		}
		for(int i = 0; i < columnas; i++){
			matrizmasmorra[0][i] = caracteres[i];
		}
		for(int i = 1; i < sizefilas; i++){
			for(int j = 0; j < columnas; j++){	
				if(j == 0){
					if(matrizmasmorra[i-1][j] == '.' && matrizmasmorra[i-1][j+1] == '.'){
						matrizmasmorra[i][j] = '.';
					} else {
						matrizmasmorra[i][j] = '^';
					}
				} else if(j == columnas-1){
					if(matrizmasmorra[i-1][j-1] == '.' && matrizmasmorra[i-1][j] == '.'){
						matrizmasmorra[i][j] = '.';
					} else {
						matrizmasmorra[i][j] = '^';
					}
				} else {
					if(matrizmasmorra[i-1][j-1] == '.' && matrizmasmorra[i-1][j] == '.' && matrizmasmorra[i-1][j+1] == '^'){
                                        	matrizmasmorra[i][j] = '^';
					} else if(matrizmasmorra[i-1][j] == '^' && matrizmasmorra[i-1][j+1] == '.' && matrizmasmorra[i-1][j+1] == '.'){
						matrizmasmorra[i][j] = '^';
					} else if(matrizmasmorra[i][j-1] == '.' && matrizmasmorra[i-1][j] == '^' && matrizmasmorra[i-1][j+1] == '^'){
						matrizmasmorra[i][j] = '^';
					} else if(matrizmasmorra[i-1][j-1] == '^' && matrizmasmorra[i-1][j] == '^' && matrizmasmorra[i-1][j+1] == '.'){
						matrizmasmorra[i][j] = '^';
					} else {
						matrizmasmorra[i][j] = '.';
					}
                                } 	
			}
		}
		imprimirmatriz(matrizmasmorra, sizefilas, columnas);

		cout <<"Desea volver[s/n]: "<<endl;
		cin >> resp;
	}

}
