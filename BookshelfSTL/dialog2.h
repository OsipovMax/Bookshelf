#ifndef DIALOG2_H
#define DIALOG2_H
#include "bookshelf.h"
#include <QDialog>

namespace Ui {
class Dialog2;
}

class Dialog2 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog2(bookshelf<MagicNumber > *books,QWidget *parent = 0);
    ~Dialog2();


private:
    Ui::Dialog2 *ui;
    bookshelf<MagicNumber > *books;
};

#endif // DIALOG2_H
