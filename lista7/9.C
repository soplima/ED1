//Escreva uma calculadora de expressões infix parentizada: ( ( ( 6 + 9 ) / 3 ) * ( 6 - 4) )

//● Considere que sempre existe um espaço entre os elementos da expressão e que ela está
//completamente parentizada para informar a ordem de precedência das operações.
//● São necessárias duas pilhas: operadores (stack <char>) e operandos (stack <float>)).
//● Utilize novamente os recursos da biblioteca C/C++ para facilitar a construção do programa.
//● Para avaliar a expressão deve-se seguir o processo abaixo:

//o Quando um operando (número) é lido, ele é colocado na pilha de operandos.
//o Quanto um parêntese esquerdo é lido "(", ele é colocado na pilha de operadores.
//o Quando um dos quatro operadores é lido, ele é colocado na pilha de operadores caso
//tenha maior precedência sobre o operador que está no topo da pilha ou topo seja “(“.
//▪ Caso contrário, deve calcular a expressão empilhada: retirar dois números da
//pilha de operandos e o operador da outra pilha. Calcular a expressão e colocar o
//resultado na pilha de operandos.
//o Quando um parêntese direito é lido ")", deve calcular a expressão empilhada seguindo o
//processo mencionado acima, colocando o resultado na pilha de operandos. Este
//processo é repetido até que o topo da pilha de operadores contenha um parêntese
//esquerdo "(", que deverá ser removido.


#include <iostream>
#include <string>
#include <stack>
#include <cctype>
#include <stdexcept>
using namespace std;

float apply_operators(float a, float b, char op){
    switch (op)
    {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/':
    if(b == '0'){
        return false;
    } 
    return a / b;
    }
}
int precendence(char op){
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    return 0;
}

float calc_infix(string expression){
    stack<float>operands;
    stack<char>operators;

    int i = 0;
    while (i < expression.length()){
        char token = expression[i];
        if (token == ' '){
            i++;
            continue;
        }
        else if (isdigit(token)){
            float num = 0;
            while(i < expression.length() && isdigit(expression[i])){
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            operands.push(num);
        }
        else if(token == '('){
            operators.push(token);
            i++;
        }
        else if(token == ')'){
            while(!operators.empty() && operators.top() != '('){
                float b = operands.top(); operands.pop();
                float a = operands.top(); operands.pop();
                char op = operators.top(); operators.pop();
                operands.push(apply_operators(a, b, op));
            }
            if (operators.top() == '('){
                operators.pop();
            }
            i++;
        }
        else if(token == '+' || token == '-' || token == '*' || token == '/'){
            while(!operators.empty() && precendence(operators.top()) >= precendence(token)){
                float b = operands.top(); operands.pop();
                float a = operands.top(); operands.pop();
                char op = operators.top(); operators.pop();
                operands.push(apply_operators(a, b, op));
            }
            operators.push(token);
            i++;
        }

    while(!operators.empty()){
        float b = operands.top(); operands.pop();
        float a = operands.top(); operands.pop();
        char op = operators.top(); operators.pop();
        operands.push(apply_operators(a, b, op));
    }
    if(operands.size() != 1){
        throw runtime_error("Invalid expression");
    }
    return operands.top();
}
}