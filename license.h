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

#ifndef LICENSE_H
#define LICENSE_H

#include <QtWidgets>


class AboutLicense : public QDialog

{

    public:

    AboutLicense(QWidget *parent);


    private:

    QTextEdit *texteLicense;
    QPushButton *fermer;


};

#endif // LICENSE_H
