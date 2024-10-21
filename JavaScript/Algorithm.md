# JS 알고리즘

- JavaScript 알고리즘 연습 코드 쪼가리 모음

---

## Queue

```jsx
class Queue {
    constructor() {
        this.queue = [];
        this.front = 0;
        this.rear = 0;
    }

    enqueue(value) {
        this.queue.push(value);
        this.rear += 1;
    }

    dequeue() {
        const returnValue = this.queue[this.front];
        delete this.queue[this.front];
        this.front += 1;
        return returnValue;
    }

    peek() {
        return this.queue[this.front];
    }

    size() {
        return this.rear - this.front;
    }

    display() {
        console.log(this.queue.slice(this.front, this.rear + 1));
    }
}

const queue = new Queue();
queue.display();

queue.enqueue(1);
queue.enqueue(3);
queue.enqueue(2);
queue.display();
console.log(`peek result is: ${queue.peek()}`);
console.log(`queue size is: ${queue.size()}`);

console.log(queue.dequeue());
console.log(queue.dequeue());
queue.display();
console.log(`queue size is: ${queue.size()}`);
```

>[]<br />
[ 1, 3, 2 ]<br />
peek result is: 1<br />
queue size is: 3<br />
1<br />
3<br />
[ 2 ]<br />
queue size is: 1<br />

## LinkedList

```jsx
class Node {
    constructor(value) {
        this.value = value;
        this.next = null;
    }
}

class LinkedList {
    constructor() {
        this.head = null;
        this.tail = null;
        this.size = 0;
    }

    append(value) {
        const newNode = new Node(value);

        if (this.head === null) {
            this.head = newNode;
            this.tail = newNode;
        }
        else {
            this.tail.next = newNode;
            this.tail = newNode;
        }

        this.size += 1;
    }

    insert(prevNode, value) {
        const newNode = new Node(value);
        newNode.next = prevNode.next;
        prevNode.next = newNode;

        this.size += 1;
    }

    remove(value) {
        var prevNode = this.head;

        while (prevNode.next.value !== value) prevNode = prevNode.next;

        if (prevNode !== null) prevNode.next = prevNode.next.next;
    }

    find(value) {
        var currNode = this.head;

        while (currNode.value !== value) currNode = currNode.next;

        return currNode;
    }

    size() {
        return this.size;
    }

    display() {
        var currNode = this.head;
        const result = [];

        while (currNode !== null) {
            result.push(currNode.value);
            currNode = currNode.next;
        }

        console.log(result.join(" -> "));
    }
}

const list = new LinkedList();

list.append(1);
list.append(4);
list.append(3);
list.append(2);
list.display();

console.log(list.find(2));

list.insert(list.find(4), 100);
list.display();

console.log("\nremove 100:");
list.remove(100);
list.display();

console.log("\nremove 3:");
list.remove(3);
list.display();
```

>1 -> 4 -> 3 -> 2<br />
Node { value: 2, next: null }<br />
1 -> 4 -> 100 -> 3 -> 2<br />
<br />
remove 100:<br />
1 -> 4 -> 3 -> 2<br />
<br />
remove 3:<br />
1 -> 4 -> 2<br />
