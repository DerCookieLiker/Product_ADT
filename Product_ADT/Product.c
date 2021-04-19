#include "Product.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PRODUCT_MAX_STRING 31

struct Product{

    int id;
    char productName[PRODUCT_MAX_STRING];
    double price;

    char* productString;

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
    retVal->productString = (char*) malloc(80 * sizeof(char));
    return retVal;
}
PProductArr ProductArr_create(){
    PProductArr retVal = (PProductArr) malloc(sizeof(struct ProductArr));

    retVal->array = NULL;
    retVal->noe = 0;

    return retVal;
}
void Product_print(PProduct _this){
    if(!_this) return;
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

char* Product_toString(PProduct _this, char sep){
    int valid;

    valid = sprintf(_this->productString, "ID: %d %c Name: %s %c Price: %.2lf", _this->id, sep,_this->productName, sep,_this->price);

    if(!valid){
        _this->productString = "Error";
    }
    return _this->productString;
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
void ProductArr_remove(PProductArr _this, int pos){

    if(pos < 0 || pos > _this->noe) return;
    PProduct* temp = ProductArr_getArray(_this);
    int i;
    for(i = pos; i < ProductArr_getNoe(_this) - 1; i++){
        temp[i] = temp[i + 1];
    }
    _this->noe -= 1;
    Product_delete(temp[i + 1]);
    temp = (PProduct*) realloc(temp, _this->noe * sizeof(PProduct));

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
void ProductArr_delete(PProductArr _this){

    free(_this->array);
    free(_this);
}

PProduct ProductArr_getProduct(PProductArr _this, int noe){

    if(noe < 0 || noe > _this->noe || !_this->array[noe]) return NULL;
    return _this->array[noe];
}
