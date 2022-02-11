#include <iostream>
#include "Make_csv_file.h"

int main(int argc, char* argv[])
{
    Read_input_file ltr;
    ltr.Read_file(argv[1]);

    Writing_csv_file ptr;
    ptr.Writing_file(argv[2], ltr.Getnumber(), ltr.Getmap());
}
