#ifndef VISUTODOWIDGET_H
#define VISUTODOWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QDateEdit>
#include <QTextEdit>
#include "contact.h"
/**
 * @brief Classe VisuTodoWidget, widget spécialisé pour la visualisation des todos
 * @author TRAORE Moussa
 * @date decembre 2023
 */
class VisuTodoWidget : public QWidget
{
    Q_OBJECT
public:
    explicit VisuTodoWidget(toDo*,QWidget *parent = nullptr);

private :
    toDo *Todo;
signals:

};

#endif // VISUTODOWIDGET_H
