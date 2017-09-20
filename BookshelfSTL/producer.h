#ifndef PRODUCER_H
#define PRODUCER_H

#include <vector>
#include "book.h"
#include "bookshelf.h"
#include <QThread>
#include <windows.h>
#include "bookaddable.h"
#include <QMutex>
#include <QThread>
#include "updateable.h"

class Producer : public QThread  {
    Q_OBJECT

private:
    bookaddable * bka;
    updateable * ua;
    std::vector<std::shared_ptr<book> > * books;

    QMutex * mtx;
public:

    Producer (std::vector<std::shared_ptr<book> >&, QMutex&, bookaddable&, updateable&);
    virtual ~Producer( );
protected:
    virtual void run( );
};

#endif // PRODUCER_H
