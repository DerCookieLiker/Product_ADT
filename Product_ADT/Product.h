#pragma once

typedef struct Product* PProduct;

PProduct Product_create(int id, char* productName, double price);

void Product_print(PProduct _this);
void Product_delete(PProduct _this);

int Product_getID(PProduct _this);
char* Product_getProductName(PProduct _this);
double Product_getPrice(PProduct _this);

void Product_setID(PProduct _this, int newId);
void Product_setProductName(PProduct _this, char* newProductName);
void Product_setPrice(PProduct _this, double newPrice);

void Product_write(PProduct _this, const char* filename);
void Product_read(PProduct _this, const char* filename, int index);

