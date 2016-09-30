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

#include "license.h"

AboutLicense::AboutLicense(QWidget *parent = 0) : QDialog(parent)
{

        setWindowIcon(QIcon("images/GPLv3"));

        texteLicense = new QTextEdit();

        QFile fichier("COPYING");

        if (fichier.open(QIODevice::ReadOnly))

        {
            texteLicense->setPlainText(fichier.readAll());

        }



        texteLicense->setReadOnly(true);

        texteLicense->setFont(QFont("dejavu"));

        texteLicense->setLineWrapMode(QTextEdit::NoWrap);


        fermer = new QPushButton("Fermer");


        QVBoxLayout *layoutPrincipal = new QVBoxLayout;

        layoutPrincipal->addWidget(texteLicense);

        layoutPrincipal->addWidget(fermer);


        resize(706, 600);

        setLayout(layoutPrincipal);


        connect(fermer, SIGNAL(clicked()), this, SLOT(accept()));
}
