#pragma once

typedef struct Product* PProduct;
typedef struct Product** PProductArr;

PProduct Product_create(int id, char* productName, double price);
PProductArr Product_createArr();

void Product_print(PProduct _this);
void Product_delete(PProduct _this);

int Product_getID(PProduct _this);
char* Product_getProductName(PProduct _this);
double Product_getPrice(PProduct _this);

void Product_setID(PProduct _this, int newId);
void Product_setProductName(PProduct _this, char* newProductName);
void Product_setPrice(PProduct _this, double newPrice);
int Product_getDataSize();

void Product_read(PProduct _this, const char* filename, int index);
void Product_add(PProductArr _this, int *noe);

