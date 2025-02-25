#include <iostream>
#include <vector>
#include <string>
using namespace std;

//Product* p = &someProduct;
//list->data[i] = 10;  // Acessando membros com '->'

//Product& p = someProduct;
//prods[i].stock = 10;  // Acessando membros com '.'

//Task:
//Write a function that:

//Checks all medicines in the inventory.
//If a medicine's stock is below min_stock, add it to the restock list.
//Before adding, check if the medicine is already in the list. If it's already in the list, increase the quantity 
//needed instead of adding a duplicate entry.
//restock amount = 2×(amount missing) + 5
//Return a vector of medicines that need restocking, with the ID and quantity required.

struct Medicine {
    int id;
    char name[50];
    int stock;
    int min_stock;
};

struct Restock {
    int id;
    int quantity;
};

vector<Restock> check_restock(vector<Medicine>& inventory) {
    vector<Restock> restock; 
    for(int i = 0; i < inventory.size(); i ++){
        if(inventory[i].stock < inventory[i].min_stock){
            bool found = false;

            for(int j = 0; j <restock.size(); j++){
                if(restock[i].id == inventory[i].id){
                    restock[i].quantity += 2 * (inventory[i].min_stock - inventory[i].stock);
                    found = true;
                }
            }
            if(!found){
                Restock newMedicine;
                newMedicine.id = inventory[i].id;
                newMedicine.quantity = 2 * (inventory[i].min_stock - inventory[i].stock);
                restock.push_back(newMedicine);
            }
        }
    } return restock;
}