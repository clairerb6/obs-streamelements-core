/********************************************************************************
** Form generated from reading UI file 'networkdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NETWORKDIALOG_H
#define UI_NETWORKDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NetworkDialog
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *ctl_message;
    QProgressBar *ctl_progressBar;
    QGridLayout *gridLayout;
    QPushButton *ctl_cancelButton;

    void setupUi(QDialog *NetworkDialog)
    {
        if (NetworkDialog->objectName().isEmpty())
            NetworkDialog->setObjectName("NetworkDialog");
        NetworkDialog->resize(640, 120);
        NetworkDialog->setMinimumSize(QSize(640, 120));
        NetworkDialog->setMaximumSize(QSize(640, 120));
        NetworkDialog->setSizeGripEnabled(false);
        NetworkDialog->setModal(true);
        verticalLayoutWidget = new QWidget(NetworkDialog);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(-1, -1, 641, 131));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setSizeConstraint(QLayout::SetNoConstraint);
        verticalLayout->setContentsMargins(20, 20, 20, 20);
        ctl_message = new QLabel(verticalLayoutWidget);
        ctl_message->setObjectName("ctl_message");
        QFont font;
        font.setPointSize(8);
        font.setBold(false);
        ctl_message->setFont(font);
        ctl_message->setAlignment(Qt::AlignCenter);
        ctl_message->setWordWrap(true);

        verticalLayout->addWidget(ctl_message);

        ctl_progressBar = new QProgressBar(verticalLayoutWidget);
        ctl_progressBar->setObjectName("ctl_progressBar");
        ctl_progressBar->setValue(24);
        ctl_progressBar->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(ctl_progressBar);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName("gridLayout");
        ctl_cancelButton = new QPushButton(verticalLayoutWidget);
        ctl_cancelButton->setObjectName("ctl_cancelButton");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ctl_cancelButton->sizePolicy().hasHeightForWidth());
        ctl_cancelButton->setSizePolicy(sizePolicy);

        gridLayout->addWidget(ctl_cancelButton, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(NetworkDialog);

        QMetaObject::connectSlotsByName(NetworkDialog);
    } // setupUi

    void retranslateUi(QDialog *NetworkDialog)
    {
        NetworkDialog->setWindowTitle(QCoreApplication::translate("NetworkDialog", "StreamElements: The Ultimate Streamer Platform", nullptr));
        ctl_message->setText(QCoreApplication::translate("NetworkDialog", "TextLabel", nullptr));
        ctl_cancelButton->setText(QCoreApplication::translate("NetworkDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NetworkDialog: public Ui_NetworkDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NETWORKDIALOG_H
