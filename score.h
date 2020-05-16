#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsItem>

class Score : public QGraphicsItem
{
public:
    Score(QGraphicsItem *parent);
    void increase();
    void getScore();

private:
    int score;

};

#endif // SCORE_H
