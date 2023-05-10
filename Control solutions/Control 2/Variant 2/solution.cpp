#include <string>
#include <vector>
#include <iostream>

class ContentListable
{
public:
    virtual void ListContents() const = 0;
    
    virtual ContentListable* clone() const = 0;
    
    virtual ~ContentListable() = default;
};

class TextDocument: public ContentListable
{
private:
    std::string name;

public:
    TextDocument(const std::string& name) : name(name) {}

    virtual void ListContents() const override final
    {
        std::cout << this->name << std::endl;
    }
    
    virtual TextDocument* clone() const override final
    {
        return new TextDocument(*this);
    }

    virtual ~TextDocument() = default;
};

class Folder: public ContentListable
{
private:
    std::vector<ContentListable*> subDocuments;

    void copy(const Folder& other)
    {
        for (std::size_t i = 0; i < other.subDocuments.size(); ++i)
        {
            this->subDocuments.push_back(other.subDocuments[i]->clone());
        }
    }

    void deallocate()
    {
        for (std::size_t i = 0; i < this->subDocuments.size(); ++i)
        {
            delete this->subDocuments[i];
        }
    }

public:
    Folder() = default;

    Folder(const Folder& other)
    {
        this->copy(other);
    }

    Folder& operator = (const Folder& other)
    {
        if (this != &other)
        {
            this->deallocate();
            this->copy(other);
        }

        return *this;
    }

    void add(const ContentListable* toAdd)
    {
        this->subDocuments.push_back(toAdd->clone());
    }

    virtual void ListContents() const override final
    {
        for (std::size_t i = 0; i < this->subDocuments.size(); ++i)
        {
            this->subDocuments[i]->ListContents();
        }
    }
    
    virtual Folder* clone() const override final
    {
        return new Folder(*this);
    }

    virtual ~Folder()
    {
        this->deallocate();
    }
};

int main ()
{
    TextDocument proizvodstvo("Proizdostvo");
    TextDocument maria("Maria Ivanova");
    TextDocument ivanka("Ivanka Marinova");
    TextDocument uchreDitelenAkt("Uchreditelen akt");

    Folder otdeli;
    otdeli.add(&proizvodstvo);

    Folder sluzhiteli;
    sluzhiteli.add(&maria);
    sluzhiteli.add(&ivanka);

    Folder danniZaOrganizaciqta;
    danniZaOrganizaciqta.add(&uchreDitelenAkt);
    danniZaOrganizaciqta.add(&sluzhiteli);
    danniZaOrganizaciqta.add(&otdeli);

    danniZaOrganizaciqta.ListContents();

    return 0;
}