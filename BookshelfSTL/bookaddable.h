#ifndef BOOKADDABLE_H
#define BOOKADDABLE_H

#include <memory>
#include "book.h"

class bookaddable {
public:
    virtual void add(std::shared_ptr<book>) = 0;
};

#endif // BOOKADDABLE_H
