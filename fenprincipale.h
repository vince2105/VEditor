/*
    This file is part of VEditor.

    VEditor is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    VEditor is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with VEditor.  If not, see <http://www.gnu.org/licenses/>.

*/

#ifndef FENPRINCIPALE_H
#define FENPRINCIPALE_H

#include <QtGui>
#include <QTextEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSpacerItem>
#include <QtWidgets>
#include <QMessageBox>
#include <QTextStream>
#include <QApplication>
#include <QtPrintSupport/QPrinter>
#include <QPrintDialog>


class FenPrincipale : public QMainWindow
{
    Q_OBJECT

    public:
        FenPrincipale();

    public slots:
    void imprimer();
    void nouveauDocument();
    void ouvrirDocument();
    void enregistrer();
    void enregistrerSous();
    void changerCouleur();
    void mettreEnGras(bool ok);
    void changerTaille(int);
    void nombreSpinBox();
    void setAlignmentLeft();
    void setAlignmentRight();
    void setAlignmentCenter();
    void setAlignmentJustify();
    void aboutVEditor();
    void License();
    void verrouillerToolBar(bool vrai);

    private:
    QTextEdit *texte;
    QToolBar *toolBar;
    QToolBar *toolBar2;
    QSpinBox *spinBox;
    QString nomFichier;
    int taillepolice;
    int nombreDeCaracteres;
    int nombreDeCaracteresActuel;
    int nombreDoc;
    QString nombreDocQString;

};

#endif // FENPRINCIPALE_H
