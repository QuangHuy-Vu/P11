#ifndef STACK_H_
#define STACK_H_

#include <iostream>
#include <cstdlib>



template <typename T>
class Stack{
    private:
    struct StackElement{
        T data;
        StackElement* naechstElement;
    };
    StackElement* top_element;
    public:
    Stack() = default;
    Stack(Stack<T> const &stack);
    Stack<T> const &operator=(Stack<T> const &other);
    virtual ~Stack();

    bool empty() const;
    T top();
    void push(T const &x);
    void pop();
    void clear();
};

template <typename T>
bool Stack<T>::empty() const{
    return (top_element == nullptr);
}

template <typename T>
T Stack<T>::top(){
    if(top_element == nullptr) exit(1);
    return top_element->data;
}

template <typename T>
void Stack<T>::push(T const &x){
    StackElement *obj = new StackElement;
    obj->data = x;
    obj->naechstElement = nullptr;
    if(empty()){
        top_element = obj;
    }
    else{
        obj->naechstElement = top_element;
        top_element = obj;
    }
}

template<typename T>
void Stack<T>::pop(){
    if(empty()){
        exit(1);
    }
    else{
        StackElement *temp = new StackElement;
        temp = top_element;
        top_element = top_element->naechstElement;
        delete temp;
    }
}
template <typename T>
void Stack<T>::clear(){
    while(top_element != nullptr){
        pop();
    }
}

template <typename T>
Stack<T>::Stack(Stack<T> const &q){
    if (q.empty()){
        top_element = nullptr;
        return;
    }
    top_element = new StackElement{q.top_element->data, nullptr};
    StackElement* temp = top_element;                                       // since temp associate with top_element's value, what is copied to temp 
                                                                            // also associates with top_element's stack.
    StackElement* q_temp = q.top_element->naechstElement;                   //copy 2nd element of original stack.
    // top_element = q.top_element;                                         //copy the 1st element of original stack.
    while(q_temp != nullptr){
        temp->naechstElement = new StackElement{q_temp->data, nullptr};     //copy the next element's data
        temp = temp->naechstElement;                                        //moving the temp to next position
        q_temp = q_temp->naechstElement;                                    //moving the q_temp to the next position.
    }
}

template<typename T>
Stack<T> const &Stack<T>::operator=(Stack<T> const &q)
{
    if (this == &q) {
        return *this;
    }
    clear();                                                    //alten Stapel löschen.
    top_element = new StackElement{q.top_element->data, nullptr};
    StackElement* temp = top_element;               // since temp associate with top_element's value, what is copied to temp 
                                                    // also associates with top_element's stack.
    StackElement* q_temp = q.top_element->naechstElement; //copy 2nd element of original stack.
    // top_element->data = q.top_element->data;                          //copy the 1st element of original stack.
    // top_element->naechstElement = q.top_element->naechstElement;
    while(q_temp != nullptr){
        temp->naechstElement = new StackElement{q_temp->data, nullptr}; //copy the next element's data
        temp = temp->naechstElement;                                     //moving the temp to next position
        q_temp = q_temp->naechstElement;                                //moving the q_temp to the next position.
    }
    return *this;
}

template <typename T>
Stack<T>::~Stack(){
    clear();
}
#endif