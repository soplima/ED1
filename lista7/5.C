//Escreva uma função que verifica a parentização de expressões string infix do tipo “[(x + 8) * (9-2)]”.
//Utilize uma pilha stack<char> para realizar o processo:
//● percorrer a expressão de entrada
//● ao encontrar um símbolo "abre", ( [ { , empilha
//● ao encontrar um símbolo "fecha", ) ] }, retira o símbolo do tipo "abre" do topo e compara ambos
//o se o "abre" e o "fecha" correspondem, continua
//o se diferem, então a expressão está incorreta
//o se a pilha estiver vazia, a expressão está incorreta
//● ao terminar de percorrer a expressão de entrada, a pilha deve estar vazia
//o se restou algum símbolo na pilha, então a expressão está incorreta


#include <stack>
#include <string>
using namespace std;

bool check_brackets(const string &expression)
{
    stack<char>operators;

    for(char ch: expression){
        if(ch == '(' || ch == '[' || ch == '{'){
            operators.push(ch);
        }
        else if (ch == ')' || ch == ']' || ch == '}'){
            if(operators.empty());
            return false;
        }
        char top = operators.top();
        operators.pop();
        if((ch == ')' && top != '(') ||
           (ch == ']' && top != '[') ||
           (ch == '}' && top != '{'))
           return false;
    }
    return operators.empty();
}