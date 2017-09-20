#ifndef BOOKSHELF
#define BOOKSHELF
#include <queue>
#include "book.h"
#include "inheritancebook.h"
#include <memory>
#include "bookaddable.h"
#define MagicNumber 1000
// класс-контейнер
template<size_t N>
class bookshelf : public bookaddable {
public:
    virtual void add(std::shared_ptr<book>);  //методы класса(add- добавляет книгу)
    std::shared_ptr<book> front( );         // возвращает ссылку на самую первую книгу
    void pop( );            // pop удаляет самую первую книгу
    size_t size( );         // возвращает количество книг
    void clear( );

    //friend void swap(bookshelf& , bookshelf& ); // позволяет обращаться к private секции
private:
    std::queue< std::shared_ptr<book> > shelf; // свойство класса( очередь в которой хранятся книги)
};
 // shared_ptr -умный указатель , для сборки мусора.
template<size_t N>
void bookshelf<N>::add(std::shared_ptr<book> bk){
    if (shelf.size( ) < N) shelf.push(bk);
}

template<size_t N>
std::shared_ptr<book> bookshelf<N>::front( ){
    return shelf.front( );
}

template<size_t N>
void bookshelf<N>::pop ( ){
    shelf.pop( );
}

template<size_t N>
size_t bookshelf<N>::size( ){
    return shelf.size( );
}

//template<size_t N>
//void swap(bookshelf<N>& a, bookshelf<N>& b ) {
//    swap(a.shelf, b.shelf);
//}

typedef bookshelf<MagicNumber> mybookshelf; // не вводит новый тип — вводит новые имена для уже существующих.

//template <typename A, typename B>
//std::shared_ptr<A> sum_books(const A& f, const B& s) {
//    std::shared_ptr<book> c; //результат функции

//    if (typeid(f) == typeid(PublicBook))
//        c = std::shared_ptr<book>(new PublicBook(dynamic_cast<const PublicBook&>(f)));
//    else
//        c = std::shared_ptr<book>(new book(f));

//    c->set_page_count(f.get_page_count() + s.get_page_count());
//    return c;
//}

template <typename A, typename B>
std::shared_ptr<A> sum_books(const A& f, const B& s) {
    std::shared_ptr<A> c = std::make_shared<A>(f); //результат функции

    c->set_page_count(f.get_page_count() + s.get_page_count());
    return c;

}

#endif // BOOKSHELF
