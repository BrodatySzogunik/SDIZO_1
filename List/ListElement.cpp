//
// Created by kmord on 20.03.2022.
//

#include "ListElement.h"


ListElement::ListElement(int value,ListElement* previous, ListElement*next) {
    this->value = value;
    this-> previous = previous;
    this->next = next;
}

ListElement* ListElement::getNext(){
    return this->next;
}

ListElement* ListElement::getPrevious() {
    return this->previous;
}
