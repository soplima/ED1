#include <iostream>
#include <vector>
#include <string>
using namespace std;

//Product* p = &someProduct;
//list->data[i] = 10;  // Acessando membros com '->'

//Product& p = someProduct;
//prods[i].stock = 10;  // Acessando membros com '.'

struct Product {
    int id;
    char name[50];
    int stock;
};

struct Order {
    int id;
    int amount;
};

vector<Order> check_stock(std::vector<Product>& prods) {
    vector<Order>order;
    for(int i = 0; i<prods.size(); i++){
        if(prods[i].stock <= 0){
            bool found = false;

            for(int j = 0; j<order.size(); j++){
                if(order[j].id == prods[i].id){
                    order[j].amount += 2 * (-prods[i].stock) + 1;
                    found = true;
                    break;
                }
            }
            if(!found){
                Order newOrder;
                newOrder.id = prods[i].id;
                newOrder.amount = 2 * (-prods[i].stock) + 1;
                order.push_back(newOrder);
            }
        }
    }
    return order;
}