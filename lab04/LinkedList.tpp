template <typename T>
LinkedList<T>::LinkedList()
: head(nullptr) { }

template <typename T>
LinkedList<T>::~LinkedList() {
    clear();
}

template <typename T>
void LinkedList<T>::append(const T& elem) {
    // TODO
    Node* newNode = new Node(elem, nullptr);

    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node* currentNode = head;
        while (currentNode->next != nullptr) {
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
    }

    this->length++;
}

template <typename T>
void LinkedList<T>::clear() {
    // TODO
    Node* currentNode = head;

    while (currentNode != nullptr) {
        Node* node = currentNode;
        currentNode = currentNode->next;
        delete node;
    }

    head = nullptr;
    this->length = 0;
}

template <typename T>
T LinkedList<T>::getElement(int position) const {
    // TODO
    if (position < 0 || position >= this->length) {
        throw string("There has been an error, position out of bounds");
    }

    Node* currentNode = head;
    for (int i = 0; i < position; i++) {
        currentNode = currentNode->next;
    }

    return currentNode->value;
}

template <typename T>
int LinkedList<T>::getLength() const {
    return this->length;
}

template <typename T>
bool LinkedList<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
void LinkedList<T>::insert(int position, const T& elem) {
    if (position < 0 || position > this->length) {
        throw string("There has been an error, position out of bounds");
    }

    Node* newNode = new Node(elem, nullptr);

    if (position == 0) {
        newNode->next = head;
        head = newNode;
        this->length++;
        return;
    }

    Node* currentNode = head;
    for (int i = 0; i < position - 1; i++) {
        currentNode = currentNode->next;
    }

    newNode->next = currentNode->next;
    currentNode->next = newNode;
    this->length++;
}

template <typename T>
void LinkedList<T>::remove(int position) {
    if (this->length == 0) {
        throw string("There has been an error, list is empty");
    }

    if (position < 0 || position >= this->length) {
        throw string("There has been an error, position out of bounds");
    }

    if (position == 0) {
        Node* node = head;
        head = head->next;
        delete node;
        this->length--;
        return;
    }

    Node* currentNode = head;
    for (int i = 0; i < position - 1; i++) {
        currentNode = currentNode->next;
    }

    Node* node = currentNode->next;
    currentNode->next = node->next;
    delete node;
    this->length--;
}

template <typename T>
void LinkedList<T>::replace(int position, const T& elem) {
    // TODO
    if (position < 0 || position >= this->length) {
        throw string("There has been an error, position out of bounds");
    }

    Node* currentNode = head;
    for (int i = 0; i < position; i++) {
        currentNode = currentNode->next;
    }

    currentNode->value = elem;
}

template <typename T>
ostream& operator<<(ostream& outStream, const LinkedList<T>& myObj) {
    if (myObj.isEmpty()) {
        outStream << "List is empty, no elements to display.\n";
    }
    else {
        typename LinkedList<T>::Node* curr = myObj.head;
        while (curr != nullptr) {
            outStream << curr->value;
            if (curr->next != nullptr) {
                outStream << " --> ";
            }
            curr = curr->next;
        }
        outStream << endl;
    }

    return outStream;
}
