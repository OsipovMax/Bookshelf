#include "myinterface.h"
#include "ui_myinterface.h"
#include <QDebug>
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <fstream>
#include "book.h"

MyInterface::MyInterface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyInterface),
    books(new bookshelf<MagicNumber>),
    pr1(b[0], mta, *books, *this),
    pr2(b[1], mta, *books, *this)
{
    ui->setupUi(this);

    //books = new bookshelf<MagicNumber>( );
    myDialog = new Dialog(this, books, b); // создаем форму
    myDialog2= new Dialog2(books);
    myDialog3= new Dialog3(this,books);
    myDialog4= new DialogHelp;
    editF= new FormEditor(this,books);
    bookTableWidget = new QTableWidgetItem[4];
    //вызов различных окон по нажатию кнопок
    connect(ui->pushButton_add, SIGNAL(clicked( )), myDialog, SLOT(show( )));
    connect(ui->pushButton_delete, SIGNAL(clicked( )), myDialog3, SLOT(show( )));
    connect(ui->pushButton_help, SIGNAL(clicked( )),myDialog4, SLOT(show()));
    connect(ui->actionAdd, SIGNAL(triggered( )), myDialog, SLOT(show( )));
    connect(ui->actionDelete, SIGNAL(triggered( )),myDialog3, SLOT(show( )));
    connect(ui->actionSwap, SIGNAL(triggered( )), myDialog2, SLOT(show( )));
    connect(ui->actionReference, SIGNAL(triggered( )), myDialog4, SLOT(show( )));


}

MyInterface::~MyInterface( ){
    delete ui;
    delete myDialog;
    delete myDialog2;
    delete myDialog3;
    delete books;
}

void MyInterface::on_pushButton_clicked( ){

}

void MyInterface::on_pushButton_delete_clicked( ){

}

void MyInterface::on_pushButton_Count_clicked( ){
    showCount( ); // по нажатию кнопки "Count" вызывает функция
}

//Функция вывода списка книг на экран
void MyInterface::showContent( ){
    ui->tableWidget_books->clear( );
    ui->tableWidget_books->setEditTriggers(QAbstractItemView::NoEditTriggers); //не редактируемые поля
    if (books->size( )) {
        ui->tableWidget_books->setRowCount(1);      //Количество строк
        ui->tableWidget_books->setColumnCount(4);   //Количество столбцов
        bookTableWidget = new QTableWidgetItem[4]; // создаем вновь

        bookTableWidget[0].setText(QString::fromStdString(books->front( )->get_title( ))); //каждому полю задаем значения
        bookTableWidget[1].setText(QString::fromStdString(books->front( )->get_author( )));
        bookTableWidget[2].setText(QString::number(books->front( )->get_year( )));
        bookTableWidget[3].setText(QString::number(books->front( )->get_page_count( )));
        // в цикле задаем каждому полю таблицы соответствующие значение 0-индекс строки , i- столбца
        for (int i = 0; i < 4; ++i)
            ui->tableWidget_books->setItem(0, i, &bookTableWidget[i]);// &book[i]- получение адреса нужного элемента
    } else
        ui->tableWidget_books->setRowCount(0);

}



//Функция вывода количества книг на экран
void MyInterface::showCount ( ){

    ui->tableWidget_books->clear( );
    // if(books->size( )){
    ui->tableWidget_books->setRowCount(1);
    ui->tableWidget_books->setColumnCount(1);
    bookTableWidget = new QTableWidgetItem[1];
    bookTableWidget[0].setText(QString::number(books->size( )));
    ui->tableWidget_books->setItem(0, 0, bookTableWidget);
    //    } else
    //        ui->tableWidget_books->setRowCount(0);

}
// Элементы "Menu"
void MyInterface::on_actionAdd_triggered( ){

}

void MyInterface::on_actionCount_triggered( ){
    showCount ( );
}

void MyInterface::on_actionDelete_triggered( ){

}

void MyInterface::on_actionReference_triggered( ){

}

void MyInterface::on_pushButton_help_clicked()
{

}


//сохраниение данных в фаил
void MyInterface::on_actionSave_file_triggered( ){
    std::ofstream fout("Lab1.txt", std::ios::app);//app- стремится к концу потока
    fout << (std::string) *(books->front( ));
    fout.close();
}



void MyInterface::on_tableWidget_books_doubleClicked(const QModelIndex &index)
{
    editF->show( ); // вызов онка редактора
}



void MyInterface::on_pushButton_2_clicked()
{
    if (books->size()<2 ){
        QMessageBox::information(this, "Warning", "No much books");
    }
    else {
    std::shared_ptr<book> a1 = books->front( );
    books->pop( );
    std::shared_ptr<book> a2 = books->front( );
    books->pop( );
    books->add(sum_books(*a1, *a2));
    showContent( );
    }
}

void MyInterface::on_pushButton_3_clicked()
{
    pr1.start( );
    pr2.start( );
}
