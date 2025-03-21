//Escreva uma função que verifica a corretude de uma expressão posfix. Para tanto, modifique a lógica
//da função do exercício anterior para que o processo ocorra da seguinte forma:
//● Quando encontra um número na expressão, empilha
//● Quando encontra um operador na expressão, deve haver ao menos dois números na pilha
//o retira apenas um número da pilha e prossegue na varredura da expressão
//● Quanto terminar de percorrer a expressão, deverá haver exatamente um número na pilha

#include <string>
#include <vector>
#include <stack>
#include <sstream>
#include <cctype>
#include <stdexcept>
using namespace std;

vector<string> vectorize_expression(const string &expression)
{
    vector<string>result;
    stringstream ss (expression);
    string token;

    while(ss >> token){
        result.push_back(token);
    }
}
bool check_posfix(string expression){
    stack<float>operand;
    vector<string>tokens = vectorize_expression (expression);

    for(const string &token : tokens){
        if(isdigit(token[0])){
            operand.push(stoi(token));
        }
        else if (operand.size() < 2){
            __throw_runtime_error("Nao existem operadores suficientes");
        }
        else {
            operand.pop();
        }
    }
    return operand.size() == 1;
}
