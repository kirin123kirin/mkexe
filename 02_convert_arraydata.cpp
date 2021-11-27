#include "00_mkexe.h"
#include <string>

int main(void) {
    FILE* bin = std::fopen(TEMPLATE_NAME, "rb");
    if(!bin) {
        fputs("[ERR] File Not Found.", stderr);
        throw std::runtime_error(TEMPLATE_NAME);
    }

    FILE* out = std::fopen(BIN_NAME, "wb");
    if(!out) {
        fputs("[ERR] Failed Open Write Binary File.", stderr);
        throw std::runtime_error(BIN_NAME);
    }

    try {
        int c;
        fputc('{', out);

        while((c = fgetc(bin)) != EOF) {
            fputs(std::to_string(c).data(), out);
            fputc(',', out);
        }
        fputc('}', out);

        std::fclose(bin);
        std::fclose(out);
        fputs("Sucess.\n", stdout);
        return 0;
    } catch(std::exception& e) {
        std::fclose(bin);
        std::fclose(out);
        fputs(e.what(), stderr);
        return 1;
    }
}
