/********************************************************************************
** Form generated from reading UI file 'confirmpendingupdatedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIRMPENDINGUPDATEDIALOG_H
#define UI_CONFIRMPENDINGUPDATEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConfirmPendingUpdateDialog
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *verticalSpacer;
    QLabel *label_2;
    QVBoxLayout *verticalLayout;
    QTextBrowser *releaseNotes;
    QSpacerItem *verticalSpacer_4;
    QLabel *label_5;
    QLabel *label;
    QLabel *ctl_imageContainer;
    QSpacerItem *verticalSpacer_2;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *ctl_rejectButton;
    QPushButton *ctl_rejectSkipVersionButton;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *ctl_acceptButton;

    void setupUi(QDialog *ConfirmPendingUpdateDialog)
    {
        if (ConfirmPendingUpdateDialog->objectName().isEmpty())
            ConfirmPendingUpdateDialog->setObjectName("ConfirmPendingUpdateDialog");
        ConfirmPendingUpdateDialog->setWindowModality(Qt::WindowModality::ApplicationModal);
        ConfirmPendingUpdateDialog->resize(800, 630);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ConfirmPendingUpdateDialog->sizePolicy().hasHeightForWidth());
        ConfirmPendingUpdateDialog->setSizePolicy(sizePolicy);
        ConfirmPendingUpdateDialog->setMinimumSize(QSize(800, 630));
        ConfirmPendingUpdateDialog->setMaximumSize(QSize(800, 630));
        ConfirmPendingUpdateDialog->setBaseSize(QSize(800, 650));
        ConfirmPendingUpdateDialog->setContextMenuPolicy(Qt::ContextMenuPolicy::NoContextMenu);
        ConfirmPendingUpdateDialog->setModal(true);
        gridLayoutWidget = new QWidget(ConfirmPendingUpdateDialog);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(0, 0, 801, 571));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setSizeConstraint(QLayout::SizeConstraint::SetNoConstraint);
        gridLayout->setContentsMargins(20, 20, 20, 20);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setSizeConstraint(QLayout::SizeConstraint::SetFixedSize);
        verticalLayout_3->setContentsMargins(-1, -1, -1, 10);
        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_5);


        gridLayout->addLayout(verticalLayout_3, 5, 0, 1, 3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 8, 1, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName("label_2");
        label_2->setTextFormat(Qt::TextFormat::AutoText);
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_2->setWordWrap(true);

        gridLayout->addWidget(label_2, 4, 0, 1, 3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        releaseNotes = new QTextBrowser(gridLayoutWidget);
        releaseNotes->setObjectName("releaseNotes");
        releaseNotes->setEnabled(true);
        releaseNotes->setReadOnly(true);
        releaseNotes->setOpenExternalLinks(true);

        verticalLayout->addWidget(releaseNotes);


        gridLayout->addLayout(verticalLayout, 6, 0, 1, 3);

        verticalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);

        gridLayout->addItem(verticalSpacer_4, 1, 1, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName("label_5");
        QPalette palette;
        QBrush brush(QColor(106, 106, 106, 255));
        brush.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::WindowText, brush);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::WindowText, brush);
        QBrush brush1(QColor(120, 120, 120, 255));
        brush1.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::WindowText, brush1);
        label_5->setPalette(palette);
        label_5->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(label_5, 9, 1, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(label, 3, 0, 1, 3);

        ctl_imageContainer = new QLabel(gridLayoutWidget);
        ctl_imageContainer->setObjectName("ctl_imageContainer");
        ctl_imageContainer->setMinimumSize(QSize(128, 200));
        ctl_imageContainer->setPixmap(QPixmap(QString::fromUtf8(":/images/updater_logo.png")));
        ctl_imageContainer->setScaledContents(false);
        ctl_imageContainer->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(ctl_imageContainer, 0, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 10, 1, 1, 1);

        horizontalLayoutWidget = new QWidget(ConfirmPendingUpdateDialog);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(20, 570, 761, 41));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        ctl_rejectButton = new QPushButton(horizontalLayoutWidget);
        ctl_rejectButton->setObjectName("ctl_rejectButton");
        ctl_rejectButton->setEnabled(true);
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setUnderline(false);
        font1.setStrikeOut(false);
        ctl_rejectButton->setFont(font1);
        ctl_rejectButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        ctl_rejectButton->setAutoFillBackground(false);
        ctl_rejectButton->setStyleSheet(QString::fromUtf8("\n"
"        QPushButton {\n"
"          border-radius: 15px;\n"
"          padding: 8px;\n"
"          padding-left: 40px;\n"
"          padding-right: 40px;\n"
"          font-weight: bold;\n"
"          text-decoration: none;\n"
"        }\n"
"\n"
"        QPushButton:hover {\n"
"        }\n"
"\n"
"        QPushButton:pressed {\n"
"        }\n"
"       "));
        ctl_rejectButton->setAutoDefault(false);
        ctl_rejectButton->setFlat(true);

        horizontalLayout_2->addWidget(ctl_rejectButton);

        ctl_rejectSkipVersionButton = new QPushButton(horizontalLayoutWidget);
        ctl_rejectSkipVersionButton->setObjectName("ctl_rejectSkipVersionButton");
        ctl_rejectSkipVersionButton->setEnabled(true);
        ctl_rejectSkipVersionButton->setFont(font1);
        ctl_rejectSkipVersionButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        ctl_rejectSkipVersionButton->setAutoFillBackground(false);
        ctl_rejectSkipVersionButton->setStyleSheet(QString::fromUtf8("\n"
"        QPushButton {\n"
"         border-radius: 15px;\n"
"         padding: 8px;\n"
"         padding-left: 40px;\n"
"         padding-right: 40px;\n"
"         font-weight: bold;\n"
"         text-decoration: none;\n"
"        }\n"
"\n"
"        QPushButton:hover {\n"
"        }\n"
"\n"
"        QPushButton:pressed {\n"
"        }\n"
"       "));
        ctl_rejectSkipVersionButton->setAutoDefault(false);
        ctl_rejectSkipVersionButton->setFlat(true);

        horizontalLayout_2->addWidget(ctl_rejectSkipVersionButton);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        ctl_acceptButton = new QPushButton(horizontalLayoutWidget);
        ctl_acceptButton->setObjectName("ctl_acceptButton");
        ctl_acceptButton->setBaseSize(QSize(0, 0));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        ctl_acceptButton->setFont(font2);
        ctl_acceptButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        ctl_acceptButton->setStyleSheet(QString::fromUtf8("\n"
"        QPushButton {\n"
"          border-radius: 15px;\n"
"          background-color: rgb(86, 132, 253);\n"
"          color: white;\n"
"          padding: 8px;\n"
"          padding-left: 100px;\n"
"          padding-right: 100px;\n"
"          font-weight: bold;\n"
"        }\n"
"\n"
"        QPushButton:hover {\n"
"          background-color: rgba(86, 132, 253, 175);\n"
"        }\n"
"\n"
"        QPushButton:pressed {\n"
"          background-color: rgba(86, 132, 253, 225);\n"
"          color: black;\n"
"        }\n"
"       "));
        ctl_acceptButton->setCheckable(false);
        ctl_acceptButton->setFlat(true);

        horizontalLayout_2->addWidget(ctl_acceptButton);


        retranslateUi(ConfirmPendingUpdateDialog);

        ctl_acceptButton->setDefault(true);


        QMetaObject::connectSlotsByName(ConfirmPendingUpdateDialog);
    } // setupUi

    void retranslateUi(QDialog *ConfirmPendingUpdateDialog)
    {
        ConfirmPendingUpdateDialog->setWindowTitle(QCoreApplication::translate("ConfirmPendingUpdateDialog", "StreamElements: The Ultimate Streamer Platform", nullptr));
        label_2->setText(QCoreApplication::translate("ConfirmPendingUpdateDialog", "Update SE.Live to Continue Streaming to Your Fans", nullptr));
        label_5->setText(QCoreApplication::translate("ConfirmPendingUpdateDialog", "Say 'Yes!' to the update gods!", nullptr));
        label->setText(QCoreApplication::translate("ConfirmPendingUpdateDialog", "SE.Live Needs an Update", nullptr));
        ctl_imageContainer->setText(QString());
        ctl_rejectButton->setText(QCoreApplication::translate("ConfirmPendingUpdateDialog", "ASK ME LATER", nullptr));
        ctl_rejectSkipVersionButton->setText(QCoreApplication::translate("ConfirmPendingUpdateDialog", "SKIP VERSION", nullptr));
        ctl_acceptButton->setText(QCoreApplication::translate("ConfirmPendingUpdateDialog", "UPDATE NOW", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConfirmPendingUpdateDialog: public Ui_ConfirmPendingUpdateDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIRMPENDINGUPDATEDIALOG_H
