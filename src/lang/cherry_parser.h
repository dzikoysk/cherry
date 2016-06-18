#ifndef CHERRY_CHERRY_PARSER_H
#define CHERRY_CHERRY_PARSER_H

#include <string>
#include "../core/parser/parser.h"
#include "../core/parser/redact/divider/divider.h"
#include "elements/wrapper.h"
#include "../core/parser/redact/formatter/formatter.h"

namespace cherry {

    class CherryParser : public Parser {

        private:
            std::wstring* source;
            Wrapper* wrapper;
            Divider* divider;
            Formatter* formatter;

        public:
            CherryParser(std::wstring* source_ptr);

            ~CherryParser();

            virtual Wrapper* parse() override;

            Executable* parseFragment(Fragment* fragment_ptr);

            Formatter* getFormatter() {
                return formatter;
            }

            Divider* getDivider() {
                return divider;
            }

            Wrapper* getWrapper() {
                return wrapper;
            }

            std::wstring* getSource() {
                return source;
            }

    };

}

#endif //CHERRY_CHERRY_PARSER_H
