/// \file SxHomeNavbarWidget.h
/// \brief SxHomeNavbarWidget class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#include "SxHomeNavbarWidget.h"
#include <sxwidgets>

SxHomeNavbarWidget::SxHomeNavbarWidget(QWidget *parent)
    : QWidget(parent){

    m_layout = new QVBoxLayout;
    m_layout->setContentsMargins(0,0,0,0);
    m_layout->addWidget(new QWidget(this), 1, Qt::AlignTop);

    // global
    QHBoxLayout *layout = new QHBoxLayout;
    QWidget *w = new QWidget(this);
    layout->addWidget(w, 1, Qt::AlignHCenter);
    layout->setContentsMargins(2,2,2,2);
    w->setLayout(m_layout);

    // total
    QHBoxLayout *tlayout = new QHBoxLayout;
    QWidget *wt = new QWidget(this);
    tlayout->addWidget(wt, 1, Qt::AlignHCenter);
    tlayout->setContentsMargins(0,0,0,0);
    wt->setLayout(layout);
    wt->setObjectName("SxHomeNavbarWidget");
    this->setLayout(tlayout);
}

void SxHomeNavbarWidget::addButton(QString icon, QString toolTip, int id, bool closable){

    SxClosableButton *button = new SxClosableButton(closable, this);
    button->setCheckable(true);
    button->setIcon(QIcon(icon));
    if (toolTip != ""){
        button->setToolTip(toolTip);
    }
    button->setId(id);
    m_layout->insertWidget(m_layout->count() -1, button);

    connect(button, SIGNAL(clicked(int)), this, SIGNAL(open(int)));
    connect(button, SIGNAL(closed(int)), this, SIGNAL(close(int)));
}

void SxHomeNavbarWidget::removeButton(int id){

    for (int i = m_layout->count()-1 ; i >= 0 ; i--){
        QLayoutItem* item = m_layout->itemAt(i);
        QWidget *w = item->widget();
        if (w){
             SxClosableButton* button = qobject_cast<SxClosableButton*>(w);
             if (button){
                 if (button->id() == id){
                     delete button;
                     return;
                 }
                 // decrease here the id if button after
                 else if(button->id() > id){
                     button->setId( button->id() -1 );
                 }
             }
        }
    }
}

void SxHomeNavbarWidget::setButtonChecked(int id, bool clicked){
    for (int i = 0 ; i < m_layout->count() ; ++i){
        QLayoutItem* item = m_layout->itemAt(i);
        QWidget *w = item->widget();
        if (w){
             SxClosableButton* button = qobject_cast<SxClosableButton*>(w);
             if (button){
                 if (button->id() == id){
                     //qDebug() << "set checked id = " << id;
                     if (!clicked){
                     button->setChecked(true);
                     }
                 }
                 else{
                     //qDebug() << "set unchecked id = " << button->id();
                     button->setChecked(false);
                 }
             }
        }
    }
}
