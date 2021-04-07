#ifndef ADDSOMMET_H
#define ADDSOMMET_H
#include <QComboBox>
#include<QDialog>
#include <QLineEdit>

class AddSommet:public QDialog{
public:
    AddSommet(QWidget* parent=nullptr);
private:
    QLineEdit * d_valeur;
    QComboBox * d_parent;
    QComboBox * d_enfant;

};

#endif // ADDSOMMET_H
