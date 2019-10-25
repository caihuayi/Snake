#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    field = new Field(100, 100, 20, 20, 20);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete field;
}

void MainWindow::paintEvent(QPaintEvent *pe)
{
    pen = new QPen();
    brush = new QBrush();
    painter = new QPainter(this);
    pen->setColor(Qt::red);
    pen->setStyle(Qt::SolidLine);
    brush->setColor(Qt::white);
    brush->setStyle(Qt::NoBrush);
    painter->setPen(*pen);
    painter->setBrush(*brush);
    field->draw(painter);
    delete painter;
    delete pen;
    delete brush;
}

void MainWindow::keyPressEvent(QKeyEvent*)
{

}
