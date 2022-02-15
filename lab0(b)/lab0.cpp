#include <iostream>
#include "Read_input_file.h"
#include "Writing_csv_file.h"

int main(int argc, char* argv[])
{
    Read_input_file ltr;
    ltr.Read_file(argv[1]);

    Writing_csv_file ptr(ltr);
    ptr.Writing_file(argv[2]);
}
