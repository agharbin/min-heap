#include <vector>
#include <map>
#include <cmath>
#include <iostream>

class minheap {
    public:
        void insert(int key, int val);
        int pop();
        void reduce_key(int val, int new_key);
        bool empty();

        void print_heap();
        void print_indexes();
    private:
        std::vector<std::pair<int, int> > heap;
        std::map<int, int> indexes;

        void bubble_up(int i);
        void trickle_down(int i);
        int parent(int i);
        int first_child(int i);
        int second_child(int i);
        void swap(int i, int j);
};

void minheap::insert(int key, int val) {
    heap.push_back(std::make_pair(key, val));
    indexes[val] = heap.size() - 1;
    bubble_up(heap.size() - 1);
}

int minheap::pop() {
    int min = heap[0].second;
    indexes.erase(min);

    std::pair<int,int> back = heap.back();
    heap.pop_back();
    heap[0] = back;
    indexes[back.second] = 0;
    trickle_down(0);
    
    return min;
}

void minheap::reduce_key(int val, int new_key) {
    int index = indexes[val];
    heap[index].first = new_key;
    bubble_up(index);
}

void minheap::bubble_up(int i) {
    while(i != 0 && heap[i].first < heap[parent(i)].first) {
        swap(i, parent(i));
        i = parent(i);
    } 
}

void minheap::trickle_down(int i) {
    while(first_child(i) < heap.size() && 
            second_child(i) < heap.size() && 
            ( heap[i].first > heap[first_child(i)].first || heap[i].first > heap[second_child(i)].first )) {
    
        if(heap[first_child(i)].first < heap[second_child(i)].first) {
            swap(i, first_child(i));
            i = first_child(i);
        } else {
            swap(i, second_child(i));
            i = second_child(i);
        }
    }
}

int minheap::parent(int i) {
    return floor((i - 1) / 2);
}

int minheap::first_child(int i) {
    return (i * 2) + 1;
}

int minheap::second_child(int i) {
    return (i * 2) + 2;
}

void minheap::swap(int i, int j) {
    int element_i = heap[i].second;
    int element_j = heap[j].second;

    // Swap elements in the heap
    std::pair<int,int> temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;

    // Swap the recorded indexes of the elements
    int temp_index = indexes[element_i];
    indexes[element_i] = indexes[element_j];
    indexes[element_j] = temp_index;
}

void minheap::print_heap() {
    for(auto i = heap.begin(); i != heap.end(); ++i) {
        std::cout << "<" << i->first << "," << i->second << ">" << std::endl;
    }
}

void minheap::print_indexes() {
    for(auto i = indexes.begin(); i != indexes.end(); ++i) {
        std::cout << i->first << " -> " << i->second << std::endl;
    }
}

bool minheap::empty() {
    return heap.size() == 0;
}
