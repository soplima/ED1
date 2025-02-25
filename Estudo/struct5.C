#include <iostream>
#include <vector>
#include <string>
using namespace std;

//Product* p = &someProduct;
//list->data[i] = 10;  // Acessando membros com '->'

//Product& p = someProduct;
//prods[i].stock = 10;  // Acessando membros com '.'

/*Problem Statement:
A store wants to calculate discounts for loyal customers based on their total spending. 
Each customer has the following information:

ID (id) – Unique identifier.
Name (name) – Customer’s name.
Total Spent (total_spent) – How much the customer has spent in the store.
Discount Rules:
Customers with $500 or more in total spending get a 20% discount.
Customers with $200 - $499 get a 10% discount.
Customers with less than $200 do not receive a discount.
If a customer already exists in the discount list, do not add them again—just update the discount 
amount.
*/


struct Customer {
    int id;
    char name[50];
    double total_spent;
};

struct Discount {
    int id;
    double discount_amount;
};

vector<Discount> calculate_discounts(vector<Customer>& customers) {
    vector<Discount>discount_list;
    double discount = 0;

    for(int i = 0; i<customers.size(); i++){
        if(customers[i].total_spent >= 500){
            discount = customers[i].total_spent * 0.2;
        } else if (customers[i].total_spent >= 200){
            discount = customers[i].total_spent * 0.1;
        }
        
        if(discount > 0){
            bool found = false;

        for(int j = 0; j<discount_list.size(); j++){
            if(customers[i].id == discount_list[j].id){
                discount_list[j].discount_amount += discount;
                found = true;
            }
        }
        if(!found){
            Discount newDiscount;
            newDiscount.id = customers[i].id;
            newDiscount.discount_amount = discount;
            discount_list.push_back(newDiscount);
            }
        }
    } return discount_list;
}
