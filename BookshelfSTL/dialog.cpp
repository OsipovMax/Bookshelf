#include "dialog.h"
#include "ui_dialog.h"
#include <QString>
#include "book.h"
#include "bookshelf.h"
#include "inheritancebook.h"
#include "myinterface.h"
#include <string>
#include <fstream>
#include <iostream>
#include <QMessageBox>
Dialog::Dialog(MyInterface *DialogUi, bookshelf<MagicNumber> *books,  std::vector<std::shared_ptr<book> >* d, QWidget *parent) :
    delayed(d),
    QDialog(parent),
    ui(new Ui::Dialog),
    books(books),
    counter(0),
    DialogUi(DialogUi) // список инициализации, который инициализирует поля класса до вызова конструктора
{
    ui->setupUi(this);
    connect(ui->pushButton_save, SIGNAL(clicked()), this, SLOT(LaneSlot()));
}

Dialog::~Dialog( ){
    delete ui;
}

void Dialog::LaneSlot( ){
    QString title = ui->lineEdit->text( ); // получаем строку из первого QLineEdit
    QString author = ui->lineEdit_2->text( ); // получаем строку из второго QLineEdit
    QString year = ui->lineEdit_3->text( );
    QString count = ui->lineEdit_4->text( );
    QString genre = ui->lineEdit_5->text( );
    QString mark = ui->lineEdit_6->text( );
}


void Dialog::on_pushButton_save_clicked(){
    if (ui->lineEdit_5->text( ).size( ) != 0 || ui->lineEdit_6->text( ).size( ) != 0)
        books->add(std::make_shared<PublicBook>(ui->lineEdit->text( ).toStdString( ),ui->lineEdit_2->text( ).toStdString( ) , ui->lineEdit_3->text( ).toInt( ), ui->lineEdit_4->text( ).toInt( ), ui->lineEdit_5->text( ).toStdString( ), ui->lineEdit_6->text( ).toInt( ))); // получаем данные от указателя
    else
        books->add(std::make_shared<book>(ui->lineEdit->text( ).toStdString( ),ui->lineEdit_2->text( ).toStdString( ) , ui->lineEdit_3->text( ).toInt( ), ui->lineEdit_4->text( ).toInt( )));
    ui->lineEdit->clear( ); //очищаем поля после нажатия Save
    ui->lineEdit_2->clear( );
    ui->lineEdit_3->clear( );
    ui->lineEdit_4->clear( );
    ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();
    DialogUi->showContent( );

}


//Чтение из файла
void Dialog::on_pushButton_clicked()
{
    std::string type_of_book;// тип книги
    std::string BookTitle,BookAuthor, genre;
    int BookYear,BookCount, mark;
    std::string filename = ui->lineEdit_7->text().toStdString();
    std::ifstream f(filename.c_str());
    while (f)
    {
        f >> type_of_book;
        if (!f) break;

        if (type_of_book == "B") {
            std::getline(f, BookTitle);
            std::getline(f, BookAuthor);
            f >> BookYear >> BookCount;

            books->add(std::make_shared<book>(BookTitle, BookAuthor, BookYear, BookCount)); // создает общий указатель, который управляет новым объектом
            continue; // переход на след. итерацию цикла
        }

        if (type_of_book == "PB") {
            std::getline(f, BookTitle);
            std::getline(f, BookAuthor);
            std::getline(f, genre);
            f >> BookYear >> BookCount >> mark;

            books->add(std::make_shared<PublicBook>(BookTitle, BookAuthor, BookYear, BookCount, genre, mark)); // создает общий указатель, который управляет новым объектом
            continue;
        }



    }
    DialogUi->showContent( );
    ui->lineEdit_7->clear(); // очищение строки имя файла
}

void Dialog::on_pushButton_3_clicked()
{
    if (ui->lineEdit_5->text( ).size( ) != 0 || ui->lineEdit_6->text( ).size( ) != 0)
        books->add(std::make_shared<PublicBook>(ui->lineEdit->text( ).toStdString( ),ui->lineEdit_2->text( ).toStdString( ) , ui->lineEdit_3->text( ).toInt( ), ui->lineEdit_4->text( ).toInt( ), ui->lineEdit_5->text( ).toStdString( ), ui->lineEdit_6->text( ).toInt( ))); // получаем данные от указателя
    else
        books->add(std::make_shared<book>(ui->lineEdit->text( ).toStdString( ),ui->lineEdit_2->text( ).toStdString( ) , ui->lineEdit_3->text( ).toInt( ), ui->lineEdit_4->text( ).toInt( )));
    ui->lineEdit->clear( ); //очищаем поля после нажатия Save
    ui->lineEdit_2->clear( );
    ui->lineEdit_3->clear( );
    ui->lineEdit_4->clear( );
    ui->lineEdit_5->clear( );
    ui->lineEdit_6->clear( );
    DialogUi->showContent( );
}

void Dialog::on_pushButton_Thread_clicked()
{
    if (ui->lineEdit_5->text( ).size( ) != 0 || ui->lineEdit_6->text( ).size( ) != 0)
        delayed[(counter++) % 2].push_back(std::make_shared<PublicBook>(ui->lineEdit->text( ).toStdString( ),ui->lineEdit_2->text( ).toStdString( ) , ui->lineEdit_3->text( ).toInt( ), ui->lineEdit_4->text( ).toInt( ), ui->lineEdit_5->text( ).toStdString( ), ui->lineEdit_6->text( ).toInt( ))); // получаем данные от указателя
    else
        delayed[(counter++) % 2].push_back(std::make_shared<book>(ui->lineEdit->text( ).toStdString( ),ui->lineEdit_2->text( ).toStdString( ) , ui->lineEdit_3->text( ).toInt( ), ui->lineEdit_4->text( ).toInt( )));
    ui->lineEdit->clear( ); //очищаем поля после нажатия Save
    ui->lineEdit_2->clear( );
    ui->lineEdit_3->clear( );
    ui->lineEdit_4->clear( );
    ui->lineEdit_5->clear( );
    ui->lineEdit_6->clear( );
}
