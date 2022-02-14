const n = require('fs').readFileSync('input.txt').toString().trim().split('');

let sum = 0;

for (let i in n) {
    sum += parseInt(n[i], 10);
}

console.log(sum);