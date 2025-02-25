#include <iostream>
#include <vector>
#include <string>
using namespace std;

//Product* p = &someProduct;
//list->data[i] = 10;  // Acessando membros com '->'

//Product& p = someProduct;
//prods[i].stock = 10;  // Acessando membros com '.'

struct Student {
    int id;
    char name[50];
    float grade1;
    float grade2;
};

//Calcule a média de cada aluno.
//Exiba os alunos que passaram (média ≥ 6.0).

vector<Student> approved_students(vector<Student>& students) {
    vector<Student> approved;
    for (int i = 0; students.size(); i++){
        float media = (students[i].grade1 + students[i].grade2) / 2;
        if (media > 6.0){
            approved.push_back(students[i]);
        }
    }
    return approved;
}
