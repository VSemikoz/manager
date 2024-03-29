#include "database.h"

DataBase::DataBase(QObject *parent) : QObject(parent){

}

DataBase::~DataBase(){

}

void DataBase::connectToDataBase(){
    if(!QFile("D:/QTprojects/manager/managerdatabase.db").exists()){
         this->restoreDataBase();
         qDebug() << "DataBase restored and conected";
    } else {
         this->openDataBase();
          qDebug() << "connection success";
    }
}

bool DataBase::restoreDataBase(){
    if(this->openDataBase()){
        if(!this->createTables()){
            return false;
        } else {
            return true;
        }
    } else {
        qDebug() << "Не удалось восстановить базу данных";
        return false;
    }
}

bool DataBase::openDataBase(){
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("D:/QTprojects/manager/managerdatabase.db");
    if (!db.open()){
        qDebug() << db.lastError().text();
        return false;
    } else {
        return true;
    }
}

void DataBase::closeDataBase(){
    db.close();
}


bool DataBase::createTables(){
    QSqlQuery query;
    if(query.exec(createIncomeTableQuery) and query.exec(createSpendingTableQuery)){
        qDebug() << "DataBase: error of create Tables";
        return true;
    } else {
        return false;
    }
}

QSqlQuery DataBase::getDataFromIncomeTable(){
    QSqlQuery query;
    query.exec("SELECT income, category, date FROM income_table");
    return query;
}

QSqlQuery DataBase::getDataFromSpendingTable(){
    QSqlQuery query;
    query.exec("SELECT spending, category, date FROM spending_table");
    return query;
}

//To calculate current balance
QString DataBase::calcBalance(){
    QSqlQuery incomeQuery = getDataFromIncomeTable();
    QSqlQuery spendingQuery = getDataFromSpendingTable();
    int incomeBalance = 0;
    int spendingBalance = 0;
    int resultBalance = 0;

    while (incomeQuery.next()) {
      incomeBalance += incomeQuery.value(0).toInt();
    }
    while (spendingQuery.next()) {
      spendingBalance += spendingQuery.value(0).toInt();
    }
    resultBalance = incomeBalance - spendingBalance;
    return QString::number(resultBalance);
}

//To calculate balance for the period
QString DataBase::calcBalancePerPeriod(QDate firstTime, QDate SecndTime){
    QSqlQuery incomeQuery = getDataFromIncomeTable();
    QSqlQuery spendingQuery = getDataFromSpendingTable();
    QDate incomeDate;
    QDate spendingDate;
    int incomeBalance = 0;
    int spendingBalance = 0;
    int resultBalance = 0;

    while (incomeQuery.next()) {
        incomeDate = incomeQuery.value(2).toDate();
        if (incomeDate >= firstTime && incomeDate <= SecndTime)
            incomeBalance += incomeQuery.value(0).toInt();
    }
    while (spendingQuery.next()) {
        spendingDate = spendingQuery.value(2).toDate();
        if (spendingDate >= firstTime && spendingDate <= SecndTime)
            spendingBalance += spendingQuery.value(0).toInt();
    }
    resultBalance = incomeBalance - spendingBalance;
    return QString::number(resultBalance);
}

//To get table <category: income>
QMap<QString, int> DataBase::getIncomeCategoryReport(){
    QSqlQuery incomeQuery = getDataFromIncomeTable();
    QMap<QString, int> categoryIncomeMap;    
    QString category;
    int income;

    while (incomeQuery.next()) {
      category = incomeQuery.value(1).toString();
      income = incomeQuery.value(0).toInt();

      if(categoryIncomeMap.contains(category)){
          categoryIncomeMap[category] +=  income;
        } else
          categoryIncomeMap[category] =  income;
    }
    return categoryIncomeMap;
}

//To get table <category: spending>
QMap<QString, int> DataBase::getSpendingCategoryReport(){
    QSqlQuery spendingQuery = getDataFromSpendingTable();
    QMap<QString, int> categorySpendingMap;
    QString category;
    int spending;

    while (spendingQuery.next()) {
      category = spendingQuery.value(1).toString();
      spending = spendingQuery.value(0).toInt();

      if(categorySpendingMap.contains(category)){
          categorySpendingMap[category] +=  spending;
        } else
          categorySpendingMap[category] =  spending;
    }
    return categorySpendingMap;
}

