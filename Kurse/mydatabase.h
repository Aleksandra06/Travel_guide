#ifndef MYDATABASE_H
#define MYDATABASE_H

#include <QSqlDatabase>

class myDataBase
{
public:
    myDataBase();

public:
   QSqlDatabase mydb;
   void Connection();
};

#endif // MYDATABASE_H
