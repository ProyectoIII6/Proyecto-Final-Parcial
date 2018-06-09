#include <iostream>
#include <conio.h>
#include <fstream>
#include <windows.h>
#include <string>
#include <cstdlib>
#include <cstring>

using namespace std;

struct listaS {
	int dato;
	listaS *siguiente;
};

struct cola {
	int dato;
	cola *siguiente;
};

void esconderCursor();
void SetColor(int ForgC);
void gotoxy(int, int);
void opcionesPrincipal();
void menuPrincipal();

//OPCION 1
void listaSimple();
void insertarLista(listaS *&, int);
void mostrarLista(listaS *);


//OPCION 2
void colaDinamica();
void insertarCola(cola *&, cola *&, int);
bool colaVacia(cola *);
void suprimirCola(cola *&, cola *&, int &);

//OPCION 3
struct Nodo {
	char curso[50];
	Nodo *sig;
};

struct Clave {
	char nombre[50];
	Clave *sig;
	Nodo *cab;
	Nodo *pie;
}*cabeza, *fin;
void Tabla_hash();
void CrearClave(char clave[]);
void BuscarClave(Clave *&encabezado, char clave[], char curso[]);
void MostrarTabla();
void MostrarDatos(Nodo *&encabezado);
void RegistrarDatos(Nodo *&encabezado, Nodo *&pie, char curso[]);


//OPCION 4
typedef struct nodo {
	int dato;
	struct nodo *siguiente;
	struct nodo *atras;
}nodo;

nodo *primero = NULL;
nodo *ultimo = NULL;

void lista_doble();
void insertarNodo();
void mostrarListaPU();
void mostrarListaUP();

//OPCION 5
typedef struct nodoCircular {
	int dato;
	struct nodoCircular *siguiente;
}nodoCircular;
nodoCircular *principio = NULL;
nodoCircular *final = NULL;
void lista_circular();
void insertarNodoCircular();
void mostrarLista();


int y=0;

//OPCION 6
void menuPILA();
void Push();
void Pop();
void Recorrer();
int Pila[6];
int Inicio, Final, Tope, Opcion = 0;
struct
{

	int edad[6];
	char nomb[6];
}persona;

//OPCION 7
typedef struct _nodo {
	int valor;
	struct _nodo *siguiente;
}tipoNodo;

typedef tipoNodo *pNodo;
typedef tipoNodo *Lista;

void menuListaEstatica();

//OPCION 8
int tam;
int matrizD0[100][100];
int matrizS0[100][100];
int matrizD[100][100];
int matrizS[100][100];
int matrizR1[100][100];
const int inf = 9999999;

void gotoxy(int, int);
void SetColor(int);
void opciones();
void crear();
void mostrar();
void floyd();
void menuFloyd();

//OPCION 9 
typedef struct dobleenlzada {
	int num;
	struct dobleenlazada *siguiente;
	struct dobleenlazada *anterior;
}dobleen;

typedef struct simple1 {
	int num;
	struct simple1 *siguiente;

}simple11;

typedef struct simple2 {
	int num;
	struct simple2 *siguiente;
}simple22;

dobleen *inicio,  *recorrido;
simple11 *recorrido2;
simple22 *recorrido3;
dobleen *nuevo;
simple11 *inicio2, *final2, *nuevo2;
simple22 *inicio3, *final3, *nuevo3;

void menudiferencia();

//OPCION 10

struct NodoABB {
	int dato;
	NodoABB *der;
	NodoABB *izq;
};

void menuABB();
NodoABB *crearNodoABB(int);
void insertarNodo(NodoABB *&, int);
void mostrarArbol(NodoABB *, int);
void mostrarArbolDerecho(NodoABB *, int);
void mostrarArbolIzquierdo(NodoABB *, int);
void mostrarNodosTerminales(NodoABB *, int);
void mostrarNodos(NodoABB *);

NodoABB *arbol = NULL;




int main() {
	esconderCursor();
	menuPrincipal();
	system("pause");
}

void esconderCursor() {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}

void SetColor(int ForgC) {
	WORD wColor;

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	if (GetConsoleScreenBufferInfo(hStdOut, &csbi)) {
		wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
		SetConsoleTextAttribute(hStdOut, wColor);
	}
}

