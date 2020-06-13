#ifndef BDDCONFIG_H
#define BDDCONFIG_H

#include <QCoreApplication>
#include <iostream>
#include <QtSql>
#include <QDebug>
#include <Windows.h> // Pour GetConsoleOutputCP et SetConsoleOutputCP (affichage des accents dans la console)


class bddConfig
{
    //initialisation des requête
    QSqlQuery requete;
    QString msgAll = "SELECT * FROM `message`";
    QString clientAll = "SELECT * FROM `client`";
    QString filtreIdSjt = "SELECT `sujet` FROM `message`";
    QString filtreMsg = "SELECT `message` FROM `message`";
public:
    bddConfig();
    QSqlDatabase db;
    void connexion();
    void ouverture(int choix);
};

#endif // BDDCONFIG_H
