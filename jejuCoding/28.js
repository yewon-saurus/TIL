const input = require('fs').readFileSync('input.txt').toString().trim().split('\n');

for (var i = 0; i < input[0].length - 1; i++) {
    console.log(input[0].slice(i, i+1), input[0].slice(i+1, i+2));
}