#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "field.h"
#include <QMainWindow>
#include <QKeyEvent>
#include <QPainter>
#include <QPen>
#include <QBrush>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent*);
    void keyPressEvent(QKeyEvent*);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Field *field;
    QPen* pen;
    QBrush* brush;
    QPainter *painter;
};
#endif // MAINWINDOW_H
