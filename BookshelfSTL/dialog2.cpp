#include "dialog2.h"
#include "ui_dialog2.h"
#include "bookshelf.h"

Dialog2::Dialog2(bookshelf<MagicNumber > *books, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog2),
    books(books)
{
    ui->setupUi(this);
}

Dialog2::~Dialog2(){
    delete ui;
}

