/*
	Name: Manejador de archivos
	Author: Carlos Pimentel
	Date: 08/06/22 
	Description: Hotel
*/
	#include <iostream>
	#include <fstream>
	#include <conio.h>
	#include <windows.h>

	using namespace std;

	void gotoxy(int x, int y);
	void menu();
	void validar(int Max_op, int mn );
	void guardarTxT();
	void efecto();
	void modul_Habitac();
	void modul_Reserv();
	
	int  valor,  T=10;
	bool seguir = true, error =false;
	char val[50];

	int main()
		{
			menu();
		    return 0;
		}
		
		// Función para establecer el menú
		void menu() {
			do{
	        	efecto();
				//opciones
				gotoxy(30,3);
					cout << "Menu de Opciones	";
				gotoxy(30,4);
					cout << "----------------";
	                gotoxy(25,5);
					    cout << "1. Modulo Registro de Habitaciones y clientes";
					gotoxy(25,6);
						cout << "2. Modulo Registro de reservas y prereservas ";
					gotoxy(25,7);
						cout << "3. Salir";
					gotoxy(25,9);
						cout <<	"Escriba el numero de la opcion deseado :";
						cin >>val;
					//valido la entrada por el usuario
					validar(3,1);
					switch (valor) {
						case 1:	modul_Habitac();
						  		break;
						case 2: modul_Reserv();
								break;
			            case 3: seguir = false;
			            		break;
			        }
				}while(seguir);
		}
		
		void modul_Habitac(){
            do{
        	efecto();
			//opciones
			gotoxy(26,3);
				cout << " Modulo Registro de Habitaciones y clientes	";
			gotoxy(26,4);
				cout << "-------------------------------------------";
                gotoxy(25,5);
				    cout << "1. Registrar cliente ";
				gotoxy(25,6);
					cout << "2. Registrar Habitaciones";
				gotoxy(25,7);
					cout << "3. Registrar Tipos de Habitaciones";
				gotoxy(25,8);
					cout << "4. atras";
				gotoxy(25,10);
					cout <<	"Escriba el numero de la opcion deseado :";
					cin >>val;
				//valido la entrada por el usuario
					validar(4,2);
				switch (valor) {
					case 1:		
					  		break;
					case 2:
							break;

		            case 3: 
							break;
		            case 4: menu();
		            		break;
		        }
			}while(seguir);
		}
		
		void modul_Reserv(){
            do{
        	efecto();
			//opciones
			gotoxy(26,3);
				cout << "Modulo Registro de reservas y prereservas	";
			gotoxy(26,4);
				cout << "------------------------------------------";
                gotoxy(25,5);
				    cout << "1. Registrar prereserva ";
				gotoxy(25,6);
					cout << "2. Registrar reserva";
				gotoxy(25,7);
					cout << "3. Registrar cobro";
				gotoxy(25,8);
					cout << "4. atras";
				gotoxy(25,10);
					cout <<	"Escriba el numero de la opcion deseado :";
					cin >>val;
				//valido la entrada por el usuario
					validar(4,2);
				switch (valor) {
					case 1:	
					  		break;
					case 2: 
							break;
		            case 3: 
                            break;
		            case 4: menu();
		            		break;
		        }
			}while(seguir);
		}

		void efecto(){
			system("cls");
			//Col_ini - final , Fil_ini - final
			int ci = 14, cf = 75,  fi = 1,  ff = 14;
			//iterador
			int o;
			//ciclo para las colunnas
			//===========================================================================================================
				for(o=ci; o<=cf; o++) {
					Sleep(T);//hace que el programa tarde unos milisegundos para ejecutar (da el efecto de mivimiento)
					//dibuja la colunna inicial
					gotoxy(o,fi);
					cout<<"ß";
					//dibuja la colunna final
					gotoxy(o,ff);
					cout<<"ß";
				}
				//ciclo para las filas
				for(o=fi; o<=ff; o++){
					Sleep(T);
					//dibuja la fila inicial
					gotoxy(ci,o);
					cout<<"Û";
					//dibuja la fila final
					gotoxy(cf,o);
					cout<<"Û";
				}
				//para borrar el caracter sobresaliente
					gotoxy(ci,ff);
					cout<<"ß";
					gotoxy(cf,ff);
					cout<<"ß";
			//===========================================================================================================
		}
		
		void validar(int Max_op, int mn ){
                valor = atoi(val);
				//==========================================================================
				if(valor > 0 ){
					if( valor > Max_op){
						gotoxy(25,11);
							cout <<	"Debe de escoger un valor valido entre 1 y "<< Max_op;
							getch();
							T=0;
						error = true;
					}
                    error=false;
				}else{
					gotoxy(25,11);
							cout <<	"por favor digite numeros";
							getch();
							T=0;
                	error = true;
				}
				//==========================================================================
				//restablesco el menu correspondiente en el error
				if(error){
					switch (mn) {
						case 1: menu();
						  		break;
						case 2: modul_Habitac();
								break;
			            case 3: modul_Reserv();
	                            break;
			        }
				}
			}
			
		//función para guardar no usado por ahora
		void guardarTxT(){
			ofstream file;//declarar archivo de la libreria
				file.open("Datos.txt");
				//edito
				file <<" cedula :";
				file <<  " 2	";
				file <<" Nombres :";
				file <<  " 3";
				file <<  " 4";
				file <<" Edad :";
				file <<" *";
				file <<endl;
				file.close();
			cout << "Guardado Con exito" ;
			getch();
		}

		//funcion gotoxy
		void gotoxy(int x, int y) {
			COORD coord;
			coord.X = x;
			coord.Y = y;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		}
