//Escreva um conversor de expressões posfix para infix, usando uma versão modificada da calculadora
//posfix. Exemplo: 6 9 + 3 / 6 4 - * → ( ( ( 6 + 9 ) / 3 ) * ( 6 - 4 ) )

//● Utilize uma pilha de strings (stack<string>) para guardar as expressões na forma infix.
//● Utilize os recursos da biblioteca C/C++ para facilitar a construção do programa.
//● Para avaliar a expressão deve-se seguir o processo abaixo:
//o Quando um número (operando) é lido, ele é colocado na pilha.
//o Quando um operador é lido, deve montar a expressão infix com os dois operandos
//previamente empilhados: retira dois topos da pilha e monta expressão (string) na forma:
//( topo operador topo ). Empilha a expressão infix na pilha.
//● Ao final da expressão, a pilha deverá conter um único elemento, com a expressão completa na
//forma infix.


#include <iostream>
#include <string>
#include <stack>
#include <cctype>
#include <stdexcept>
using namespace std;

string posfix_to_infix(string expression)
{
    stack<string>operands;

    int i = 0;
    while (i < expression.length()){
        char token = expression[i];

        if(token == ' '){
            i++;
            continue;
        }
        else if(isdigit(token)){
           string num = "";
           while(i < expression.length() && isdigit(expression[i])){
            num += expression[i];
            i++;
           }
           operands.push(num);
        }
        else if (token == '+'|| token == '-'|| token == '*'|| token == '/'){
            operands.size() < 2;
            throw invalid_argument("Expressão posfixa inválida.");
        }
        string operands2 = operands.top(); operands.pop();
        string operands1 = operands.top(); operands.pop();
        string infix_exp = "(" + operands1 + " " + token + " " + operands2 + ")";
        operands.push(infix_exp);
        i++;
    }
    if(operands.size() != 1){
        throw invalid_argument("Expressão posfixa inválida.");
    }
    return operands.top();
}