#include "Product.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PRODUCT_MAX_STRING 31

struct Product{

    int id;
    char productName[PRODUCT_MAX_STRING];
    double price;

};

PProduct Product_create(int id, char* productName, double price){

    PProduct retVal = (PProduct) malloc(sizeof(struct Product));

    retVal->id = id;
    strcpy(retVal->productName, productName);
    retVal->price = price;

    return retVal;
}
PProductArr Product_createArr(){
    return (PProductArr) malloc(sizeof(PProduct));
}
void Product_print(PProduct _this){

    printf("ID: %d\n", _this->id);
    printf("ProductName: %s\n", _this->productName);
    printf("Price: %.2lf", _this->price);
}
void Product_delete(PProduct _this){
    free(_this);
}

int Product_getID(PProduct _this){
    return _this->id;
}
char* Product_getProductName(PProduct _this) {

    return _this->productName;
}
double Product_getPrice(PProduct _this){
    return _this->price;
}
int Product_getDataSize(){
    return sizeof(struct Product);
}

void Product_setID(PProduct _this, int newId){
    _this->id = newId;
}
void Product_setProductName(PProduct _this, char* newProductName){
    strcpy(_this->productName, newProductName);
}
void Product_setPrice(PProduct _this, double newPrice){
    _this->price = newPrice;
}
void Product_add(PProductArr _this, PProduct p,int* noe){


}
