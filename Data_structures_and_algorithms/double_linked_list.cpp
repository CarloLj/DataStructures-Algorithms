#include <iostream>

using namespace std;

template <class T> class Node {
    public:
        T data; // The object information
        Node* next; // Pointer to the next node element
        Node* previous;// Pointer to the next node element
        Node<T> *head;
        Node<T> *tail;

        Node(){
            head = NULL;
            tail = NULL;
        }

        ~Node(){

        }

        void set_data(T new_data){
            this->data = new_data;
        }

        void set_next(Node *next_node){
            this->next = next_node;
        }

        void set_next(Node *next_node){
            this->next = next_node;
        }

        void set_previous(Node *previous_node){
            this->previous = previous_node;
        }

        void insert_node_end(T info) {
            if(head == NULL){ //if our list is currently empty  
                Node<T> *newNode = new Node<T>; //Create new node of type T
                newNode->set_data(info);
                newNode->set_next(NULL);
                newNode->set_previous(NULL);
                head->newNode;
                tail->newNode;
            }
            else{ //if not empty add to the end and move the tail
                Node<T>* temp = new Node<T>;
                temp->set_data(info);
                temp->set_next(NULL);
                temp->set_previous(tail);
                tail->set_next(temp);
                this->tail = temp;
            }
        }

        void print_list(){
            Node<T>* current_node = this->head;
            while (current_node != NULL){
                cout << current_node ->data << " -> ";

                    current_node = current_node->next;
                }
            cout << endl;
        } 
};

int main(){
    Node<int> node;

    node.insert_node_end(50);
    node.insert_node_end(40);
    node.insert_node_end(30);

    node.print_list();

    return 1;
}
