#include <inheritancebook.h>
#include <sstream>
// реализация селекторов( методы класса)
const std::string& PublicBook::get_genre ( ) const {
    return genre;
}

int PublicBook::get_mark ( ) const {
    return mark;
}

// реализация модификаторов

void PublicBook::set_genre(const std::string& genre) {
    bool genre_valid = true;
    for (std::string::const_iterator i = genre.begin(); i != genre.end(); ++i)
        if (!isalpha(*i) && *i != ' ') {
            genre_valid = false;
        }
    if (genre_valid)
        this->genre = genre;    // this инициализирует значение адреса объекта, для которого вызван метод
}
/// Установка значения оценки
/// mark (int) - новое значение
void PublicBook::set_mark(int mark) {
    if (mark > -1 && mark < 11)
        this->mark = mark;
}
//переопределение метода наследованного класса
std::string PublicBook::get_title( ) const {
    std::stringstream ss; // операции ввода  на основе потоков.
    ss << book::title << " (" << get_genre( ) << "), " << mark;

    std::string result;
    getline(ss, result); // считываем в result данные из буфера
    return result;
}

PublicBook::operator std::string( ) const {
    std::stringstream ss; //реализует операции ввода / вывода на память на основе потоков.
    ss << "PB " << title << std::endl <<
          author << std::endl <<
          genre << std::endl <<
          year << " " << page_count << " " << mark << std::endl;

    return ss.str( ); // получает или задает содержание основного объекта строку
}
