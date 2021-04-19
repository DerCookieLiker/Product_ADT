#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ProductCSV.h"

struct ProductCVS{

    const char* filename;
    char sep;
};

PProductCVS ProductCVS_create(const char* filename, char sep){

    PProductCVS retVal = (PProductCVS) malloc(sizeof(struct ProductCVS));

    retVal->filename = filename;
    retVal->sep = sep;

    return retVal;
}
void ProductCVS_write(PProductCVS _this, PProduct product){

    FILE *fp = fopen(_this->filename, "a");

    if(!fp){
        printf("Cannot Access to the file: %s", _this->filename);
    }

    fprintf(fp, "%d %c %s %c %.2lf\n", Product_getID(product), _this->sep, Product_getProductName(product), _this->sep, Product_getPrice(product));

    fclose(fp);
}
void ProductCVS_writeAll(PProductCVS _this, PProductArr array){

    for(int i = 0; i < ProductArr_getNoe(array); i++){

        ProductCVS_write(_this, ProductArr_getProduct(array, i));
    }

}
void ProductCVS_delete(PProductCVS _this){
    free(_this);
}
