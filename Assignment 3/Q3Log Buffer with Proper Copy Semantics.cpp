#include <iostream>
#include <cstring>

using namespace std;

class LogBuffer {
private:
    char* buffer;
    int capacity;
    int size;
    static int instanceCount;

public:
    // Constructor
    LogBuffer(int cap) : capacity(cap), size(0) {
        buffer = new char[capacity];
        buffer[0] = '\0';
        instanceCount++;
        cout << "[LogBuffer Created] capacity=" << capacity << endl;
    }

    // Copy Constructor
    LogBuffer(const LogBuffer& other) : capacity(other.capacity), size(other.size) {
        buffer = new char[capacity];
        memcpy(buffer, other.buffer, size + 1);
        instanceCount++;
        cout << "[LogBuffer Deep Copied] capacity=" << capacity << endl;
    }

    // Copy Assignment Operator
    LogBuffer& operator=(const LogBuffer& other) {
        if (this == &other) {
            cout << "[Self-assignment detected — no operation]" << endl;
            return *this;
        }
        delete[] buffer;
        capacity = other.capacity;
        size = other.size;
        buffer = new char[capacity];
        memcpy(buffer, other.buffer, size + 1);
        cout << "[LogBuffer Assigned]" << endl;
        return *this;
    }

    // Destructor
    ~LogBuffer() {
        delete[] buffer;
        instanceCount--;
        cout << "[LogBuffer Destroyed]" << endl;
    }

    // Append String Data
    void append(const char* msg) {
        if (!msg) return;
        int msgLen = strlen(msg);
        int availableSpace = capacity - size - 1;
        if (availableSpace > 0) {
            int toCopy = (msgLen > availableSpace) ? availableSpace : msgLen;
            memcpy(buffer + size, msg, toCopy);
            size += toCopy;
            buffer[size] = '\0';
        }
    }

    // Print raw buffer data
    void print() const {
        cout << buffer << endl;
    }

    void clear() {
        size = 0;
        if (buffer) buffer[0] = '\0';
    }

    static int getInstanceCount() {
        return instanceCount;
    }
};

int LogBuffer::instanceCount = 0;

int main() {
    // Objective 1 : Basic usage
    LogBuffer log1(256);
    log1.append("Server started on port 8080");
    log1.append(" | Request received from 192.168.1.10");
    log1.print();

    // Objective 2 : Deep copy via copy constructor
    LogBuffer log2 = log1;
    log2.append(" | Cached response sent");
    cout << "log1 : ";
    log1.print();
    cout << "log2 : ";
    log2.print();

    // Objective 3 : Copy assignment operator
    LogBuffer log3(128);
    log3 = log1;
    cout << "log3 : ";
    log3.print();

    // Objective 4 : Self-assignment guard
    log1 = log1;

    // Objective 5 : Static member
    cout << "Live LogBuffer objects : " << LogBuffer::getInstanceCount() << endl;

    return 0;
}
