#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QRegularExpression>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->lineEdit, &QLineEdit::textEdited, [this](QString current)
    {
        QRegularExpression exp("\\+\\d\\d\\d\\d\\d\\d\\d\\d\\d\\d\\d$");
        if (exp.match(current).hasMatch()) {
            setOkLabel();
        }
        else {
            setFailLabel();
        }
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setOkLabel()
{
   ui->label->setText("OK");
   ui->label->setStyleSheet("QLabel{color:green;}");
}

void MainWindow::setFailLabel()
{
    ui->label->setText("FAIL");
    ui->label->setStyleSheet("QLabel{color:red;}");
}

