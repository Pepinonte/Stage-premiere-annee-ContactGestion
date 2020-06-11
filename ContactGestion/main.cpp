#include <QCoreApplication>
#include <iostream>
#include <QtSql>
#include <QDebug>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //***********************************************************************************************************
    //*****************************************Recuperation BDD**************************************************
    //***********************************************************************************************************
     QSqlDatabase db;

     // Instanciation de la variable membre db
     db = QSqlDatabase::addDatabase("QMYSQL");

     // Définition des paramètres de connexion à la base de données
     db.setHostName("localhost"); // @ip serveur MySQL
     db.setDatabaseName("gestion_des_notes_cg"); // Nom de la base
     db.setUserName("root"); // Nom utilisateur
     db.setPassword(""); // Mot de passe

     if(db.open()) {
     qDebug() << "Ok - ouverture de la base de donnée";

     // Exécution d'une requête
     QSqlQuery requete;
     if(requete.exec("SELECT * FROM Meteo")) {
     qDebug() << "Ok - requete";

     // Boucle qui permet de parcourir les enregistrements renvoyés par la requête
     while(requete.next()) {
     // On accède ici aux différents champs par leurs noms, il est également possible
     // d'y accéder par leur index : requete.value(0)
     qDebug() << requete.value("Date") << " " << requete.value("Temp1") << " "
     << requete.value("Temp2") << " " << requete.value("Pression")
     << requete.value("Humidite ");
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
    //*****************************************Initialisation variables******************************************
    //***********************************************************************************************************
    //QTime heure = requete.value("Heure").toTime();
    //float temperature = requete.value("Temp2").toFloat();
    //int humidite = requete.value("Humidite ").toInt();
    //int nbrMsg = requete.value("nbrMsg").toInt();

    //***********************************************************************************************************
    //*****************************************affichage nbr de msg**********************************************
    //***********************************************************************************************************
     cout<<"Vous avais reçu XX messages";
    //*****************************************listing des sujets************************************************
    //*****************************************consult stats*****************************************************
    //*****************************************consult msg*******************************************************
    return a.exec();
}
