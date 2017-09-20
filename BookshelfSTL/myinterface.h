#ifndef MYINTERFACE_H
#define MYINTERFACE_H

#include <QMainWindow> 
#include "dialog.h"
#include "dialog2.h"
#include "dialog3.h"
#include "dialoghelp.h"
#include "search.h"
#include "ui_myinterface.h"
#include "formeditor.h"
#include <QMutex>
#include "producer.h"
#include "updateable.h"

namespace Ui {
class MyInterface;
}

class MyInterface : public QMainWindow, public updateable
{
    Q_OBJECT

public:
    explicit MyInterface(QWidget *parent = 0);
    ~MyInterface();
    void showCount( );
    virtual void showContent( );


private slots:
    void on_pushButton_clicked();

    void on_pushButton_delete_clicked();

    void on_pushButton_Count_clicked();

    void on_actionAdd_triggered();

    void on_actionCount_triggered();

    void on_actionDelete_triggered();

    void on_actionReference_triggered();

    void on_pushButton_help_clicked();

    void on_actionSave_file_triggered();


    void on_tableWidget_books_doubleClicked(const QModelIndex &index);


    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MyInterface *ui;
    Dialog  *myDialog; // указатель на форму Dialog
    Dialog2 *myDialog2;
    Dialog3 *myDialog3;
    DialogHelp *myDialog4;
    bookshelf<MagicNumber > *books;
    std::vector<std::shared_ptr<book> > b[2];
    Producer pr1, pr2;

    QMutex mta;
    book *DiffrentBook;
    QTableWidgetItem *bookTableWidget; // чтобы деструктор мог удалить 4 Item слота
    Search *myDialog5;
    FormEditor *editF;
};





#endif // MYINTERFACE_H
