const fs = require('fs');

const input = fs.readFileSync("/dev/stdin").toString().trim().split(" ").map(Number);

let result = input.reduce((a, b) => {
    return a + b;
});

console.log(result)