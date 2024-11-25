#ifndef PERSON_HPP
#define PERSON_HPP

#include <QDateTime>
#include <QString>

class Person
{
public:
    long id;
    QString firstName;
    QString lastName;
    QDateTime birthDate;
};

// QX_REGISTER_HPP_MY_DEMO(Person, qx::trait::no_base_class_defined, 0)
QX_REGISTER_HPP(Person, qx::trait::no_base_class_defined, 0)

#endif // PERSON_HPP