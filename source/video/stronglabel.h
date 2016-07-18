#ifndef STRONGLABEL_H
#define STRONGLABEL_H

#include <QLabel>
#include <QObject>
#include <QMouseEvent>
#include <QMenu>
#include <QAction>
#include <QCursor>
#include "../ui/threshold.h"

class StrongLabel : public QLabel
{
    Q_OBJECT
public:
    explicit StrongLabel(QWidget *parent=0);
    ~StrongLabel();

private:
    void createActions();

signals:
    void signal_threshold();
    void save_image();

private slots:
    //产生一个界面用来进行分割阈值的处理，还有分割模式的选择
    void slot_deal_threshold();

protected:
    virtual void contextMenuEvent(QContextMenuEvent *event);

private:
    QMenu *p_menu;
    QAction *p_threshold;
    QAction *p_save;

private:
    Threshold* p_threshold_widget;
};

#endif // STRONGLABEL_H
