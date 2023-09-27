#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

int main() {

    std::string line;
    std::ifstream in("C:\\IDE\\in.txt");
    std::vector<int>mass1{};
    std::vector<int>mass2{};


    if (in.is_open())
    {
        std::getline(in, line);
        int N = stoi(line);
        while (N > 0) {
            in >> line;
            int y = stoi(line);
            mass1.push_back(y);
            --N;
        }

        for (int i = 0; i < mass1.size() - 1; ++i) {
            int c = mass1[i + 1];
            mass1[i + 1] = mass1[i];
            mass1[i] = c;
        }

        in >> line;
        int M = stoi(line);
        while (M > 0) {
            in >> line;
            int y = stoi(line);
            mass2.push_back(y);
            --M;
        }

        for (int i = mass2.size() - 1; i > 0; --i) {
            int c = mass2[i - 1];
            mass2[i - 1] = mass2[i];
            mass2[i] = c;
        }

    }

    in.close();



    std::ofstream out;
    out.open("C:\\out.txt");
    if (out.is_open()) {

        out << std::to_string(mass2.size());
        out << "\n";

        for (int i = 0; i < mass2.size(); ++i)
            out << std::to_string(mass2[i]) << " ";

        out << "\n";

        out << std::to_string(mass1.size());
        out << "\n";

        for (int i = 0; i < mass1.size(); ++i)
            out << std::to_string(mass1[i]) << " ";

    }

    out.close();

    return 0;
}