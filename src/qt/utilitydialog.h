// Copyright (c) 2011-2014 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef UTILITYDIALOG_H
#define UTILITYDIALOG_H

#include <QDialog>
#include <QObject>
#include <QCamera>
#include "walletmodel.h"

class BitcoinGUI;
class ClientModel;

namespace Ui {
    class AboutDialog;
    class PaperWalletDialog;
    class ScanPaperWalletDialog;
    class HelpMessageDialog;
}

/** "About" dialog box */
class AboutDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AboutDialog(QWidget *parent);
    ~AboutDialog();

    void setModel(ClientModel *model);

private:
    Ui::AboutDialog *ui;

private slots:
    void on_buttonBox_accepted();
};

/** "Paper Wallet" dialog box */
class PaperWalletDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PaperWalletDialog(QWidget *parent);
    ~PaperWalletDialog();

    void setModel(WalletModel *model);

private:
    Ui::PaperWalletDialog *ui;
    WalletModel *model;
    static const int PAPER_WALLET_READJUST_LIMIT = 20;
    static const int PAPER_WALLET_PAGE_MARGIN = 50;

private slots:
    void on_getNewAddress_clicked();
    void on_printButton_clicked();
};

/** "Scan Paper Wallet" dialog box */
class ScanPaperWalletDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ScanPaperWalletDialog(QWidget *parent);
    ~ScanPaperWalletDialog();

    void setModel(WalletModel *model);

private:
    Ui::ScanPaperWalletDialog *ui;
    WalletModel *model;
    QCamera *camera;

private slots:
    void on_buttonBox_accepted();
    void on_take_picture();
    void processCapturedImage(int requestId, const QImage &img);
};

/** "Help message" dialog box */
class HelpMessageDialog : public QDialog
{
    Q_OBJECT

public:
    explicit HelpMessageDialog(QWidget *parent);
    ~HelpMessageDialog();

    void printToConsole();
    void showOrPrint();

private:
    Ui::HelpMessageDialog *ui;
    QString header;
    QString coreOptions;
    QString uiOptions;

private slots:
    void on_okButton_accepted();
};


/** "Shutdown" window */
class ShutdownWindow : public QObject
{
    Q_OBJECT

public:
    static void showShutdownWindow(BitcoinGUI *window);
};

#endif // UTILITYDIALOG_H
