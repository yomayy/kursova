/********************************************************************************
** Form generated from reading UI file 'mainwindowtree.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOWTREE_H
#define UI_MAINWINDOWTREE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowTree
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *txtTitle;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *txtAuthor;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *txtLang;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *txtPrice;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *txtYear;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *btAdd;
    QPushButton *btDelete;
    QTreeWidget *treeWidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QPushButton *btSearch;
    QCheckBox *checkFav;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *btFav;
    QPushButton *btUnsetFav;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindowTree)
    {
        if (MainWindowTree->objectName().isEmpty())
            MainWindowTree->setObjectName(QStringLiteral("MainWindowTree"));
        MainWindowTree->resize(953, 681);
        centralwidget = new QWidget(MainWindowTree);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 370, 219, 161));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        txtTitle = new QLineEdit(layoutWidget);
        txtTitle->setObjectName(QStringLiteral("txtTitle"));

        horizontalLayout->addWidget(txtTitle);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        txtAuthor = new QLineEdit(layoutWidget);
        txtAuthor->setObjectName(QStringLiteral("txtAuthor"));

        horizontalLayout_2->addWidget(txtAuthor);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        txtLang = new QLineEdit(layoutWidget);
        txtLang->setObjectName(QStringLiteral("txtLang"));

        horizontalLayout_3->addWidget(txtLang);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        txtPrice = new QLineEdit(layoutWidget);
        txtPrice->setObjectName(QStringLiteral("txtPrice"));

        horizontalLayout_4->addWidget(txtPrice);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_5->addWidget(label_5);

        txtYear = new QLineEdit(layoutWidget);
        txtYear->setObjectName(QStringLiteral("txtYear"));

        horizontalLayout_5->addWidget(txtYear);


        verticalLayout->addLayout(horizontalLayout_5);

        layoutWidget_2 = new QWidget(centralwidget);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(30, 320, 168, 27));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        btAdd = new QPushButton(layoutWidget_2);
        btAdd->setObjectName(QStringLiteral("btAdd"));

        horizontalLayout_6->addWidget(btAdd);

        btDelete = new QPushButton(layoutWidget_2);
        btDelete->setObjectName(QStringLiteral("btDelete"));

        horizontalLayout_6->addWidget(btDelete);

        treeWidget = new QTreeWidget(centralwidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setGeometry(QRect(30, 0, 911, 291));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(90, 550, 111, 71));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        btSearch = new QPushButton(widget);
        btSearch->setObjectName(QStringLiteral("btSearch"));

        verticalLayout_2->addWidget(btSearch);

        checkFav = new QCheckBox(widget);
        checkFav->setObjectName(QStringLiteral("checkFav"));

        verticalLayout_2->addWidget(checkFav);

        widget1 = new QWidget(centralwidget);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(270, 320, 168, 27));
        horizontalLayout_7 = new QHBoxLayout(widget1);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        btFav = new QPushButton(widget1);
        btFav->setObjectName(QStringLiteral("btFav"));

        horizontalLayout_7->addWidget(btFav);

        btUnsetFav = new QPushButton(widget1);
        btUnsetFav->setObjectName(QStringLiteral("btUnsetFav"));

        horizontalLayout_7->addWidget(btUnsetFav);

        MainWindowTree->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindowTree);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 953, 22));
        MainWindowTree->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindowTree);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindowTree->setStatusBar(statusbar);

        retranslateUi(MainWindowTree);

        QMetaObject::connectSlotsByName(MainWindowTree);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowTree)
    {
        MainWindowTree->setWindowTitle(QApplication::translate("MainWindowTree", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindowTree", "Title", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindowTree", "Author", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindowTree", "Language", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindowTree", "Price", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindowTree", "Year", Q_NULLPTR));
        btAdd->setText(QApplication::translate("MainWindowTree", "Add", Q_NULLPTR));
        btDelete->setText(QApplication::translate("MainWindowTree", "Delete", Q_NULLPTR));
        btSearch->setText(QApplication::translate("MainWindowTree", "Search", Q_NULLPTR));
        checkFav->setText(QApplication::translate("MainWindowTree", "Favourite", Q_NULLPTR));
        btFav->setText(QApplication::translate("MainWindowTree", "setFav", Q_NULLPTR));
        btUnsetFav->setText(QApplication::translate("MainWindowTree", "unsetFav", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindowTree: public Ui_MainWindowTree {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOWTREE_H
