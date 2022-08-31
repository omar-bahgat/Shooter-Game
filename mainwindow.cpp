#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <Game.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_startGame_clicked()
{
    Game * game;
    game = new Game();
    game->show();
}


void MainWindow::on_pushButton_clicked()
{
    close();
}

