#include "00_mkexe.h"

static const unsigned char bin[] =
#include BIN_NAME
    ;

int main(int argc, char** argv) {
    FILE* out = std::fopen("RenameMe.exe", "wb");

    if(argc == 1) {
        throw std::logic_error("Please Input At least 1 arguments.");
    }

    if(!out) {
        throw std::runtime_error("[ERR] Write File Open Failed. .\\RenameMe.exe\n");
    }
    try {
        const char mw[WIN_CMD_SIZE_MAX] = MAGIC_WORD;
        int count = WIN_CMD_SIZE_MAX - 1;

        for(auto *p = bin, *end = bin + sizeof(bin); p != end; ++p) {
            if(memcmp(p, mw, WIN_CMD_SIZE_MAX) == 0) {
                for(int j = 1; j < argc; ++j) {
                    if(j > 1) {
                        fputs(" && ", out);
                        count -= 4;
                        p += 4;
                    }
                    int len = strnlen_s(argv[j], std::size_t(bin - p));
                    for(int k = 0; k < len; ++k, ++p, --count)
                        fputc((const char)argv[j][k], out);
                }

                for(size_t l = 0; l < count; ++l, p++) {
                    fputc(0, out);
                }
                fputc(0, out);
            } else {
                fputc((const char)*p, out);
            }
        }
        std::fclose(out);
        if(count == WIN_CMD_SIZE_MAX - 1)
            throw std::runtime_error("[ERR] ValueError of a.exe. NotFound magic words.");
        fputs("Runtime Make Sucess.\nBuild File -> .\\RenameMe.exe\n", stdout);
        return 0;
    } catch(std::exception& e) {
        std::fclose(out);
        fputs(e.what(), stderr);
        return 1;
    }
}
