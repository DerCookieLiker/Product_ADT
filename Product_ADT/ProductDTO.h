#pragma once

typedef struct ProductDTO* PProductDTO;
typedef struct Product* PProduct;
typedef struct ProductArr* PProductArr;

PProductDTO ProductDTO_create(const char* filename);

PProduct ProductDTO_read(PProductDTO _this, int index);
void ProductDTO_write(PProductDTO _this, PProduct p);

void ProductDTO_writeAll(PProductDTO _this, PProductArr array);
PProductArr ProductDTO_readAll(PProductDTO _this, int count);

void ProductDTO_delete(PProductDTO _this);
