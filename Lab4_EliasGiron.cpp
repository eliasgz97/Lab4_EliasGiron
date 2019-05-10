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
	cout << endl;

}
void liberarMatriz(char**& labmatrix,int size){
        for (int i = 0; i < size; i++){
                delete[] labmatrix[i];
                //labmatrix[i] = NULL;
        }
        delete[] labmatrix;
        //labmatrix = NULL;
}
int main(){
	char resp = 's';
	string caracteres = "";
	int fila_inicial = 0, sizefilas = 0, columnas = 0, seguros = 0, trampas = 0;
	while (resp == 's' || resp == 'S'){
		cout <<"Ingrese el numero de filas: "<<endl;
		cin >> sizefilas;
		cout << "Ingrese cadena de caracteres: "<<endl;
		cin >> caracteres;
		cout << endl;
		columnas = caracteres.length();
		char** matrizmasmorra = NULL;
		matrizmasmorra = new char*[sizefilas];
		for(int i = 0; i < columnas; i++){
			matrizmasmorra[i] = new char[columnas];
		}
		for(int i = 0; i < columnas; i++){
			matrizmasmorra[0][i] = caracteres[i];
			if(caracteres[i] == '.'){
				seguros++;
			} else {
				trampas++;
			}
		}
		for(int i = 1; i < sizefilas; i++){
			for(int j = 0; j < columnas; j++){	
				if(j == 0){
					if(matrizmasmorra[i-1][j] == '.' && matrizmasmorra[i-1][j+1] == '.'){
						matrizmasmorra[i][j] = '.';
						seguros++;
					} else {
						matrizmasmorra[i][j] = '^';
						trampas++;
					}
				} else if(j == columnas-1){
					if(matrizmasmorra[i-1][j] == '.' && matrizmasmorra[i-1][j-1] == '.'){
						matrizmasmorra[i][j] = '.';
						seguros++;
					} else {
						matrizmasmorra[i][j] = '^';
						trampas++;
					}
				} else {
					if(matrizmasmorra[i-1][j-1] == '.' && matrizmasmorra[i-1][j] == '.' && matrizmasmorra[i-1][j+1] == '^'){
                                        	matrizmasmorra[i][j] = '^';
						trampas++;
					} else if(matrizmasmorra[i-1][j-1] == '^' && matrizmasmorra[i-1][j] == '.' && matrizmasmorra[i-1][j+1] == '.'){
						matrizmasmorra[i][j] = '^';
						trampas++;
					} else if(matrizmasmorra[i-1][j-1] == '.' && matrizmasmorra[i-1][j] == '^' && matrizmasmorra[i-1][j+1] == '^'){
						matrizmasmorra[i][j] = '^';
						trampas++;
					} else if(matrizmasmorra[i-1][j-1] == '^' && matrizmasmorra[i-1][j] == '^' && matrizmasmorra[i-1][j+1] == '.'){
						matrizmasmorra[i][j] = '^';
						trampas++;
					} else {
						matrizmasmorra[i][j] = '.';
						seguros++;
					}
                                } 	
			}
		}
		imprimirmatriz(matrizmasmorra, sizefilas, columnas);
		cout << "La cantidad de libres son: "<<seguros<<" y la cantidad de trampas son: "<<trampas<<endl;
		//liberar casillas
	        for(int i = 1; i < columnas; i++){
        	        delete[] matrizmasmorra[i];
                	matrizmasmorra[i] = NULL;
        	}
        	//liberar la matriz de la memoria
        	if(matrizmasmorra != NULL){
                	delete[] matrizmasmorra;
                	matrizmasmorra = NULL;
        	}
		cout <<"Desea volver[s/n]:"<<endl;
		cin >> resp;
	}

}
