const n = require('fs').readFileSync('input.txt').toString().trim().split('');

let sum = 0;
for (let i = 0; i < n.length; i++) {
    sum += parseInt(n[i], 10);
}

console.log(sum);