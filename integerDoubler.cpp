#include <iostream>
#include <fstream>
#include <ios>

void integerDoubler(std::string inputFile, std::string outputFile) {

    int input_int = 0;
    std::ifstream in(inputFile, std::ios::binary);
    std::ofstream out(outputFile, std::ios::binary);
    size_t i = 0;
    while(!in.eof()) {
        ++i;
        char* input_int_ptr = reinterpret_cast<char*>(&input_int);
        
        in.read(input_int_ptr, sizeof(int));

        double output_double = static_cast<double>(input_int);


        char* output_double_ptr = reinterpret_cast<char*>(&output_double);
        out.write(output_double_ptr, sizeof(double));
    }
    std::cout << "Loop ended!\n" << i << std::endl;

    in.close();
    out.close();
}

/*int main() {
    integerDoubler("./in.txt", "./out.txt");
}*/