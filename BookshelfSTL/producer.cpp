#include "producer.h"

#include <vector>
#include "book.h"
#include "bookshelf.h"
#include <QThread>
#include <windows.h>
#include "bookaddable.h"
#include "updateable.h"
#include <QMutex>

Producer::Producer(std::vector<std::shared_ptr<book> >& bks, QMutex& mtx, bookaddable& bka, updateable& ua) :
    mtx(&mtx), bka(&bka), ua(&ua),
    books(&bks)
{

}

Producer::~Producer( ) {

}

void Producer::run( ) {
    for (int i = 0; i < books->size( ); ++i) {
        mtx->lock( );
        bka->add((*books)[i]);
        ua->showContent( );
        mtx->unlock( );
        Sleep(5000);
    }
}
