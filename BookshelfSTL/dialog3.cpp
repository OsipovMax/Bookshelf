#include "dialog3.h"
#include "ui_dialog3.h"
#include "book.h"
#include "bookshelf.h"
#include "myinterface.h"


Dialog3::Dialog3(MyInterface *DialogUi, bookshelf<MagicNumber> *books, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog3),
    books(books),
    DialogUi(DialogUi)  // список инициализации, который инициализирует поля класса до вызова конструктора
{
    ui->setupUi(this);
}

Dialog3::~Dialog3(){
    delete ui;
}



void Dialog3::on_pushButton_del_yes_clicked(){
    if (books->size( )){
        books->pop();
        DialogUi->showContent( );} //вывод данных на экран по нажатию кнопки "Delete"
}
