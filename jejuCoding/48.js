let input = require('fs').readFileSync('input.txt').toString().trim().split('');
let test = '';

for (let i in input) {
    if (input[i] === (input[i]).toUpperCase()) {
        test += input[i].toLowerCase();
    }
    else {
        test += input[i].toUpperCase();
    }
}

console.log(test);