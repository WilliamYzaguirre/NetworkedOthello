#include "boardgui.h"
#include <QBrush>
#include "tilegui.h"
#include "diskgui.h"
#include "othelloboard.h"
#include <string>

BoardGui::BoardGui(QWidget *parent) : QGraphicsView(parent)
{

}

BoardGui::~BoardGui()
{
    delete gameScene;
    delete blackScore;
    delete whiteScore;
    delete turnDisplay;
    delete endGameDialog;

    for (int x = 0; x < 8; ++x) {
        for (int y = 0; y < 8; ++y) {
            delete tileList[x][y];
            delete diskList[x][y];
        }
    }
}

//Draws main scene. Background rectangle of fixed size
//Width=1400, height=900
void BoardGui::drawMainScene()
{
    gameScene = new QGraphicsScene();
    gameScene->setSceneRect(0,0,2000,1200);

    setFixedSize(2000,1200);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setScene(gameScene);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::gray);
    setBackgroundBrush(brush);
}

void BoardGui::drawBoard()
{
    for (int x = 0; x < 8; ++x) {
        for (int y = 0; y < 8; ++y) {
            drawTile(x,y);
        }
    }
}


//draws a tile for the board
void BoardGui::drawTile(int x, int y)
{
    TileGui* tile = new TileGui();
    tile->setLocation(x, y);
    tile->setRect((2000/2-400)+100*x, 100+100*y,100,100);
    tileList[x][y] = tile;
    tile->setState(empty);
    this->addToScene(tile);
}

//adds object to main scene
void BoardGui::addToScene(QGraphicsItem *item) {
    gameScene->addItem(item);
}

//removes object from main scene
void BoardGui::removeFromScene(QGraphicsItem *item) {
    gameScene->removeItem(item);
}

//int x: column of disk
//int y: row of disk
//QColor color: color of disk initially
//Draws a disk to the given location
void BoardGui::drawPiece(int x, int y, QColor color)
{
    DiskGui* disk = new DiskGui();
    disk->setRect((2000/2-400)+100*x, 100+100*y,100,100);
    disk->setColor(color);
    diskList[x][y] = disk;
    if (color == Qt::black) {
        tileList[x][y]->setState(black);
    }
    else {
        tileList[x][y]->setState(white);
    }
    //tileList[x][y]->setDisk(disk);
    this->addToScene(disk);
}

//Connects tiles to game.cpp so when they are clicked, the game can know
void BoardGui::connectAllTiles()
{
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            connect(tileList[x][y], SIGNAL(tileClicked(int, int)), this, SLOT(recieveTileClick(int, int)));
        }
    }
}

void BoardGui::connectTiles(std::vector<std::pair<int, int> > tiles) {
    for (std::pair<int, int> tile : tiles) {
        connect(tileList[tile.first][tile.second], SIGNAL(tileClicked(int, int)), this, SLOT(recieveTileClick(int, int)));
    }
}

void BoardGui::disconnectAllTiles()
{
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            disconnect(tileList[x][y], SIGNAL(tileClicked(int, int)), this, SLOT(recieveTileClick(int, int)));
        }
    }
}

void BoardGui::disconnectTile(std::vector<std::pair<int, int> > tiles)
{
    for (std::pair<int, int> tile : tiles) {
        disconnect(tileList[tile.first][tile.second], SIGNAL(tileClicked(int, int)), this, SLOT(recieveTileClick(int, int)));
    }
}

void BoardGui::flipDisks(std::vector<std::pair<int, int> > disks)
{
    for (std::pair<int,int> disk : disks) {
        diskList[disk.first][disk.second]->flipColor();
    }
}

void BoardGui::drawTurnIndicator()
{
    turnDisplay = new QGraphicsTextItem();
    turnDisplay->setPos(width()/2-100, 10);
    turnDisplay->setZValue(1);
    turnDisplay->setDefaultTextColor(Qt::white);
    turnDisplay->setFont(QFont("",18));
    turnDisplay->setPlainText("Turn : BLACK");
    addToScene(turnDisplay);
}

void BoardGui::switchTurnBlack()
{
    turnDisplay->setPlainText("Turn : BLACK");
}

void BoardGui::switchTurnWhite()
{
    turnDisplay->setPlainText("Turn : WHITE");
}

void BoardGui::drawScores()
{
    blackScore = new QGraphicsTextItem();
    blackScore->setPos(10, height()/2);
    blackScore->setZValue(1);
    blackScore->setDefaultTextColor(Qt::white);
    blackScore->setFont(QFont("",18));
    blackScore->setPlainText("Black Score: 2");
    addToScene(blackScore);

    whiteScore = new QGraphicsTextItem();
    whiteScore->setPos(1500, height()/2);
    whiteScore->setZValue(1);
    whiteScore->setDefaultTextColor(Qt::white);
    whiteScore->setFont(QFont("",18));
    whiteScore->setPlainText("White Score: 2");
    addToScene(whiteScore);
}

void BoardGui::updateBlackScore(int score)
{
    QString s = QString::number(score);
    blackScore->setPlainText("Black Score: " + s);
}

void BoardGui::updateWhiteScore(int score)
{
    QString s = QString::number(score);
    whiteScore->setPlainText("White Score: " + s);
}

void BoardGui::drawEndGame(TileState winner)
{
    endGameDialog = new QGraphicsTextItem();
    endGameDialog->setPos(width()/2 - 200, height()/2);
    endGameDialog->setZValue(1);
    endGameDialog->setDefaultTextColor(Qt::red);
    endGameDialog->setFont(QFont("",18));
    if (winner == black) {
        endGameDialog->setPlainText("Congradulations Black! You Won!");
    }
    else {
        endGameDialog->setPlainText("Congradulations White! You Won!");

    }
    addToScene(endGameDialog);
}

void BoardGui::reDrawPieces(OthelloBoard* board)
{
    for (int x = 0; x < 8; ++x) {
        for (int y = 0; y < 8; ++y) {
            if (tileList[x][y]->getState() != board->getTile(x,y)) {
                if (tileList[x][y]->getState() == empty) {
                    if (board->getTile(x,y) == black) {
                        drawPiece(x,y,Qt::black);
                    }
                    else if (board->getTile(x,y) == white) {
                        drawPiece(x,y,Qt::white);
                    }
                }
                else if (tileList[x][y]->getState() == black) {
                    if (board->getTile(x,y) == white) {
                        removeFromScene(diskList[x][y]);
                        drawPiece(x,y, Qt::white);
                    }
                }
                else if (tileList[x][y]->getState() == white) {
                    if (board->getTile(x,y) == black) {
                        removeFromScene(diskList[x][y]);
                        drawPiece(x,y, Qt::black);
                    }
                }
            }
        }
    }
}

//Signals that a tile has been clicked at x,y
void BoardGui::recieveTileClick(int x, int y)
{
    emit sendTileClick(x, y);
}
