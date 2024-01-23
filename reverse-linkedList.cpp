#include <iostream>

// Definición de la estructura del nodo de la lista enlazada
struct Nodo {
    int dato;
    Nodo* siguiente;
    
    Nodo(int valor) : dato(valor), siguiente(nullptr) {}
};

// Función para imprimir la lista enlazada
void imprimirLista(Nodo* cabeza) {
    while (cabeza != nullptr) {
        std::cout << cabeza->dato << " ";
        cabeza = cabeza->siguiente;
    }
    std::cout << std::endl;
}

// Función para invertir la lista enlazada
Nodo* invertirLista(Nodo* cabeza) {
    Nodo* prev = nullptr;
    Nodo* actual = cabeza;
    Nodo* siguiente = nullptr;

    while (actual != nullptr) {
        siguiente = actual->siguiente;
        actual->siguiente = prev;
        prev = actual;
        actual = siguiente;
    }

    // Al finalizar el bucle, 'prev' apunta al nuevo primer nodo invertido
    return prev;
}

int main() {
    // Crear una lista enlazada de ejemplo
    Nodo* cabeza = new Nodo(1);
    cabeza->siguiente = new Nodo(2);
    cabeza->siguiente->siguiente = new Nodo(3);
    cabeza->siguiente->siguiente->siguiente = new Nodo(4);

    std::cout << "Lista original: ";
    imprimirLista(cabeza);

    // Invertir la lista
    cabeza = invertirLista(cabeza);

    std::cout << "Lista invertida: ";
    imprimirLista(cabeza);

    // Liberar la memoria al finalizar el programa
    while (cabeza != nullptr) {
        Nodo* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    }

    return 0;
}
