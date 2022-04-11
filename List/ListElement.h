//
// Created by kmord on 20.03.2022.
//

#ifndef UNTITLED2_LISTELEMENT_H
#define UNTITLED2_LISTELEMENT_H


class ListElement {



public:
    ListElement* previous;
    ListElement* next;

    ListElement* getNext();
    ListElement* getPrevious();
    ListElement(int value,ListElement* previous, ListElement*next);

    int value;
};


#endif //UNTITLED2_LISTELEMENT_H
