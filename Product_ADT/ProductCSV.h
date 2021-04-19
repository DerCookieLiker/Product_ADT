#pragma once

#include "Product.h"

typedef struct ProductCVS* PProductCVS;

PProductCVS ProductCVS_create(const char* filename, char sep);

void ProductCVS_write(PProductCVS _this, PProduct product);
void ProductCVS_writeAll(PProductCVS _this, PProductArr array);

void ProductCVS_delete(PProductCVS _this);
