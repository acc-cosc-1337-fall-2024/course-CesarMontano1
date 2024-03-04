//add include statements
#include "func.h"
//add function code here
double get_gc_content(const std::string& dna) {
    int gc_count = 0;

    for (char nucleotide : dna) {
        if (nucleotide == 'G' || nucleotide == 'C') {
            gc_count++;
        }
    }

    return static_cast<double>(gc_count) / dna.length();
}

std::string reverse_string(const std::string& dna) {
    std::string reversed = "";

    for (int i = dna.length() - 1; i >= 0; i--) {
        reversed += dna[i];
    }

    return reversed;
}

std::string get_dna_complement(const std::string& dna) {
    std::string complement = reverse_string(dna);

    for (char& nucleotide : complement) {
        switch (nucleotide) {
            case 'A':
                nucleotide = 'T';
                break;
            case 'T':
                nucleotide = 'A';
                break;
            case 'C':
                nucleotide = 'G';
                break;
            case 'G':
                nucleotide = 'C';
                break;
            default:
                // Handle invalid characters if necessary
                break;
        }
    }

    return complement;
}