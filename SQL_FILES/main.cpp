#include <QCoreApplication>
#include <QFile>
#include <QDataStream>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>


class Person{
private:
    QString name;
    int age;
    double salary;
public:
    Person() : name{""}, age{0}, salary{0.0} {}
    Person(const Person& p) : name{p.name},
        age{p.age}, salary{p.salary} {}
    Person(const QString &name_, int age_, double salary_)
        : name{name_}, age{age_}, salary{salary_} {}

    void setName(const QString& name_) {name = name_;}
    void setAge(int age_) {age = age_;}
    void setSalary(double salary_) {salary = salary_;}

    QString getName() const {return name;}
    int getAge() const { return age; }
    double getSalary() const {return salary;}

    void print() const{
        qDebug() << name << age << salary << "\n";
    }
};

inline QDataStream &operator <<(QDataStream& d, const Person& p){
    return d << p.getName() << p.getAge() << p.getSalary();
}

inline QDataStream &operator>>(QDataStream& d, Person& p){
    QString name;
    int age;
    double salary;
    d >> name >> age >> salary;
    p.setName(name);
    p.setAge(age);
    p.setSalary(salary);
    return d;
}

int filesMode(){
    QFile a("/home/rafa/Desktop/data.txt");
    if(!a.open(QIODevice::WriteOnly)){
        qDebug() << "Error: " << a.errorString();
        return -1;
    }

    QDataStream d(&a);
    d.setVersion(QDataStream::Qt_6_2);
    Person employee[5] = {
        Person("John",30,1000.0),
        Person("Michael",40,2000.0),
        Person("Novak",50,3000.0),
        Person("Larissa",60,4000.0),
        Person("Greng",70,5000.0)
    };

    for(int i = 0; i < 5; ++i){
        d << employee[i];
        employee[i].print();
    }

    a.close();

    return 0;
}

int databaseMode(){
    if(!QSqlDatabase::isDriverAvailable("QSQLITE")){
        qDebug() << "ERROR: QSQLITE not available";
        return -1;
    }

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/rafa/Desktop/data.db");

    if(!db.open()){
        qDebug() << db.lastError().text();
        return -2;
    }

    QSqlQuery q;
    if(!q.exec("CREATE TABLE IF NOT EXISTS person "
                "(id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, "
                "name VARCHAR(255) NOT NULL, age INTEGER NOT NULL, "
                "salary DOUBLE)")){
        qDebug() << q.lastError().text();
        return -3;
    }

    q.exec("INSERT INTO person (name,age,salary) "
           "VALUES('John',30,1000.0)");
    q.exec("INSERT INTO person (name,age,salary) "
           "VALUES('Michael',40,2000.0)");
    q.exec("INSERT INTO person (name,age,salary) "
           "VALUES('Novak',50,3000.0)");
    q.exec("INSERT INTO person (name,age,salary) "
           "VALUES('Larissa',60,4000.0)");
    q.exec("INSERT INTO person (name,age,salary) "
           "VALUES('Greng',70,5000.0)");

    q.exec("SELECT * FROM person");

    while(q.next()){
        qDebug() << q.value("id").toInt();
        qDebug() << q.value("name").toString();
        qDebug() << q.value("age").toInt(),
            qDebug() << q.value("salary").toDouble();
    }

    db.close();

    return 0;
}

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    databaseMode();
    filesMode();
    return app.exec();
}
