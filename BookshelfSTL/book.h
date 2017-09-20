#ifndef BOOK
#define BOOK

#include <string>
#include <memory>
#include <typeinfo>

class book {
public:
    book( ) : title(""), author(""), year(0), page_count(0) {} // !!
    ~book( ) { } // деструктор
    book(const std::string& title, const std::string& author, int year, int page_count) :
        title(title), author(""), year(0), page_count(0) {
        set_author(author);
        set_year(year);
        set_page_count(page_count);
    }    // конструктор инициализации (после двоеточия собственная инициализация) // !!!
    book(const book& ref) :
        title(ref.title), author(ref.author), year(ref.year), page_count(ref.page_count) { } // конструктор копирования

    virtual std::string get_title( ) const;    // селекторы (1-const- возвращает константную ссылку на строку)
    virtual std::string get_author( ) const;     // 2 const -не изменеят объект в процессе выполнения
    virtual int get_year( ) const;
    virtual int get_page_count( ) const;

    virtual void set_title(const std::string&);     // модификаторы
    virtual void set_author(const std::string&);
    virtual void set_year(int);                     //вертуальный метод
    virtual void set_page_count(int);
    virtual operator std::string( )const; // перегрузка оператора приведения типи


///Перегрузка операторов


book& operator( ) (int, int, std::string, std::string);
book operator-- (int); // постфикс
book operator-- (   );

book operator* (int) const;
book operator+ (int) const;
book operator- (int) const;

bool operator> (const book&) const;
bool operator|| (const book&) const;

book operator| (const book&) const;
book operator& (const book&) const;

book& operator= (const book&);

friend bool operator && (const book&, const book&);
friend std::istream& operator>> (std::istream&, book&);
friend std::ostream& operator<<(std::ostream&,book&);
private:

protected:
    std::string title, author;              // свойства класса
    mutable int	year, page_count;       // позволяет изменять поле даже у константных объектов
};

#endif // BOOK

