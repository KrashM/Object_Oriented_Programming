#ifndef LICENCEKEY
#define LICENCEKEY

class LicenceKey{

    private:
        int key, numberOfCopies, maxNumberOfCopies;

    public:
        LicenceKey();
        LicenceKey(int key, int maxNumberOfCopies);

        int activate();

};

#endif