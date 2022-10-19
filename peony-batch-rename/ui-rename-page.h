#pragma once
/********************************************************************************
** Form generated from reading UI file ''
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RenamePage
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_search;
    QLineEdit *edit_search;
    QLabel *label_replace;
    QLineEdit *edit_replace;
    QTableView *names_table;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *button_apply;
    QPushButton *button_rename;
    QPushButton *button_cancel;

    void setupUi(QWidget *RenamePage)
    {
        if (RenamePage->objectName().isEmpty())
            RenamePage->setObjectName(QString::fromUtf8("RenamePage"));
        RenamePage->resize(610, 412);
        verticalLayout_2 = new QVBoxLayout(RenamePage);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_search = new QLabel(RenamePage);
        label_search->setObjectName(QString::fromUtf8("label_search"));

        horizontalLayout->addWidget(label_search);

        edit_search = new QLineEdit(RenamePage);
        edit_search->setObjectName(QString::fromUtf8("edit_search"));

        horizontalLayout->addWidget(edit_search);

        label_replace = new QLabel(RenamePage);
        label_replace->setObjectName(QString::fromUtf8("label_replace"));

        horizontalLayout->addWidget(label_replace);

        edit_replace = new QLineEdit(RenamePage);
        edit_replace->setObjectName(QString::fromUtf8("edit_replace"));

        horizontalLayout->addWidget(edit_replace);


        verticalLayout->addLayout(horizontalLayout);

        names_table = new QTableView(RenamePage);
        names_table->setObjectName(QString::fromUtf8("names_table"));

        verticalLayout->addWidget(names_table);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        button_apply = new QPushButton(RenamePage);
        button_apply->setObjectName(QString::fromUtf8("button_apply"));

        horizontalLayout_2->addWidget(button_apply);

        button_rename = new QPushButton(RenamePage);
        button_rename->setObjectName(QString::fromUtf8("button_rename"));

        horizontalLayout_2->addWidget(button_rename);

        button_cancel = new QPushButton(RenamePage);
        button_cancel->setObjectName(QString::fromUtf8("button_cancel"));

        horizontalLayout_2->addWidget(button_cancel);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(RenamePage);

        QMetaObject::connectSlotsByName(RenamePage);
    } // setupUi

    void retranslateUi(QWidget *RenamePage)
    {
        RenamePage->setWindowTitle(QCoreApplication::translate("RenamePage", "RenamePage", nullptr));
        label_search->setText(QCoreApplication::translate("RenamePage", "Search:", nullptr));
        label_replace->setText(QCoreApplication::translate("RenamePage", "Replace with:", nullptr));
        button_apply->setText(QCoreApplication::translate("RenamePage", "Apply", nullptr));
        button_rename->setText(QCoreApplication::translate("RenamePage", "Rename", nullptr));
        button_cancel->setText(QCoreApplication::translate("RenamePage", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RenamePage: public Ui_RenamePage {};
} // namespace Uii

QT_END_NAMESPACE

