#include <stdio.h>
#include <stdlib.h>
#include "Product.h"
#include "ProductDTO.h"

void ProductManager();
int main(){

    remove("productArray.dat");

    ProductManager();




}
void ProductManager(){

    PProductArr arr = ProductArr_create();
    PProductDTO saveFile = ProductDTO_create("productArray.dat");
    PProductArr copyArray = ProductArr_create();

    ProductArr_add(arr, Product_create(0, "milk", 1.5));
    ProductArr_add(arr, Product_create(1, "apple", 0.4));
    ProductArr_add(arr, Product_create(2, "orange", 0.6));
    ProductArr_add(arr, Product_create(3, "banana", 1));

    ProductArr_print(arr);
    ProductDTO_writeAll(saveFile, arr);

    printf("\n============\nUpdate: Index: 0\n");
    ProductDTO_update(saveFile, Product_create(10, "Name", 0), 0);
    copyArray = ProductDTO_readAll(saveFile);
    ProductArr_print(copyArray);
    printf("\n\n");


    printf("\n=============\nRemove: Index: 0\n");
    ProductDTO_remove(saveFile, 0);
    PProductArr newArray = ProductArr_create();
    newArray = ProductDTO_readAll(saveFile);

    ProductArr_print(newArray);
    printf("\n\n");

    printf("\n=============\nTo String\n");
    char* str;
    PProduct newObj = Product_create(0, " ", 0);
    newObj = ProductDTO_read(saveFile, 1);
    Product_print(newObj);
    str = Product_toString(newObj);
    puts(str);
    printf("\n\n");

    Product_delete(newObj);
    ProductArr_delete(arr);
    ProductArr_delete(newArray);
    ProductArr_delete(copyArray);
    ProductDTO_delete(saveFile);
}
