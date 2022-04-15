#include <string>

class Text {
    int len;
    int fontSize;
    char *text;
    bool *bold;
    bool *italicized;
    bool *underlined;

    Text();
    Text(const char *words);
    Text(int sizeFont, const char *words);
    void setText();
    void setText(const char *words);
    void setBold();
    void setBold(bool isBold, int start, int end);
    void setItalics();
    void setItalics(bool isItalicized, int start, int end);
    void setUnderline();
    void setUnderline(bool isUnderlined, int start, int end);
}