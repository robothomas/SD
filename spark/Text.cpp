#include <Text.h>
#include <string>

int findLength(const char *c) {
    int length = 0;
    while (c[length]) {}
}

bool *reallocate(bool *original, int newLength) {
    bool *n = new 
}

Text() {
    fontSize = 20;
    len = 40;

    text = new char[len];
    setText();

    bold = new bool[len];
    setBold(false, 0, len - 1);

    italicized = new bool[len];
    setItalics(false, 0, len - 1);

    underlined = new bool[len];
    setUnderline(false, 0, len - 1);
}

Text(const char *words) {
    fontSize = 20;
    len = findLength(words);
    text = char(len);

}

void Text::setText() {
    for (int i = 0; i < len; i++) {
        text[i] = ' ';
    }
}

void Text::setText(const char *words) {
    if (len < findLength(words)) {
        len = findLength();

        delete [] text;
        delete [] bold;
        delete [] italicized;
        delete [] underlined;

        text = new char[len];
        bold = new bool[len];
        italicized = new bool[len];
        underlined = new bool[len];
    }

    for (int i = 0; i < len; i++) {
        text[i] = words[i];
    }
}

void Text::setBold() {
    for (int i = 0; i < len; i++) {
        bold[i] = false;
    }
}

void Text::setBold(bool isBold, int start, int end) {
    for (int i = start; i <= end; i++) {
        bold[i] = isBold;
    }
}

void Text::setItalics() {
    for (int i = 0; i < len; i++) {
        italicized[i] = false;
    }
}

void Text::setItalics(bool isItalicized, int start, int end) {
    for (int i = start; i <= end; i++) {
        italicized[i] = isItalicized;
    }
}

void Text::setUnderline() {
    for (int i = 0; i < len; i++) {
        underlined[i] = false;
    }
}

void Text::setUnderline(bool isUnderlined, int start, int end) {
    for (int i = start; i <= end; i++) {
        underlined[i] = isUnderlined;
    }
}

