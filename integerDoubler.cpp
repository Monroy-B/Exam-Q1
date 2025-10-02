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
/*/
int main() {
    std::ofstream out("./in.txt", std::ios::binary);
    int test = 1223;
    out.write(reinterpret_cast<char*>(&test), sizeof(int));
    out.write(reinterpret_cast<char*>(&test), sizeof(int));
    out.write(reinterpret_cast<char*>(&test), sizeof(int));
    out.write(reinterpret_cast<char*>(&test), sizeof(int));
    out.close();
    
    integerDoubler("./in.txt", "./out.txt");

    std::ifstream in("./out.txt", std::ios::binary);
    double testd;
    in.read(reinterpret_cast<char*>(&testd), sizeof(double));
    std::cout << "double: " << testd << std::endl;
    in.read(reinterpret_cast<char*>(&testd), sizeof(double));
    std::cout << "double: " << testd << std::endl;
    in.read(reinterpret_cast<char*>(&testd), sizeof(double));
    std::cout << "double: " << testd << std::endl;
    in.read(reinterpret_cast<char*>(&testd), sizeof(double));
    std::cout << "double: " << testd << std::endl;
    /*in.read(reinterpret_cast<char*>(&testd), sizeof(int));
    std::cout << "int: " << testd << std::endl;
    in.read(reinterpret_cast<char*>(&testd), sizeof(int));
    std::cout << "int: " << testd << std::endl;
    in.read(reinterpret_cast<char*>(&testd), sizeof(int));
    std::cout << "int: " << testd << std::endl;*/

}*/