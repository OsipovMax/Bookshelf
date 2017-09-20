#ifndef FORMEDITOR_H
#define FORMEDITOR_H

#include <QDialog>
#include "bookshelf.h"
namespace Ui {
class FormEditor;
}

class MyInterface;

class FormEditor : public QDialog
{
    Q_OBJECT

public:
    explicit FormEditor(MyInterface* , bookshelf<MagicNumber> *books, QWidget *parent = 0);//bookshelf на book
    void show( );
    ~FormEditor();

private slots:

    void EditLaneSlot();
    void on_pushButton_2_clicked();

private:
    Ui::FormEditor *ui;
    bookshelf<MagicNumber> *books;
    MyInterface *DialogUi;
};

#endif // FORMEDITOR_H
