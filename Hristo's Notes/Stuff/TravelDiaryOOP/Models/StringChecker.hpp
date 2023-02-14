#pragma once

#include <cstring>

class StringChecker{

    public:
        #define DEFAULT_STRING_SIZE 1024
        #define LOWERCASELETTERS "abcdefghijklmnopqrstuvwxyz"
        #define UPPERCASELETTERS "ABCDEFGIHJKLMNOPQRSTUVWXYZ"
        #define DIGITS "0123456789"
        #define OTHERCHARS "~`!@#$%^&*()_-+={[}]|\\:;\"\'<,>.?/"
        #define EMAILFORMAT "@mail.bg"
        #define UNDESCORE '_'
        #define JPEG ".jpeg"
        #define PNG ".png"

        static const bool contains(const char *string, const char symbol);
        static const bool isLower(const char symbol){ return contains(LOWERCASELETTERS, symbol); }
        static const bool isUpper(const char symbol){ return contains(UPPERCASELETTERS, symbol); }
        static const bool isDigit(const char symbol){ return contains(DIGITS, symbol); }
        static const bool isOther(const char symbol){ return contains(OTHERCHARS, symbol); }
        static const bool isUnder(const char symbol){ return symbol == UNDESCORE; }
        static const bool isAny(const char symbol){ return isLower(symbol) || isUpper(symbol) || isDigit(symbol) || isOther(symbol); }
        static const void isUsername(const char *username);
        static const void isPassword(const char *password);
        static const void isEmail(const char *email);
        static const bool isPng(const char *photo, const size_t photoSize);
        static const bool isJpeg(const char *photo, const size_t photoSize);
        static const bool isPhoto(const char *photo);

};