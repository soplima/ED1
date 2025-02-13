//Escreva uma função que recebe uma expressão pós-fixada (notação Polonesa Inversa) como uma
//string e devolve um vector<string> contendo cada elemento da expressão. Note que existe um
//caractere de espaço entre cada elemento da expressão e que os números podem ser compostos por
//mais de um dígito. Utilize os recursos sugeridos da biblioteca padrão de C++.
//Exemplo: entrada: "24 32 + 2 / 41 5 * +"
//saída: vector<string> = {24, 32, +, 2, /, 41, 5, *, +}

#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<string> vectorize_expression(const string &expression)
{
    vector<string>result;
    stringstream ss (expression);
    string token;
    while(ss >> token){
        result.push_back(token);
    }
    return result;
}
