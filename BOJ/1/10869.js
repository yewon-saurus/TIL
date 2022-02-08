const input = require('fs').readFileSync('/dev/stdin').toString().split(' ');

const a = parseInt(input[0], 10);
const b = parseInt(input[1], 10);

console.log(a + b);
console.log(a - b);
console.log(a * b);
console.log(Math.floor(a / b));
console.log(a % b);