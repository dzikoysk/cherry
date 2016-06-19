#include <iostream>
#include "divider.h"

cherry::Divider::Divider(std::wstring* source_ptr) : source(source_ptr) {
    caret = 0;
    line = 0;
}

cherry::Fragment* cherry::Divider::getNext() {
    std::wstring fragment_source = L"";

    for (; caret < source->size(); caret++) {
        const wchar_t character = source->at(caret);
        fragment_source += character;

        if (character == '{' || character == ';' || character == '}') {
            caret++;
            break;
        }
        else if (character == '\n') {
            line++;
        }
    }

    Fragment* fragment = new Fragment();
    fragment->setFragment(&fragment_source);
    fragment->setLine(line);
    fragment->setCaretPosition(caret);

    return fragment;
}

bool cherry::Divider::hasNext() {
    return caret < source->length();
}




