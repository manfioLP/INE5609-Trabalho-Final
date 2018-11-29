//
// Created by poldera_sithgod on 29/11/18.
//

#ifndef INNERLINKEDLIST_H
#define INNERLINKEDLIST_H

#include "LinkedList.h"

template <typename T>
class InnerLinkedList : public LinkedList<T> {

public:
    InnerLinkedList(std::string type);
    ~InnerLinkedList();
    const std::string &get_type() const;
    void set_type(const std::string &_type);

private:
    std::string _type;
};

template <typename T>
InnerLinkedList<T>::InnerLinkedList(std::string type) {
    LinkedList<T>();
    _type = type;
}

template <typename T>
InnerLinkedList<T>::~InnerLinkedList() {
    ~LinkedList<T>();
}

template<typename T>
const std::string &InnerLinkedList<T>::get_type() const {
    return _type;
}

template<typename T>
void InnerLinkedList<T>::set_type(const std::string &_type) {
    InnerLinkedList::_type = _type;
}

#endif //INNERLINKEDLIST_H
