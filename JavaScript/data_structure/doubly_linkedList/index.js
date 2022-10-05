
class Node {
    constructor (val) {
        this.val = val;
        this.prev = null;
        this.next = null;
    }
}

class DoublyLinkedList {
    constructor () {
        this.head = null;
        this.tail = this.head;
        this.length = 0;
    }

    push(val) {
        const newNode = new Node(val);

        if (this.length === 0) {
            this.head = newNode;
            this.tail = this.head;
            this.length = 1;
            return newNode;
        }

        newNode.prev = this.tail;
        this.tail.next = newNode;
        this.tail = newNode;
        this.length++;
        return newNode;
    }

    pop() {
        if (this.length === 0) {
            return null;
        }

        if (this.length === 1) {
            this.head = null;
            this.tail = null;
            this.length = 0;
            return this;
        }
    }

    unshift(val) {
        const newNode = new Node(val);
        if (this.length === 0) {
            this.head = newNode;
            this.tail = this.head;
            this.length = 1;
            return newNode;
        }

        newNode.next = this.head;
        this.head.prev = newNode;
        this.head = newNode;
        this.length++;
        return this;
    }

    shift() {
        if (this.length === 0) {
            return null;
        }

        if (this.length === 1) {
            this.head = null;
            this.tail = this.head;
            this.length = 0;
            return this;
        }

        const next = this.head.next;

        next.prev = null;
        
        this.head = next;
        return this;
    }
}

const list = new DoublyLinkedList();

list.push(5);
list.push(6);
list.push(7);
list.unshift(4);
list.shift();

module.exports = DoublyLinkedList;