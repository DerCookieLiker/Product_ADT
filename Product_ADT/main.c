#include <stdio.h>
#include <stdlib.h>
#include "Product.h"
#include "ProductDTO.h"

int main(){

    PProductArr arr = ProductArr_create();

    ProductArr_add(arr, Product_create(0, "apple", 2));
    ProductArr_add(arr, Product_create(2, "apple XR", 100));
    ProductArr_add(arr, Product_create(3, "orange", 2.2));
    ProductArr_add(arr, Product_create(4, "TV", 200));

    ProductArr_print(arr);

    PProductDTO saveFile = ProductDTO_create("productArray.dat");

    ProductDAO_writeAll(saveFile, arr);
}
