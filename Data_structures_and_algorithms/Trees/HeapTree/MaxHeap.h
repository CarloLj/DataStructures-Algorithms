/*
This class represents a heap tree data structure, which includes a vector 
with data where each of the nodes is greater than its two respective children.
*/
class MaxHeap {
    private:
        int tree_size{}; //This is the initialization performed when a variable is constructed with an empty initializer.
        vector<int> vect = {-1};

        //Returns the parent node of the current child - i/2 right bitshifting 
        int parent(int i) {return i>>1;};
        //Returns i*2 left bitshifting
        int left(int i) {return i<<1;};
        //Returns i*2 + 1 left bitshifting
        int right(int i) {return (i<<1) + 1;}; 
    public:
        int size() {return tree_size;};
        bool empty() const {return tree_size == 0;};
        int top() const {return vect[1];}; //The number in the first index is always the Max
        void push(int val);
        void shiftUp(int i);
        void shiftDown(int i);
        int pop();
        void printTree();
};

/*
This function prints each of the elements inside the MaxHeap vector
O(n) Complexity because it goes through each of the elements in the vector
*/
void MaxHeap::printTree(){
    for (int i = 1; i < vect.size(); i++){
        cout << vect[i] << " ";
    }
    cout << endl;
}

/*
This function is in charge of updating the priority queue when a new element 
will be inserted, moving each of the parent nodes until the index is not present 
or when it reaches the index of the first node in the tree.
O(log n) Because the function is cutting in half the number
of operations through each operation
*/
void MaxHeap::shiftUp(int i){
    if (i > tree_size) return;
    if (i == 1) return; //Stop the recurssion if the index is the top 
    if (vect[i] > vect[parent(i)]) {
        std::swap(vect[parent(i)], vect[i]);
    }
    shiftUp(parent(i));
}

/*
This function is in charge of inserting a new element to the priority queue,
thus this function takes O(1) complexity time, we need to run the shiftUp() function
recursively to conserve the max heap structure wich in the worst case takes O(log n). 
We can say that the insertion of a new element costs O(log n) time complexity. In practice
it costs O(1) time complexity most of the times.
*/
void MaxHeap::push(int val){
    if (tree_size + 1 >= vect.size()) {
        vect.push_back(0); //Create the placeholder to our new value
    }
    vect[++tree_size] = val;
    printTree();
    shiftUp(tree_size);
    printTree();
    return;
}

/*
This function is in charge of updating the priority queue when the highest value in the
maxheap tree is deleted, moving each of the nodes until the id to swap hasn't changed, meaning
that the tree is balanced again
O(log n) Because the function is cutting in half the number
of operations through each operation
*/
void MaxHeap::shiftDown(int i){
    if (i > tree_size) return;

    int swapId = i;

    if (left(i) <= tree_size && vect[i] < vect[left(i)]) {
        swapId = left(i);
    }

    if (right(i) <= tree_size && vect[swapId] < vect[right(i)]) {
        swapId = right(i);
    }

    if (swapId != i) {
        std::swap(vect[i], vect[swapId]);
        shiftDown(swapId);
    }
    return;
}

/*
This function is in charge of deleting the highest value in the priority queue,
thus this function takes O(1) complexity time, we need to run the shiftDown() function
recursively to conserve the max heap structure wich in the worst case takes O(log n). 
We can say that the deletion of a new element costs O(log n) time complexity.
*/
int MaxHeap::pop(){
    int maxNum = vect[1];
    std::swap(vect[1], vect[tree_size--]);
    shiftDown(1);
    vect.pop_back();
    return maxNum;
}