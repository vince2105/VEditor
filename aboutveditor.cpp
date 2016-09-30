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

#include "aboutveditor.h"

AboutVEditor::AboutVEditor()
{



    setWindowTitle("about VEditor");

    setWindowIcon(QIcon("images/VEditor.png"));

    QLabel *icone = new QLabel;

    icone->setPixmap(QPixmap("images/VEditor(128).png"));

    QLabel *texteA = new QLabel;

    texteA->setText("Editor");

    QFont mapolice("Ubuntu", 60);

    texteA->setFont(mapolice);

    QTabWidget *onglets = new QTabWidget;

    QLabel *aPropos = new QLabel;

    QLabel *versions = new QLabel;

    QLabel *auteur = new QLabel;

    aPropos->setText("Editeur de texte\n\ncopyright(c) 2016 Pelletier Vincent\n\nLicense : version 3 de la License Générale Publique GNU");

    versions->setText("Version 1.0\n\nUtilise Qt 5.5.1\n\n");

    auteur->setText("\nVincent Pelletier\n\nVous pouvez me contacter à :\n\nv.pelletier995@yahoo.com\n");

    onglets->addTab(aPropos, "À propos");

    onglets->addTab(versions, "Versions");

    onglets->addTab(auteur, "Auteur");


    QVBoxLayout *layoutA = new QVBoxLayout;

    QHBoxLayout *layoutB = new QHBoxLayout;

    QHBoxLayout *layoutC = new QHBoxLayout;



    int zero(0);

    layoutB->addWidget(icone);

    layoutB->addWidget(texteA);

    layoutB->addStretch(zero);

    layoutA->addLayout(layoutB);

    layoutA->addWidget(onglets);

    layoutA->addLayout(layoutC);

    setLayout(layoutA);

    resize(400, 100);

    show();

}
