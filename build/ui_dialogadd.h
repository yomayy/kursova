/********************************************************************************
** Form generated from reading UI file 'dialogadd.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGADD_H
#define UI_DIALOGADD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogAdd
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *DtxtTitle;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *DtxtAuthor;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *DtxtLang;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *DtxtPrice;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *DtxtYear;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *DbtCancel;
    QPushButton *DbtOk;

    void setupUi(QDialog *DialogAdd)
    {
        if (DialogAdd->objectName().isEmpty())
            DialogAdd->setObjectName(QStringLiteral("DialogAdd"));
        DialogAdd->resize(400, 300);
        layoutWidget = new QWidget(DialogAdd);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(80, 30, 219, 161));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        DtxtTitle = new QLineEdit(layoutWidget);
        DtxtTitle->setObjectName(QStringLiteral("DtxtTitle"));

        horizontalLayout->addWidget(DtxtTitle);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        DtxtAuthor = new QLineEdit(layoutWidget);
        DtxtAuthor->setObjectName(QStringLiteral("DtxtAuthor"));

        horizontalLayout_2->addWidget(DtxtAuthor);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        DtxtLang = new QLineEdit(layoutWidget);
        DtxtLang->setObjectName(QStringLiteral("DtxtLang"));

        horizontalLayout_3->addWidget(DtxtLang);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        DtxtPrice = new QLineEdit(layoutWidget);
        DtxtPrice->setObjectName(QStringLiteral("DtxtPrice"));

        horizontalLayout_4->addWidget(DtxtPrice);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_5->addWidget(label_5);

        DtxtYear = new QLineEdit(layoutWidget);
        DtxtYear->setObjectName(QStringLiteral("DtxtYear"));

        horizontalLayout_5->addWidget(DtxtYear);


        verticalLayout->addLayout(horizontalLayout_5);

        widget = new QWidget(DialogAdd);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(200, 240, 168, 27));
        horizontalLayout_6 = new QHBoxLayout(widget);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        DbtCancel = new QPushButton(widget);
        DbtCancel->setObjectName(QStringLiteral("DbtCancel"));

        horizontalLayout_6->addWidget(DbtCancel);

        DbtOk = new QPushButton(widget);
        DbtOk->setObjectName(QStringLiteral("DbtOk"));

        horizontalLayout_6->addWidget(DbtOk);


        retranslateUi(DialogAdd);

        QMetaObject::connectSlotsByName(DialogAdd);
    } // setupUi

    void retranslateUi(QDialog *DialogAdd)
    {
        DialogAdd->setWindowTitle(QApplication::translate("DialogAdd", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("DialogAdd", "Title", Q_NULLPTR));
        label_2->setText(QApplication::translate("DialogAdd", "Author", Q_NULLPTR));
        label_3->setText(QApplication::translate("DialogAdd", "Language", Q_NULLPTR));
        label_4->setText(QApplication::translate("DialogAdd", "Price", Q_NULLPTR));
        label_5->setText(QApplication::translate("DialogAdd", "Year", Q_NULLPTR));
        DbtCancel->setText(QApplication::translate("DialogAdd", "cancel", Q_NULLPTR));
        DbtOk->setText(QApplication::translate("DialogAdd", "ok", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogAdd: public Ui_DialogAdd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGADD_H
