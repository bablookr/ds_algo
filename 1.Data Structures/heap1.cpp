#include<iostream>
#define MAX 11
using namespace std;

int heap[MAX];
int hsize = 0;

/*Binary Heap: MinHeap Basic Functions
minHeapify,getMin,decreaseKey,extractMin,ins,del*/

void minHeapify(int i){
    int l = 2*i + 1;
    int r = 2*i + 2;
    int smallest = i;
    if (l < hsize && heap[l] < heap[i])
        smallest = l;
    if (r < hsize && heap[r] < heap[smallest])
        smallest = r;
    if (smallest != i){
        swap(heap[i], heap[smallest]);
        minHeapify(smallest);
    }
}

int getMin(){
    return heap[0];
}

void decreaseKey(int i, int new_val){
    heap[i] = new_val;
    while (i != 0 && heap[(i-1)/2] > heap[i]){
       swap(heap[i], heap[(i-1)/2]);
       i = (i-1)/2;
    }
}

int extractMin(){
    if (hsize <= 0)
        return 9999999;
    if (hsize == 1){
        hsize--;
        return heap[0];
    }

    int root = heap[0];
    heap[0] = heap[hsize-1];
    hsize--;
    minHeapify(0);

    return root;
}

void ins(int key){
    if (hsize == MAX){
        cout << "\nOverflow: Could not ins\n";
        return;
    }

    hsize++;
    int i = hsize - 1;
    heap[i] = key;

    while (i != 0 && heap[(i-1)/2] > heap[i]){
       swap(heap[i], heap[(i-1)/2]);
       i = (i-1)/2;
    }
}

void del(int i){
    decreaseKey(i, -999999999);
    extractMin();
}

int main(){
    ins(3);
    ins(2);
    del(1);
    ins(15);
    ins(5);
    ins(4);
    ins(45);
    cout << extractMin() << " ";
    cout << getMin() << " ";
    decreaseKey(2, 1);
    cout << getMin();
    return 0;
}


