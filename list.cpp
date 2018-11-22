#include "list.hpp"

#include <utility>
#include <algorithm>

namespace pjc {

    list::~list() {
        while(head){
            node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void list::reverse() {

    }

    list::list(const std::vector<double> &vec) {
        for(unsigned long i=0; i<vec.size(); i++){
            if(head == nullptr){
                node* new_node = new node;
                new_node->val = vec[i];
                head = new_node;
                tail = head;
            }
            else{
                node* current = new node;
                current->val = vec[i];
                tail->next = current;
                current->prev = tail;
                tail = current;
            }
            num_elements++;
        }
    }

    void list::push_back(double elem) {
        node* new_node = new node;
        new_node->val = elem;
        if(head == nullptr && tail == nullptr){
            head = new_node;
            tail = head;
        }
        else{
            tail->next = new_node;
            new_node->prev = tail;
            new_node->next = nullptr;
            tail = new_node;
        }
        num_elements++;
    }

    void list::push_front(double elem) {
        node* new_node = new node;
        new_node->val = elem;
        if(head == nullptr){
            head = new_node;
            tail = head;
        }
        else{
            head->prev = new_node;
            new_node->next = head;
            new_node->prev = nullptr;
            head = new_node;
        }
        num_elements++;
    }

    void list::pop_back() {
        if(empty()){
            throw std::out_of_range("Can't pop from empty list");
        }

        if(head == tail){
            delete head;
            num_elements--;
            head = nullptr;
            tail = nullptr;
            return;
        }

        node* new_last = new node;
        while(new_last->next != tail){
            new_last = new_last->next;
        }

        num_elements--;
        delete tail;

        tail = new_last;
        tail->next = nullptr;
    }

    void list::pop_front() {
        if(empty()){
            throw std::out_of_range("Can't pop from empty list");
        }

        if(head == tail){
            delete head;
            head = nullptr;
            tail = nullptr;
            return;
        }

        num_elements--;
        node* new_head = head->next;
        new_head->prev = nullptr;
        delete head;
        head = new_head;
    }

    bool list::empty() const {
        return head == nullptr;
    }

    double& list::back() {
        return this->tail->val;
    }

    double const& list::back() const {
        return this->tail->val;
    }

    double& list::front() {
        return this->head->val;
    }

    double const& list::front() const {
        return this->head->val;
    }

    size_t list::size() const {
        return this->num_elements;
    }


}
