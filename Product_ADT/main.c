#include <stdio.h>
#include <stdlib.h>
#include "Product.h"

int main()
{
    PProduct apple = Product_create(0, "apple", 0.12);
    PProduct appleCopy = Product_create(0, " ", 0);


    Product_write(apple, "product.dat");
    Product_read(appleCopy, "product.dat", 0);
    printf("%s\n", Product_getProductName(appleCopy));
    Product_print(appleCopy);

    //Product_write(apple, "product.dat");
    Product_delete(appleCopy);
}
