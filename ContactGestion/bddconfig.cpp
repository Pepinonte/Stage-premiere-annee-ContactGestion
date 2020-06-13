#include "bddconfig.h"


bddConfig::bddConfig()
{
     // Instanciation de la variable membre db
     db = QSqlDatabase::addDatabase("QMYSQL");
}

void bddConfig::connexion()
{
    // Définition des paramètres de connexion à la base de données
    db.setHostName("localhost"); // ip serveur MySQL
    db.setDatabaseName("contact"); // Nom de la base
    db.setUserName("root"); // Nom utilisateur
    db.setPassword(""); // Mot de passe
    qDebug() << "connexion ok";
}

void bddConfig::ouverture(int choix)
{
    QSqlQuery requete;

    if(db.open())
        {
            qDebug() << endl;
            qDebug() << endl;
            qDebug() <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
            qDebug() <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
            qDebug() <<"~~~~                                                                ~~~~";
            qDebug() <<"~~~~                GESTION      DES      MESSAGES                  ~~~~";
            qDebug() <<"~~~~                                                                ~~~~";
            qDebug() <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
            qDebug() <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
            qDebug() << endl;
            qDebug() << endl;

            switch (choix)
            {
                case 1:
                    //liste de sujets
                    if(requete.exec(filtreIdSjt))
                    {
                        while(requete.next())
                        {
                            QString sujet = requete.value(0).toString();
                            qDebug() << sujet;
                        }
                    }
                    else
                    {
                        qDebug() <<"echec de la requete";
                    }
                    break;
                case 2:
                    //liste de messages
                    if(requete.exec(msgAll)) {
                        if(requete.exec(filtreMsg))
                        {
                            while(requete.next())
                            {
                                QString msg = requete.value(0).toString();
                                qDebug() << "-------------------------------------------------------------------------------------------------";
                                qDebug() << msg;
                                qDebug() << "-------------------------------------------------------------------------------------------------";
                            }
                        }
                    }
                    else
                    {
                        qDebug() <<"echec de la requete";
                    }
                    break;
                case 3:
                    //nombre de msg
                    if(requete.exec(msgAll))
                    {
                        int nbrMsg =requete.size();
                        qDebug() << "--------------------------------------------------";
                        qDebug() << "Il y a encore " << nbrMsg << "messages"; //affichage nombre de msg
                    }
                    else
                    {
                        qDebug() <<"echec de la requete";
                    }
                    break;
            }

            db.close(); // Fermeture de la base de données
        }

        else
        {
            qDebug() << "Echec d'ouverture de la base de donnée";
            qDebug() << db.lastError();
        }

}