void gotoxy(int x, int y) {
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void opcionesPrincipal() {
	SetColor(15);
	gotoxy(50, 4);  cout << "LISTA SIMPLE";
	gotoxy(30, 5);  cout << "_____________________________________________________________";
	gotoxy(50, 6);  cout << "COLA DINAMICA";
	gotoxy(30, 7);  cout << "_____________________________________________________________";
	gotoxy(55, 8);  cout << "TABLA DE HASH";
	gotoxy(30, 9);  cout << "_____________________________________________________________";
	gotoxy(55, 10); cout << "LISTA DOBLE";
	gotoxy(30, 11); cout << "_____________________________________________________________";
	gotoxy(55, 12); cout << "LISTA CIRCULAR";
	gotoxy(30, 13); cout << "_____________________________________________________________";
	gotoxy(55, 14); cout << "PILA DINAMICA";
	gotoxy(30, 15); cout << "_____________________________________________________________";
	gotoxy(55, 16); cout << "LISTA ESTATICA";
	gotoxy(30, 17); cout << "_____________________________________________________________";
	gotoxy(55, 18); cout << "MENU FLOYD";
	gotoxy(30, 19); cout << "_____________________________________________________________";
	gotoxy(55, 20); cout << "DIFERENCIA ENTRE PILA Y COLA";
	gotoxy(30, 21); cout << "_____________________________________________________________";
	gotoxy(55, 22); cout << "ARBOL BINARIO";
	gotoxy(30, 23); cout << "_____________________________________________________________";
	gotoxy(56, 24); cout << "SALIR";
	gotoxy(30, 25); cout << "_____________________________________________________________";

	if (y == 4) {
		SetColor(11);
		gotoxy(50, 4);  cout << "LISTA SIMPLE";
		SetColor(13);
		gotoxy(30, 5);  cout << "_____________________________________________________________";
	}
	else if (y == 6) {
		SetColor(11);
		gotoxy(50, 6);  cout << "COLA DINAMICA";
		SetColor(13);
		gotoxy(30, 7);  cout << "_____________________________________________________________";
	}
	else if (y == 8) {
		SetColor(11);
		gotoxy(55, 8);  cout << "TABLA DE HASH";
		SetColor(13);
		gotoxy(30, 9);  cout << "_____________________________________________________________";
	}
	else if (y == 10) {
		SetColor(11);
		gotoxy(55, 10);  cout << "LISTA DOBLE";
		SetColor(13);
		gotoxy(30, 11);  cout << "_____________________________________________________________";
	}
	else if (y == 12) {
		SetColor(11);
		gotoxy(55, 12);  cout << "LISTA CIRCULAR";
		SetColor(13);
		gotoxy(30, 13);  cout << "_____________________________________________________________";
	}
	else if (y == 14) {
		SetColor(11);
		gotoxy(55, 14);  cout << "PILA DINAMICA";
		SetColor(13);
		gotoxy(30, 15);  cout << "_____________________________________________________________";
	}
	else if (y == 16) {
		SetColor(11);
		gotoxy(55, 16);  cout << "LISTA ESTATICA";
		SetColor(13);
		gotoxy(30, 17);  cout << "_____________________________________________________________";
	}
	else if (y == 18) {
		SetColor(11);
		gotoxy(55, 18);  cout << "MENU FLOYD";
		SetColor(13);
		gotoxy(30, 19);  cout << "_____________________________________________________________";
	}
	else if (y == 20) {
		SetColor(11);
		gotoxy(55, 20);  cout << "DIFERENCIA ENTRE PILA Y COLA";
		SetColor(13);
		gotoxy(30, 21);  cout << "_____________________________________________________________";
	}
	else if (y == 22) {
		SetColor(11);
		gotoxy(55, 22);  cout << "ARBOL BINARIO";
		SetColor(13);
		gotoxy(30, 23);  cout << "_____________________________________________________________";
	}
	else if (y == 24) {
		SetColor(11);
		gotoxy(56, 24);  cout << "SALIR";
		SetColor(13);
		gotoxy(30, 25);  cout << "_____________________________________________________________";
	}
}

void menuPrincipal() {
	y = 4;
	char tecla;

	do {
		opcionesPrincipal();
		tecla = _getch();

		if (tecla == -32) {
			tecla = _getch();

			if (tecla == 72) { //tecla de arriba 
				if (y == 4)
					y = 24;
				else
					y -= 2;
			}
			if (tecla == 80) { //tecla de abajo
				if (y == 24)
					y = 4;
				else
					y += 2;
			}
		}

		if (tecla == 13) { //tecla enter
			if (y == 4) {
				system("cls");
				listaSimple();
				system("cls");
			}
			else if (y == 6) {
				system("cls");
				colaDinamica();
				system("cls");
			}
			else if (y == 8) {
				system("cls");
				Tabla_hash();
				system("cls");

			}
			else if (y == 10) {
				system("cls");
				lista_doble();
				system("cls");

			}
			else if (y == 12) {
				system("cls");
				lista_circular();
				system("cls");

			}
			else if (y == 14) {
				system("cls");
				menuPILA();
				system("cls");
			}
			else if (y == 16) {
				system("cls");
				menuListaEstatica();
				system("cls");
			}
			else if (y == 18) {
				system("cls");
				menuFloyd();
				system("cls");
			}
			else if (y == 20) {
				system("cls");
				menudiferencia();
				system("cls");
			}
			else if (y == 22) {
				system("cls");
				menuABB();
				system("cls");
			}
			else if (y == 24) {
				break;
			}
		}
	} while (1);
}

//OPCION 1
void listaSimple() {
	listaS *lista = NULL;
	int dato;
	SetColor(13);
	gotoxy(0, 2); cout << "________________________________________________________________________________________________________________________";
	SetColor(11); gotoxy(45, 1); cout << "LISTA SIMPLEMENTE ENLAZADA LAB NO.1";
	gotoxy(10, 7); cout << "PARA SALIR DE ESTA OPCION DEL PROGRAMA DIGITE '-1' ";

	for (int i = 3; i <= 30; i++) {
		gotoxy(102, i); cout << "|";
		gotoxy(108, i); cout << "|";
	}

	do {
		gotoxy(10, 9); cout << "Digite un dato: ";
		gotoxy(28, 9); cin >> dato;
		insertarLista(lista, dato);
		mostrarLista(lista);
	} while (dato != -1);

	gotoxy(10, 20); system("pause");
}

void insertarLista(listaS *&lista, int n) {
	listaS *nuevo_nodo = new listaS();
	nuevo_nodo->dato = n;

	listaS *aux1 = lista;
	listaS *aux2 = NULL;

	while ((aux1 != NULL) && (aux1->dato < n)) {
		aux2 = aux1;
		aux1 = aux1->siguiente;
	}

	if (lista == aux1)
		lista = nuevo_nodo;
	else
		aux2->siguiente = nuevo_nodo;

	nuevo_nodo->siguiente = aux1;
}

void mostrarLista(listaS *lista) {
	int i = 5;
	listaS *actual = new listaS();

	actual = lista;
	while (actual != NULL) {
		gotoxy(105, i + 1); cout << actual->dato;
		actual = actual->siguiente;
		i += 2;
	}
}

//OPCION 2
void colaDinamica() {
	cola *frente = NULL;
	cola *fin = NULL;
	int dato, i = 17;

	SetColor(13);
	gotoxy(0, 2); cout << "________________________________________________________________________________________________________________________";
	SetColor(11); gotoxy(45, 1); cout << "COLA ENLAZADA LAB NO.2";
	gotoxy(10, 7); cout << "PARA SALIR DE ESTA OPCION DEL PROGRAMA DIGITE '-1' ";

	do {
		gotoxy(10, 9); cout << "Digite un dato: ";
		gotoxy(28, 9); cin >> dato;
		insertarCola(frente, fin, dato);
	} while (dato != -1);

	gotoxy(15, 14); cout << "MOSTRANDO COLA INSERTADA";

	while (frente != NULL) {
		suprimirCola(frente, fin, dato);

		if (frente != NULL) {
			gotoxy(i, 17); cout << dato;
		}
		i += 3;
	}
	gotoxy(14, 18); cout << "|";
	gotoxy(14, 19); cout << "frente";

	gotoxy(i - 3, 18); cout << "|";
	gotoxy(i - 3, 19); cout << "fin";
	gotoxy(20, 20); system("pause");
}

void insertarCola(cola *&frente, cola *&fin, int n) {
	cola *nuevo_nodo = new cola();

	nuevo_nodo->dato = n;
	nuevo_nodo->siguiente = NULL;

	if (colaVacia(frente))
		frente = nuevo_nodo;
	else
		fin->siguiente = nuevo_nodo;

	fin = nuevo_nodo;
}

bool colaVacia(cola *frente) {
	return (frente == NULL) ? true : false;
}

void suprimirCola(cola *&frente, cola *&fin, int &n) {
	n = frente->dato;
	cola *aux = frente;

	if (frente == fin) {
		frente = NULL;
		fin = NULL;
	}
	else
		frente = frente->siguiente;

	delete aux;
}

//OPCION 3
void CrearClave(char clave[]) {
	Clave *nueva_clave = new Clave();
	strcpy_s(nueva_clave->nombre, clave);
	Clave *actual = new Clave();
	actual = cabeza;
	Clave *anterior = new Clave();

	if (cabeza == NULL) {
		//Si la tabla esta vacia
		cabeza = nueva_clave;
		nueva_clave->sig = NULL;
		fin = cabeza;
	}
	else {
		while (actual != NULL) {
			if (strcmp(clave, actual->nombre) < 0) {
				if (actual == cabeza) {
					//Si la clave es menor que el actual y es la cabeza
					nueva_clave->sig = cabeza;
					cabeza = nueva_clave;
					break;
				}
				else {
					//Si la clave es menor que el actual y no es la cabeza
					anterior->sig = nueva_clave;
					nueva_clave->sig = actual;
					break;
				}
			}
			else if (strcmp(clave, actual->nombre) > 0) {
				if (actual == fin) {
					//Si la clave es mayor que toda la lista, se inserta al final
					fin->sig = nueva_clave;
					nueva_clave->sig = NULL;
					fin = nueva_clave;
					break;
				}
				else {
					//Si la clave es menor al que se analizo, que siga recorriendo la lista
					anterior = actual;
					actual = actual->sig;
				}
			}
			else {
				cout << "No se puede ingresar nuevos" << endl;
				break;
			}
		}
	}
}

void BuscarClave(Clave *&encabezado, char clave[], char curso[]) {
	Clave *buscador = new Clave();
	buscador = encabezado;

	if (buscador != NULL) {
		while (buscador != NULL) {
			if (strcmp(clave, buscador->nombre) == 0) {
				RegistrarDatos(buscador->cab, buscador->pie, curso);
				break;
			}
			buscador = buscador->sig;
		}
	}
}

void RegistrarDatos(Nodo *&encabezado, Nodo *&pie, char curso[]) {
	Nodo *nuevo_nodo = new Nodo();
	strcpy_s(nuevo_nodo->curso, curso);

	if (encabezado == NULL) {
		encabezado = nuevo_nodo;
		nuevo_nodo->sig = NULL;
		pie = encabezado;
	}
	else {
		pie->sig = nuevo_nodo;
		nuevo_nodo->sig = NULL;
		pie = nuevo_nodo;
	}
}

void MostrarTabla() {
	Clave *actual = new Clave();
	actual = cabeza;

	if (actual != NULL) {
		while (actual != NULL) {
			cout << actual->nombre << endl;
			cout << endl;
			MostrarDatos(actual->cab);
			actual = actual->sig;
		}
	}
}

void MostrarDatos(Nodo *&encabezado) {
	Nodo *actual = new Nodo();
	actual = encabezado;
	if (actual != NULL) {
		while (actual != NULL) {
			cout << " -> " << actual->curso << endl;
			actual = actual->sig;
		}
	}
	cout << endl;
}

void Tabla_hash() {
	int opc = 0;
	int salida = 0;
	char curso[50];
	char unidades[50];

	while (opc != 4) {
		system("cls");
		cout << "Tabla de Hash" << endl;
		cout << "[1] Crear Curso" << endl;
		cout << "[2] Agregar Unidades" << endl;
		cout << "[3] Consultar Curso" << endl;
		cout << "[4] Salir" << endl;
		cin >> opc; cin.ignore();

		switch (opc) {
		case 1:
			system("cls");
			cout << "-> Creacion de Cursos <- " << endl;
			cout << endl;
			cout << "Ingrese el nombre del curso " << endl;
			gets_s(curso);
			CrearClave(curso);
			strcpy_s(curso, "");
			system("pause>null");
			break;
		case 2:

			system("cls");
			cout << "-> Unidades <-" << endl;
			cout << endl;
			cout << "Ingrese el nombre del curso" << endl;
			gets_s(curso);

			while (salida != 1) {
				cout << "Ingrese la unidad" << endl;
				gets_s(unidades);

				BuscarClave(cabeza, curso, unidades);
				strcpy_s(unidades, "");

				cout << "Desea Ingresar otra Unidad? [SI = 0 | NO = 1]" << endl;
				cin >> salida; cin.ignore();
				cout << endl;
			}
			strcpy_s(curso, "");
			salida = 0;
			system("pause>null");
			break;
		case 3:
			system("cls");
			cout << "-> Lista de Cursos <-" << endl;
			cout << endl;
			MostrarTabla();
			system("pause>null");
			break;
		}
	}
}

//OPCION 4
void insertarNodo() {
	system("cls");
	char op;
	nodo *nuevo = new nodo();
	cout << "..:INGRESO DE DATOS:..\n";
	cout << "Ingrese un valor entero ";
	cin >> nuevo->dato;
	if (primero == NULL)
	{
		primero = nuevo;
		primero->siguiente = NULL;
		primero->atras = NULL;
		ultimo = primero;
	}
	else
	{
		ultimo->siguiente = nuevo;
		nuevo->siguiente = NULL;
		nuevo->atras = ultimo;
		ultimo = nuevo;

	}
	cout << "Dato ingresado con exito\n ";
	system("pause");
}

void mostrarListaPU() {
	system("cls");
	cout << "\n...:LISTA DEL PRIMERO AL ULTIMO:...\n";
	nodo *actual = new nodo();
	actual = primero;
	if (primero != NULL)
	{
		while (actual != NULL)
		{
			cout << "\n" << actual->dato;
			actual = actual->siguiente;
		}
	}
	else
	{
		cout << "La lista se encuentra vacia\n";
	}

}

void mostrarListaUP() {

	cout << "\n...:LISTA DEL ULTIMO AL PRIMERO:...\n";
	nodo *actual = (nodo*)malloc(sizeof(nodo));
	actual = ultimo;
	if (primero != NULL)
	{
		while (actual != NULL)
		{
			cout << "\n" << actual->dato;
			actual = actual->atras;
		}
	}
	else
	{
		cout << "La lista se encuentra vacia\n";
	}

}

void lista_doble() {
	insertarNodo();
	insertarNodo();
	insertarNodo();
	insertarNodo();
	insertarNodo();
	insertarNodo();
	mostrarListaPU();
	mostrarListaUP();
	cout << endl;
	system("pause");
}

//OPCION 5
void insertarNodoCircular() {
	nodoCircular *nuevo = new nodoCircular();
	cout << "\nIngrese un dato entero ";
	cin >> nuevo->dato;

	if (principio == NULL)
	{
		principio = nuevo;
		principio->siguiente = principio;
		final = principio;
	}
	else
	{
		final->siguiente = nuevo;
		nuevo->siguiente = principio;
		final = nuevo;
	}
	cout << "\nNodo ingresado con exito\n";

}

void mostrarLista() {
	nodoCircular *actual = new nodoCircular();
	actual = principio;
	cout << "\n..:LA LISTA INGRESADA ES:.\n";
	if (primero != NULL)
	{
		do
		{
			cout << "\n" << actual->dato;
			actual = actual->siguiente;
		} while (actual != principio);
	}
	else
	{
		"\nLa lista se encuentra vacia\n";
	}
}

void lista_circular() {
	insertarNodoCircular();
	insertarNodoCircular();
	insertarNodoCircular();
	insertarNodoCircular();
	insertarNodoCircular();
	mostrarLista();
	cout << endl;
	system("pause");
}

//OPCION 6
void Push() {
	system("cls");
	if (Tope == Final)
	{
		cout << "La pila se encuentra llena, ocasionaria desbordamiento";
	}
	else
	{

		cout << "Ingrese una edad" << endl;
		Final++;
		cin >> persona.edad[Final];
		cout << "ingrese un nombre" << endl;
		cin >> persona.nomb;


		cout << "Valor agregado en la Pila en la Posicion : ";
		cout << Final;
	}
}

void Pop() {
	system("cls");
	if (Final == 0)
	{
		cout << "La pila se encuentra vacia, no procede";
	}
	else
	{
		cout << "Eliminando de la Pila el valor: ";
		cout << Pila[Final];
		cout << " De la posicion en la Pila: ";
		cout << Final;
		Pila[Final] = 0;
		Final--;

	}
}

void Recorrer() {
	system("cls");
	if (Final == 0)
	{
		cout << "La pila se encuentra vacia, no procede";
	}
	else
	{
		for (int r = 1; r <= Final; r++)
		{
			cout << "Posicion en Pila: ";
			cout << r;
			cout << " \n";
			cout << ", Valor en posicion : ";
			cout << persona.edad[r];
			cout << " \n";
			cout << persona.nomb;


		}
	}
	system("pause");
}

void menuPILA() {
	Tope = 6;
	Final = 0;
	do {
		system("cls");
		cout << "Programa para control de pilas\n" << endl;
		cout << "1.Ingrese Valores a la Pila" << endl;
		cout << "2.Mostrar datos de la pila" << endl;
		cout << "3. Eliminar datos de la pila" << endl;
		cout << "4.Salir del menu" << endl;
		cout << "Que opcion desea seleccionar" << endl;
		cin >> Opcion;
		switch (Opcion) {
		case 1:
			Push(); break;
		case 2:
			Recorrer(); break;
		case 3:
			Pop(); break;
		case 4:
			break;
		default: "NO es una opcion valida";
		}
		system("pause");
	} while (Opcion != 4);
}

//OPCION 7
void Insertar(Lista *l, int v);
void Borrar(Lista *l, int v);

int ListaVacia(Lista l);

void BorrarLista(Lista *);
void MostrarLista(Lista l);

void menuListaEstatica()
{
	Lista lista = NULL;
	//pNodo p;

	Insertar(&lista, 20);
	Insertar(&lista, 10);
	Insertar(&lista, 40);
	Insertar(&lista, 30);

	MostrarLista(lista);

	Borrar(&lista, 10);
	Borrar(&lista, 15);
	Borrar(&lista, 45);
	Borrar(&lista, 30);
	Borrar(&lista, 40);

	MostrarLista(lista);

	BorrarLista(&lista);

	system("Pause");

}

void Insertar(Lista *lista, int v)
{
	pNodo nuevo, anterior;

	/*Crear un nodo nuevo*/

	nuevo = (pNodo)malloc(sizeof(tipoNodo));
	nuevo->valor = v;

	/*Si la lista esta vacia*/
	if (ListaVacia(*lista) || (*lista)->valor > v) {
		/*Anadimos la lista a continuacion del nuevo nodo*/
		nuevo->siguiente = *lista;
		/*Ahora, el comienzo de nuestra lista es en nuevo nodo*/
		*lista = nuevo;
	}
	else {
		/*Buscar el nodo de valor menor a v*/
		anterior = *lista;
		/*Avanzamos hasta el ultimo elemento o hasta que el siguiente tenga
		un valor mayor que v*/
		while (anterior->siguiente && anterior->siguiente->valor <= v)
			anterior = anterior->siguiente;
		/*Insertamos el nuevo nodo despues del nodo anterior*/
		nuevo->siguiente = anterior->siguiente;
		anterior->siguiente = nuevo;
	}
}

void Borrar(Lista *lista, int v)
{
	pNodo anterior, nodo;

	nodo = *lista;
	anterior = NULL;
	while (nodo&&nodo->valor < v)
	{
		anterior = nodo;
		nodo = nodo->siguiente;
	}
	if (!nodo || nodo->valor != v)return;
	else {/*Borrar el nodo*/
		if (!anterior)/*Primer elemento*/
			*lista = nodo->siguiente;
		else
			/*un elemento cualquiera*/
			anterior->siguiente = nodo->siguiente;
		free(nodo);
	}
}

int ListaVacia(Lista lista)
{
	return(lista == NULL);
}

/*int ListaVacia(Lista lista)
{
return(lista == NULL);
}*/

void BorrarLista(Lista *lista)
{
	pNodo nodo;

	while (*lista) {
		nodo = *lista;
		*lista = nodo->siguiente;
		free(nodo);
	}
}

void MostrarLista(Lista lista)
{
	pNodo nodo = lista;

	if (ListaVacia(lista)) printf("Lista vacia\n");
	else {
		while (nodo) {
			printf("%d->", nodo->valor);
			nodo = nodo->siguiente;
		}
		printf("\n");
	}
}

//OPCION 8

void opciones() {

	SetColor(15);
	gotoxy(25, 0);  cout << "======================";
	gotoxy(25, 2);  cout << "======================";
	SetColor(11);
	gotoxy(25, 1);  cout << "..::MENU PRINCIPAL::..";

	SetColor(15);
	gotoxy(20, 4); cout << " CREAR LAS MATRICES ";
	gotoxy(20, 5); cout << " MOSTRAR RESULTADOS MATRICIALES";
	gotoxy(20, 6); cout << " MATRICES ALGORITMO DE FLOYD ";
	gotoxy(20, 7); cout << " SALIR ";

	if (y == 4) {
		SetColor(11); gotoxy(20, y);  cout << " CREAR LAS MATRICES";
	}
	else if (y == 5) {
		SetColor(11); gotoxy(20, y);  cout << " MOSTRAR RESULTADOS MATRICIALES";
	}
	else if (y == 6) {
		SetColor(11); gotoxy(20, y);  cout << " MATRICES ALGORITMO DE FLOYD";
	}
	else if (y == 7) {
		SetColor(11); gotoxy(20, y);  cout << " SALIR";
	}
}

void menuFloyd() {
	y = 4;
	char tecla;
	SetColor(12); gotoxy(17, 4);  cout << "~~>";

	do {
		opciones();
		tecla = _getch();

		if (tecla == -32) {
			gotoxy(17, y); cout << "   ";
			tecla = _getch();

			if (tecla == 72) { //tecla de arriba
				if (y == 4) {
					y = 7;
				}
				else {
					y--;
				}
			}

			if (tecla == 80) { //tecla de abajo
				if (y == 7) {
					y = 4;
				}
				else {
					y++;
				}
			}
			SetColor(12); gotoxy(17, y); cout << "~~>";
		}

		if (tecla == 13) { //tecla enter
			if (y == 4) {
				crear();
			}
			else if (y == 5) {
				mostrar();
			}
			else if (y == 6) {
				floyd();
			}
			else if (y == 7) {
				break;
				system("cls");
			}
		}
	} while (1);
}

void crear() {
	system("cls");
	SetColor(15);
	gotoxy(25, 0);  cout << "======================";
	gotoxy(25, 2);  cout << "======================";
	SetColor(11);
	gotoxy(25, 1);  cout << "..::Creacion de Matriz::..";
	gotoxy(8, 5); cout << "Ingrese el tamano de la matriz: ";
	cin >> tam;
	gotoxy(8, 6); cout << "Si desea ingresar un numero infinito escriba '-1' " << endl << endl;
	for (int i = 1; i <= tam; i++) {
		for (int j = 1; j <= tam; j++) {
			cout << "Ingrese el dato de la matriz en la posicion: " << i << "," << j << ": ";
			cin >> matrizD0[i][j];
			cout << endl;
			if (matrizD0[i][j] == -1) {
				matrizD0[i][j] = 999;
			}
			matrizS0[i][j] = j;
			if (i == j) {
				matrizD0[i][j] = 0;
				matrizS0[i][j] = 0;
			}
		}
	}
	system("cls");
	SetColor(12); gotoxy(17, y); cout << "~~>";
}

void floyd() {
	system("cls");
	gotoxy(20, 0);  cout << "=================================";
	gotoxy(20, 2);  cout << "=================================";
	SetColor(11);
	gotoxy(20, 1);  cout << "..::ALGORITMO DE FLOYD-WARSHALL::..";
	for (int i = 1; i <= tam; i++) {
		for (int j = 1; j <= tam; j++) {
			matrizD[i][j] = matrizD0[i][j];
			if (matrizD[i][j] == 999)
			{
				matrizD[i][j] = inf;
			}
			matrizS[i][j] = matrizS0[i][j];
		}
	}
	for (int x = 1; x <= tam; x++) {
		/*cout << endl << endl << "\tMatriz D" << x << endl << endl;
		for (int i = 1; i <= tam; i++) {
		for (int j = 1; j <= tam; j++) {
		if (matrizD[i][x] + matrizD[x][j] < matrizD[i][j]) {
		matrizD[i][j] = matrizD[i][x] + matrizD[x][j];
		matrizS[i][j] = x;
		}
		cout << "\t" << matrizD[i][j];
		//gotoxy((5 +tam)*(tam + j), tam * i +x + 2); cout << matrizD[i][j];
		//cout << "\t\t\t"; cout << "\t" << matrizS[i][j];
		}
		cout << endl << endl;
		}*/
		gotoxy(20, 0);  cout << "=================================";
		gotoxy(20, 2);  cout << "=================================";
		SetColor(11);
		gotoxy(20, 1);  cout << "..::ALGORITMO DE FLOYD-WARSHALL::..";
		cout << endl << endl << "\tMatriz De Floyd" << x << endl << endl;
		for (int i = 1; i <= tam; i++) {
			for (int j = 1; j <= tam; j++) {
				if (matrizD[i][x] + matrizD[x][j] < matrizD[i][j]) {
					matrizD[i][j] = matrizD[i][x] + matrizD[x][j];
					matrizS[i][j] = x;

				}
				gotoxy(tam + j * tam + j + j + j, tam + i + 3);cout << matrizD[i][j];

				gotoxy(tam + j * tam + 49 + j, tam + i + 3);cout << matrizS[i][j];


				//gotoxy((5 +tam)*(tam + j), tam * i +x + 2); cout << matrizD[i][j];
				//cout << "\t\t\t"; cout << "\t" << matrizS[i][j];            
			}
			cout << endl << endl;
		}


		_getch();
		system("cls");
	}

	system("pause");
	system("cls");
	SetColor(12); gotoxy(17, y); cout << "~~>";
}

void mostrar() {
	system("cls");
	if (tam == 0)
	{
		gotoxy(25, 0);  cout << "=========================";
		gotoxy(25, 2);  cout << "=========================";
		SetColor(11);
		gotoxy(25, 1); cout << "No hay datos en la Matriz";
		cout << endl;
		cout << endl;
		system("pause");

	}
	else
	{


		gotoxy(25, 0);  cout << "=========================";
		gotoxy(25, 2);  cout << "=========================";
		SetColor(11);
		gotoxy(25, 1);  cout << "..::MATRICES ORIGINALES::..";
		gotoxy(10, 5); cout << "MATRIZ D " << endl << endl;
		for (int i = 1; i <= tam; i++) {
			for (int j = 1; j <= tam; j++) {
				gotoxy(tam + j * tam + 5, tam + i + 3); cout << matrizD0[i][j];
			}
			cout << endl;
		}
		cout << endl << endl;
		gotoxy(46, 5); cout << "MATRIZ S" << endl << endl;
		for (int i = 1; i <= tam; i++) {
			for (int j = 1; j <= tam; j++) {
				gotoxy(tam + j * tam + 40, tam + i + 3); cout << matrizS0[i][j];
			}
			cout << endl;
		}

		cout << endl << endl;
	}
	system("pause");
	system("cls");
	SetColor(12); gotoxy(17, y); cout << "~~>";

}

//OPCION 9
void ingresarsimple1() {
	system("cls");
	nuevo2 = (simple11 *)malloc(sizeof(simple11));
	nuevo2->num = nuevo->num;
	if (inicio2 == NULL)
	{
		inicio2 = nuevo2;
		final2 = nuevo2;
	}
	else
	{
		final2->siguiente = nuevo2;
		final2 = nuevo2;
		final2->siguiente = NULL;
	}
}
void ingresarsimple2() {
	system("cls");
	simple22 *aux;
	nuevo3 = (simple22 *)malloc(sizeof(simple22));
	nuevo3->num = nuevo->num;
	nuevo3->siguiente = final3;
	if (inicio3 == NULL) {
		inicio3 = nuevo3;
		final3 = nuevo3;
	}
	else
	{
		aux = inicio3;
		inicio3 = nuevo3;
		inicio3->siguiente = aux;
	}
}
void ingresardoble() {
	system("cls");
	nuevo = (dobleen *)malloc(sizeof(dobleen));
	if (nuevo == NULL) {
		cout << "No hay espacio en memoria para crear" << endl;
	}
	else
	{
		cout << "*************Ingreso De Datos*****************" << endl;
		cout << "Ingrese un numero" << endl;
		cin >> nuevo->num;
		ingresarsimple1();
		ingresarsimple2();
		nuevo->siguiente = NULL;
		if (inicio == NULL) {
			inicio = nuevo;
		
		}
	}
}
void mostrardef() {
	system("cls");
	recorrido = inicio;
	cout << "********Lista Doblemente Enlazada*********" << endl;
	while (recorrido != NULL) {
		cout << recorrido->num << "\n";
		recorrido->anterior = recorrido->anterior;
	}
	system("pause");
}

void mostrarsimple1() {
	system("cls");
	recorrido2 = inicio2;
	cout << "*******Lista Simple******" << endl;
	while (recorrido2 != NULL)
	{
		cout << recorrido2->num << "\n";
		recorrido2 = recorrido2->siguiente;
	}
	system("pause");
}

void mostrarsimple2() {
	system("cls");
	recorrido3 = inicio3;
	cout << "*******Lista Simple******" << endl;
	while (recorrido3 != NULL)
	{
		cout << recorrido3->num << "\n";
		recorrido3 = recorrido3->siguiente;
	}
	system("pause");
}

void menudiferencia() {
	int opcion = 0;
	while (opcion != 5) {
		system("cls");
		cout << "1.Ingresar datos \n";
		cout << "2.Mostrar Lista Doblemente enlazada\n";
		cout << "3.Mostrar Lista simple1 \n";
		cout << "4.Mostrar Lista simple2 \n";
		cout << "5.Salir\n";
		cout << "Seleccione una opcion";
		cin >> opcion;
		switch (opcion) {
		case 1:
			ingresardoble();
			break;
		case 2:
			mostrar();
			break;
		case 3:
			mostrarsimple1();
			break;
		case 4:
			mostrarsimple2();
			break;
		default:
			cout << "No es una opcion correcta";
			system("pause");
			break;
		}
	}
}

//OPCION 10
void menuABB() {
	int dato, opcion, contador = 0;

	do {
		system("cls");
		cout << "\t MENU \n";
		cout << "1. Insertar un nuevo nodo\n";
		cout << "2. Mostrar Arbol Completo\n";
		cout << "3. Mostrar SubArbol Derecho\n";
		cout << "4. Mostrar SubArbol Izquierdo\n";
		cout << "5. Mostrar Nodos Terminales\n";
		cout << "6. Mostrar Nodos\n";
		cout << "7. Salir\n";
		cout << "Opcion: ";
		cin >> opcion;

		switch (opcion) {
		case 1: cout << "\nIngrese un numero: ";
			cin >> dato;
			insertarNodo(arbol, dato);
			cout << "\n";
			break;
		case 2:
			cout << "\nMostrando el arbol completo\n\n";
			mostrarArbol(arbol, contador);
			cout << "\n";
			system("pause");
			break;
		case 3:
			cout << "\nMostrando el subarbol derecho\n\n";
			mostrarArbolDerecho(arbol, contador);
			cout << "\n";
			system("pause");
			break;
		case 4:
			cout << "\nMostrando el subarbol izquierdo\n\n";
			mostrarArbolIzquierdo(arbol, contador);
			cout << "\n";
			system("pause");
			break;
		case 5:
			cout << "\nNodos Terminales\n\n";
			mostrarNodosTerminales(arbol, 0);
			cout << "\n";
			system("pause");
			break;
		case 6:
			cout << "\nNodos\n\n";
			mostrarNodos(arbol);
			cout << "\n";
			system("pause");
			break;

		}
	} while (opcion != 7);

}

NodoABB *crearNodoABB(int n) {
	NodoABB *nuevo_nodo = new NodoABB();

	nuevo_nodo->dato = n;
	nuevo_nodo->der = NULL;
	nuevo_nodo->izq = NULL;

	return nuevo_nodo;
}
void insertarNodo(NodoABB *&arbol, int n) {
	//Si el arbol esta vacio
	if (arbol == NULL) {
		NodoABB *nuevo_nodo = crearNodoABB(n);
		arbol = nuevo_nodo;
	}
	else {
		int valorRaiz = arbol->dato;
		if (n < valorRaiz) {
			insertarNodo(arbol->izq, n);
		}
		else
		{
			insertarNodo(arbol->der, n);
		}
	}
}

void mostrarArbol(NodoABB *arbol, int cont)
{
	if (arbol == NULL) {
		return;
	}
	else
	{
		mostrarArbol(arbol->der, cont + 1);
		for (int i = 0; i < cont; i++) {
			cout << "   ";
		}
		cout << arbol->dato << endl;
		mostrarArbol(arbol->izq, cont + 1);
	}
}

void mostrarArbolDerecho(NodoABB *arbol, int cont)
{
	if (arbol == NULL) {
		return;
	}
	else
	{
		mostrarArbol(arbol->der, cont + 1);
		for (int i = 0; i < cont; i++) {
			cout << "   ";
		}
		cout << arbol->dato << endl;
	}
}

void mostrarArbolIzquierdo(NodoABB *arbol, int cont)
{
	if (arbol == NULL) {
		return;
	}
	else
	{
		for (int i = 0; i < cont; i++) {
			cout << "   ";
		}
		cout << arbol->dato << endl;
		mostrarArbol(arbol->izq, cont + 1);
	}
}

void mostrarNodosTerminales(NodoABB *arbol, int n) {

	if (arbol == NULL)
	{
		return;
	}

	if (arbol->izq == NULL && arbol->der == NULL)
	{
		cout << arbol->dato << " ";
	}

	mostrarNodosTerminales(arbol->der, n + 1);
	mostrarNodosTerminales(arbol->izq, n + 1);

}

void mostrarNodos(NodoABB *arbol) {

	if (arbol == NULL)
	{
		return;
	}

	else
	{
		cout << "Nodo Padre:" << arbol->dato << endl;
		if (arbol->izq != NULL)
			cout << "Nodo Izquierdo:" << arbol->izq->dato << endl;
		else
			cout << "Nodo Izquierdo: NULL" << endl;

		if (arbol->der != NULL)
			cout << "Nodo Derecho:" << arbol->der->dato << endl << endl;
		else
			cout << "Nodo Derecho: NULL" << endl << endl;

		mostrarNodos(arbol->izq);
		mostrarNodos(arbol->der);
	}

}
