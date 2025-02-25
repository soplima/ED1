#include <iostream>
#include <vector>
#include <string>
using namespace std;

//Product* p = &someProduct;
//list->data[i] = 10;  // Acessando membros com '->'

//Product& p = someProduct;
//prods[i].stock = 10;  // Acessando membros com '.'

struct Employee {
    int id;
    char name[50];
    char position[50];
    double salary;
    int days_worked;
};

struct Payment {
    int id;
    double amount;
};

//A empresa quer calcular o pagamento de funcionários com base nos dias trabalhados. Se um funcionário trabalhou 
//menos de 20 dias no mês, ele deve ser registrado na lista de pagamentos reduzidos.

//Regras para pagamento reduzido:

//O salário é proporcional aos dias trabalhados.
//Apenas funcionários com menos de 20 dias trabalhados entram na lista.
//Sua função deve percorrer a lista de funcionários e retornar um vetor contendo os funcionários que tiveram 
//pagamento reduzido e o valor a ser pago a eles.

vector<Payment> calculate_reduced_payments(vector<Employee>& employees) {
    vector<Payment> reduced_payments; // Armazena os funcionários com pagamento reduzido
    for(int i = 0; i < employees.size(); i ++){
        if(employees[i].days_worked < 20){
            bool found = false;
            
            for(int j = 0; j < reduced_payments.size(); j++){
                if(employees[i].id == reduced_payments[j].id){
                    reduced_payments[j].amount += (employees[i].salary /30 ) * employees[i].days_worked;
                    found = true; 
                }
            }
            if (!found){
                Payment newPayment;
                newPayment.id = employees[i].id;
                newPayment.amount = (employees[i].salary /30 ) * employees[i].days_worked;
                reduced_payments.push_back(newPayment);
            }
        }
    }
    return reduced_payments;
}
