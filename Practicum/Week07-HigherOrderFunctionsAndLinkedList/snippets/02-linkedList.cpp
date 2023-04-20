#include <iostream>

struct box
{
    int data;
    box* next;

    box(int data, box* next = nullptr)
        : data(data), next(next) {}
};

void print (box* start)
{
    while (start)
    {
        std::cout << start->data << " ";
        start = start->next;
    }
    std::cout << std::endl;
}

void deallocate(box* start)
{
    while (start)
    {
        box* toDelete = start;
        start = start->next;
        delete toDelete;
    }
}

box* copy(box* other)
{
    if (!other)
    {
        return nullptr;
    }

    box* result = new box(other->data);
    box* temp = result;

    while (other->next)
    {
        temp->next = new box(other->next->data);
        temp = temp->next;
        other = other->next;
    }

    return result;
}

void removeConsecutiveDuplicates(box* start)
 {
    if (!start->next)
    {
        return;
    }

    box* temp = start;
    while(temp->next)
    {
        if (temp->data == temp->next->data)
        {
            box* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
        else
        {
            temp = temp->next;
        }
    }
 }

void insertAt(box*& start, int element, std::size_t index)
{
    box* prev = nullptr;
    box* curr = start;

    std::size_t i;
    for (i = 0; i < index && curr != nullptr; ++i)
    {
        prev = curr;
        curr = curr->next;
    }

    if (i < index)
    {
        std::cout << "too big index" << std::endl;
        return;
    }

    box* newBox = new box(element);

    if (!prev)
    {
        newBox->next = start;
        start = newBox;
    }
    else
    {
        newBox->next = curr;
        prev->next = newBox;
    }
}


int main()
{
    box* list = new box(8, new box(4, new box(3, new box(2, new box(5)))));

    print(list);

    box* copyList = copy(list);

    print(list);
    print(copyList);

    box* listWithDuplicates = new box(1, new box(1, new box(2, new box(2, new box(2, new box(3, new box(4, new box(4))))))));

    removeConsecutiveDuplicates(listWithDuplicates);
    print(listWithDuplicates);

    insertAt(copyList, 0, 0);
    print(copyList);

    deallocate(list);
    deallocate(listWithDuplicates);
    deallocate(copyList);

    return 0;
}
