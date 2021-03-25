#include <stdio.h>
#include <stdlib.h>
#include "Product.h"
#include "ProductDTO.h"

int main(){
    PProduct apple[10];

    for(int i = 0; i < 10; i++){
        apple[i] = Product_create(i, "apple", i + 0.2);
    }


    PProductDTO save = ProductDTO_create("productsArr.dat");

    ProductDAO_writeAll(save, apple, 10);

    Product_print(apple[0]);
}
