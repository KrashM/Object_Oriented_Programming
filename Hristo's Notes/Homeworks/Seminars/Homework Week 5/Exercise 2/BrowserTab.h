#ifndef BROWSERTAB
#define BROWSERTAB

class BrowserTab{

    private:
        char *URL, *HTML;

    public:
        BrowserTab();
        BrowserTab(const BrowserTab &bt);
        BrowserTab(const char *URL, const char *HTML);
        ~BrowserTab();

        char *getURL();
        char *getHTML();

};

#endif