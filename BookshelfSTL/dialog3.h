#ifndef DIALOG3_H
#define DIALOG3_H
#include "bookshelf.h"
#include <QDialog>

namespace Ui {
class Dialog3;
}

class MyInterface; // говорит о том, что есть тип MyInterface

class Dialog3 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog3(MyInterface*, bookshelf<MagicNumber> *books, QWidget *parent = 0);
    ~Dialog3();

private slots:

    void on_pushButton_del_yes_clicked();

private:
    Ui::Dialog3 *ui;
    bookshelf<MagicNumber> *books;
    MyInterface *DialogUi;
};

#endif // DIALOG3_H
