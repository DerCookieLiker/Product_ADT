#include <stdio.h>
#include <stdlib.h>
#include "Product.h"
#include "ProductDTO.h"

void ProductManager();
int main(){

    ProductManager();

}
void ProductManager(){

    PProductArr arr = ProductArr_create();
    PProductDTO saveFile = ProductDTO_create("productArray.dat");
    PProductArr copyArray = ProductArr_create();

    ProductArr_add(arr, Product_create(0, "apple", 2));
    ProductArr_add(arr, Product_create(2, "apple XR", 100));
    ProductArr_add(arr, Product_create(3, "orange", 2.2));
    ProductArr_add(arr, Product_create(4, "TV", 200));

    ProductArr_print(arr);
    ProductDTO_writeAll(saveFile, arr);

    copyArray = ProductDTO_readAll(saveFile, 4);
    ProductArr_print(copyArray);

    ProductArr_delete(arr);
    ProductArr_delete(copyArray);
    ProductDTO_delete(saveFile);
}
