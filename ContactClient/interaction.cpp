#include "interaction.h"
#include <iostream>
/**
 * @author Moussa TRAORE
 * @date Octobre 2023
 * @brief implémentation des constructeurs*/
//constructeurs
Interaction::Interaction()
{

}

void Interaction::setdatedb(std::string s){this->datestring=s;}
Interaction::Interaction(Contact * c,std::string contenu)
{  setID(0);
    setContact(c);
    this->setContenu(contenu);

 }
/**
 * @author Moussa TRAORE
 * @date Octobre 2023
 * @brief implémentation des accesseurs*/

//accesseurs
void Interaction::setID(int i){this->id=i;}
int  Interaction::getID(){return this->id;}
void Interaction::setContenu(std::string  & cont)
{
    this->contenu = "";
    gTD.removeAllToDo();
    std::string buffer = cont;

    while (buffer.size()!=0)
    {
        unsigned long indice = buffer.find("@todo");
        if(indice<buffer.size())
        {
            contenu+=buffer.substr(0, indice); //on recupère le contenu sans tag @todo
            //on traite le @todo
            buffer = buffer.substr(indice);
            indice = buffer.find("\n");
            std::string s;
            if(indice<buffer.size())
            {
                s = buffer.substr(0,indice);
                buffer = buffer.substr(indice);
            }
            else
            {
                s=buffer;
                buffer ="";
            }
             toDo *t = new toDo(this, s);

            addToDo(t);
        }
        else
        {
            contenu = buffer;
            buffer = "";
        }
    }
    this->setDate(new Date());
}

std::string Interaction::getContenu() const{return this->contenu;}
GestionToDo Interaction::getGestionToDo() const {return gTD;}
void Interaction::setDate(Date * d ){ datestring=(*d).getDateToString();}
std::string Interaction::getDate() const {return this->datestring;}
void Interaction::setContact(Contact* const C){this->contact = C;}
Contact* Interaction::getContact() const{return this->contact;}

/**
 * @author Moussa TRAORE
 * @date Octobre 2023
 * @brief implémentation des methodes addToo et removeTodo*/
void Interaction::addToDo(toDo *td){gTD.addToDo(td);}
void Interaction::removeToDo(toDo * td){ gTD.removeToDo(td);}
/**
 * @author Moussa TRAORE
 * @date Octobre 2023
 * @brief implémentation des surcharges des operateurs == et <<*/
bool Interaction::operator==(Interaction test){return this->getContact()== test.getContact() && this->getContenu()== test.getContenu() && this->getDate() == test.getDate();}


std::ostream& operator<<(std::ostream & os, const Interaction I )
{
  GestionToDo liste = I.getGestionToDo();
  os << I.getDate()<<" : "<<std::endl<<I.getContenu()<<liste.toString();
  return os ;
}


