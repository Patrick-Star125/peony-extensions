/********************************************************************************
** Form generated from reading UI file 'rename-page.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RENAME_2D_PAGE_H
#define UI_RENAME_2D_PAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
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
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_search;
    QLabel *label_replace;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *edit_search;
    QLineEdit *edit_replace;
    QVBoxLayout *verticalLayout;
    QCheckBox *check_use_reg;
    QCheckBox *check_match_all;
    QCheckBox *check_case_sen;
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
        verticalLayout_5 = new QVBoxLayout(RenamePage);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_search = new QLabel(RenamePage);
        label_search->setObjectName(QString::fromUtf8("label_search"));

        verticalLayout_2->addWidget(label_search);

        label_replace = new QLabel(RenamePage);
        label_replace->setObjectName(QString::fromUtf8("label_replace"));

        verticalLayout_2->addWidget(label_replace);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        edit_search = new QLineEdit(RenamePage);
        edit_search->setObjectName(QString::fromUtf8("edit_search"));

        verticalLayout_3->addWidget(edit_search);

        edit_replace = new QLineEdit(RenamePage);
        edit_replace->setObjectName(QString::fromUtf8("edit_replace"));

        verticalLayout_3->addWidget(edit_replace);


        horizontalLayout->addLayout(verticalLayout_3);


        horizontalLayout_3->addLayout(horizontalLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        check_use_reg = new QCheckBox(RenamePage);
        check_use_reg->setObjectName(QString::fromUtf8("check_use_reg"));

        verticalLayout->addWidget(check_use_reg);

        check_match_all = new QCheckBox(RenamePage);
        check_match_all->setObjectName(QString::fromUtf8("check_match_all"));

        verticalLayout->addWidget(check_match_all);

        check_case_sen = new QCheckBox(RenamePage);
        check_case_sen->setObjectName(QString::fromUtf8("check_case_sen"));

        verticalLayout->addWidget(check_case_sen);


        horizontalLayout_3->addLayout(verticalLayout);


        verticalLayout_4->addLayout(horizontalLayout_3);

        names_table = new QTableView(RenamePage);
        names_table->setObjectName(QString::fromUtf8("names_table"));

        verticalLayout_4->addWidget(names_table);

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


        verticalLayout_4->addLayout(horizontalLayout_2);


        verticalLayout_5->addLayout(verticalLayout_4);


        retranslateUi(RenamePage);

        QMetaObject::connectSlotsByName(RenamePage);
    } // setupUi

    void retranslateUi(QWidget *RenamePage)
    {
        RenamePage->setWindowTitle(QCoreApplication::translate("RenamePage", "RenamePage", nullptr));
        label_search->setText(QCoreApplication::translate("RenamePage", "Search:", nullptr));
        label_replace->setText(QCoreApplication::translate("RenamePage", "Replace:", nullptr));
        check_use_reg->setText(QCoreApplication::translate("RenamePage", "Use regular expressions", nullptr));
        check_match_all->setText(QCoreApplication::translate("RenamePage", "Match all occurrences", nullptr));
        check_case_sen->setText(QCoreApplication::translate("RenamePage", "Case sensitive", nullptr));
        button_apply->setText(QCoreApplication::translate("RenamePage", "Apply", nullptr));
        button_rename->setText(QCoreApplication::translate("RenamePage", "Rename", nullptr));
        button_cancel->setText(QCoreApplication::translate("RenamePage", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RenamePage: public Ui_RenamePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RENAME_2D_PAGE_H