//To get table <date: income_in_date> for the period
QMap<QDate, int> DataBase::getIncomePeriodReport(QDate firstDate, QDate secondDate){
    QSqlQuery incomeQuery = getDataFromIncomeTable();
    QMap<QDate, int> categoryIncomeMap;
    QDate date;
    int income;

    while (incomeQuery.next()) {
      date = incomeQuery.value(2).toDate();
      income = incomeQuery.value(0).toInt();
      if (date >= firstDate && date <= secondDate){
          if(categoryIncomeMap.contains(date)){
              categoryIncomeMap[date] +=  income;
            } else
              categoryIncomeMap[date] =  income;
        }
      }
    return categoryIncomeMap;
}

//To get table <date: spending_in_date> for the period
QMap<QDate, int> DataBase::getSpendingPeriodReport(QDate firstDate, QDate secondDate){
    QSqlQuery spendingQuery = getDataFromSpendingTable();
    QMap<QDate, int> categorySpendingMap;
    QDate date;
    int spending;

    while (spendingQuery.next()) {
      date = spendingQuery.value(2).toDate();
      spending = spendingQuery.value(0).toInt();
      if (date >= firstDate && date <= secondDate){
          if(categorySpendingMap.contains(date)){
              categorySpendingMap[date] +=  spending;
            } else
              categorySpendingMap[date] =  spending;
        }
      }
    return categorySpendingMap;
}

//To get table <date: balance_in_date> for the period
QMap<double, double> DataBase::getBalancePeriodReport(QDate firstDate, QDate secondDate){
    QMap<QDate, int> spendingPeriodMap = getSpendingPeriodReport(firstDate, secondDate);
    QMap<QDate, int> incomePeriodMap = getIncomePeriodReport(firstDate, secondDate);
    QMap<QDate, int> balancePeriodMap;
    QMap<double, double> doubleBalancePeriodMap;
    QMap<double, double> sortBalancePeriodMap;

    QList<QDate> spendingKeys = spendingPeriodMap.keys();
    QList<QDate> incomeKeys = incomePeriodMap.keys();

    for(int i = 0; i < spendingKeys.count(); i++){
        if(balancePeriodMap.contains(spendingKeys[i]))
            balancePeriodMap[spendingKeys[i]] -= spendingPeriodMap[spendingKeys[i]];
        else
            balancePeriodMap[spendingKeys[i]] = -spendingPeriodMap[spendingKeys[i]];

    }
    for(int i = 0; i < incomeKeys.count(); i++){
        if(balancePeriodMap.contains(incomeKeys[i]))
            balancePeriodMap[incomeKeys[i]] += incomePeriodMap[incomeKeys[i]];
        else
            balancePeriodMap[incomeKeys[i]] = incomePeriodMap[incomeKeys[i]];
    }
    doubleBalancePeriodMap = convertToDoubleMap(balancePeriodMap);
    sortBalancePeriodMap = sortBalancePeriodReport(doubleBalancePeriodMap);

    return sortBalancePeriodMap;
}

//To convert QMap<QDate, int> -> QMap<double, double>
QMap<double, double> DataBase::convertToDoubleMap (QMap<QDate, int> balancePeriodMap){
    QMap<double, double> doubleBalancePeriodMap;

    for (int i = 0; i < balancePeriodMap.keys().count(); i++){
        double timeT = QDateTime(balancePeriodMap.keys()[i]).toTime_t();
        double blanceDouble = (double) balancePeriodMap[balancePeriodMap.keys()[i]];
        doubleBalancePeriodMap[timeT] = blanceDouble;
    }
    return doubleBalancePeriodMap;
}


//To sort <date: date_in_date> and calculate <date: balnce_for_all_period>
QMap<double, double> DataBase::sortBalancePeriodReport(QMap<double, double> doubleBalancePeriodMap){
    QMap<double, double> sortBalancePeriodMap;
    double minKey;
    double prevValue;

    while (!doubleBalancePeriodMap.isEmpty()) {
        minKey = doubleBalancePeriodMap.keys()[0];
        for (int j = 0; j < doubleBalancePeriodMap.keys().count(); j++){
            if (minKey >= doubleBalancePeriodMap.keys()[j])
                minKey = doubleBalancePeriodMap.keys()[j];
        }
        if(sortBalancePeriodMap.isEmpty())
            sortBalancePeriodMap[minKey] = doubleBalancePeriodMap.value(minKey);
        else
            sortBalancePeriodMap[minKey] = doubleBalancePeriodMap.value(minKey) + prevValue;

        prevValue = sortBalancePeriodMap[minKey];
        doubleBalancePeriodMap.remove(minKey);
    }
    return sortBalancePeriodMap;
}
