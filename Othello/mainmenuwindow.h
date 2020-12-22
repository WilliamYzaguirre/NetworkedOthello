#ifndef MAINMENUWINDOW_H
#define MAINMENUWINDOW_H

#include <QMainWindow>
#include "gameengine.h"

namespace Ui {
class MainMenuWindow;
}

class MainMenuWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainMenuWindow(QWidget *parent = nullptr);
    ~MainMenuWindow();

private slots:
    void on_startButton_clicked();

signals:
    void startGame(QString, QString);

private:
    Ui::MainMenuWindow *ui;

    GameEngine* gameEngine;
};

#endif // MAINMENUWINDOW_H
