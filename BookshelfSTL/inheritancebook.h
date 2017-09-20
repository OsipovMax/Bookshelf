#ifndef INHERITANCEBOOK
#define INHERITANCEBOOK
#include <book.h>

class PublicBook: public book {
public:
    PublicBook( ) : genre(""), mark(0) { } // !!
    ~PublicBook( ) { } // деструктор
    PublicBook( const std::string& title, const std::string& author, int year, int page_count, const std::string& genre, int mark ) :
        genre(""), mark(0) {
        set_title(title);
        set_author(author);
        set_year(year);
        set_page_count(page_count);
        set_genre(genre);
        set_mark(mark);
    }
    /*  PublicBook(const PublicBook& copy) :
        janr(copy.janr), mark(copy.mark) { }*/

    const std::string& get_genre( ) const;
    int get_mark( ) const;

    void set_genre(const std::string&);
    void set_mark(int);
    virtual std::string get_title( ) const;
    virtual operator std::string( ) const;
private:
    std::string genre;
    int	mark;
};

#endif // INHERITANCEBOOK
