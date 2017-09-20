#include "book.h"
#include <sstream>

// реализация селекторов( методы класса)
std::string book::get_title ( ) const {
    return title;
}
std::string book::get_author ( ) const {
    return author;
}
int book::get_year ( ) const {
    return year;
}
int book::get_page_count( ) const {
    return page_count;
}

// реализация модификаторов
void book::set_title(const std::string& title) {
    this->title = title;
}
void book::set_author(const std::string& author) {
    bool author_valid = true;
    for (std::string::const_iterator i = author.begin(); i != author.end(); ++i)
        if (!isalpha(*i) && *i != ' ') {
            author_valid = false;
        }
    if (author_valid)
        this->author = author;    // this инициализирует значение адреса объекта, для которого вызван метод
}
void book::set_year(int year) {
    if (year > 1431 && year < 2016)
        this->year = year;
}//реализует операции ввода / вывода на память на основе потоков.
void book::set_page_count(int page_count) {
    if (page_count > 0)
        this->page_count = page_count;
}



///Блок перегрузки операторов



book::operator std::string( ) const {
    std::stringstream fout;
    const book* DiffrentBook = this; // получение адреса от указателя на начальную книгу
    fout << "B " << DiffrentBook->get_title( ) << std::endl
         << DiffrentBook->get_author( ) << std::endl
         << DiffrentBook->get_year( ) << " "
         << DiffrentBook->get_page_count( ) << std::endl;

    return fout.str( );
}

std::istream& operator >> (std::istream& is, book& ExpBook ) {
    return (is >> ExpBook.title >> ExpBook.author >> ExpBook.year >> ExpBook.page_count);
}
std::ostream& operator << (std::ostream& on, book& ExpBook ) {
    return (on << ExpBook.title << ExpBook.author << ExpBook.year << ExpBook.page_count);
}

book& book::operator() (int i, int j, std::string k, std::string l){
    title=k; author=l;year=i;page_count=j;
    return *this;
}

book& book:: operator= (const book& ExpBook ){
    this->title=ExpBook.title;
    this->author=ExpBook.author;
    this->year=ExpBook.year;
    this->page_count=ExpBook.page_count;
    return *this;
}

bool operator&& (const book &left, const book &right){
   return (left.title + right.title).size( ) % 2;
}

book book::operator * (int a) const {
    book c = *this;
    c.set_page_count(this->page_count * a);
    return c;
}
book book::operator + (int a) const {
    book c = *this;
    c.set_page_count(this->page_count + a);
    return c;
}
book book::operator - (int a) const {
    book c = *this;
    c.set_page_count(this->page_count - a);
    return c;
}

bool book::operator > (const book& b) const {
    return this->page_count > b.page_count;
}

bool book::operator || (const book& right) const {
    return (this->title + right.title).size( ) % 2 == 0;
}

book book::operator | (const book& b) const {
    book c = *this;
    c.set_page_count(this->page_count | b.page_count);
    return c;
}
book book::operator & (const book& b) const {
    book c = *this;
    c.set_page_count(this->page_count & b.page_count);
    return c;
}

//постфикс
book book::operator--(int) {
    book tmp = *this;
    --*this;
    return tmp;
}

book book::operator--( ){
    page_count--;
    return *this;
}
