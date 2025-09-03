struct Node
{
    int key, val, freq;
    Node *prev;
    Node *next;
    Node(int k, int v)
    {
        key = k;
        val = v;
        freq = 1;
        prev = next = nullptr;
    }
};

struct DLList
{
    Node *head;
    Node *tail;
    int size;
    DLList()
    {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addFront(Node *node)
    {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
        size++;
    }

    void removeNode(Node *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        size--;
    }

    Node *removeLast()
    {
        if (size > 0)
        {
            Node *node = tail->prev;
            removeNode(node);
            return node;
        }
        return nullptr;
    }
};
class LFUCache
{
public:
    int capacity, minFreq, currSize;
    unordered_map<int, Node *> keyNode;
    unordered_map<int, DLList *> freqList;
    LFUCache(int capacity)
    {
        this->capacity = capacity;
        minFreq = 0;
        currSize = 0;
    }

    int get(int key)
    {
        if (keyNode.find(key) == keyNode.end())
            return -1;
        Node *node = keyNode[key];
        updateNode(node);
        return node->val;
    }

    void put(int key, int value)
    {
        if (capacity == 0)
            return;

        if (keyNode.find(key) != keyNode.end())
        {
            Node *node = keyNode[key];
            node->val = value;
            updateNode(node);
        }
        else
        {
            if (currSize == capacity)
            {
                DLList *list = freqList[minFreq];
                Node *evict = list->removeLast();
                keyNode.erase(evict->key);
                delete evict;
                currSize--;
            }
            Node *newNode = new Node(key, value);
            minFreq = 1;
            if (freqList.find(minFreq) == freqList.end())
            {
                freqList[minFreq] = new DLList();
            }
            freqList[minFreq]->addFront(newNode);
            keyNode[key] = newNode;
            currSize++;
        }
    }

private:
    void updateNode(Node *node)
    {
        int oldFreq = node->freq;
        freqList[oldFreq]->removeNode(node);
        if (oldFreq == minFreq && freqList[oldFreq]->size == 0)
        {
            minFreq++;
        }
        node->freq++;
        if (freqList.find(node->freq) == freqList.end())
        {
            freqList[node->freq] = new DLList();
        }
        freqList[node->freq]->addFront(node);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */