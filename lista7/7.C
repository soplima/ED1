//Escreva uma função que calcula e devolve o resultado de expressões posfix usando os recursos da
//biblioteca padrão de C/C++. Considere que sempre existe um espaço entre os elementos da
//expressão e que os números são inteiros positivos e podem ser formados por mais de um algarismo.
//Operações possíveis: + - * /. É necessário usar uma pilha para os operandos (stack<float>).

//Recursos:
//● isdigit(): verifica se caractere é um dígito (número)
//● stoi(): converte string C++ para número (http://www.cplusplus.com/reference/string/stoi/)

//Processo:
//● Transforme a expressão string em um vector<string>. Desta forma, cada símbolo (operador ou
//operando) estará em uma posição do vector.
//● Varrer a expressão no vector:
//▪ Quando encontra um número na expressão, empilha (stack<float>).
//▪ Quando encontra um operador na expressão, retira dois elementos da pilha, executa a
//operação e empilha resultado (a ordem dos operandos deve ser considerada na
//execução da operação);
//▪ Quando terminar de percorrer a expressão, o resultado estará no topo da pilha

#include <string>
#include <vector>
#include <stack>
#include <sstream>
#include <stdexcept>
#include <cctype>
using namespace std;

vector<string> vectorize_expression(const string& expression) {
    vector<string> result;
    stringstream ss(expression);
    string token;
    
    while (ss >> token) {
        result.push_back(token);
    }
    
    return result;
}

float calc_posfix(string expression) {
    stack<float> operand;
    vector<string> tokens = vectorize_expression(expression);

    for (const string& token : tokens) {
        if (isdigit(token[0])) {  // If it's a number, push to stack
            operand.push(stoi(token));
        } else if (operand.size() < 2) {  // Ensure there are enough operands
            throw runtime_error("Not enough operands in the stack");
        } else {
            float b = operand.top(); operand.pop();
            float a = operand.top(); operand.pop();

            if (token == "+") {
                operand.push(a + b);
            } else if (token == "-") {
                operand.push(a - b);
            } else if (token == "*") {
                operand.push(a * b);
            } else if (token == "/") {
                if (b == 0) {
                    throw runtime_error("Division by zero");
                }
                operand.push(a / b);
            } else {
                throw runtime_error("Invalid operator: " + token);
            }
        }
    }

    if (operand.size() != 1) {  
        throw runtime_error("Malformed expression");
    }

    return operand.top();
}
