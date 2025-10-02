#include <iostream>
#include <fstream>
#include <ios>

void integerDoubler(std::string inputFile, std::string outputFile) {
    int input_int = 0;
    int output_double = 0;

    std::ifstream in(inputFile, std::ios::binary);
    std::ofstream out(outputFile, std::ios::binary);

    char* input_int_ptr = reinterpret_cast<char*>(&input_int);
    char* output_double_ptr = reinterpret_cast<char*>(&output_double);

    //size_t i = 0;
    while(!in.eof()) {
        //++i;
        in.read(input_int_ptr, sizeof(int));
        output_double = input_int * 2;
        out.write(output_double_ptr, sizeof(int));
    }
    //std::cout << "Loop ended!\n" << i << std::endl;

    in.close();
    out.close();
}
