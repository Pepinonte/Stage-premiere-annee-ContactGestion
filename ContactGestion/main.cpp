#include "bddconfig.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Pour affichage correct des accents dans la console
    uint temp = GetConsoleOutputCP(); // Sauvegarde du réglage par défaut
    SetConsoleOutputCP(CP_UTF8); // Modification du réglage
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);

     bddConfig bdd;

     bdd.connexion();

     int choix =0;
     cout << "1-        LISTE DE SUJETS " << endl;
     cout << "2-        LISTE DE MESSAGES " << endl;
     cout << "3-        NOMBRE DE MESSAGES " << endl;



     cin >> choix;
     bdd.ouverture(choix);

     return a.exec();
}
