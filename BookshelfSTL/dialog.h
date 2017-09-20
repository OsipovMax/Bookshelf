#ifndef DIALOG_H
#define DIALOG_H
#include "bookshelf.h"
#include <QDialog>

namespace Ui {
class Dialog;
}

class MyInterface; // говорит о том, что есть тип MyInterface

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(MyInterface* , bookshelf<MagicNumber > *books, std::vector<std::shared_ptr<book> > *, QWidget *parent = 0); // * и диалоговое окно и интефейс работали с одной и той же книжной полкой
    ~Dialog();

private slots:
    void on_pushButton_save_clicked();

    void LaneSlot(); // slot edit

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_Thread_clicked();

private:
    std::vector<std::shared_ptr<book> > * delayed;
    int counter;
    Ui::Dialog *ui;
    bookshelf<MagicNumber > *books;
    MyInterface *DialogUi;
};

#endif // DIALOG_H
