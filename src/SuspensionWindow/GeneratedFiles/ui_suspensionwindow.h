/********************************************************************************
** Form generated from reading UI file 'suspensionwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUSPENSIONWINDOW_H
#define UI_SUSPENSIONWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SuspensionWindowClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;

    void setupUi(QMainWindow *SuspensionWindowClass)
    {
        if (SuspensionWindowClass->objectName().isEmpty())
            SuspensionWindowClass->setObjectName(QStringLiteral("SuspensionWindowClass"));
        SuspensionWindowClass->resize(338, 283);
        centralWidget = new QWidget(SuspensionWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        SuspensionWindowClass->setCentralWidget(centralWidget);

        retranslateUi(SuspensionWindowClass);

        QMetaObject::connectSlotsByName(SuspensionWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *SuspensionWindowClass)
    {
        SuspensionWindowClass->setWindowTitle(QApplication::translate("SuspensionWindowClass", "SuspensionWindow", 0));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SuspensionWindowClass: public Ui_SuspensionWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUSPENSIONWINDOW_H
