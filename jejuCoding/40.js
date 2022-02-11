const input = require('fs').readFileSync('input.txt').toString().trim().split('\n');

const limit = parseInt(input[0], 10);
const n = parseInt(input[1], 10);
const freind = input.slice(2);

let sum = 0;
let count = 0;

for (let i = 0; i < n; i++) {
    sum += parseInt(freind[i], 10);
    if (sum <= limit) {
        count = i + 1;
    }
}

console.log(count);