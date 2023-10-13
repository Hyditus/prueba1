#include <iostream>
#include <stack>
#include <string>

using namespace std;

int prioridad(char operador) {
    if (operador == '+' || operador == '-')
        return 1;
    if (operador == '*' || operador == '/')
        return 2;
    return 0;
}

string infixToPostfix(string expresion) {
    stack<char> pila;
    string resultado;

    for (char caracter : expresion) {
        if (isalnum(caracter)) {
            resultado += caracter;
        } else if (caracter == '(') {
            pila.push(caracter);
        } else if (caracter == ')') {
            while (!pila.empty() && pila.top() != '(') {
                resultado += pila.top();
                pila.pop();
            }
            pila.pop();
        } else { 
            while (!pila.empty() && prioridad(pila.top()) >= prioridad(caracter)) {
                resultado += pila.top();
                pila.pop();
            }
            pila.push(caracter);
        }
    }

    while (!pila.empty()) {
        resultado += pila.top();
        pila.pop();
    }

    return resultado;
}

int main() {
    string expresion;
    cout << "Ingrese una expresion algebraica: ";
    cin >> expresion;

    string postfija = infixToPostfix(expresion);
    cout << "La expresion en notacion postfija es: " << postfija << endl;

    return 0;
}
