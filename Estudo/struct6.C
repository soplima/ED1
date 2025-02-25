#include <iostream>
#include <vector>
#include <string>
using namespace std;

//Product* p = &someProduct;
//list->data[i] = 10;  // Acessando membros com '->'

//Product& p = someProduct;
//prods[i].stock = 10;  // Acessando membros com '.'

/*Problem Statement:
A property management company needs to calculate rental payments for tenants, considering their stay duration. If a tenant stays for less than 30 days, their payment should be reduced.

Payment Rules:
The rent is proportional to the days stayed.
If a tenant stays for less than 30 days, they should be considered for a reduced rent.
Calculate the reduced rent based on the following formula:
reduced rent = 1.5 × ( full rent) × days stayed / 30

Only tenants who have stayed less than 30 days should be considered for reduced rent.
Task:
Write a function that:

Loops through all tenants in the property management system.
If a tenant stayed less than 30 days, calculate their reduced rent.
If a tenant is already in the reduced rent list, increase the rent amount for that tenant instead of adding them again.
Return a list of tenants who had their rent reduced, with their ID and the amount to pay.
*/

struct Tenant {
    int id;
    char name[50];
    int days_stayed;
    double full_rent;
};

struct Rent {
    int id;
    double amount;
};

vector<Rent> calculate_reduced_rent(vector<Tenant>& tenants) {
    vector<Rent> reduced_rent;
    for(int i = 0; i<tenants.size(); i++){
        if(tenants[i].days_stayed < 30){
            bool found = false;

        for(int j = 0; j<reduced_rent.size(); j++){
            if(reduced_rent[i].id == tenants[i].id){
                reduced_rent[j].amount += 1.5 * tenants[i].full_rent * (tenants[i].days_stayed / 30);
                found = true;
                }
            }
            if(!found){
                Rent newRent;
                newRent.id = tenants[i].id;
                newRent.amount = 1.5 * tenants[i].full_rent * (tenants[i].days_stayed / 30);
                reduced_rent.push_back(newRent);
            }
        }
    }return reduced_rent;
}
