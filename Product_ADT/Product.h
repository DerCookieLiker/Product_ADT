#pragma once

typedef struct Product* PProduct;
typedef struct ProductArr* PProductArr;

PProduct Product_create(int id, char* productName, double price);
PProductArr ProductArr_create();

void Product_print(PProduct _this);
void Product_delete(PProduct _this);

int Product_getID(PProduct _this);
char* Product_getProductName(PProduct _this);
double Product_getPrice(PProduct _this);

void Product_setID(PProduct _this, int newId);
void Product_setProductName(PProduct _this, char* newProductName);
void Product_setPrice(PProduct _this, double newPrice);
int Product_getDataSize();
char* Product_toString(PProduct _this);

void Product_read(PProduct _this, const char* filename, int index);

void ProductArr_add(PProductArr _this, PProduct p);
void ProductArr_print(PProductArr _this);
void ProductArr_delete(PProductArr _this);

PProduct* ProductArr_getArray(PProductArr _this);
int ProductArr_getNoe(PProductArr _this);
void ProductArr_remove(PProductArr _this, int pos);

