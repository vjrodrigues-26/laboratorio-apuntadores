/* MENU BASE PARA MANEJO DE LISTAS */
#include <iostream>

using namespace std;

struct lista {
    int valor;
    lista* prox;
};

void insertarC(lista** p, int n) { //Inserción por cabeza
    lista* ax = new lista;
    ax->valor = n;
    ax->prox = NULL;

    if (*p == NULL) {
        *p = ax;
    }
    else {
        ax->prox = *p;
        *p = ax;
    }
}

void mostrarLista(lista* p) { //Imprime la lista
    lista* ax = p;

    while (ax) {
        cout << "[" << ax->valor << "]->";
        ax = ax->prox;
    }
    cout << "NULL";
}

int  buscarElemento(lista* p, int n) { //Busca un elemento en la lista y devuelve cuántas veces se repite.
    lista* ax = p;
    int contador = 0; 

    while (ax) {
        if (ax->valor == n) {
            contador++;
        }
        ax = ax->prox;
    }
    return contador;
}

void eliminarNum(lista** p, int n) {
    lista* ax = *p;
    lista* t = *p;

    if (*p) {
        while ((ax->valor == n)) { //Eliminando n si se encuentra en la cabeza de la lista
            *p = ax->prox;
            delete ax;
            ax = *p;
        }

        while ((ax->prox) && (ax->prox->valor != n)) { //El siguiente nodo existe y su valor es diferente de n, muevo ax.
            ax = ax->prox;
        }
        if (ax->prox == NULL) { //Salgo de la lista si no encuentra nada
            cout << "No existe ese número en la lista.";
            return;
        }
        while (ax->prox) {
            while ((ax->prox->valor == n)) { //Recorro la lista para eliminar cualquier ocurrencia de n en la lista
                t = ax->prox;
                ax->prox = t->prox;
                delete t;
            }
            ax = ax->prox;
        }
    }
}

void insertarF(lista** p, int n) {
    lista* ax = new lista;
    lista* t = *p;
    ax->valor = n;
    ax->prox = NULL;

    if (*p == NULL) {
        *p = ax;
        return;
    }

    while ((t) && (t->prox)) {
        t = t->prox;
    }

    if (t->prox == NULL) {
        t->prox = ax;
    }
}

void eliminarU(lista** p, int n) {

}


int main() {
    int n = 0, op = -1, respuesta;
    lista* p = NULL; //Inicializo la cabeza de la lista

    while (op != 0) {
        cout << "\n\n\t\tMENU BASE DE LISTAS\n\n";
        cout << "\t1. Insertar por cabeza.\n";
        cout << "\t2. Mostrar lista.\n";
        cout << "\t3. Buscar un elemento de la lista.\n";
        cout << "\t4. Eliminar un elemento de la lista.\n";
        cout << "\t5. Insertar por la cola.\n";
        cout << "\t6. Eliminar última ocurrencia.\n";

        cout << "\nSeleccione una opción del menú: ";
        cin >> op;

        switch (op) {

        case 1:
            cout << "Ingrese el número a insertar: ";
            cin >> n;
            system("cls");
            insertarC(&p, n);
            break;

        case 2:
            system("cls");
            mostrarLista(p);
            break;

        case 3:
            cout << "Ingrese el número a buscar: ";
            cin >> n;
            system("cls");
            respuesta = buscarElemento(p, n);
            if (respuesta != 0) {
                mostrarLista(p);
                cout << "\nEl número " << n << " se repite " << respuesta << " veces.";
            } else cout << "El número no existe en la lista";
            break;

        case 4:
            cout << "Ingrese el número a eliminar: ";
            cin >> n;
            eliminarNum(&p, n);
            break;

        case 5:
            cout << "Ingrese el número a insertar por la cola: ";
            cin >> n;
            insertarF(&p, n);
            break;

        case 6: 
            cout << "Ingrese el número a eliminar su última ocurrencia: ";
            cin >> n;
            eliminarU(&p, n);
            break;
        }
    }

    system("pause");
    system("cls");

    return 0;
};