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


#include "fenprincipale.h"
#include "aboutveditor.h"
#include "license.h"

FenPrincipale::FenPrincipale()
{


    setWindowTitle("VEditor");

    setWindowIcon(QIcon("images/VEditor.png"));


    // QTEXTEDIT

    texte = new QTextEdit(this);

    setCentralWidget(texte);


    // Menu - "Fichier"
    QMenu *menuFichier = menuBar()->addMenu("&Fichier");
        // Menu - Fichier - Sous menus

            // Nouveau fichier
            QAction *actionNouveau = menuFichier->addAction("&Nouveau");
            actionNouveau->setShortcut(QKeySequence("Ctrl+N"));
            actionNouveau->setIcon(QIcon("images/nouveaudocument.png"));
            connect(actionNouveau, SIGNAL(triggered()), this, SLOT(nouveauDocument())); // CONNEXION

            // Ouvrir
            QAction *actionOuvrir = menuFichier->addAction("&Ouvrir");
            actionOuvrir->setShortcut(QKeySequence("Ctrl+O"));
            actionOuvrir->setIcon(QIcon("images/ouvrirdocument.png"));
            connect(actionOuvrir, SIGNAL(triggered()), this, SLOT(ouvrirDocument()));


            // Enregistrer
            QAction *actionEnregistrer = menuFichier->addAction("Enregi&strer");
            actionEnregistrer->setShortcut(QKeySequence("Ctrl+S"));
            actionEnregistrer->setIcon(QIcon("images/enregistrer.png"));
            connect(actionEnregistrer, SIGNAL(triggered()), this, SLOT(enregistrer())); // CONNEXION

            // Enregistrer sous
            QAction *actionEnregistrerSous = menuFichier->addAction("Enregistrer sous");
            actionEnregistrerSous->setShortcut(QKeySequence("-"));
            actionEnregistrerSous->setIcon(QIcon("images/enregistrersous.png"));
            connect(actionEnregistrerSous, SIGNAL(triggered()), this, SLOT(enregistrerSous())); // CONNEXION

            // Imprimer
            QAction *actionImprimer = menuFichier->addAction("Imprimer");
            actionImprimer->setShortcut(QKeySequence("-"));
            actionImprimer->setIcon(QIcon("images/imprimer.png"));
            connect(actionImprimer, SIGNAL(triggered()), this, SLOT(imprimer())); // CONNEXION

            // Quitter
            QAction *actionQuitter = menuFichier->addAction("&Quitter");
            actionQuitter->setShortcut(QKeySequence("Ctrl+Q"));
            actionQuitter->setIcon(QIcon("images/quitter.png"));
            connect(actionQuitter, SIGNAL(triggered()), qApp, SLOT(quit())); // CONNEXION

    // Menu "Edition"
    QMenu *menuEdition = menuBar()->addMenu("&Edition");
        // Menu Edition - Sous menus


            // Undo
            QAction *actionUndo = menuEdition->addAction("&Undo");
            actionUndo->setIcon(QIcon("images/undo.png"));
            connect(actionUndo, SIGNAL(triggered()), texte, SLOT(undo()));
            actionUndo->setShortcut(QKeySequence("Ctrl+Z"));

            // Redo
            QAction *actionRedo = menuEdition->addAction("&Redo");
            actionRedo->setIcon(QIcon("images/redo.png"));
            connect(actionRedo, SIGNAL(triggered()), texte, SLOT(redo()));
            actionRedo->setShortcut(QKeySequence("Ctrl+Shift+Z"));

            // Gras
            QAction *styleGras = menuEdition->addAction("Gras");
            styleGras->setIcon(QIcon("images/gras.png"));
            styleGras->setCheckable(true);
            connect(styleGras, SIGNAL(triggered(bool)), this, SLOT(mettreEnGras(bool)));

            // Italique
            QAction *styleItalique = menuEdition->addAction("Italique");
            styleItalique->setIcon(QIcon("images/italique.png"));
            styleItalique->setCheckable(true);
            connect(styleItalique, SIGNAL(triggered(bool)), texte, SLOT(setFontItalic(bool)));

            // Souligne
            QAction *styleSouligne = menuEdition->addAction("Souligné");
            styleSouligne->setIcon(QIcon("images/souligner.png"));
            styleSouligne->setCheckable(true);
            connect(styleSouligne, SIGNAL(triggered(bool)), texte, SLOT(setFontUnderline(bool)));

            // Qt::AlignLeft
            QAction *actionAlignLeft = menuEdition->addAction("AlignLeft");
            actionAlignLeft->setIcon(QIcon("images/alignLeft"));
            connect(actionAlignLeft, SIGNAL(triggered()), this, SLOT(setAlignmentLeft()));


            // Qt::AlignRight
            QAction *actionAlignRight = menuEdition->addAction("AlignRight");
            actionAlignRight->setIcon(QIcon("images/alignRight"));
            connect(actionAlignRight, SIGNAL(triggered()), this, SLOT(setAlignmentRight()));


            // Qt::AlignJustify
            QAction *actionAlignJustify = menuEdition->addAction("AlignJustify");
            actionAlignJustify->setIcon(QIcon("images/alignJustify"));
            connect(actionAlignJustify, SIGNAL(triggered()), this, SLOT(setAlignmentJustify()));


            // Qt::AlignCenter
            QAction *actionAlignCenter = menuEdition->addAction("AlignCenter");
            actionAlignCenter->setIcon(QIcon("images/alignCenter"));
            connect(actionAlignCenter, SIGNAL(triggered()), this, SLOT(setAlignmentCenter()));



            // Barre
            //QAction *styleBarre = menuEdition->addAction("Barré");
            //styleBarre->setIcon(QIcon("images/barré.png"));
            //styleBarre->setCheckable(true);

            // Couleur
            QAction *styleCouleur = menuEdition->addAction("Couleur");
            styleCouleur->setIcon(QIcon("images/couleur.png"));
            connect(styleCouleur, SIGNAL(triggered()), this, SLOT(changerCouleur())); // CONNEXION


    // Menu "Affichage"
    QMenu *menuAffichage = menuBar()->addMenu("&Affichage");

            // cacher la barre
            QAction *cacherToolBar = new QAction("Cacher la barre d'outils haute", this);
            cacherToolBar->setCheckable(true);
            menuAffichage->addAction(cacherToolBar);


            QAction *actionVerrouillerToolBar = new QAction("Verrouiller les barres d'outils", this);
            actionVerrouillerToolBar->setCheckable(true);
            menuAffichage->addAction(actionVerrouillerToolBar);
            connect(actionVerrouillerToolBar, SIGNAL(triggered(bool)), this, SLOT(verrouillerToolBar(bool)));




    // Menu "Aide"
    QMenu *menuAide = menuBar()->addMenu("&Aide");

            // About QT
            QAction *actionAboutQT = new QAction("&A propos de QT", this);
            menuAide->addAction(actionAboutQT);
            connect(actionAboutQT, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
            actionAboutQT->setIcon(QIcon("images/QT.png"));

            // About VEditor
            QAction *actionAboutVEditor = new QAction("&A propos de VEditor", this);
            menuAide->addAction(actionAboutVEditor);
            connect(actionAboutVEditor, SIGNAL(triggered()), this, SLOT(aboutVEditor()));
            actionAboutVEditor->setIcon(QIcon("images/VEditor.png"));

            // License
            QAction *actionLicense = new QAction("license", this);
            menuAide->addAction(actionLicense);
            connect(actionLicense, SIGNAL(triggered()), this, SLOT(License()));
            actionLicense->setIcon(QIcon("images/GPLv3"));




    // LA BARRE D'OUTILS HAUTE
    toolBar = new QToolBar("Afficher la barre d'outils haute");
    addToolBar(toolBar);
    toolBar->addAction(actionNouveau);
    toolBar->addAction(actionOuvrir);
    toolBar->addAction(actionEnregistrer);
    toolBar->addAction(actionEnregistrerSous);
    toolBar->addAction(actionImprimer);
    toolBar->addSeparator();
    toolBar->addAction(styleGras);
    toolBar->addAction(styleItalique);
    toolBar->addAction(styleSouligne);
    //toolBar->addAction(styleBarre);
    toolBar->addAction(styleCouleur);
    toolBar->addSeparator();
    toolBar->addAction(actionAlignLeft);
    toolBar->addAction(actionAlignRight);
    toolBar->addAction(actionAlignCenter);
    toolBar->addAction(actionAlignJustify);
    toolBar->addSeparator();
    toolBar->addAction(actionUndo);
    toolBar->addAction(actionRedo);
    connect(cacherToolBar, SIGNAL(triggered(bool)), toolBar, SLOT(setHidden(bool)));

    // LA BARRE D'OUTILS BASSE
    spinBox = new QSpinBox;
    spinBox->setMinimum(10);
    spinBox->setMaximum(100);
    connect(spinBox , SIGNAL(valueChanged(int)), this,  SLOT(changerTaille(int)));
    connect(texte, SIGNAL(selectionChanged()), this, SLOT(nombreSpinBox()));
    QFontComboBox *choixPolice = new QFontComboBox;
    choixPolice->setMinimumWidth(100);
    connect(choixPolice, SIGNAL(currentFontChanged(QFont)), texte, SLOT(setCurrentFont(QFont)));
    toolBar2 = new QToolBar("Afficher barre d'outils basse");
    addToolBar(Qt::BottomToolBarArea, toolBar2);
    toolBar2->addWidget(choixPolice);
    toolBar2->addWidget(spinBox);


    resize(548, 600);

}

// SLOT imprimer
void FenPrincipale::imprimer()
{
    //QString texteEnHtml = texte->toHtml();
    //QTextDocument *texteDocument = new QTextDocument(texteEnHtml);

    QPrinter * imprimante = new QPrinter;
        QPrintDialog * dialogue = new QPrintDialog(imprimante, this);

        if(dialogue->exec() == QDialog::Accepted)
            texte->print(imprimante);

}


// SLOT nouveauDocument
void FenPrincipale::nouveauDocument()
{
    nombreDoc = 0;

    nombreDocQString = QString::number(nombreDoc);

    QString titreFenetreNewDoc = "sans titre " + nombreDoc;

    nombreDeCaracteresActuel = texte->toPlainText().size();

    if(nombreDeCaracteresActuel != nombreDeCaracteres or nomFichier.isEmpty())

    {

        int reponse = QMessageBox::question(this, "Enregistrer", "Voulez vous sauvegarder les modifications?", QMessageBox ::Yes | QMessageBox::No);


        if (reponse == QMessageBox::Yes)

        {

            QString texteEnHtml = texte->toHtml(); // Ici on stocke dans une variable la "version html" de ton texte

            if(nomFichier.isEmpty())

            {

            nomFichier = QFileDialog::getSaveFileName(this, "Enregistrer...", "Sans titre.txt"); // Ici on stocke dans la variable le chemin et le nom du fichier choisi par l'utilisateur via le dialogue

            }

            QFile fichier(nomFichier); // On crée un objet QFile en indiquant le chemin du fichier

            if (fichier.open(QIODevice::WriteOnly))
            {
                QTextStream out(&fichier); // Alors on crée un objet QTextStream (flux de texte) nommé out auquel on renseigne l'adresse en mémoire du fichier ouvert (ici "&fichier")
                out << texteEnHtml; // C'est simple on fait "entrer" dans le flux le texte en html !
                nombreDeCaracteres = texte->toPlainText().size();
            }


            texte->clear();

            nomFichier = "";

            setWindowTitle(titreFenetreNewDoc);


        }

        else if (reponse == QMessageBox::No)

        {

            texte->clear();

            nomFichier = "";

            setWindowTitle(titreFenetreNewDoc);


        }



    }

    else

    {

        texte->clear();

        nomFichier = "";

        setWindowTitle(titreFenetreNewDoc);

    }

}

// SLOT ouvrirDocument
void FenPrincipale::ouvrirDocument()
{
    QString nomFichier = QFileDialog::getOpenFileName(this, "Ouvrir un fichier", QString()); // On récupère donc dans nomFichier le chemin du fichier à ouvrir via le dialogue (PS : ce n'est pas le même que pour enregistrer())

        QFile fichier(nomFichier); // On crée encore et toujours notre objet QFile en précisant le chemin du fichier
        if (fichier.open(QIODevice::ReadOnly)) // Cette fois-ci c'est le flag ReadOnly qui est utilisé, cependant lui si le fichier sélectionné n'existe pas il retournera irrémédiablement false
        {
            texte->setText(fichier.readAll()); // Là on dit au QTextEdit de récupérer TOUTES les données du fichier ouvert via readAll(), de plus la fonction setText() retournera un texte riche et non plus en html

            setWindowTitle(nomFichier + " - VEditor"); // Ici c'est un bonus xD, rien ne t'empêche en effet d'ajouter autant de fonctions que tu veux lors de l'ouverture de ton fichier !
        }
}


// SLOT enregistrer
void FenPrincipale::enregistrer()
{

    QString texteEnHtml = texte->toHtml(); // Ici on stocke dans une variable la "version html" de ton texte

    if(nomFichier.isEmpty())

    {

    nomFichier = QFileDialog::getSaveFileName(this, "Enregistrer...", "Sans titre 1.txt"); // Ici on stocke dans la variable le chemin et le nom du fichier choisi par l'utilisateur via le dialogue

    }

    QFile fichier(nomFichier); // On crée un objet QFile en indiquant le chemin du fichier

    if (fichier.open(QIODevice::WriteOnly))
    {
        QTextStream out(&fichier); // Alors on crée un objet QTextStream (flux de texte) nommé out auquel on renseigne l'adresse en mémoire du fichier ouvert (ici "&fichier")
        out << texteEnHtml; // C'est simple on fait "entrer" dans le flux le texte en html !
        nombreDeCaracteres = texte->toPlainText().size();
    }



}

// SLOT enregistrerSous
void FenPrincipale::enregistrerSous()
{
        QString texteEnHtml = texte->toHtml(); // Ici on stocke dans une variable la "version html" de ton texte

        nomFichier = QFileDialog::getSaveFileName(this, "Enregistrer...", "Sans titre 1.txt"); // Ici on stocke dans la variable le chemin et le nom du fichier choisi par l'utilisateur via le dialogue

        QFile fichier(nomFichier); // On crée un objet QFile en indiquant le chemin du fichier

        if (fichier.open(QIODevice::WriteOnly))
        {
            QTextStream out(&fichier); // Alors on crée un objet QTextStream (flux de texte) nommé out auquel on renseigne l'adresse en mémoire du fichier ouvert (ici "&fichier")
            out << texteEnHtml; // C'est simple on fait "entrer" dans le flux le texte en html !
            nombreDeCaracteres = texte->toPlainText().size();
        }
}


// SLOT changerCouleur
void FenPrincipale::changerCouleur()
{
    QColor couleur = QColorDialog::getColor(Qt::white, this); // Ici ta variable va donc stocker la réponse du dialogue qui renverra un QColor

    texte->setTextColor(couleur); // Lequel nous passons à la fonction setTextColor qui définit la couleur du texte
}


// SLOT verrouiller la barre
void FenPrincipale::verrouillerToolBar(bool vrai)

{
   if (vrai)
   {

       toolBar->setMovable(false);
       toolBar2->setMovable(false);

   }
   else
   {

       toolBar->setMovable(true);
       toolBar2->setMovable(true);

   }

}


// SLOT mettreEnGras
void FenPrincipale::mettreEnGras(bool ok)
{
    if (ok)
    {
        texte->setFontWeight(QFont::Bold);
    }
    else
    {
        texte->setFontWeight(QFont::Normal);
    }
}


// SLOT nombre du spinbox
void FenPrincipale::nombreSpinBox()
{

    taillepolice = texte->fontPointSize();

    spinBox->blockSignals(true);

    spinBox->setValue(taillepolice);

    spinBox->blockSignals(false);





}


// SLOT taille police
void FenPrincipale::changerTaille(int taille)
{

    texte->setFontPointSize(taille);

}


// SLOT alignement left
void FenPrincipale::setAlignmentLeft()
{
    texte->setAlignment(Qt::AlignLeft);
}


// SLOT alignement right
void FenPrincipale::setAlignmentRight()
{
    texte->setAlignment(Qt::AlignRight);
}


// SLOT alignement center
void FenPrincipale::setAlignmentCenter()
{
    texte->setAlignment(Qt::AlignCenter);
}


// SLOT alignement justify
void FenPrincipale::setAlignmentJustify()
{
    texte->setAlignment(Qt::AlignJustify);
}


//implementation de About VEditor
void FenPrincipale::aboutVEditor()

{

    AboutVEditor *Apropos = new AboutVEditor;
    Apropos->show();

}

// SLOT about License

void FenPrincipale::License()
{
    AboutLicense *fenetreLicense = new AboutLicense(this);
    fenetreLicense->exec();
}

