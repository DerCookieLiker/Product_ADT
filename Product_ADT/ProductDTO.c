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
        return NULL;
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
PProductArr ProductDTO_readAll(PProductDTO _this){

    PProductArr retVal = ProductArr_create();

    FILE *fp = fopen(_this->filename, "rb");

    if(!fp){
        printf("Cannot access to the file %s", _this->filename);
        return NULL;
    }

    fseek(fp, 0, SEEK_END);

    int count = ftell(fp) / Product_getDataSize();

    fclose(fp);

    for(int i = 0; i < count; i++){

        ProductArr_add(retVal, ProductDTO_read(_this, i));
    }

    return retVal;
}
void ProductDTO_delete(PProductDTO _this){
    free(_this);
}
void ProductDTO_update(PProductDTO _this, PProduct p, int pos){

    PProductArr array = ProductArr_create();
    PProduct* temp;
    array = ProductDTO_readAll(_this);
    temp = ProductArr_getArray(array);

    temp[pos] = p;

    fopen(_this->filename, "wb");
    //I cant use remove(_this->filename); and I don't know why so I delete the content of the File

    ProductDTO_writeAll(_this, array);
    ProductArr_delete(array);
    free(temp);
}
void ProductDTO_remove(PProductDTO _this, int pos){

    PProductArr array = ProductArr_create();
    array = ProductDTO_readAll(_this);

    ProductArr_remove(array, pos);

    fopen(_this->filename, "wb");
    //I cant use remove(_this->filename); and I don't know why so I delete the content of the File

    ProductDTO_writeAll(_this, array);
    ProductArr_delete(array);
}

