#ifndef BOARDGUI_H
#define BOARDGUI_H
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QObject>
#include "diskgui.h"
#include "tilegui.h"
#include "othelloboard.h"

class BoardGui : public QGraphicsView
{
    Q_OBJECT
public:
    BoardGui(QWidget *parent = 0);

    ~BoardGui();

    void drawMainScene();

    void drawBoard();

    void drawTile(int x, int y);

    void addToScene(QGraphicsItem *item);
    void removeFromScene(QGraphicsItem *item);

    void drawPiece(int x, int y, QColor color);

    void reDrawPieces(OthelloBoard* board);

    void connectAllTiles();

    void connectTiles(std::vector<std::pair<int, int>> tiles);

    void disconnectAllTiles();

    void disconnectTile(std::vector<std::pair<int, int>> tiles);

    void flipDisks(std::vector<std::pair<int,int>> disks);

    void drawTurnIndicator();

    void switchTurnBlack();

    void switchTurnWhite();

    void drawScores();

    void updateBlackScore(int score);

    void updateWhiteScore(int score);

    void drawEndGame(TileState winner);    

public slots:
    void recieveTileClick(int, int);

signals:
    void sendTileClick(int, int);

private:
    QGraphicsScene* gameScene;
    QGraphicsTextItem* turnDisplay;

    QGraphicsTextItem* blackScore;
    QGraphicsTextItem* whiteScore;

    QGraphicsTextItem* endGameDialog;

    DiskGui* diskList[8][8];
    TileGui* tileList[8][8];
};

#endif // BOARDGUI_H
