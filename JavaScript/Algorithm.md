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

## Heap

### MaxHeap

```jsx
class MaxHeap {
    constructor() {
        this.heap = [];
    }

    push(value) {
        this.heap.push(value);

        var curr = this.heap.length - 1;
        var parent = Math.floor(curr / 2);

        while (this.heap[curr] > this.heap[parent]) {
            const temp = this.heap[curr];
            this.heap[curr] = this.heap[parent];
            this.heap[parent] = temp;

            curr = parent;
            parent = Math.floor(curr / 2);
        }
    }

    pop() {
        const maxValue = this.heap[0];
        this.heap[0] = this.heap[this.heap.length - 1];
        this.heap.pop();

        if (!maxValue) return "heap이 비어 있습니다.";

        var curr = 0;
        var left = 1;
        var right = 2;

        while (this.heap[curr] < this.heap[left] || this.heap[curr] < this.heap[right]) {
            if (this.heap[left] < this.heap[right]) {
                const temp = this.heap[right];
                this.heap[right] = this.heap[curr];
                this.heap[curr] = temp;

                curr = right;
            }
            else {
                const temp = this.heap[left];
                this.heap[left] = this.heap[curr];
                this.heap[curr] = temp;

                curr = left;
            }

            left = curr * 2 + 1;
            right = curr * 2 + 2;
        }

        return maxValue;
    }

    size() {
        return this.heap.length;
    }

    display() {
        console.log(this.heap);
    }
}
```

```jsx
const maxHeap = new MaxHeap();

console.log(maxHeap.pop());

maxHeap.push(3);
maxHeap.display();
maxHeap.push(2);
maxHeap.display();
maxHeap.push(6);
maxHeap.display();

maxHeap.push(11);
maxHeap.push(1);
maxHeap.push(122);
maxHeap.display();

console.log(maxHeap.pop());
maxHeap.display();
console.log(maxHeap.pop());
maxHeap.display();
console.log(maxHeap.pop());
maxHeap.display();
console.log(maxHeap.pop());
maxHeap.display();
console.log(maxHeap.pop());
maxHeap.display();
console.log(maxHeap.pop());
maxHeap.display();
console.log(maxHeap.pop());
maxHeap.display();
```

>heap이 비어 있습니다.<br />
[ 3 ]<br />
[ 3, 2 ]<br />
[ 6, 3, 2 ]<br />
[ 122, 11, 6, 3, 1, 2 ]<br />
122<br />
[ 11, 2, 6, 3, 1 ]<br />
11<br />
[ 6, 2, 1, 3 ]<br />
6<br />
[ 3, 2, 1 ]<br />
3<br />
[ 2, 1 ]<br />
2<br />
[ 1 ]<br />
1<br />
[]<br />
heap이 비어 있습니다.<br />
[]<br />

```jsx
const arr = [192, 12, 123, 1, 24, 12312, 34, 3];
const sortedArr = [];

const maxHeap = new MaxHeap();

for (item of arr) {
    maxHeap.push(item);
}

maxHeap.display();
while (maxHeap.size() > 0) {
    sortedArr.push(maxHeap.pop());
    maxHeap.display();
}

console.log(sortedArr);
```

>[ 12312, 192, 123, 34, 12, 24, 1, 3 ]<br />
[ 192, 34, 123, 3, 12, 24, 1 ]<br />
[ 123, 34, 24, 3, 12, 1 ]<br />
[ 34, 12, 24, 3, 1 ]<br />
[ 24, 12, 1, 3 ]<br />
[ 12, 3, 1 ]<br />
[ 3, 1 ]<br />
[ 1 ]<br />
[]<br />
[ 12312, 192, 123, 34,  24,  12, 3, 1 ]
