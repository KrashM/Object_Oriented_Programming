#pragma once

#include "ShapeCollection.h"

class IO{

    public:
        static void menu();

        static void open();
        static void save();
        static void saveas();
        static void close();

        static void help();

        static void print();
        static void create();
        static void erase();
        static void translate();
        static void within();
        static void pointIn();
        static void areas();
        static void pers();

        static void loadColorNames();
        static bool validateColor(const String &);

    private:
        static ShapeCollection collection;
        static String currentFile;
        static bool saved, closed, changes;
        static Vector<String> colorNames;

};