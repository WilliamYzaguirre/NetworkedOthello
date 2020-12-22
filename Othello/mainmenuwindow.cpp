#include "mainmenuwindow.h"
#include "ui_mainmenuwindow.h"
#include "othelloai.h"
#include "PlayerTypes.h"

MainMenuWindow::MainMenuWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenuWindow)
{
    ui->setupUi(this);

    ui->player1select->addItem("Human");
    ui->player1select->addItem("AI");

    ui->player2select->addItem("Human");
    ui->player2select->addItem("AI");

    ui->titleDisplay->setText("Othello");
    ui->titleDisplay->setFont(QFont("", 20));

    ui->p1display->setText("Please Select Player 1 (Black)");
    ui->p2display->setText("Please Select Player 2 (White)");

    ui->startButton->setText("Start Game");
}

MainMenuWindow::~MainMenuWindow()
{
    delete ui;
}



void MainMenuWindow::on_startButton_clicked()
{
    PlayerType p1;
    PlayerType p2;
    if (ui->player1select->currentText() == "AI") {
        qDebug("ai");
        p1 = ai;
    }
    else {
        p1 = human;
    }
    if (ui->player2select->currentText() == "AI") {
        p2 = ai;
    }
    else {
        p2 = human;
    }
    gameEngine = new GameEngine(p1, p2);
}
