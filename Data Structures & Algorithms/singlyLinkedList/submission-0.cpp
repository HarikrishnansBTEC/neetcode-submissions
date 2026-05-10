struct Node {
    int val;
    Node* next;

    Node(int v) {
        val = v;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Get value at index
    int get(int index) {
        if (index < 0) return -1;

        Node* temp = head;
        int i = 0;

        while (temp != nullptr && i < index) {
            temp = temp->next;
            i++;
        }

        if (temp == nullptr) return -1;
        return temp->val;
    }

    // Insert at head
    void insertHead(int val) {
        Node* node = new Node(val);
        node->next = head;
        head = node;
    }

    // Insert at tail
    void insertTail(int val) {
        Node* node = new Node(val);

        if (head == nullptr) {
            head = node;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = node;
    }

    // Remove node at index
    bool remove(int index) {
        if (index < 0 || head == nullptr) return false;

        // Remove head
        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return true;
        }

        Node* prev = head;
        Node* curr = head->next;
        int i = 1;

        while (curr != nullptr && i < index) {
            prev = curr;
            curr = curr->next;
            i++;
        }

        if (curr == nullptr) return false;

        prev->next = curr->next;
        delete curr;
        return true;
    }

    // Return all values
    vector<int> getValues() {
        vector<int> result;
        Node* temp = head;

        while (temp != nullptr) {
            result.push_back(temp->val);
            temp = temp->next;
        }
        return result;
    }

    // Destructor to free memory
    ~LinkedList() {
        Node* curr = head;
        while (curr != nullptr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }
};