# JS 알고리즘

- JavaScript 알고리즘 연습 코드 쪼가리 모음

---

Queue

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
