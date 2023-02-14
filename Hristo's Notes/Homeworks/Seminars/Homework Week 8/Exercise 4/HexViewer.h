#ifndef HEXVIEWER
#define HEXVIEWER

class HexViewer{

    private:
        char *path, *content;
        int contentSize;
        bool failed;
        void clearContent();
        void loadBytes();

    public:
        HexViewer(char *path);
        ~HexViewer();

        const bool menu();
        const bool fail();
        void changeByte(unsigned index, const char *byte);
        void remove();
        void add(const char *byte);
        void save();
        void saveAs(const char *newFileName);
        void printContent();

};

#endif