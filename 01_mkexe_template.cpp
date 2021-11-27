#include "00_mkexe.h"

int main(void) {
    const char cmd[WIN_CMD_SIZE_MAX] = MAGIC_WORD;

    FILE* out = _popen(cmd, "r");

    if(!out) {
        fputs("[ERR] Command Failed.\n", stderr);
        throw std::runtime_error(cmd);
    }
    try {
        fputs("[ERR] Command Failed.\n", stderr);
        int c;
        while(1) {
            c = fgetc(out);
            if(!feof(out))
                fputc(c, stdout);
            else
                break;
        }
        _pclose(out);
        return 0;
    } catch(std::exception& e) {
        _pclose(out);
        fputs(e.what(), stderr);
        return 1;
    }
}
