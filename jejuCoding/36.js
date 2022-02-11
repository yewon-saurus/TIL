const n = require('fs').readFileSync('input.txt').toString().trim().split(' ');
let result = '';

for (let i = 1; i < 10; i++) {
    result += n[0] * i + ' ';
}

console.log(result)