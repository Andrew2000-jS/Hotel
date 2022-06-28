	#include <cstdlib>
	#include <iostream>
	#include <sqlite3.h>
	#include <conio.h>
	#include <stdio.h>
	#include <string>
	#include <windows.h>
	#include <stdlib.h>
	#include <fstream>
	
	using namespace std;
    /* ==============================*/
    /*funciones generales*/
	void menu();
	void modul_Habitac();
	void agregar_cliente();
	void agregar_Tip_habit();
	void agregar_habitac();
	 
	void ing_reg(string titulo ,string coma);
	
	void modul_Reserv();
	void agregar_reserv();
	void agregar_cobro();
	
	void modul_busqueda();

	void consultar_client();
	void consultar_habitrac();
	void validar(int Max_op, int mn);
	void efecto();
	void gotoxy(int x, int y);
	
	/*variables para la */
	int valor, T = 10;
	bool seguir = true, error = false;
	char val[50];
	string cadena, aux;
    /* ==============================*/
	/*funciones para la conexion*/
	void conexion();
	bool stetament(string sql, string tipo, string tabla, string campos, string valores);
	static int callback(void *NotUsed, int argc, char **argv, char **azColName);
	/*variables para la conexion*/
    sqlite3 *db;
    char *zErrMsg = 0;
	int rc;
	ofstream file; //para los log
	const char* data = "Callback function called";
	int main(int argc, char* argv[]){
        conexion();
        menu();
		sqlite3_close(db);
		return 0;
	}
	void menu(){
	    do{
	        efecto();
	        // opciones
	        gotoxy(30, 3);
	        cout << "Menu de Opciones	";
	        gotoxy(30, 4);
	        cout << "----------------";
	        gotoxy(25, 5);
	        cout << "1. Modulo Registro de Habitaciones y clientes";
	        gotoxy(25, 6);
	        cout << "2. Modulo Registro de reservas";
	        gotoxy(25, 7);
	        cout << "3. Modulo Busqueda de habitaciones y clientes ";
	        gotoxy(25, 8);
	        cout << "4. Salir";
	        gotoxy(25, 11);
	        cout << "Escriba el numero de la opcion deseado :";
	        cin >> val;
	        // valido la entrada por el usuario
	        validar(4, 1);
	        switch (valor){
	        case 1:
	            modul_Habitac();
	            break;
	        case 2:
	            modul_Reserv();
	            break;
	        case 3:
	            modul_busqueda();
	            break;
	        case 4:
	            system("cls");
	            efecto();
	            gotoxy(30, 3);
	            cout << "Gracias por utilizar el programa";
	            seguir = false;
	            break;
	        }
	    } while (seguir);
	}

	void modul_Habitac(){
	    do{
	        efecto();
	        // opciones
	        gotoxy(26, 3);
	        cout << " Modulo Registro de Habitaciones y clientes	";
	        gotoxy(26, 4);
	        cout << "-------------------------------------------";
	        gotoxy(25, 5);
	        cout << "1. Registrar cliente ";
	        gotoxy(25, 6);
	        cout << "2. Registrar Tipos de Habitaciones";
	        gotoxy(25, 7);
	        cout << "3. Registrar Habitaciones";
	        gotoxy(25, 8);
	        cout << "4. atras";
	        gotoxy(25, 10);
	        cout << "Escriba el numero de la opcion deseado :";
	        cin >> val;
	        // valido la entrada por el usuario
	        validar(4, 2);
	        switch (valor){
	        case 1:
	            efecto();
	            agregar_cliente();
	            break;
	        case 2:
				efecto();
	            agregar_Tip_habit();
	            break;

	        case 3:
                efecto();
	            agregar_habitac();
	            break;
	        case 4:
	            menu();
	            break;
	        }
	    } while (seguir);
	}
	void agregar_cliente(){
        gotoxy(26, 3);
        cout << " Agregar cliente	";
        gotoxy(26, 4);
        cout << "-------------------------------------------";
		ing_reg("Ingrese la cedula ", ",");
        ing_reg("Ingrese el nombre ", ",");
        ing_reg("Ingrese el apellido ", ",");
        ing_reg("Ingrese el telefono ", ",");
        ing_reg("Ingrese la direcion ", "");
        if(stetament("","INSERT INTO ", "cliente", " (cedula, nombre, apellido, telefono, direccion)", " values ("+aux))
		{system("cls");  cout << "registrado"; getch(); }
		aux=" ";
	}
	void agregar_Tip_habit(){
        gotoxy(26, 3);
        cout << " Agregar Tipos de Habitaciones	";
        gotoxy(26, 4);
        cout << "-------------------------------------------";
        ing_reg("Ingrese el codigo del tipo de habitacion", ",");
		ing_reg("Ingrese el nombre del tipo de habitacion", "");
        if(stetament("","INSERT INTO ", "[tipo_de _habitaciones]", " ( tipoHB_id, descripcion)", " values ("+aux))
		{system("cls");  cout << "registrado"; getch(); }
		aux=" ";
	}
	void agregar_habitac(){
        gotoxy(26, 3);
        cout << " Agregar Habitaciones	";
        gotoxy(26, 4);
        cout << "-------------------------------------------";
        ing_reg("Ingrese el codigo de la habitacion ", ",");
        ing_reg("Ingrese el precio de la habitacion ", "");
        if(stetament("","INSERT INTO ", "habitaciones", " (tipoHB_id, precio)", " values ("+aux))
		{system("cls");  cout << "registrado"; getch(); }
        aux=" ";
	}
	void modul_Reserv(){
	    do{
	        efecto();
	        // opciones
	        gotoxy(26, 3);
	        cout << "Modulo Registro de reservas y prereservas	";
	        gotoxy(26, 4);
	        cout << "------------------------------------------";
	        gotoxy(25, 5);
	        cout << "1. Registrar prereserva ";
	        gotoxy(25, 6);
	        cout << "2. Registrar cobro";
	        gotoxy(25, 7);
	        cout << "3. atras";
	        gotoxy(25, 9);
	        cout << "Escriba el numero de la opcion deseado :";
	        cin >> val;
	        // valido la entrada por el usuario
	        validar(4, 2);
	        switch (valor){
	        case 1: agregar_reserv();
	            break;
	        case 2: agregar_cobro();
	            break;
	        case 3:
	            menu();
	            break;
	        }
	    } while (seguir);
	}
	void agregar_reserv(){
        gotoxy(26, 3);
        cout << " Agregar Habitaciones	";
        gotoxy(26, 4);
        cout << "-------------------------------------------";
        ing_reg("Ingrese la cedula del cliente ", ",");
        ing_reg("Ingrese el codigo de la habitacion ", ",");
        ing_reg("Ingrese los días que se quedara ", ",");
        ing_reg("Ingrese el estado de su solicitud ", ",");
        ing_reg("Ingrese el monto a pagar ", "");
        if(stetament("","INSERT INTO ", "reserva", " ( cedula,  habitaciones_id,  estadia, estado,  monto )", " values ("+aux))
		{system("cls");  cout << "registrado"; getch(); }
        aux=" ";
	}
	void agregar_cobro(){
        gotoxy(26, 3);
        cout << " Agregar Habitaciones	";
        gotoxy(26, 4);
        cout << "-------------------------------------------";
        ing_reg("Ingrese la cedula del cliente", ",");
        ing_reg("Ingrese el numero de reserva", ",");
        ing_reg("Ingrese forma de pago", ",");
        ing_reg("Ingrese el monto", "");
        if(stetament("","INSERT INTO ", "cobro", " ( cedula,  reserva_id,  forma_de_pago, monto)", " values ("+aux))
		{system("cls");  cout << "registrado"; getch(); }
        aux=" ";
	}
	void modul_busqueda(){
	    do{
	        efecto();
	        gotoxy(26, 3);
	        cout << " Modulo de busqueda de habitaciones y clientes	";
	        gotoxy(26, 4);
	        cout << "-------------------------------------------";
	        gotoxy(25, 5);
	        cout << "1. Buscar todos los clientes  ";
	        gotoxy(25, 6);
	        cout << "2. Buscar todas las habitaciones";
	        gotoxy(25, 7);
	        cout << "3. atras";
	        gotoxy(25, 10);
	        cout << "Escriba el numero de la opcion deseado :";
	        cin >> val;
	        validar(3, 2);
	        switch (valor){
	        case 1: consultar_client();
	            break;
	        case 2:
	            break;
	        case 3:
	            menu();
	            break;
	        }
	    } while (seguir);
	}
	void consultar_client(){
        gotoxy(26, 3);
        cout << " consultar	clientes";
        gotoxy(26, 4);
        cout << "-------------------------------------------";
        stetament("","select ", "*", "from", " cliente --");
        aux=" ";
	}
	void consultar_habitrac(){
        gotoxy(26, 3);
        cout << " consultar	habitaciones";
        gotoxy(26, 4);
        cout << "-------------------------------------------";
        stetament("","select ", "*", "from", " habitaciones --");
        aux=" ";
	}
	void efecto(){
	    system("cls");
	    // Col_ini - final , Fil_ini - final
	    int ci = 14, cf = 75, fi = 1, ff = 14;
	    // iterador
	    int o;
	    //===========================================================================================================
		// ciclo para las colunnas
		for (o = ci; o <= cf; o++)
	    {
	        Sleep(T); // hace que el programa tarde unos milisegundos para ejecutar (da el efecto de mivimiento)
	        // dibuja la colunna inicial
	        gotoxy(o, fi);
	        cout << "ß";
	        // dibuja la colunna final
	        gotoxy(o, ff);
	        cout << "ß";
	    }
	    // ciclo para las filas
	    for (o = fi; o <= ff; o++){
	        Sleep(T);
	        // dibuja la fila inicial
	        gotoxy(ci, o);
	        cout << "Û";
	        // dibuja la fila final
	        gotoxy(cf, o);
	        cout << "Û";
	    }
	    // para borrar el caracter sobresaliente
	    gotoxy(ci, ff);
	    cout << "ß";
	    gotoxy(cf, ff);
	    cout << "ß";
	    //===========================================================================================================
	}
	void validar(int Max_op, int mn){
	    valor = atoi(val);
	    //==========================================================================
	    if (valor > 0){
	        if (valor > Max_op){
	            gotoxy(25, 11);
	            cout << "Debe de escoger un valor valido entre 1 y " << Max_op;
	            getch();
	            T = 0;
	            error = true;
	        }
	        error = false;
	    }
	    else{
	        gotoxy(25, 11);
	        cout << "por favor digite numeros";
	        getch();
	        T = 0;
	        error = true;
	    }
	    //==========================================================================
	    // restablesco el menu correspondiente en el error
	    if (error){
	        switch (mn){
	        case 1:
	            menu();
	            break;
	        case 2:
	            modul_Habitac();
	            break;
	        case 3:
	            modul_Reserv();
	            break;
	        }
	    }
	}
	void showClient(){

	}
	// funcion gotoxy
	void gotoxy(int x, int y)
	{
	    COORD coord;
	    coord.X = x;
	    coord.Y = y;
	    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}
	/* ==============================*/
	/* funciones para bases de datos*/
	/* ==============================*/
	void conexion(){
        file.open("log.txt", ios::app);
		rc = sqlite3_open("Hotel.db", &db);
	    if( rc ){
			file <<"no se pudo conectar con la base de datos: %s\n"<<sqlite3_errmsg(db);
	   	}
	   	file.close();
	}
	bool stetament(string sql, string tipo, string tabla, string campos, string valores){
	    file.open("log.txt", ios::app); 
		bool resul;
		sql = tipo + tabla + campos + valores+ ");";
		/*inicio de conversion*/
    	// declaring character array : p
	    char p[sql.length()];
	    int i;
	    for (i = 0; i < sizeof(p); i++) {
	        p[i] = sql[i];
	       file << p[i];
	    }/*fin de conversion*/
		rc = sqlite3_exec(db, p, callback, (void*)data, &zErrMsg);
	   	if( rc != SQLITE_OK ){
		    file << "\n" << zErrMsg << endl;// edito
	      	sqlite3_free(zErrMsg);
	      	resul = false;
	   	}else{
       		resul = true;
	   	}
	   	file.close();
		return resul;
	}
	static int callback(void *data, int argc, char **argv, char **azColName){
 	   system("cls");
	   int i;
	   for(i=0; i<argc; i++){
	      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	   }
	   printf("\n");
	   getch();
	   return 0;
	}
	void ing_reg(string titulo ,string coma){
        gotoxy(25, 5);
        cout << "                                             ";
        gotoxy(25, 6);
        cout << "                                             ";
        gotoxy(25, 5);
        cout << titulo;
        gotoxy(25, 6);
        cin >> cadena;
        aux = aux +" '"+cadena+"'"+coma;
        cout << aux;
        getch();
	}
	/* ==============================*/
