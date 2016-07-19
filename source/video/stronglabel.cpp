#include "stronglabel.h"

StrongLabel::StrongLabel(QWidget *parent) : QLabel(parent) {
    p_menu = NULL;
    p_submenu = NULL;
    p_threshold = NULL;
    p_save = NULL;
    createActions();
    p_threshold_widget = NULL;
}

StrongLabel::~StrongLabel() {
    delete p_menu;
    delete p_threshold;
    delete p_save;
}

void StrongLabel::createActions() {
    p_menu = new QMenu(this);

    p_threshold = new QAction(this);
    p_threshold->setText(tr("阈值分割"));
    connect(p_threshold, SIGNAL(triggered(bool)), this, SLOT(slot_deal_threshold()));

    p_VideoModel = new QAction(this);
    p_VideoModel->setText(tr("背景建模"));

    p_save = new QAction(this);
    p_save->setText(tr("图片存储"));

    p_submenu = new QMenu(this);
    p_video_gaussian = new QAction(this);
    p_video_gaussian->setText(tr("高斯背景模型"));
    connect(p_video_gaussian, SIGNAL(triggered(bool)), this, SLOT(slot_deal_gaussian_model()));

    p_video_lightflow = new QAction(this);
    p_video_lightflow->setText(tr("光流模型"));
}

void StrongLabel::slot_deal_threshold() {
    if(p_threshold_widget) {
        delete p_threshold_widget;
        p_threshold_widget = NULL;
    }
    p_threshold_widget = new Threshold();
    p_threshold_widget->show();
}

void StrongLabel::slot_deal_gaussian_model() {

}

void StrongLabel::contextMenuEvent(QContextMenuEvent *event) {
    p_menu->clear();
    p_menu->addAction(p_threshold);
    p_menu->addAction(p_VideoModel);

    p_submenu->addAction(p_video_gaussian);
    p_submenu->addAction(p_video_lightflow);
    p_VideoModel->setMenu(p_submenu);

    p_menu->addSeparator();
    p_menu->addAction(p_save);
    p_menu->exec(QCursor::pos());
    event->accept();
}
