const input = require('fs').readFileSync('input.txt').toString().trim().split(' ').reverse();
let result = '';

for (var i = 0; i < input.length; i++) {
    result += input[i] + ' ';
}

console.log(result);