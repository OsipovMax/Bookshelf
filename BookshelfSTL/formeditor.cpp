#include "formeditor.h"
#include "ui_formeditor.h"
#include "bookshelf.h"
#include "myinterface.h"

FormEditor::FormEditor(MyInterface *DialogUi, bookshelf<MagicNumber > *books, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FormEditor),
    books(books),
    DialogUi(DialogUi)
{
    ui->setupUi(this);
}

FormEditor::~FormEditor()
{
    delete ui;
}

void FormEditor::show( ) {
    QDialog::show( );
    //ui->lineEdit_Editor1->setText(QString::fromStdString(books->front( )->get_title( ))); // получаем строку из первого QLineEdit
    //ui->lineEdit_Editor2->setText(QString::fromStdString(books->front( )->get_author( ))); // получаем строку из второго QLineEdit
    //ui->lineEdit_Editor3->setText(QString::number(books->front( )->get_year( )));
    //ui->lineEdit_Editor4->setText(QString::number(books->front( )->get_page_count( )));
}

void FormEditor::EditLaneSlot( ){
   QString title = ui->lineEdit_Editor1->text( );
}



void FormEditor::on_pushButton_2_clicked()
{
    book& ForBook = *(books->front( ));// получение сслыки на первую кингу
    if (ui->lineEdit_Editor1->text( ).size( )) ForBook.set_title(ui->lineEdit_Editor1->text( ).toStdString( ));
    if (ui->lineEdit_Editor2->text( ).size( )) ForBook.set_author(ui->lineEdit_Editor2->text( ).toStdString( ));
    if (ui->lineEdit_Editor3->text( ).size( )) ForBook.set_year(ui->lineEdit_Editor3->text( ).toInt( ));
    if (ui->lineEdit_Editor4->text( ).size( )) ForBook.set_page_count(ui->lineEdit_Editor4->text( ).toInt( ));


    ui->lineEdit_Editor1->clear( ); //очищаем поля после нажатия Save
    ui->lineEdit_Editor2->clear( );
    ui->lineEdit_Editor3->clear( );
    ui->lineEdit_Editor4->clear( );
    DialogUi->showContent( );

}
