const input = require('fs').readFileSync('input.txt').toString().trim().split('');
let result = '';

for (let i = 0; i < input.length; i++) {
    if (input[i] == 'q') {
        result += 'e'
    }
    else {
        result += input[i];
    }
}

console.log(result);