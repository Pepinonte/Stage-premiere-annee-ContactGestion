#include <QCoreApplication>
#include <iostream>
#include <QtSql>
#include <QDebug>
#include <Windows.h> // Pour GetConsoleOutputCP et SetConsoleOutputCP (affichage des accents dans la console)

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Pour affichage correct des accents dans la console
    uint temp = GetConsoleOutputCP(); // Sauvegarde du réglage par défaut
    SetConsoleOutputCP(CP_UTF8); // Modification du réglage
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);

    //***********************************************************************************************************
    //*****************************************Recuperation BDD**************************************************
    //***********************************************************************************************************
     QSqlDatabase db;

     // Instanciation de la variable membre db
     db = QSqlDatabase::addDatabase("QMYSQL");

     // Définition des paramètres de connexion à la base de données
     db.setHostName("localhost"); // ip serveur MySQL
     db.setDatabaseName("contact"); // Nom de la base
     db.setUserName("root"); // Nom utilisateur
     db.setPassword(""); // Mot de passe

     if(db.open()) {

         qDebug() << "Ok - ouverture de la base de donnée";

         // Exécution d'une requête
         QSqlQuery requete;

         QString sSql = "SELECT sujet "
                        "FROM client";

         if(requete.exec(sSql)) {

             // Boucle qui permet de parcourir les enregistrements renvoyés par la requête
             while(requete.next()) {
                 // On accède ici aux différents champs par leurs noms, il est également possible
                 // d'y accéder par leur index : requete.value(0)
                 //***********************************************************************************************************
                 //*****************************************Initialisation variables******************************************
                 //***********************************************************************************************************
                 //QTime date = requete.value("date").toTime();
                 //QString nom = requete.value("nom").toString();
                 //QString prenom = requete.value("prenom").toString();
                 //QString mail = requete.value("mail").toString();
                 //QString message = requete.value("message").toString();
                 QString sujet = requete.value("sujet").toString();

                 qDebug() << sujet ;
             }
     }

     else {
         qDebug() << "Echec de la requête";
         // La méthode lastError permet d'afficher un message
         // plus explicite sur les causes de l'erreur
         qDebug() << requete.lastError();
     }
     db.close(); // Fermeture de la base de données
     }

     else {
         qDebug() << "Echec d'ouverture de la base de donnée";
         qDebug() << db.lastError();
     }

    //***********************************************************************************************************
    //*****************************************affichage nombre de msg*******************************************
    //***********************************************************************************************************

    //***********************************************************************************************************
    //*****************************************listing des sujets************************************************
    //***********************************************************************************************************

    //***********************************************************************************************************
    //*****************************************consult stats*****************************************************
    //***********************************************************************************************************

    //***********************************************************************************************************
    //*****************************************consult msg*******************************************************
    //***********************************************************************************************************

     return a.exec();
}
