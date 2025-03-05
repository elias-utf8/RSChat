/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGroupBox *groupBox;
    QPushButton *boutonOuvrir;
    QPushButton *boutonFermer;
    QComboBox *comboPort;
    QLineEdit *lineEdit;
    QPushButton *boutonEnvoyer;
    QFrame *line;
    QTextEdit *TextEditZoneMessages;
    QLabel *labelInfo;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(340, 309);
        QFont font;
        font.setPointSize(8);
        Widget->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/icones/vga.png"), QSize(), QIcon::Normal, QIcon::Off);
        Widget->setWindowIcon(icon);
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 20, 311, 81));
        groupBox->setFont(font);
        groupBox->setStyleSheet(QString::fromUtf8("border : 1px solid #096ad9;"));
        boutonOuvrir = new QPushButton(groupBox);
        boutonOuvrir->setObjectName(QString::fromUtf8("boutonOuvrir"));
        boutonOuvrir->setGeometry(QRect(10, 20, 75, 23));
        boutonFermer = new QPushButton(groupBox);
        boutonFermer->setObjectName(QString::fromUtf8("boutonFermer"));
        boutonFermer->setGeometry(QRect(90, 20, 75, 23));
        comboPort = new QComboBox(groupBox);
        comboPort->setObjectName(QString::fromUtf8("comboPort"));
        comboPort->setGeometry(QRect(10, 50, 291, 22));
        comboPort->setFont(font);
        lineEdit = new QLineEdit(Widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 250, 281, 20));
        boutonEnvoyer = new QPushButton(Widget);
        boutonEnvoyer->setObjectName(QString::fromUtf8("boutonEnvoyer"));
        boutonEnvoyer->setGeometry(QRect(300, 250, 20, 21));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/icones/send-message.png"), QSize(), QIcon::Normal, QIcon::Off);
        boutonEnvoyer->setIcon(icon1);
        line = new QFrame(Widget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 230, 341, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        TextEditZoneMessages = new QTextEdit(Widget);
        TextEditZoneMessages->setObjectName(QString::fromUtf8("TextEditZoneMessages"));
        TextEditZoneMessages->setGeometry(QRect(10, 110, 311, 121));
        TextEditZoneMessages->setReadOnly(true);
        labelInfo = new QLabel(Widget);
        labelInfo->setObjectName(QString::fromUtf8("labelInfo"));
        labelInfo->setGeometry(QRect(10, 270, 321, 16));
        labelInfo->setTextFormat(Qt::AutoText);
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(280, 0, 51, 21));
        label->setStyleSheet(QString::fromUtf8("font-weight: bold;\n"
"font-style: italic;\n"
"color:#096ad9;\n"
"font-size: 13px;\n"
""));
        label->setTextFormat(Qt::RichText);
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(290, 210, 31, 21));
        label_2->setStyleSheet(QString::fromUtf8("font-weight: bold;\n"
"color:#096ad9;\n"
"font-size: 9px;\n"
""));
        label_2->setTextFormat(Qt::RichText);
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(180, 290, 151, 21));
        label_3->setStyleSheet(QString::fromUtf8("font-weight: bold;\n"
"color:#096ad9;\n"
"font-size: 9px;\n"
""));
        label_3->setTextFormat(Qt::RichText);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "RSChat ", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Widget", "Gestion du port s\303\251rie ", nullptr));
        boutonOuvrir->setText(QCoreApplication::translate("Widget", "Ouvrir", nullptr));
        boutonFermer->setText(QCoreApplication::translate("Widget", "Fermer", nullptr));
        boutonEnvoyer->setText(QString());
        labelInfo->setText(QString());
        label->setText(QCoreApplication::translate("Widget", "RSChat", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "/help", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "Elias GAUTHIER | BTS CIEL2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
