#include <iostream>
#include <vector>
using namespace std;

template <class T> class Node {
    private:
        T data; // The object information
        Node* next; // Pointer to the next node element
		int priority;

    public:

        Node(){
            this->data = NULL;
            this->next = NULL;
			this->priority = 0;
        }
        
        Node(T new_data,  int priority){
            this->data = new_data;
			this->priority = priority;
            this->next = NULL;
        }

        void set_data(T new_data){
            this->data = new_data;
        }

        void set_priority(int priority){
            this->priority = priority;
        }
		
		int get_priority() {
			return this->priority;
		}

        T get_data(){
            return this->data;
        }

        void set_next(Node *next_node){
            this->next = next_node;
        }

        Node* get_next(){
            return this->next;
        }
};


template <class T> class CustomLinkedList{
    public:
        Node<T> *head;
        
        CustomLinkedList(){
            head = NULL;
        }

        ~CustomLinkedList(){

        }

        // Method adds data to the end of the list
        /* void add_begin(T data){
            Node<T>* temp = new Node<T>(data, head);
            this->head = temp;
        }
        
        void delete_end(){
            Node<T> *temp = this->head;
            this->head = this->head->get_next();
            delete temp;
        }*/

        void queue(T data, int priority){
          	Node<T>* temp = new Node<T>(data, priority);
          	Node<T>* current = this->head;

            if (this->head == NULL) {
              this->head = temp;
              return;
            }
						
            while (current->get_next()->get_priority() <= priority){ 
              current = current->get_next();
            }
						       
            temp->set_next(current->get_next());
            current->set_next(temp);
        }

        void dequeue(){
			Node<T>* old_head = this->head;
            if (this->head == NULL) {
            	return;
            }

			if (this->head->get_next() == NULL) {
				delete this->head;
				this->head = NULL;
            } else {
              this->head = this->head->get_next();
              delete old_head;
            }
        }

		void print_queue(){
            Node<T>* current_node = this->head;
            while (current_node != NULL){
                cout << current_node->get_data() << " -> ";
                current_node = current_node->get_next();
            }
            cout << endl;
		}
};

bool isValid(string s) {
    vector<char> stack;
    for (char x : s){
        if (x == ')' || x == ']' || x == '}'){
            if (stack.size() == 0){
               return false;
            }
            char c = stack.back();
            stack.pop_back();
            if (x == ')' && c != '('){
                return false;
            }
            if (x == ']' && c != '['){
                return false;
            }
            if (x == '}' && c != '{'){
                return false;
            }
        } else {
            stack.push_back(x);
        }
    }
    return stack.size() == 0;
}

