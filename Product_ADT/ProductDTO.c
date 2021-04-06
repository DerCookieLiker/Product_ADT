#include "ProductDTO.h"
#include "Product.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct ProductDTO{

    const char* filename;
};

PProductDTO ProductDTO_create(const char* filename){

    PProductDTO retVal = (PProductDTO) malloc(sizeof(struct ProductDTO));

    retVal->filename = filename;

    return retVal;
}
void ProductDTO_write(PProductDTO _this, PProduct p){

    FILE* fp;

    fp = fopen(_this->filename, "ab");

    if(!fp){

        printf("Error");
        return;
    }

    fwrite(p, Product_getDataSize(), 1, fp);
    fclose(fp);
}
PProduct ProductDTO_read(PProductDTO _this, int index){

    FILE* fp;

    int size = Product_getDataSize();

    fp = fopen(_this->filename, "rb");

    if(!fp){

        printf("Error File not found");
        return NULL;
    }

    PProduct retVal = Product_create(0, " ", 0);

    fseek(fp, index * size, SEEK_SET);
    if(!fread(retVal, size, 1, fp)){
        printf("ERROR Index to big");
    }
    fclose(fp);

    return retVal;
}
void ProductDTO_writeAll(PProductDTO _this, PProductArr array){

    PProduct* temp = ProductArr_getArray(array);

    for(int i = 0; i < ProductArr_getNoe(array); i++){

        ProductDTO_write(_this, temp[i]);
    }
}
PProductArr ProductDTO_readAll(PProductDTO _this, int count){

    PProductArr retVal = ProductArr_create();

    for(int i = 0; i < count; i++){

        ProductArr_add(retVal, ProductDTO_read(_this, i));
    }
    return retVal;
}
void ProductDTO_delete(PProductDTO _this){
    free(_this);
}
