#include "search.h"
#include "ui_search.h"
#include <QFile>
#include <QTextStream>

Search::Search(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Search)
{
    ui->setupUi(this);
    loadTextFile();
}

Search::~Search()
{
    delete ui;
}

void Search::on_pushButton_search_clicked()
{
    QString searchString = ui->lineEdit->text();
       ui->lineEdit_For_search->find(searchString, QTextDocument::FindWholeWords);
}
void TextFinder::loadTextFile()
{
    QFile inputFile(":/input.txt");
    inputFile.open(QIODevice::ReadOnly);

    QTextStream in(&inputFile);
    QString line = in.readAll();
    inputFile.close();

    ui->textEdit->setPlainText(line);
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor, 1);
}
}
