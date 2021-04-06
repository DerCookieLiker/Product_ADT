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
struct ProductArr{

    PProduct *array;
    int noe;
};
PProduct Product_create(int id, char* productName, double price){

    PProduct retVal = (PProduct) malloc(sizeof(struct Product));

    retVal->id = id;
    strcpy(retVal->productName, productName);
    retVal->price = price;

    return retVal;
}
PProductArr ProductArr_create(){
    PProductArr retVal = (PProductArr) malloc(sizeof(struct ProductArr));

    retVal->array = NULL;
    retVal->noe = 0;

    return retVal;
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

void ProductArr_add(PProductArr _this, PProduct p){

    if(!_this->array){
        _this->array = (PProduct *) malloc(sizeof(PProduct));
    }
    _this->noe += 1;
    PProduct* newArray = (PProduct*) realloc(_this->array, (_this->noe) * sizeof(PProduct));

    newArray[_this->noe - 1] = p;

    _this->array = newArray;
}
void ProductArr_print(PProductArr _this){

    int noe = _this->noe;

    for(int i = 0; i < noe; i++){

        Product_print(_this->array[i]);
        printf("\n");
    }
}
PProduct* ProductArr_getArray(PProductArr _this){
    return _this->array;
}
int ProductArr_getNoe(PProductArr _this){
    return _this->noe;
}
