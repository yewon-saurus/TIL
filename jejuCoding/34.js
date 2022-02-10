const input = require('fs').readFileSync('input.txt').toString().trim().split(' ');

function re(data) {
    for (let i = 0; i < data.length; i++) {
        if (data[i] > data[i+1]) {
            return 'NO';
        }
    }
    return 'YES';
}

console.log(re(input));